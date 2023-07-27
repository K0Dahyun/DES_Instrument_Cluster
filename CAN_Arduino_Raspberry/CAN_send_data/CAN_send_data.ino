#include <SPI.h>
#include <mcp2515.h>

//-------DISTANCE-----
#define ECHOPIN 4
#define TRIGPIN 5

//-------RPM-----
#include "Waveshare_LCD1602_RGB.h"
Waveshare_LCD1602_RGB lcd(16,2);

const byte PulsesPerRevolution = 2;
const unsigned long ZeroTimeout = 100000;
const byte numReadings = 2;

volatile unsigned long LastTimeWeMeasured;
volatile unsigned long PeriodBetweenPulses = ZeroTimeout + 1000;
volatile unsigned long PeriodAverage = ZeroTimeout + 1000;
unsigned long FrequencyRaw;
unsigned long FrequencyReal;
unsigned long RPM;
unsigned int PulseCounter = 1;
unsigned long PeriodSum;

unsigned long LastTimeCycleMeasure = LastTimeWeMeasured;
unsigned long CurrentMicros = micros();
unsigned int AmountOfReadings = 1;
unsigned int ZeroDebouncingExtra;
unsigned long readings[numReadings];
unsigned long readIndex;  
unsigned long total; 
unsigned long average;

//-------CAN-----
struct can_frame speed;
MCP2515 mcp2515(9);


long whatisDistance(){
  long distance;
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(15);
  digitalWrite(TRIGPIN, LOW);
  distance = pulseIn(ECHOPIN, HIGH, 26000);
  distance=distance/58;
  
  return distance;
}


long whatisRPM(){
  long RPM;
  LastTimeCycleMeasure = LastTimeWeMeasured;
  CurrentMicros = micros();
  if (CurrentMicros < LastTimeCycleMeasure) {
    LastTimeCycleMeasure = CurrentMicros;
  }
  FrequencyRaw = 10000000000 / PeriodAverage;
  if (PeriodBetweenPulses > ZeroTimeout - ZeroDebouncingExtra || CurrentMicros - LastTimeCycleMeasure > ZeroTimeout - ZeroDebouncingExtra) {
    FrequencyRaw = 0;  // Set frequency as 0.
    ZeroDebouncingExtra = 2000;
  } else {
    ZeroDebouncingExtra = 0;
  }
  FrequencyReal = FrequencyRaw / 10000;

  RPM = FrequencyRaw / PulsesPerRevolution * 60;
  RPM = RPM / 10000;
  total = total - readings[readIndex];
  readings[readIndex] = RPM;
  total = total + readings[readIndex];
  readIndex = readIndex + 1;

  if (readIndex >= numReadings) {
    readIndex = 0;
  }
  average = total / numReadings;

  return RPM;
}

void setup() {
  Serial.begin(115200);
  
  pinMode(ECHOPIN,INPUT_PULLUP); 
  pinMode(TRIGPIN, OUTPUT);
  digitalWrite(ECHOPIN, HIGH);
 
  attachInterrupt(digitalPinToInterrupt(3), Pulse_Event, RISING);

  mcp2515.reset();
  mcp2515.setBitrate(CAN_125KBPS,MCP_16MHZ);
  mcp2515.setNormalMode();

  speed.can_id=0x000;
  speed.can_dlc=8;
  for(int i=0;i<8;i++){
    speed.data[i]=0;
  }
  
}

void Pulse_Event() {
  PeriodBetweenPulses = micros() - LastTimeWeMeasured;
  LastTimeWeMeasured = micros();
  if (PulseCounter >= AmountOfReadings)  {
    PeriodAverage = PeriodSum / AmountOfReadings;
    PulseCounter = 1;
    PeriodSum = PeriodBetweenPulses;

    int RemapedAmountOfReadings = map(PeriodBetweenPulses, 40000, 5000, 1, 10);
    RemapedAmountOfReadings = constrain(RemapedAmountOfReadings, 1, 10);
    AmountOfReadings = RemapedAmountOfReadings;
  } else {
    PulseCounter++;
    PeriodSum = PeriodSum + PeriodBetweenPulses;
  }
}

void loop() {

  long distance = whatisDistance();
  long RPM = whatisRPM();

  speed.data[0] = RPM%256;
  speed.data[1] = RPM/256;
  speed.data[2] = distance%256;
  speed.data[3] = distance/256;

  for(int i=0;i<8;i++){
    Serial.print(speed.data[i]);
    Serial.print(" ");
  }

  Serial.println();
  mcp2515.sendMessage(&speed);
}

# Connect the Speed and Ultrasonic Sensor
Connect the speed sensor and ultrasonic sensor wires to the Arduino Uno and verify that it receives data correctly.


## 1. Speed Sensor(Model : LM393)
Whether you’re building a small robot or using any kind of motors in your projects, it might be useful to know the speed at which your are driving them.
In this section, we will see how to connect and use an infrared speed sensor based on the LM393 chip.
The speed sensor uses a disc with holes (encoder disc) to block the infrared beam, thus by counting the number of times the sensors goes from Low to High we can calculate the number of revolution for a given time period.

In this section, we will connect the speed sensor and the LCD together. However, the final goal is to connect the LCD to the Raspberry Pi, not the Arduino. The LCD connection discussed here is merely a test.

First, we need to wire it as shown in the picture below.
![image](https://github.com/K0Dahyun/Project-2/assets/119277948/21710b9f-f7cd-4fee-ba04-134a9d7eacd3)


Second, run the code below to check if the data is being received correctly.
[l2C](https://drive.google.com/file/d/15-vg0hSKDJ9EafxvWnjkg-o3WERHccBx/view?usp=sharing)
[Reference](https://srituhobby.com/ir-infrared-speed-sensor-with-arduino-how-does-work-ir-speed-sensor/?utm_content=cmp-true)

```c
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27, 16, 2);

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
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  attachInterrupt(digitalPinToInterrupt(2), Pulse_Event, RISING);
  delay(1000);

}
void loop() {
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



  Serial.print("Period: ");
  Serial.print(PeriodBetweenPulses);
  Serial.print("\tReadings: ");
  Serial.print(AmountOfReadings);
  Serial.print("\tFrequency: ");
  Serial.print(FrequencyReal);
  Serial.print("\tRPM: ");
  Serial.print(RPM);
  Serial.print("\tTachometer: ");
  Serial.println(average);
  lcd.setCursor(0, 0);
  lcd.print("RPM : ");
  lcd.print(RPM);
  lcd.print("   ");

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
```

At this point, the interrupt pin number is specified as 2. If you have connected to a different pin, you need to modify attachInterrupt(digitalPinToInterrupt(2), Pulse_Event, RISING);


## 2. Ultrasonic Sensor(Model : HC-SR04)
Similarly, connect as shown in the picture below.

![image](https://github.com/K0Dahyun/Project-2/assets/119277948/c2f3eb9b-9ecf-47c3-a7be-74f8253c4b4b)
[Reference](https://www.brainy-bits.com/post/using-the-hc-sr04-ultrasonic-range-sensor-with-an-arduino)

```c
#define ECHOPIN 10
#define TRIGPIN 9

void setup() {
  Serial.begin(9600);
  pinMode(ECHOPIN,INPUT_PULLUP);
  pinMode(TRIGPIN, OUTPUT);
  digitalWrite(ECHOPIN, HIGH);
}

void loop() {
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(15);
  digitalWrite(TRIGPIN, LOW);
  int distance = pulseIn(ECHOPIN, HIGH, 26000);
  distance=distance/58;

  Serial.print(distance);
  Serial.println("   cm");
  delay(50);
}
```

#define ECHOPIN 4
#define TRIGPIN 5

void setup() {
  Serial.begin(115200);
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

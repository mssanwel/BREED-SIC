void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  String c = Serial.readString();
  // Just enter the number in the serial monitor click enter, the message typed into the monitor will be sent
   Serial.println(c);
}

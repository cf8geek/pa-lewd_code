
int relayPin = 12;

void setup()
{
  // start serial port at 9600 bps and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

}
void loop() {
  // if there's any serial available, read it:
  while (Serial.available() > 0) {
    int serialData = Serial.read();
    if (serialData == '1') {
      // alarm ON
      digitalWrite(relayPin, HIGH);
    }
    if (serialData == '0') {
      // alarm OFF
      digitalWrite(relayPin, LOW);
    }
  }
}

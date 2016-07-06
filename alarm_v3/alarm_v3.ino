/*
some code to wake me up in the morning,
using my custom alarm box

-geek/cf8
*/

int relayPin0 = 11; // the PSU
int relayPin1 = 10; // the horn
int relayPin2 = 9; // the siren
int alarmState = 0;

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
      alarmState = '1';
    }
    if (serialData == '0') {
      // alarm OFF
      alarmState = '0';
    }
  }
  if (alarmState == '1') {
    digitalWrite(relayPin0, HIGH);
    digitalWrite(relayPin1, HIGH);
    delay(1500);
    digitalWrite(relayPin1, LOW);
    delay(1000);
    digitalWrite(relayPin2, HIGH);
    delay(500);
    digitalWrite(relayPin2, LOW);
    delay(500);
    digitalWrite(relayPin2, HIGH);
    delay(500);
    digitalWrite(relayPin2, LOW);
    delay(500);
    digitalWrite(relayPin2, HIGH);
    delay(500);
    digitalWrite(relayPin2, LOW);
    delay(500);
  }
  if (alarmState == '0') {
    digitalWrite(relayPin0, LOW);
    digitalWrite(relayPin1, LOW);
    digitalWrite(relayPin2, LOW);
  }
}

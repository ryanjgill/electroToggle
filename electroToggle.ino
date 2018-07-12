/* Electroplating
 * 
 * Toggle relay with set on and off durations
 * 
 */

int relay = 7;
int led = 13;
long onTime = 4000;
long offTime = 4000;

void turnOn() {
  digitalWrite(relay, HIGH);
  Serial.println("Relay ON");
}

void turnOff() {
  digitalWrite(relay, LOW);
  Serial.println("Relay OFF");
}

void setup()
{
  // Set both relay and led pins to OUTPUT
  pinMode(relay, OUTPUT);
  pinMode(led, OUTPUT);

  // Turn on power led
  digitalWrite(led, HIGH);
}

void loop()
{
  Serial.begin(9600);
  // Turn on relay for on duration
  turnOn();
  delay(onTime);

  // Turn off relay for off duration
  turnOff();
  delay(offTime);
}

/* Electroplating
 * 
 * Toggle relay with set on and off durations
 * Power switch interrupt to toggle cycling of relay
 * 
 */

const int powerSwitch = 2;
const int relay = 7;
const int led = 13;

long onTime = 10000;
long offTime = 3000;

volatile bool isActive = false;

void turnOn() {
  digitalWrite(relay, HIGH);
}

void turnOff() {
  digitalWrite(relay, LOW);
}

void toggleState() {
  isActive = !isActive;
  digitalWrite(led, isActive);
}

void setup()
{
  // Set both relay and led pins to OUTPUT
  pinMode(relay, OUTPUT);
  pinMode(led, OUTPUT);
  // Set power switch pin to INPUT
  pinMode(powerSwitch, INPUT);
  // Default power switch to HIGH state
  // Pressing switch brings it LOW
  digitalWrite(powerSwitch, HIGH); 
  // Attach an interrupt to the power switch pin
  attachInterrupt(digitalPinToInterrupt(powerSwitch), toggleState, FALLING);
}

void loop()
{
  while(isActive) {
    // Turn on relay for on duration
    turnOn();
    delay(onTime);
    // Turn off relay for off duration
    turnOff();
    delay(offTime);
  } 
}

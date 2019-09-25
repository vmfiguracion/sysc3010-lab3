#include <MsTimer2.h>

#define VAR_RESISTOR A0
int var_resistor_value;

void readVariableResistor();

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  MsTimer2::set(20, readVariableResistor);
  MsTimer2::start();
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(var_resistor_value);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(var_resistor_value);                       // wait for a second
}

void readVariableResistor() {
  var_resistor_value = analogRead(VAR_RESISTOR);
  Serial.println(var_resistor_value);
}

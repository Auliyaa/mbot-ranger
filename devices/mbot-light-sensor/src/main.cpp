#include <Arduino.h>

#include <MeAuriga.h>
#include <mbot/light_sensors.h>

mbot::light_sensors_t light_sensors;

void setup()
{
  Serial.begin(115200);
}

// Periodically reads and sends back the value for both light sensors.
void loop()
{
  Serial.print("Right sensor: ");
  Serial.print(light_sensors.read_right());
  Serial.print(" Left sensor: ");
  Serial.println(light_sensors.read_left());
  delay(1000);
}

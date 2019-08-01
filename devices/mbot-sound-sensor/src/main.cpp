#include <Arduino.h>

#include <MeAuriga.h>
#include <mbot/sound_sensor.h>

mbot::sound_sensor_t sound;

void setup()
{
  Serial.begin(115200);
}

// Simply print the current value of the sound sensor at each loop.
void loop()
{
  Serial.print("Sound sensor: ");
  Serial.print(sound.read());
  Serial.print(" (");
  Serial.print(sound.percent());
  Serial.println("%)");
  delay(20);
}

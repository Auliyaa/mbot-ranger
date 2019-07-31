#include <MeAuriga.h>

#include <mbot/ultrasonic.h>

mbot::ultrasonic_t u;

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  Serial.println(u.distance());
  delay(50);
}

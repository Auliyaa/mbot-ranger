#include <MeAuriga.h>

#include <mbot/gyro.h>

mbot::gyro_t g(0,0x68);
mbot::gyro_t g1(1,0x69);

void setup()
{
  Serial.begin(115200);
  g.begin();
}

void loop()
{
  Serial.print("X: ");
  Serial.print(g.x());
  Serial.print(" Y: ");
  Serial.print(g.y());
  Serial.print(" Z: ");
  Serial.println(g.z());

  Serial.print("X: ");
  Serial.print(g1.x());
  Serial.print(" Y: ");
  Serial.print(g1.y());
  Serial.print(" Z: ");
  Serial.println(g1.z());
  delay(20);
}

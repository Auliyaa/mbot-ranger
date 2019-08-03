#include <MeAuriga.h>

#include <mbot/servo.h>

mbot::servo_t servo{PORT_8};

void setup()
{
  servo.attach();
}

void loop()
{
  servo.set_angle_1(0);
  delay(1000);
  servo.set_angle_1(90);
  delay(1000);
  servo.set_angle_1(180);
  delay(1000);
  servo.set_angle_1(90);
}

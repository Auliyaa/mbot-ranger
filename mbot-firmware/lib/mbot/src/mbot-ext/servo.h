#ifndef _MBOT_SERVO_H_
#define _MBOT_SERVO_H_

#include <MePort.h>

namespace mbot
{

/**
  * (Variey Gizmos Addon) Wraps the included Servo which is connected to a 2-PIN board
  */
class servo_t
{
public:
  servo_t(uint8_t port);
  virtual ~servo_t() = default;

  /**
    * Attaches the Servo board to its 2 pins extensions.
    * Note: Must be called at setup() and not from the global scope.
    */
  void attach();

  /**
    * Sets the angle of the servo on PIN #1.
    * Angle is between 0 and 360°
    */
  void set_angle_1(int a);

  /**
    * Sets the angle of the servo on PIN #2.
    * Angle is between 0 and 360°
    */
  void set_angle_2(int a);

private:
  MePort _port;

  Servo _device_1;
  Servo _device_2;
};

} // namespace mbot

#endif // _MBOT_SERVO_H_

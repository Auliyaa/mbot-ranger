#ifndef _MBOT_MOTORS_H_
#define _MBOT_MOTORS_H_

#include <MeEncoderOnBoard.h>
#include <MePort.h>

namespace mbot
{

/**
  * Represents one of the PWM motor located on the mBot ranger.
  */
class motor_t
{
public:
  motor_t(uint8_t slot);
  virtual ~motor_t() = default;

  /**
    * Sets the current PWM value on this motor.
    */
  void set_pwm(int16_t p);

  /**
    * Returns the current PWM value set on this instance.
    */
  int16_t pwm() const;

private:
  MeEncoderOnBoard _device;
};

} // namespace mbot

#endif // _MBOT_MOTORS_H_

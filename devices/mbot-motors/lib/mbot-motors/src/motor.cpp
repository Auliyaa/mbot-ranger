#include <mbot/motor.h>

using namespace mbot;

motor_t::motor_t(uint8_t slot)
  : _device{slot}
{
}

void motor_t::set_pwm(int16_t p)
{
  _device.setMotorPwm(p);
}

int16_t motor_t::pwm() const
{
  return _device.getCurPwm();
}

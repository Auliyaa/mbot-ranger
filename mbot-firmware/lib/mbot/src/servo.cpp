#include <mbot-ext/servo.h>

using namespace mbot;

mbot::servo_t::servo_t(uint8_t port)
  : _port{port}
{
}

void mbot::servo_t::attach()
{
  _device_1.attach(_port.pin1());
  _device_2.attach(_port.pin2());
}

void mbot::servo_t::set_angle_1(int a)
{
  _device_1.write(a);
}

void mbot::servo_t::set_angle_2(int a)
{
  _device_2.write(a);
}

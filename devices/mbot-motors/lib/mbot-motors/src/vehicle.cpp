#include <mbot/vehicle.h>

using namespace mbot;

vehicle_t::vehicle_t(uint8_t slot_right, uint8_t slot_left)
  : _right{slot_right}, _left{slot_left},
    _speed_right{0}, _speed_left{0}
{
}

void vehicle_t::apply_direction(mbot::vehicle_t::direction_t d)
{
  switch(d)
  {
    case direction_t::forward:
      _speed_right = -abs(_speed_right);
      _speed_left  =  abs(_speed_left);
      break;
    case direction_t::backwards:
      _speed_right =  abs(_speed_right);
      _speed_left  = -abs(_speed_left);
      break;
    case direction_t::right:
      _speed_right =  abs(_speed_right);
      _speed_left  =  abs(_speed_left);
      break;
    case direction_t::left:
      _speed_right = -abs(_speed_right);
      _speed_left  = -abs(_speed_left);
      break;
  }
}

void vehicle_t::shift_speed_right(int16_t s)
{
  _speed_right += s;
}

void vehicle_t::shift_speed_left(int16_t s)
{
  _speed_left += s;
}

void vehicle_t::start()
{
  _right.set_pwm(_speed_right);
  _left.set_pwm(_speed_left);
}

void vehicle_t::stop()
{
  _right.set_pwm(0);
  _left.set_pwm(0);
}

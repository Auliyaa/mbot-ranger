#include <mbot/ultrasonic.h>

using namespace mbot;

ultrasonic_t::ultrasonic_t(uint8_t port)
  : _device{port}
{
}

double ultrasonic_t::distance(mbot::ultrasonic_t::unit_t u, uint16_t max)
{
  switch(u)
  {
    case unit_t::cm: return _device.distanceCm(max != 0 ? max : 400);
    case unit_t::in: return _device.distanceInch(max != 0 ? max : 180);
  }
}

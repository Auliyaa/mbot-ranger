#include <mbot/ultrasonic_sensor.h>

using namespace mbot;

ultrasonic_sensor_t::ultrasonic_sensor_t(uint8_t port)
  : _device{port}
{
}

double ultrasonic_sensor_t::distance(mbot::ultrasonic_sensor_t::unit_t u, uint16_t max)
{
  switch(u)
  {
    case unit_t::cm: return _device.distanceCm(max != 0 ? max : 400);
    case unit_t::in: return _device.distanceInch(max != 0 ? max : 180);
  }
}

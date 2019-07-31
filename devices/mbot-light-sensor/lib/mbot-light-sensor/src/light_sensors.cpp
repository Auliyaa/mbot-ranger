#include <mbot/light_sensors.h>

using namespace mbot;

light_sensors_t::light_sensors_t(uint8_t port_right, uint8_t port_left)
  : _right{port_right}, _left{port_left}
{
}

int16_t light_sensors_t::read_right() const
{
  return _right.read();
}

int16_t light_sensors_t::read_left() const
{
  return _left.read();
}

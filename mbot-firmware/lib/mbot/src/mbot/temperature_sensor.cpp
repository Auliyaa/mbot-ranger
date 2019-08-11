#include <mbot/temperature_sensor.h>

using namespace mbot;

temperature_sensor_t::temperature_sensor_t(uint8_t port, uint8_t slot)
  : _device{port, slot}
{
}

float temperature_sensor_t::read() const
{
  return _device.temperature();
}

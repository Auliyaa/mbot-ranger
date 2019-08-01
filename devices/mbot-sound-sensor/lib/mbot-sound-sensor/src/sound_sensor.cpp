#include <mbot/sound_sensor.h>

using namespace mbot;

sound_sensor_t::sound_sensor_t(uint8_t port)
  : _device{port}
{
}

int16_t sound_sensor_t::read() const
{
  return _device.strength();
}

float sound_sensor_t::percent() const
{
  return static_cast<float>(read()) * 100. / static_cast<float>(MBOT_MAX_SOUND_SENSOR_VALUE);
}

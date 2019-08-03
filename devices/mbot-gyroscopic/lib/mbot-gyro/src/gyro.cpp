#include <mbot/gyro.h>

using namespace mbot;

gyro_t::gyro_t(uint8_t port, uint8_t address)
  : _device{port, address}
{
}

void gyro_t::begin()
{
  _device.begin();
}

double gyro_t::x() const
{
  _device.update();
  return _device.getAngle(1);
}

double gyro_t::y() const
{
  return _device.getAngle(2);
}

double gyro_t::z() const
{
  return _device.getAngle(3);
}

#ifndef _MBOT_TEMPERATURE_SENSOR_H_
#define _MBOT_TEMPERATURE_SENSOR_H_

#include <MeTemperature.h>

namespace mbot
{

/**
  A thin wrapper around the mbot's onboard tempertature sensor.
  */
class temperature_sensor_t
{
public:
  temperature_sensor_t(uint8_t port, uint8_t slot);
  virtual ~temperature_sensor_t() = default;

  /**
    * Returns the current temperature in °C
    */
  float read() const;

private:
  MeTemperature _device;
};

} // namespace mbot

#endif // _MBOT_TEMPERATURE_SENSOR_H_

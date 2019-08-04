#ifndef _MBOT_SOUND_SENSOR_H_
#define _MBOT_SOUND_SENSOR_H_

#include <MeSoundSensor.h>

/**
  * Default port for the sound sensor device on the mBot Ranger.
  * Note that manual testing reveals that this device can also be accessed through PORT5
  */
#define MBOT_SOUND_SENSOR_PORT 14

/**
  * Minimum documented value that can be reported by the sound sensor device.
  */
#define MBOT_MIN_SOUND_SENSOR_VALUE 0

/**
  * Maximum documented value that can be reported by the sound sensor device.
  */
#define MBOT_MAX_SOUND_SENSOR_VALUE 1023

namespace mbot
{

/**
  * A very thin wrapper around sound sensor device embedded on the mBot Ranger
  */
class sound_sensor_t
{
public:
  sound_sensor_t(uint8_t port=MBOT_SOUND_SENSOR_PORT);
  virtual ~sound_sensor_t() = default;

  /**
    * Returns the raw sound value reported by the sound sensor
    */
  int16_t read() const;

  /**
    * Returns the percentage value of the current sound strength reported by the sound sensor device.
    * The percentage value is computed inside the range [MBOT_MIN_SOUND_SENSOR_VALUE, MBOT_MAX_SOUND_SENSOR_VALUE]
    */
  float percent() const;

private:
  MeSoundSensor _device;
};

} // namespace mbot

#endif // _MBOT_SOUND_SENSOR_H_

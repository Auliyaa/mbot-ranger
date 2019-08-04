#ifndef _MBOT_ULTRASOUND_H_
#define _MBOT_ULTRASOUND_H_

#include <MeUltrasonicSensor.h>

namespace mbot
{

/**
  * Default port where the ultrasonic sensor is plugged-in, according to the mbot ranger manual.
  */
#define MBOT_ULTRASONIC_SENSOR_PORT PORT_10

/**
  * Very thin wrapper around the ultrasonic sensor embedded on the Auriga board.
  */
class ultrasonic_sensor_t
{
public:
  /**
    * Describe each unit of distance supported by this sensor.
    */
  enum class unit_t
  {
    cm,
    in
  };

  ultrasonic_sensor_t(uint8_t port=MBOT_ULTRASONIC_SENSOR_PORT);
  virtual ~ultrasonic_sensor_t() = default;

  /**
    * Fetches the current distance reported by the sensor, in the provided unit.
    * The max parameter is indicated by the firmware as the max measureable distance. Whatever that means.
    * Leaving max to 0 will use a default max of 400 for cm, 180 for inches.
    */
  double distance(unit_t u=unit_t::cm, uint16_t max=0);

private:
  MeUltrasonicSensor _device;
};

} // namespace mbot

#endif // _MBOT_ULTRASOUND_H_

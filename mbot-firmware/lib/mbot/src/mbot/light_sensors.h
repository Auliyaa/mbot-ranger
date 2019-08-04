#ifndef _MBOT_LIGHT_SENSOR_H_
#define _MBOT_LIGHT_SENSOR_H_

#include <MeLightSensor.h>

namespace mbot
{

/**
  * Default port for the right-sided port sensor.
  * Note: Manual testing shows that PORT2 reports the same value.
  */
#define MBOT_RIGHT_LIGHT_SENSOR_PORT PORT_11

/**
  * Default port for the left-sided port sensor.
  */
#define MBOT_LEFT_LIGHT_SENSOR_PORT PORT_12

/**
  * About the maximum value obtainable on a light sensor.
  * This comes from manual testing and should be used with a grain of salt.
  */
#define MBOT_MAX_LIGHT_SENSOR_VALUE 1000

/**
  * Minimum value reported by light sensors.
  * This comes from manual testing and should be used with a grain of salt.
  */
#define MBOT_MIN_LIGHT_SENSOR_VALUE 0

class light_sensors_t
{
public:
  light_sensors_t(uint8_t port_right=MBOT_RIGHT_LIGHT_SENSOR_PORT, uint8_t port_left=MBOT_LEFT_LIGHT_SENSOR_PORT);

  /**
    * Returns the numerical value reported by the right-sided light sensor.
    */
  int16_t read_right() const;

  /**
    * Returns the numerical value reported by the left-sided light sensor.
    */
  int16_t read_left() const;

private:
  MeLightSensor _right;
  MeLightSensor _left;
};

} // namespace mbot

#endif // _MBOT_LIGHT_SENSOR_H_

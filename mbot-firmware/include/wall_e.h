#ifndef _WALL_E_H_
#define _WALL_E_H_

#include <mbot/serial.h>

#include <mbot/vehicle.h>
#include <mbot/buzzer.h>
#include <mbot/led_ring.h>
#include <mbot-ext/segments_display.h>
#include <mbot-ext/servo.h>

#include <mbot/light_sensors.h>
#include <mbot/sound_sensor.h>
#include <mbot/ultrasonic_sensor.h>

#include <mbot/buzzer_tones.h>

#ifndef WALL_E_DEBUG
#define DBG(m)
#else // WALL_E_DEBUG
#define DBG(m) Serial.print(m)
#endif // WALL_E_DEBUG

struct wall_e_t
{
  mbot::vehicle_t          vehicle;
  mbot::servo_t            servo;

  mbot::buzzer_t           buzzer;
  mbot::led_ring_t         led_ring;
  mbot::segments_display_t display;

  mbot::light_sensors_t light_sensor;
  mbot::sound_sensor_t sound_sensor;
  mbot::ultrasonic_sensor_t ultrasonic_sensor;

  wall_e_t();
  virtual ~wall_e_t() = default;

  void init();
  void check();
};

#endif // _WALL_E_H_

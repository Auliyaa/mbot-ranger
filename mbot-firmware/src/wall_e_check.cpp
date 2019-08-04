#include <wall_e.h>

void wall_e_t::check()
{
  DBG("Checking buzzer");
  buzzer.play(TONE_A4, 500);

  DBG("Checking motors");
  buzzer.play(TONE_A4, 100);
  vehicle.set_speed(MBOT_SPEED_MID);
  vehicle.apply_direction(mbot::vehicle_t::direction_t::forward);
  vehicle.start();
  delay(500);
  vehicle.apply_direction(mbot::vehicle_t::direction_t::backwards);
  vehicle.start();
  delay(500);
  vehicle.apply_direction(mbot::vehicle_t::direction_t::left);
  vehicle.start();
  delay(500);
  vehicle.apply_direction(mbot::vehicle_t::direction_t::right);
  vehicle.start();
  delay(500);
  vehicle.stop();

  DBG("Checking servo");
  servo.set_angle_1(0);
  delay(500);
  servo.set_angle_1(90);
  delay(500);
  servo.set_angle_1(180);
  delay(500);
  servo.set_angle_1(90);
  delay(500);

  DBG("Checking LED ring");
  buzzer.play(TONE_A4, 100);
  for(uint8_t led_idx=0; led_idx < led_ring.led_count(); ++led_idx)
  {
    led_ring.set_color(led_idx, 255,0,0);
    led_ring.apply();
    delay(100);
  }
  led_ring.clear();
  led_ring.apply();

  DBG("Checking segments display");
  buzzer.play(TONE_A4, 100);

  display.show(9);
  delay(500);
  display.show(98);
  delay(500);
  display.show(987);
  delay(500);
  display.show(9876);
  delay(500);
  display.clear();

  DBG("Checking sound sensor");
  buzzer.play(TONE_A4, 100);
  for(int i=0; i<5; ++i)
  {
    buzzer.play(TONE_A4, 100);
    display.show(sound_sensor.percent());
    delay(1000);
  }
  display.clear();

  DBG("Checking ultrasonic sensor");
  buzzer.play(TONE_A4, 100);
  for(int i=0; i<5; ++i)
  {
    buzzer.play(TONE_A4, 100);
    display.show(ultrasonic_sensor.distance());
    delay(1000);
  }
  display.clear();

  DBG("Checking light sensor");
  buzzer.play(TONE_A4, 100);
  for(int i=0; i<5; ++i)
  {
    buzzer.play(TONE_A4, 100);
    display.show(light_sensor.read_left());
    delay(1000);
    display.show(light_sensor.read_right());
  }
  display.clear();
}

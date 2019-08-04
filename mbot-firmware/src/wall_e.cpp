#include <wall_e.h>

wall_e_t::wall_e_t()
  : vehicle{MBOT_RIGHT_MOTOR_SLOT, MBOT_LEFT_MOTOR_SLOT},
    servo{PORT_7},
    led_ring{MBOT_LED_RING_PORT},
    display{PORT_10},
    light_sensor{MBOT_RIGHT_LIGHT_SENSOR_PORT, MBOT_LEFT_LIGHT_SENSOR_PORT},
    sound_sensor{MBOT_SOUND_SENSOR_PORT},
    ultrasonic_sensor{PORT_6}
{
}

void wall_e_t::init()
{
  Serial.begin(MBOT_SERIAL_BAUD_RATE);

  vehicle.set_speed(MBOT_SPEED_MID);

  servo.attach();
  servo.set_angle_1(90);

  buzzer.open(MBOT_BUZZER_PIN);

  led_ring.connect(MBOT_LED_RING_PIN);
  led_ring.clear();
  led_ring.apply();

  display.init();
  display.set_brightness(2);
}

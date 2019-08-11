#include <wall_e.h>

wall_e_t::wall_e_t()
  : vehicle{SLOT_1, SLOT_2},
    servo{PORT_7},
    led_ring{PORT0},
    display{PORT_10},
    light_sensor{PORT_11, PORT_12},
    sound_sensor{PORT_14},
    ultrasonic_sensor{PORT_6},
    // temperature_sensor{PORT0,0},
    line_sensor{PORT_9}
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

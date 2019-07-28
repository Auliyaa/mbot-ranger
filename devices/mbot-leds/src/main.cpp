#include <MeAuriga.h>

#include <mbot/led-ring.h>

mbot::led_ring_t leds;

void setup()
{
  // Connects to the onboard device. Must be called once at setup.
  leds.connect();

  // Resets all colors on the LED ring
  // Note: For some reason, when working while tue board is plugged-in via USB, the LED 1 keeps showing as green.
  // Un-plugging and re-plugging the board fixes the issue.
  leds.set_color(0, 0, 0);
  leds.apply();
}

// Set this to true to use the HSV colorspace instead of RGB
bool hsv_mode{true};

void rgb_mode_loop();
void hsv_mode_loop();

void loop()
{
  if (hsv_mode)
  {
    // HSV mode: Change the hue of each LED independently
    hsv_mode_loop();
  }
  else
  {
    // RGB mode: Set all LEDs to RED, one by one and loop.
    rgb_mode_loop();
  }
}

void hsv_mode_loop()
{
  // -> The index of the current LED
  static uint8_t idx{0};

  // -> Const saturation and value
  static const uint8_t s = 100;
  static const uint8_t v = 100;
  static uint16_t h = random(361);

  leds.set_color(idx, mbot::led_ring_t::hsv_t{h, s, v});
  h+=random(30);
  if (h > 360)
  {
    h = 0;
  }

  // -> Increment the index and loop if we reached the last LED.
  ++idx;
  if (idx == leds.led_count())
  {
    idx = 0;
  }
  // -> Send all data to the LED controller.
  leds.apply();
  // And wait a bit for the next loop.
  delay(30);
}

void rgb_mode_loop()
{
  // -> The index of the current LED
  static uint8_t idx{0};
  // -> start by resetting all LEDs to off.
  leds.set_color(0, 0, 0);
  // -> Then apply red on the current LED.
  leds.set_color(idx, 255, 0, 0);
  // -> Increment the index and loop if we reached the last LED.
  ++idx;
  if (idx == leds.led_count())
  {
    idx = 0;
  }
  // -> Send all data to the LED controller.
  leds.apply();
  // And wait a bit for the next loop.
  delay(100);
}

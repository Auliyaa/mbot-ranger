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

void loop()
{
  // As an example, we will light each LED one by one in red and loop indefinitely.
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

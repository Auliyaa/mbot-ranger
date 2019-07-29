#include <mbot/led-ring.h>

using namespace mbot;

led_ring_t::led_ring_t(uint8_t port, uint8_t led_count)
  : _device{port, led_count},
    _led_count{led_count}
{
}

bool led_ring_t::connect(uint8_t pin)
{
  _device.setpin(pin);
  return true;
}

uint8_t led_ring_t::led_count() const
{
  return _led_count;
}

rgb_t led_ring_t::color_at(uint8_t idx) const
{
  return _device.getColorAt(idx);
}

bool led_ring_t::set_color(uint8_t idx, uint8_t r, uint8_t g, uint8_t b)
{
  return _device.setColor(idx+1, r, g, b);
}

bool led_ring_t::set_color(uint8_t r, uint8_t g, uint8_t b)
{
  // 0 means all LEDs
  return _device.setColor(0, r, g, b);
}

void led_ring_t::apply()
{
  _device.show();
}

void led_ring_t::clear()
{
  // Avoids a weird issue with the LED ring where 1 led stays green if we only apply 0,0,0 to all LEDs.
  set_color(1,0,0);
  set_color(0,0,0);
}

#include <mbot/segments_display.h>

using namespace mbot;

segments_display_t::segments_display_t(uint8_t port)
  : _device{port}
{
}

void segments_display_t::init()
{
  _device.init();
}

void segments_display_t::clear()
{
  _device.clearDisplay();
}

void segments_display_t::set_brightness(uint8_t level)
{
  _device.setBrightness(level);
}

void segments_display_t::display(uint16_t v)
{
  _device.display(v);
}

void segments_display_t::display(float v)
{
  _device.display(v);
}

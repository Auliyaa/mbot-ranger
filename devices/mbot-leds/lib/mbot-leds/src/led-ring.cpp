#include <mbot/led-ring.h>

using namespace mbot;

led_ring_t::hsv_t led_ring_t::rgb_t::to_hsv() const
{
  float fr = static_cast<float>(r)/255.;
  float fg = static_cast<float>(g)/255.;
  float fb = static_cast<float>(b)/255.;

  float cmax = max(max(fr,fg),fb);
  float cmin = min(min(fr,fg),fb);
  float cdelta = cmax - cmin;

  float fh, fs, fv;

  if (cdelta > 0)
  {
    if (cmax == fr)
    {
      fh = 60. * (fmod(((fg - fb) / cdelta), 6));
    }
    else if(cmax == fg)
    {
      fh = 60. * (((fb - fr) / cdelta) + 2.);
    }
    else if(cmax == fb)
    {
      fh = 60. * (((fr - fg) / cdelta) + 4.);
    }

    if (cmax > 0)
    {
      fs = cdelta / cmax;
    }
    else
    {
      fs = 0;
    }

    fv = cmax;
  }

  else // delta < 0
  {
    fh = 0;
    fs = 0;
    fv = cmax;
  }

  if (fh < 0)
  {
    fh += 360.;
  }

  return hsv_t{static_cast<uint16_t>(fh), static_cast<uint8_t>(fs*100.), static_cast<uint8_t>(fv*100.)};
}

led_ring_t::rgb_t led_ring_t::hsv_t::to_rgb() const
{
  float fs = static_cast<float>(s)/100.;
  float fv = static_cast<float>(v)/100.;

  float c = fs * fv;
  float x = c * (1. - abs(fmod(static_cast<float>(h) / 60., 2) - 1.));
  float m = fv - c;

  float rs, gs, bs;

#define _to_rgb(rs, gs, bs) {static_cast<uint8_t>((rs+m)*255.), static_cast<uint8_t>((gs+m)*255.), static_cast<uint8_t>((bs+m)*255.)}

  if (h >= 0 && h < 60)
  {
    return _to_rgb(c, x, 0);
  }
  else if (h < 120)
  {
    return _to_rgb(x, c, 0);
  }
  else if (h < 180)
  {
    return _to_rgb(0, c, x);
  }
  else if (h < 240)
  {
    return _to_rgb(0, x, c);
  }
  else if (h < 300)
  {
    return _to_rgb(x, 0, c);
  }

  return _to_rgb(c, 0, x);

#undef _to_rgb
}

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

led_ring_t::rgb_t led_ring_t::color_at(uint8_t idx) const
{
  return _device.getColorAt(idx);
}

bool led_ring_t::set_color(uint8_t idx, const led_ring_t::rgb_t& rgb)
{
  return set_color(idx, rgb.r, rgb.g, rgb.b);
}

bool led_ring_t::set_color(uint8_t idx, uint8_t r, uint8_t g, uint8_t b)
{
  return _device.setColor(idx+1, r, g, b);
}

bool led_ring_t::set_color(uint8_t idx, const led_ring_t::hsv_t& hsv)
{
  return set_color(idx, hsv.to_rgb());
}

bool led_ring_t::set_color(const led_ring_t::rgb_t& rgb)
{
  return set_color(rgb.r, rgb.g, rgb.b);
}

bool led_ring_t::set_color(uint8_t r, uint8_t g, uint8_t b)
{
  // 0 means all LEDs
  return _device.setColor(0, r, g, b);
}

bool led_ring_t::set_color(const led_ring_t::hsv_t& hsv)
{
  return set_color(hsv.to_rgb());
}

void led_ring_t::apply()
{
  _device.show();
}

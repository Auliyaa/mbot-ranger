#ifndef _MBOT_LEDS_H_
#define _MBOT_LEDS_H_

#include <MeRGBLed.h>

namespace mbot
{
  /**
    * A ring of LEDS where each led can be controlled individually.
    */
  class led_ring_t
  {
    MeRGBLed _device;
    uint8_t _led_count;
  public:
    struct hsv_t;

    /**
      * Describes a color in the RGB color space where:
      * R (red) is in the range [0, 255]
      * G (green) is in the range [0, 255]
      * B (blue) is in the range [0, 255]
      */
    struct rgb_t
    {
      uint8_t r;
      uint8_t g;
      uint8_t b;

      rgb_t(uint8_t r=0, uint8_t g=0, uint8_t b=0): r{r}, g{g}, b{b} {}
      rgb_t(const cRGB& rgb): r{rgb.r}, g{rgb.g}, b{rgb.b} {}
      rgb_t(const rgb_t& other) = default;

      virtual ~rgb_t() = default;

      /**
        * Converts the current instance into the HSV colorspace
        * See https://gist.github.com/fairlight1337/4935ae72bcbcc1ba5c72
        */
      hsv_t to_hsv() const;
    };

    /**
      * Describes a color in the HSV Color space where:
      * H (hue) is in the range [0,360]
      * S (saturation) is in the range [0,100]
      * V (value) is in the range [0,100]
      */
    struct hsv_t
    {
      uint16_t h;
      uint8_t  s;
      uint8_t  v;

      hsv_t(uint16_t h=0, uint8_t s=0, uint8_t v=0): h{h}, s{s}, v{v} {}
      hsv_t(const hsv_t& other) = default;
      virtual ~hsv_t() = default;

      /**
        * Converts the current instance into the RGB color space.
        * See https://gist.github.com/kuathadianto/200148f53616cbd226d993b400214a7f for details.
        */
      rgb_t to_rgb() const;
    };

    /**
      * Constructor
      * By default, Auriga on-board light ring is on PORT0 and has 12 LEDs.
      */
    led_ring_t(uint8_t port=PORT0, uint8_t led_count=12);

    /**
      * Destructor
      */
    virtual ~led_ring_t() = default;

    /**
      * Sets the data PIN for the current LED ring.
      * By default, the LED Ring controller is on Auriga D44/PWM.
      */
    bool connect(uint8_t pin=44);

    /**
      * Returns the number of available LEDs.
      */
    uint8_t led_count() const;

    /**
      * Returns the color for the LED at a specified index
      */
    rgb_t color_at(uint8_t idx) const;

    /**
      * Sets the color for the LED at the specified index.
      * Note: You need to call the apply() method to apply all pending color changes.
      */
    bool set_color(uint8_t idx, const led_ring_t::rgb_t& rgb);
    bool set_color(uint8_t idx, uint8_t r, uint8_t g, uint8_t b);

    /**
      * Same as other set_color(idx) variants, but using the HSV colorspace.
      * See led_strip_t::hsv_t for details.
      */
    bool set_color(uint8_t idx, const led_ring_t::hsv_t& hsv);

    /**
      * Sets the color for all LEDs.
      * Note: You need to call the apply() method to apply all pending color changes.
      */
    bool set_color(const led_ring_t::rgb_t& rgb);
    bool set_color(uint8_t r, uint8_t g, uint8_t b);

    /**
      * Same as other set_color() variants, but using the HSV colorspace.
      * See led_strip_t::hsv_t for details.
      */
    bool set_color(const led_ring_t::hsv_t& hsv);

    /**
      * Sends all color changes applied through the set_color() methods calls since the last apply() call.
      */
    void apply();

    /**
      * Clear any colors and turn off all LEDs.
      * Note: You still need to call apply for this jto take effect.
      */
    void clear();
  };
}

#endif // _MBOT_LEDS_H_

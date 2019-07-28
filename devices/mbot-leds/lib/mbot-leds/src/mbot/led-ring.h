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
    using rgb_t = cRGB;

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
    bool set_color(uint8_t idx, led_ring_t::rgb_t rgb);
    bool set_color(uint8_t idx, uint8_t r, uint8_t g, uint8_t b);

    /**
      * Sets the color for all LEDs.
      * Note: You need to call the apply() method to apply all pending color changes.
      */
    bool set_color(led_ring_t::rgb_t rgb);
    bool set_color(uint8_t r, uint8_t g, uint8_t b);

    /**
      * Sends all color changes applied through the set_color() methods calls since the last apply() call.
      */
    void apply();
  };
}

#endif // _MBOT_LEDS_H_

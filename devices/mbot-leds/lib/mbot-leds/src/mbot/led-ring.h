#ifndef _MBOT_LED_RING_H_
#define _MBOT_LED_RING_H_

#include <MeRGBLed.h>

#include <mbot/colors.h>

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
    bool set_color(uint8_t idx, const rgb_t& rgb);
    bool set_color(uint8_t idx, uint8_t r, uint8_t g, uint8_t b);

    /**
      * Same as other set_color(idx) variants, but using the HSV colorspace.
      * See led_strip_t::hsv_t for details.
      */
    bool set_color(uint8_t idx, const hsv_t& hsv);

    /**
      * Sets the color for all LEDs.
      * Note: You need to call the apply() method to apply all pending color changes.
      */
    bool set_color(const rgb_t& rgb);
    bool set_color(uint8_t r, uint8_t g, uint8_t b);

    /**
      * Same as other set_color() variants, but using the HSV colorspace.
      * See led_strip_t::hsv_t for details.
      */
    bool set_color(const hsv_t& hsv);

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
} // namespace mbot

#endif // _MBOT_LED_RING_H_

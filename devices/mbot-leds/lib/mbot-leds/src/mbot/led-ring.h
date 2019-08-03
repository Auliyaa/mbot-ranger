#ifndef _MBOT_LED_RING_H_
#define _MBOT_LED_RING_H_

#include <MeRGBLed.h>
#include <mbot/colors.h>

/**
  * On the mBot ranger, the LED ring is located on the PORT0.
  */
#define MBOT_LED_RING_PORT PORT_0

/**
  * On the mBot ranger, the LED ring is located on pin #44
  */
#define MBOT_LED_RING_PIN 44

/**
  * On the mBot ranger, the LED ring has 12 LEDs.
  */
#define MBOT_LED_RING_LED_COUNT 12

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
    led_ring_t(uint8_t port=MBOT_LED_RING_PORT, uint8_t led_count=MBOT_LED_RING_LED_COUNT);

    /**
      * Destructor
      */
    virtual ~led_ring_t() = default;

    /**
      * Sets the data PIN for the current LED ring.
      * By default, the LED Ring controller is on Auriga D44/PWM.
      */
    bool connect(uint8_t pin=MBOT_LED_RING_PIN);

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
      * Contrary to the MeRGBLed interface, here indexes start at 0 and you may use the set_color(const rgb_t&) variant to set the color for all LEDs at the same time.
      *
      * Note: You need to call the apply() method to apply all pending color changes.
      */
    inline bool set_color(uint8_t idx, const rgb_t& rgb) { return set_color(idx, rgb.r, rgb.g, rgb.b); }
    bool set_color(uint8_t idx, uint8_t r, uint8_t g, uint8_t b);

    /**
      * Same as other set_color(idx) variants, but using the HSV colorspace.
      *
      * See led_strip_t::hsv_t for details.
      */
    inline bool set_color(uint8_t idx, const hsv_t& hsv) { return set_color(idx, hsv.to_rgb()); }

    /**
      * Sets the color for all LEDs.
      *
      * Note: You need to call the apply() method to apply all pending color changes.
      */
    inline bool set_color(const rgb_t& rgb) { return set_color(rgb.r, rgb.g, rgb.b); }
    bool set_color(uint8_t r, uint8_t g, uint8_t b);

    /**
      * Same as other set_color() variants, but using the HSV colorspace.
      *
      * See led_strip_t::hsv_t for details.
      */
    inline bool set_color(const hsv_t& hsv) { return set_color(hsv.to_rgb()); }

    /**
      * Sends all color changes applied through the set_color() methods calls since the last apply() call.
      */
    void apply();

    /**
      * Clear any colors and turn off all LEDs.
      *
      * Note: You still need to call apply for this jto take effect.
      */
    void clear();
  };
} // namespace mbot

#endif // _MBOT_LED_RING_H_

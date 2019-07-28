#ifndef _MBOT_COLORS_H_
#define _MBOT_COLORS_H_

#include <MeRGBLed.h>

namespace mbot
{
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
} // namespace mbot

#endif // _MBOT_COLORS_H_

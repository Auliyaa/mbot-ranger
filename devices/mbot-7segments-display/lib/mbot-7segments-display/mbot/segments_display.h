#ifndef _MBOT_SEGMENTS_DISPLAY_H_
#define _MBOT_SEGMENTS_DISPLAY_H_

#include <Me7SegmentDisplay.h>

namespace mbot
{

#define MBOT_SEGMENTS_BRIGHTNESS_0 BRIGHTNESS_0;
#define MBOT_SEGMENTS_BRIGHTNESS_1 BRIGHTNESS_1;
#define MBOT_SEGMENTS_BRIGHTNESS_2 BRIGHTNESS_2;
#define MBOT_SEGMENTS_BRIGHTNESS_3 BRIGHTNESS_3;
#define MBOT_SEGMENTS_BRIGHTNESS_4 BRIGHTNESS_4;
#define MBOT_SEGMENTS_BRIGHTNESS_5 BRIGHTNESS_5;
#define MBOT_SEGMENTS_BRIGHTNESS_6 BRIGHTNESS_6;
#define MBOT_SEGMENTS_BRIGHTNESS_7 BRIGHTNESS_7;

/**
  * (Variey Gizmos Addon) Wrapper aound the 7-segments display
  */
class segments_display_t
{
public:
  /**
    * Connect to the 7-segments display connected to a given port
    */
  segments_display_t(uint8_t port);
  virtual ~segments_display_t() = default;

  /**
    * Initializes device's buffers.
    * Note: Must be called at setup() instead of the global scope.
    */
  void init();

  /**
    * Sets the display brightness level in the range [0-7]
    */
  void set_brightness(uint8_t level);

  /**
    * Clears the display from any displayed value.
    */
  void clear();

  /// Displays the given integer value.
  void display(uint16_t v);
  /// Displays the given integer value.
  inline void display(int v) { display(static_cast<uint16_t>(v)); }

  /// Displays the given floating point value.
  void display(float v);
  /// Displays the given floating point value.
  inline void display(double v) { display(static_cast<float>(v)); }

private:
  Me7SegmentDisplay _device;
};

} // namespace mbot

#endif // _MBOT_SEGMENTS_DISPLAY_H_

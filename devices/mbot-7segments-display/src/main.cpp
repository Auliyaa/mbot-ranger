#include <MeAuriga.h>

#include <mbot/segments_display.h>

mbot::segments_display_t disp(PORT_7);

void setup()
{
  disp.init();
  disp.set_brightness(BRIGHTNESS_2);
}

void loop()
{
  disp.display(3.14);
  delay(1000);
  disp.clear();
  delay(1000);
}

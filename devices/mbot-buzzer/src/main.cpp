#include <MeAuriga.h>

#include <mbot/buzzer.h>
#include <mbot/buzzer_tones.h>

mbot::buzzer_t buzzer;

void setup()
{
  // Connect the buzzer to the default pin.
  buzzer.open();
}

void loop()
{
  // Play some notes and stop
  static bool first_loop{true};
  if (first_loop)
  {
    first_loop = false;

    // Start with an A4 for 1 sec.
    buzzer.play(TONE_A4, 1000);

    // and play a bunch of tones in a row, each of the same duration.
    uint16_t tones[32] = { TONE_C5, TONE_E5, TONE_G5, TONE_C6, TONE_E6, TONE_G5, TONE_C6, TONE_E6,
                           TONE_C5, TONE_E5, TONE_G5, TONE_C6, TONE_E6, TONE_G5, TONE_C6, TONE_E6,
                           TONE_C5, TONE_D5, TONE_G5, TONE_D6, TONE_F6, TONE_G5, TONE_D6, TONE_F6,
                           TONE_C5, TONE_D5, TONE_G5, TONE_D6, TONE_F6, TONE_G5, TONE_D6, TONE_F6 };

    buzzer.play(tones, 32, 100, 50);
  }
}

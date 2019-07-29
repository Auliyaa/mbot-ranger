#ifndef _MBOT_BUZZER_H_
#define _MBOT_BUZZER_H_

#include <MeBuzzer.h>

/**
  * By default on the mBot ranger, the buzzer is connected to the pin #45
  */
#define MBOT_BUZZER_PIN 45

namespace mbot
{

/**
  * Wraps the buzzer connected to the auriga board.
  */
class buzzer_t
{
public:
  buzzer_t() = default;
  virtual ~buzzer_t() = default;

  /**
    * Opens the buzzer connected to the specified pin.
    * By default, the buzzer of the Auriga board is located on the pin 45.
    */
  bool open(int port=MBOT_BUZZER_PIN);

  /**
    * Plays a given tone during a given number of milliseconds and returns afterwards.
    * If wait is > 0, this method only returns after a given number of milliseconds once the note has been played, allowing you to leave some time in between each tone.
    */
  void play(uint16_t frequency, uint32_t ms=UINT32_MAX, uint32_t wait_ms=0);

  /**
    * Play a series of tones in sequence, each of the given duration in ms and returns once all tones have been played.
    * If wait is > 0, a given wait time in ms is inserted in between each tone.
    */
  void play(const uint16_t* tones, size_t count, uint32_t ms, uint32_t wait_ms=0);

  /**
    * Stops playing the current tone
    */
  void stop();

private:
  MeBuzzer _device;
};

} // namespace mbot

#endif // _MBOT_BUZZER_H_

#include <mbot/buzzer.h>

using namespace mbot;

bool buzzer_t::open(int pin)
{
  _device.setpin(pin);
  return true;
}

void buzzer_t::play(uint16_t frequency, uint32_t ms, uint32_t wait_ms)
{
  _device.tone(frequency, ms);
  if (wait_ms > 0)
  {
    delay(wait_ms);
  }
}

void buzzer_t::play(const uint16_t* tones, size_t count, uint32_t ms, uint32_t wait_ms)
{
  for(size_t ii=0; ii < count; ++ii)
  {
    play(tones[ii], ms, wait_ms);
  }
}

void buzzer_t::stop()
{
  _device.noTone();
}

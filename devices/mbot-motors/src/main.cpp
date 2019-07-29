#include <MeAuriga.h>

#include <mbot/vehicle.h>

mbot::vehicle_t v;

void setup()
{
  v.set_speed(MBOT_SPEED_MID);
}

void loop()
{
  static bool first{true};

  if (first)
  {
    first = false;

    v.apply_direction(mbot::vehicle_t::direction_t::forward);
    v.start();
    delay(1000);

    v.apply_direction(mbot::vehicle_t::direction_t::backwards);
    v.start();
    delay(1000);

    v.apply_direction(mbot::vehicle_t::direction_t::left);
    v.start();
    delay(1000);

    v.apply_direction(mbot::vehicle_t::direction_t::right);
    v.start();
    delay(1000);

    v.stop();
  }

}

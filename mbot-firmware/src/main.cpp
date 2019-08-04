#include <MeAuriga.h>
#include <wall_e.h>

wall_e_t wall_e;

void setup()
{
  wall_e.init();
}

void loop()
{
  static bool first = true;
  if (first)
  {
    first = false;
    wall_e.check();
  }
}

#include <MeAuriga.h>

MeDCMotor dc;

void setup()
{
  dc.reset(PORT_1);
  dc.run(0);
  dc.reset(PORT_2);
  dc.run(0);
  dc.reset(PORT_3);
  dc.run(0);
  dc.reset(PORT_4);
  dc.run(0);
}

void loop()
{
}

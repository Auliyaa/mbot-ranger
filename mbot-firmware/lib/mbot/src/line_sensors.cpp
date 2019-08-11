#include <mbot/line_sensor.h>

using namespace mbot;

line_sensor_t::line_sensor_t(uint8_t port)
  : _device{port}, _last_state{state_t::unknown}
{
}

line_sensor_t::state_t line_sensor_t::read() const
{
  const_cast<line_sensor_t*>(this)->_last_state = parse(_device.readSensors());
  return _last_state;
}

line_sensor_t::state_t line_sensor_t::parse(int d) const
{
  switch(d)
  {
  case S1_IN_S2_IN  : return state_t::s1_in_s2_in;
  case S1_OUT_S2_OUT: return state_t::s1_out_s2_out;
  case S1_IN_S2_OUT : return state_t::s1_in_s2_out;
  case S1_OUT_S2_IN : return state_t::s1_out_s2_in;
  }
  return state_t::unknown;
}

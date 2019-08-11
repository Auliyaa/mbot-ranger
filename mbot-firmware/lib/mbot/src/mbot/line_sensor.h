#ifndef _MBOT_LINE_SENSOR_T_
#define _MBOT_LINE_SENSOR_T_

#include <MeLineFollower.h>

namespace mbot
{

#define MBOT_LINE_SENSOR_PORT PORT_9

class line_sensor_t
{
public:
  enum class state_t
  {
    unknown,
    s1_in_s2_in,
    s1_out_s2_out,
    s1_in_s2_out,
    s1_out_s2_in
  };

  line_sensor_t(uint8_t port=MBOT_LINE_SENSOR_PORT);
  virtual ~line_sensor_t() = default;

  state_t read() const;
  inline state_t last_state() const { return _last_state; }

  inline bool s1_in() const { return _last_state == s1_in_s2_in || _last_state == s1_in_s2_out; }
  inline bool s2_in() const { return _last_state == s1_in_s2_in || _last_state == s1_out_s2_in; }

private:
  MeLineFollower _device;
  state_t _last_state;

  state_t parse(int d) const;
};

} // namespace mbot

#endif // _MBOT_LINE_SENSOR_T_

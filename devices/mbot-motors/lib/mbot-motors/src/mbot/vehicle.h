#ifndef _MBOT_VEHICLE_H_
#define _MBOT_VEHICLE_H_

#include <mbot/motor.h>

namespace mbot
{

/**
  * By default on the mBot ranger, the right motor is plugged into slot #1.
  */
#define MBOT_RIGHT_MOTOR_SLOT SLOT1

/**
  * By default on the mBot ranger, the left motor is plugged into slot #2.
  */
#define MBOT_LEFT_MOTOR_SLOT SLOT2

#define MBOT_SPEED_SLOW 100
#define MBOT_SPEED_MID 200
#define MBOT_SPEED_FAST 300

class vehicle_t
{
public:
  enum class direction_t
  {
    forward,
    backwards,
    left,
    right
  };

  vehicle_t(uint8_t slot_right=MBOT_RIGHT_MOTOR_SLOT, uint8_t slot_left=MBOT_LEFT_MOTOR_SLOT);
  virtual ~vehicle_t() = default;

  inline mbot::motor_t& right() { return _right; }
  inline mbot::motor_t& left()  { return _left; }

  inline void set_speed_right(int16_t s) { _speed_right = s; }
  inline void set_speed_left(int16_t s) { _speed_left = s; }

  inline void set_speed(int16_t r, int16_t l) { _speed_right = r; _speed_left = l; }
  inline void set_speed(int16_t s) { _speed_right = s; _speed_left = s; }

  inline int16_t speed_right() const { return _speed_right; }
  inline int16_t speed_left() const { return _speed_left; }

  void shift_speed_right(int16_t s);
  void shift_speed_left(int16_t s);

  void apply_direction(direction_t d);

  void start();
  void stop();

  inline void apply() { start(); }

private:
  mbot::motor_t _right;
  mbot::motor_t _left;

  int16_t _speed_right;
  int16_t _speed_left;
};

} // namespace mbot

#endif // _MBOT_VEHICLE_H_

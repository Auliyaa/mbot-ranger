#ifndef _MBOT_VEHICLE_H_
#define _MBOT_VEHICLE_H_

#include <mbot/motor.h>

namespace mbot
{

/**
  * By default on the mBot ranger, the right motor is plugged into slot #1.
  */
#define MBOT_RIGHT_MOTOR_SLOT SLOT_1

/**
  * By default on the mBot ranger, the left motor is plugged into slot #2.
  */
#define MBOT_LEFT_MOTOR_SLOT SLOT_2

/**
  * Around the minimum PWM value you could set on any motor.
  * Below this, the wheel does not spin
  */
#define MBOT_SPEED_SLOW 100

/**
  * Mid-range value you can use for normal speed.
  */
#define MBOT_SPEED_MID 200

/**
  * Around the highest value that may be set on a motor.
  */
#define MBOT_SPEED_FAST 300

/**
  * Wrapper around both onboard motors that enables to apply directions.
  * This class is used by setting either a global speed on both motors through the set_speed(int16_t s) or by setting individual speed on each motor.
  * From there, you may use the apply_direction() method to switch the sign of each motor's speed so that the vehicle will follow that direction.
  * Basically, considering a vehicle going at a speed S, the PWM value of each motor should be:
  *
  * - When going forward  : Right motor=-S, Left motor=+S.
  * - When going backwards: Right motor=+S, Left motor=-S.
  * - When going right    : Right motor=+S, Left motor=+S.
  * - When going left     : Right motor=-S, Left motor=-S.
  *
  * Note that setting a direction or speed will not move the vehicle but will only change its internal speed value.
  * After a speed and/or direction, you may still alter the speed of each motor. For instance, you may need to shift back the speed of one motor so that you can apply slight variants in the direction of the vehicle.
  * Once your done tweaking the speed of each motor, you can use the apply() or start() method and both motors will be set to their configured speed.
  * Finally, the stop() method stops both motors but does not change the speed that was applied before. So calling start() again then will set the vehicle into the exact same motion it had before stopping.
  */
class vehicle_t
{
public:
  /**
    * Describes one of the basic directions the vehicle can take.
    */
  enum class direction_t
  {
    forward,
    backwards,
    left,
    right
  };

  /**
    * Initializes the vehicle with both motors.
    */
  vehicle_t(uint8_t slot_right=MBOT_RIGHT_MOTOR_SLOT, uint8_t slot_left=MBOT_LEFT_MOTOR_SLOT);
  virtual ~vehicle_t() = default;

  /// Returns a wrapper around the right sided PWM motor controller.
  inline mbot::motor_t& right() { return _right; }
  /// Returns a wrapper around the left sided PWM motor controller.
  inline mbot::motor_t& left()  { return _left; }

  /// Sets the PWM speed of the right motor, erasing any previous value.
  inline void set_speed_right(int16_t s) { _speed_right = s; }
  /// Sets the PWM speed of the left motor, erasing any previous value.
  inline void set_speed_left(int16_t s) { _speed_left = s; }

  /// Sets the PWM speed of both motors, erasing any previous values.
  inline void set_speed(int16_t r, int16_t l) { _speed_right = r; _speed_left = l; }
  /// Sets the same PWM speed for both motors, erasing any previous values.
  inline void set_speed(int16_t s) { _speed_right = s; _speed_left = s; }

  /**
    * Returns the last set speed for the right motor, taking any applied direction into account.
    * Please note that this may be different from the actual motor's speed, which can be access by calling right_motor().pwm() as the speed is only sent to the PWM device when calling apply() or start()
    */
  inline int16_t speed_right() const { return _speed_right; }
  /**
    * Returns the last set speed for the left motor, taking any applied direction into account.
    * Please note that this may be different from the actual motor's speed, which can be access by calling left_motor().pwm() as the speed is only sent to the PWM device when calling apply() or start()
    */
  inline int16_t speed_left() const { return _speed_left; }

  /**
    * Apply a shift to the currently set speed of the right motor.
    */
  void shift_speed_right(int16_t s);

  /**
    * Apply a shift to the currently set speed of the right motor.
    */
  void shift_speed_left(int16_t s);

  /**
    * Apply a sign shift to each motor speed to match what's described in this class description.
    * Please note that this method behaves independently from the previous sign of the speed value itself.
    * Each speed will be reset to its absolute positive value then reapplied a sign depending on the set direction.
    */
  void apply_direction(direction_t d);

  /**
    * Apply the currently set speed to each PWM motor.
    * This method will set the vehicle in motion according to any previous call to set_speed(), shift_speed_left(), shift_speed_right() and apply_direction()
    */
  void start();

  /**
    * Stops both motors by resetting their PWM value to 0.
    * Calling this does not change the value reported by either speed_left() or speed_right().
    * To fetch the actual PWM value of a motor, call right_motor().pwm() or left_motor().pwm()
    */
  void stop();

  /**
    * See start()
    */
  inline void apply() { start(); }

private:
  mbot::motor_t _right;
  mbot::motor_t _left;

  int16_t _speed_right;
  int16_t _speed_left;
};

} // namespace mbot

#endif // _MBOT_VEHICLE_H_

#ifndef _MBOT_GYRO_H_
#define _MBOT_GYRO_H_

#include <MeGyro.h>

namespace mbot
{

class gyro_t
{
public:
  gyro_t(uint8_t port, uint8_t address);
  virtual ~gyro_t() = default;

  void begin();

  double x() const;
  double y() const;
  double z() const;

private:
  MeGyro _device;
};

} // namespace mbot

#endif // _MBOT_GYRO_H_

#pragma once
#include <libhal-soft/bit_bang_i2c.hpp>
#include <libhal-util/i2c.hpp>
#include <libhal-util/serial.hpp>
#include <libhal-util/steady_clock.hpp>
#include <libhal/serial.hpp>
#include <libhal/units.hpp>
namespace sjsu::trial_project {
class mpu6050
{
private:
  hal::steady_clock& m_clock;
  hal::soft::bit_bang_i2c& m_i2c;

public:
  mpu6050(hal::steady_clock& p_clock,
          hal::soft::bit_bang_i2c& p_i2c);

  enum addresses
  {
    device_address = 0x68,
    power_address = 0x6B,
    accelerometer_config = 0x1C,
    accel_xout_first_half = 0x3B,
    accel_xout_second_half = 0x3C,
    accel_yout_first_half = 0x3D,
    accel_yout_second_half = 0x3E,
    accel_zout_first_half = 0x3F,
    accel_zout_second_half = 0x40
  };

  struct acceleration
  {
    float accelx;
    float accely;
    float accelz;
  };

  acceleration accel;

  void read_accel();
  float calculate_roll_angle();
};

}  // namespace sjsu::trial_project
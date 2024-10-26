#include "../hardware_map.hpp"
#include "../include/mpu6050.hpp"
#include "resource_list.hpp"
#include <libhal-util/serial.hpp>
#include <libhal-util/steady_clock.hpp>
#include <libhal/error.hpp>
#include <libhal/units.hpp>

namespace sjsu::trial_project {
void application(hardware_map_t& hardware_map)
{
  using namespace std::literals;
  auto& clock = *hardware_map.steady_clock;
  auto& terminal = *hardware_map.terminal;
  auto& bit_bang_i2c = *hardware_map.bit_bang_i2c;
  auto& servo = *hardware_map.servo;

  auto mpu = mpu6050(clock, bit_bang_i2c);

  // hal::print<64>(serial, "hello!\n");
  // bit_bang_i2c.configure(hal::i2c::settings{ .clock_rate = 100.0_kHz });
  // hal::print<64>(serial, "hello!\n");
  float angle;
  // auto& led = hal::micromod::v1::led();
  // std::array<hal::byte, 1> buffer;

  servo.position(0);
  while (true) {
    angle = mpu.calculate_roll_angle();
    hal::print<64>(terminal,
                   "X: %f Y: %f Z: %f\n",
                   mpu.accel.accelx,
                   mpu.accel.accely,
                   mpu.accel.accelz);
    hal::print<64>(terminal, "Angle: %f\n", angle);
    hal::delay(clock, 10ms);

    // auto read_data = serial.read(buffer);

    // if(!buffer.empty()){
    // offSet = buffer[0];
    // buffer.fill(0);

    servo.position(angle);
  }
}

}  // namespace sjsu::trial_project
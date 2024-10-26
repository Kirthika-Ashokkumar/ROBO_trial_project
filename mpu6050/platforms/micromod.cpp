// Copyright 2024 Khalil Estell
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// #include <libhal-arm-mcu/lpc40/uart.hpp>
#include "resource_list.hpp"
#include <libhal-actuator/rc_servo.hpp>
#include <libhal-arm-mcu/stm32f1/output_pin.hpp>
#include <libhal-expander/pca9685.hpp>
#include <libhal-micromod/micromod.hpp>
#include <libhal-soft/bit_bang_i2c.hpp>
#include <libhal-soft/rc_servo.hpp>
#include <libhal-util/math.hpp>
#include <libhal-util/serial.hpp>
#include <libhal/input_pin.hpp>
#include <libhal/output_pin.hpp>
#include <libhal/pwm.hpp>
#include <libhal/serial.hpp>
#include <libhal/steady_clock.hpp>


#include <hardware_map.hpp>
#include <libhal-micromod/micromod.hpp>

namespace sjsu::trial_project {
// using hardware_map_t = sjsu::trial_project::resource_list;
// void initialize_platform(sjsu::trial_project::resource_list& resouces)
// {
//   static auto& clk = hal::micromod::v1::uptime_clock();
//   resouces.steady_clock = &clk;
//   static auto& terminal = hal::micromod::v1::console(hal::buffer<1024>);
//   resouces.terminal = &terminal;
//   hal::print(terminal, "clk and terminal setup\n");

//   static auto& sda = hal::micromod::v1::output_g0();
//   static auto& scl = hal::micromod::v1::output_g1();
//   static auto i2c = hal::soft::bit_bang_i2c({ .sda = &sda, .scl = &scl }, clk);

//   resouces.sda = &sda;
//   resouces.scl = &scl;
//   resouces.i2c = &i2c;
//   hal::print(terminal, "i2c setup\n");

//   static auto pca = hal::expander::pca9685(i2c, 0b100'0000);
//   static auto pwm0 = pca.get_pwm_channel<0>();
//   static auto servo =
//     hal::soft::rc_servo(pwm0, { .min_angle = -90, .max_angle = 90 });

//   resouces.pca = &pca;
//   resouces.pwm0 = &pwm0;
//   resouces.servo = &servo;
//   hal::print(terminal, "Resources set\n");
// }

hardware_map_t initialize_platform()
{
  using namespace hal::literals;
  using namespace std::chrono_literals;

  static auto& counter = hal::micromod::v1::uptime_clock();
  static auto& terminal = hal::micromod::v1::console(hal::buffer<1024>);
  hal::print(terminal, "created terminal and counter\n");

  //   static auto& pin0 = hal::micromod::v1::output_g0();
  //   static auto& pin1 = hal::micromod::v1::output_g1();
  //   static auto& pin2 = hal::micromod::v1::output_g2();
  //   static auto& pin3 = hal::micromod::v1::output_g3();

  static auto& scl = hal::micromod::v1::output_g1();
  static auto& sda = hal::micromod::v1::output_g0();
  hal::print(terminal, "created g0 and g1\n");

  static hal::soft::bit_bang_i2c bit_bang_i2c({ .sda = &sda, .scl = &scl },
                                              counter);
  hal::print(terminal, "created i2c\n");

  static hal::expander::pca9685 pca9685(bit_bang_i2c, 0b100'0000);
  static auto pwm0 = pca9685.get_pwm_channel<0>();
  hal::print(terminal, "created pca and got pwm\n");

  hal::actuator::rc_servo::settings rc_servo_settings{
    .frequency = 50,
    // Total 180 deg, change for your use case.
    .min_angle = -90,
    .max_angle = 90,
    // Change to 500us and 2500us if your rc servo
    // supports those pulse widths.
    .min_microseconds = 1000,
    .max_microseconds = 2000,
  };

  static hal::actuator::rc_servo servo(pwm0, rc_servo_settings);
  hal::print(terminal, "created servo\n");

  return hardware_map_t{
    .steady_clock = &counter,
    .terminal = &terminal,
    // .pin0 = &pin0,
    // .pin1 = &pin1,
    // .pin2 = &pin2,
    // .pin3 = &pin3,
    .bit_bang_i2c = &bit_bang_i2c,
    .servo = &servo,
    // .scl = &scl,
    // .sda = &sda,

    // .servo = &servo,
    .reset = +[]() { hal::micromod::v1::reset(); },
  };
}
}  // namespace sjsu::trial_project

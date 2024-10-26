// #pragma once
// #include <libhal-actuator/rc_servo.hpp>
// #include <libhal-arm-mcu/stm32f1/output_pin.hpp>
// #include <libhal-expander/pca9685.hpp>
// #include <libhal-micromod/micromod.hpp>
// #include <libhal-soft/bit_bang_i2c.hpp>
// #include <libhal-soft/rc_servo.hpp>
// #include <libhal-util/units.hpp>
// #include <libhal/i2c.hpp>
// #include <libhal/input_pin.hpp>
// #include <libhal/output_pin.hpp>
// #include <libhal/pwm.hpp>
// #include <libhal/serial.hpp>
// #include <libhal/servo.hpp>
// #include <libhal/steady_clock.hpp>
// #include <optional>

// using namespace std::chrono_literals;
// using namespace hal::literals;

// namespace sjsu::trial_project {
// struct resource_list
// {
//   std::optional<hal::serial*> terminal;
//   std::optional<hal::steady_clock*> steady_clock;
//   std::optional<hal::output_pin*> sda;
//   std::optional<hal::output_pin*> scl;
//   std::optional<hal::i2c*> i2c;
//   std::optional<hal::expander::pca9685*> pca;
//   std::optional<hal::pwm*> pwm0;
//   std::optional<hal::servo*> servo;
// };
// }  // namespace sjsu::trial_project
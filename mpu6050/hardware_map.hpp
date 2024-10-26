#pragma once
#include "resource_list.hpp"
#include <libhal-arm-mcu/stm32f1/output_pin.hpp>
#include <libhal-micromod/micromod.hpp>
#include <libhal-soft/bit_bang_i2c.hpp>
#include <libhal-soft/rc_servo.hpp>
#include <libhal-util/units.hpp>
#include <libhal/i2c.hpp>
#include <libhal/input_pin.hpp>
#include <libhal/output_pin.hpp>
#include <libhal/serial.hpp>
#include <libhal/steady_clock.hpp>
// #include <optional>

using namespace std::chrono_literals;
using namespace hal::literals;

namespace sjsu::trial_project {
struct hardware_map_t
{
  hal::steady_clock* steady_clock;
  hal::serial* terminal;
  hal::soft::bit_bang_i2c* bit_bang_i2c;
  hal::servo* servo;
  //   std::optional<hal::output_pin*> pin0;
  //   std::optional<hal::output_pin*> pin1;
  //   std::optional<hal::output_pin*> pin2;
  //   std::optional<hal::output_pin*> pin3;

  hal::callback<void()> reset;
};

hardware_map_t initialize_platform();
void application(hardware_map_t& p_framework);
}  // namespace sjsu::trial_project

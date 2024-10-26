// #include "hardware_map.hpp"
// #include <libhal-util/serial.hpp>
// #include <libhal-util/steady_clock.hpp>
// #include <libhal/error.hpp>
// #include <libhal/serial.hpp>
// #include <libhal/units.hpp>

// #include <libhal-soft/bit_bang_i2c.hpp>
// #include <libhal-util/i2c.hpp>
// #include <libhal-util/serial.hpp>
// #include <libhal-util/steady_clock.hpp>
// #include <libhal/serial.hpp>
// #include <libhal/units.hpp>

// namespace sjsu::trial_project {
// void application(hardware_map_t& hardware_map)
// {
//   auto& pin0 = *hardware_map.pin0.value();
//   auto& pin1 = *hardware_map.pin1.value();
//   auto& pin2 = *hardware_map.pin2.value();
//   auto& pin3 = *hardware_map.pin3.value();

//   auto& clk = *hardware_map.steady_clock;
//   auto& serial = *hardware_map.terminal;

//   bool state = false;
//   while (true) {

//     hal::print(serial, "Hello, starting loop!\n");
//     pin0.level(state);
//     pin1.level(state);
//     pin2.level(state);
//     pin3.level(state);
//     hal::print<128>(serial,
//                     "pin0: %d pin1: %d pin2: %d pin3: %d\n",
//                     pin0.level(),
//                     pin1.level(),
//                     pin2.level(),
//                     pin3.level());
//     hal::delay(clk, 1s);
//     state = !state;
//   }
// }

// }  // namespace sjsu::trial_project
// #include "../hardware_map.hpp"
// #include "../include/mpu6050.hpp"
// #include "resource_list.hpp"
// #include <libhal-util/serial.hpp>
// #include <libhal-util/steady_clock.hpp>
// #include <libhal/error.hpp>
// #include <libhal/units.hpp>

// namespace sjsu::trial_project {
// void application(hardware_map_t& hardware_map)
// {
//   using namespace std::literals;
//   auto& clock = *hardware_map.steady_clock;
//   auto& terminal = *hardware_map.terminal;
//   //   hal::print(terminal, "not working!\n");
//   auto& servo = *hardware_map.servo;

//   while (true) {
//     // servo.position(0);
//     hal::print(terminal, "Hello!\n");

//     try {
//       servo.position(0);
//     } catch (hal::argument_out_of_domain&) {
//       hal::print(terminal, "Out of range!\n");
//     } catch (...) {
//       hal::print(terminal, "what?");
//     }
//     continue;
//     hal::print(terminal, "Hello!\n");
//     hal::delay(clock, 100ms);
//     try {
//       servo.position(0);
//     } catch (hal::argument_out_of_domain&) {
//       hal::print(terminal, "Out of range!\n");
//     }
//     hal::delay(clock, 100ms);
//     hal::print(terminal, "Hello!\n");
//     // servo.position(-90);
//     hal::delay(clock, 100ms);
//     hal::print(terminal, "Hello!\n");
//   }
// }

// }  // namespace sjsu::trial_project
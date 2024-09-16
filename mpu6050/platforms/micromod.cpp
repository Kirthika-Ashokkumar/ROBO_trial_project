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
#include <libhal-micromod/micromod.hpp>
#include <libhal/i2c.hpp>
#include <libhal/input_pin.hpp>
#include <libhal/serial.hpp>
#include <libhal/steady_clock.hpp>
#include <libhal/pwm.hpp>
#include <libhal-soft/rc_servo.hpp>

// #include <libhal-lpc40/uart.hpp>

#include <libhal-micromod/micromod.hpp>
#include <hardware_map.hpp>


namespace sjsu::trial_project{
    hardware_map_t initialize_platform(){
        using namespace hal::literals;
        using namespace std::chrono_literals;

        auto& counter = hal::micromod::v1::uptime_clock();
        auto& terminal = hal::micromod::v1::console(hal::buffer<1024>);
        // auto& i2c = hal::micromod::v1::i2c();
        // auto& pwm = hal::micromod::v1::pwm0();

        // auto servo_settings = hal::soft::rc_servo::settings{
        //     .min_angle = 0.0_deg,
        //     .max_angle = 180.0_deg,
        //     .min_microseconds = 1000,
        //     .max_microseconds = 2000,
        // };

        // static hal::soft::rc_servo servo(pwm, servo_settings);


        return hardware_map_t{
            .steady_clock = &counter,
            .terminal = &terminal,
            .i2c = nullptr,
            .servo = nullptr,
            // .i2c = &i2c,
            // .servo = &servo,
            .reset = +[]() { hal::micromod::v1::reset(); },
        };
    }
}



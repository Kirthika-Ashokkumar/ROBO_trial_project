#pragma once
#include <libhal-micromod/micromod.hpp>
#include <libhal/i2c.hpp>
#include <libhal/input_pin.hpp>
#include <libhal/serial.hpp>
#include <libhal/steady_clock.hpp>
#include <libhal-soft/rc_servo.hpp>


namespace sjsu::trial_project{
    struct hardware_map_t{
        hal::steady_clock* steady_clock;
        hal::serial* terminal;
        hal::i2c* i2c;
        hal::servo* servo;
        hal::callback<void()> reset;
    };

    hardware_map_t initialize_platform();
    void application(hardware_map_t& p_framework);
}


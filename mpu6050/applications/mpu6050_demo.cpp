#include "../include/mpu6050.hpp"
#include "../hardware_map.hpp"


namespace sjsu::trial_project{
    void application(hardware_map_t& hardware_map){
        using namespace std::literals;
        auto& clock = *hardware_map.steady_clock;
        auto& serial = *hardware_map.terminal;
        // hal::print<64>(serial, "hello Wold");
        // auto& i2c = *hardware_map.i2c;
        // hal::print<64>(serial, "hello Wold");
        // auto& servo = *hardware_map.servo;
        // hal::print<64>(serial, "hello Wold");
        // auto mpu = mpu6050(clock, i2c);
        // float angle;
        auto& led = hal::micromod::v1::led();
        // std::array<hal::byte, 1> buffer;

        // int offSet = 90;

        while(true){
            hal::print<64>(serial, "hello Wold");
            // angle = mpu.calculate_roll_angle();
            led.level(true);
            hal::delay(clock, 50ms);
            led.level(false);

            // hal::print<64>(serial, "X: %f Y: %f Z: %f\n", mpu.accel.accelx, mpu.accel.accely, mpu.accel.accelz);
            // auto read_data = serial.read(buffer);
            // std::cout << read_data.data().size();

            // if(!buffer.empty()){
                // offSet = buffer[0];
                // buffer.fill(0);

                // if(offSet > 0){
                //     servo.position(offSet-angle);
                // }
                // else if (offSet < 0){
                //     offSet= 90 + (offSet*-1);
                // }
                // else{
                //     offSet = 90;
                // }
            // }

            // servo.position(offSet - angle);
            hal::delay(clock, 50ms);
        }
    }

}
#include "../include/mpu6050.hpp"


#define PI 3.1415926
namespace sjsu::trial_project{
    mpu6050::mpu6050(hal::steady_clock& p_clock, hal::i2c& p_i2c) : m_clock(p_clock), m_i2c(p_i2c){
        std::array<hal::byte, 2> power_settings = { addresses::power_address, 0x10};
        hal::write(m_i2c, addresses::device_address, power_settings);
    }

    
    void mpu6050::read_accel(){
        std::array<hal::byte, 1> adresses_write_to = {addresses::accel_xout_first_half};
        std::array<hal::byte, 6> buffer;
    

        hal::write_then_read(m_i2c, addresses::device_address, adresses_write_to, buffer);
        accel.accelx = (buffer[0] << 8 | buffer[1])/16384.0;
        accel.accely = (buffer[2] << 8 | buffer[3])/16384.0;
        accel.accelz = (buffer[4] << 8 | buffer[5])/16384.0;
    }

    float mpu6050::calculate_roll_angle(){
        mpu6050::read_accel();
        float roll = (std::atan(accel.accely / std::sqrt(std::pow(accel.accelx, 2) + std::pow(accel.accelz, 2))) * 180 /PI);
        return roll;
    }
}
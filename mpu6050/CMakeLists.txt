cmake_minimum_required(VERSION 3.20)

project(application LANGUAGES CXX)

libhal_build_demos(
    DEMOS
    mpu6050_demo

    PACKAGES
    libhal-util
    # libhal-soft
    libhal-expander
    libhal-actuator


    LINK_LIBRARIES
    libhal::util
    # libhal::soft
    libhal::expander
    libhal::actuator


    INCLUDES
    .

    SOURCES
    implementations/mpu6050.cpp
) 
cmake_minimum_required(VERSION 3.20)

project(application LANGUAGES CXX)

libhal_build_demos(
    DEMOS
    mpu6050_demo

    PACKAGES
    libhal-util
    libhal-soft


    LINK_LIBRARIES
    libhal::util
    libhal::soft


    INCLUDES
    .

    SOURCES
    implementations/mpu6050.cpp
) 
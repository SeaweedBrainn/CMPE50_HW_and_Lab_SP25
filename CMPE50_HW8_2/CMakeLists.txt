cmake_minimum_required(VERSION 3.29)
project(CMPE50_HW8_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(CMPE50_HW8_2 CMPE50_HW8_2.cpp
        salariedemployee.h
        salariedemployee.cpp
        employee.cpp
        employee.h
        Manager.cpp
        Manager.h
)

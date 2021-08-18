cmake_minimum_required(VERSION 3.13)

include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)

project(Demo C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(Demo main.cpp ../Lcd1_14driver.cpp ../Frame.cpp)

# Link with the pico libraries
target_link_libraries(Demo pico_stdlib hardware_spi)

# Create map/bin/hex/uf2 files
pico_add_extra_outputs(Demo)

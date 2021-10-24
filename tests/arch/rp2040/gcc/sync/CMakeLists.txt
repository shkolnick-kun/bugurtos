cmake_minimum_required(VERSION 3.13)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

###############################################################################
#Test name
set(PRJ_NAME "sync")

###############################################################################
#libraries

#Get sorce tree root dir
set(SRC_ROOT_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../../../../")
get_filename_component(SRC_ROOT_DIR "${SRC_ROOT_DIR}" REALPATH)

# initalize pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "${SRC_ROOT_DIR}/thirdparty/pico-sdk")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

set(BGRT_CONFIG_DIR "${CMAKE_CURRENT_LIST_DIR}/../")
set(BGRT_ARCH "rp2040")
include("${SRC_ROOT_DIR}/bugurtos/bugurtos.cmake")

###############################################################################
#Project
project(${PRJ_NAME} C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1
add_executable(${PRJ_NAME} 
        "${BGRT_DIR}/tests/main/bsync/main.c" 
        "${BGRT_CONFIG_DIR}/test_func.c"
        )

pico_set_program_name(${PRJ_NAME} "BuguRTOS test: ${PRJ_NAME}")
pico_set_program_version(${PRJ_NAME} "0.0.0")

pico_enable_stdio_uart(${PRJ_NAME} 1)
pico_enable_stdio_usb(${PRJ_NAME} 0)

# Add the standard library to the build
target_link_libraries(${PRJ_NAME}
        pico_stdlib
        bugurtos_kernel
        bugurtos_native_api
        )

# create map/bin/hex file etc.
pico_add_extra_outputs(${PRJ_NAME})


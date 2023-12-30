cmake_minimum_required(VERSION 3.12)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
include($ENV{PICO_SDK_PATH}/tools/CMakeLists.txt)

# file(MAKE_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/generated)

set(PICO_BOARD pico_w)
set(WIFI_SSID "Your Network")
set(WIFI_PASSWORD "Your Password")
set(TEST_TCP_SERVER_IP "192.168.0.1")

project(ov2640_pio C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(${PROJECT_NAME}
    main.c
    src/ov2640.c
    src/sccb.c
    src/image_process.c
)

pico_generate_pio_header(${PROJECT_NAME}
    ${CMAKE_CURRENT_LIST_DIR}/src/camera_interface.pio
    OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/inc
)

pico_add_extra_outputs(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
    pico_stdlib
    pico_cyw43_arch_none 
    hardware_pio
    hardware_dma
    hardware_i2c
    hardware_irq
    hardware_gpio
)

# pico_enable_stdio_usb(${PROJECT_NAME} 1)
# pico_enable_stdio_uart(${PROJECT_NAME} 0)
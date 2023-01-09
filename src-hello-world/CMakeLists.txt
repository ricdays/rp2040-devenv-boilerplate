# Add your source files
add_executable(${XIO_DEVICE_NAME}
    main.cpp # <-- Add source files here!
    TransportUsbHid.cpp
)

target_link_libraries(${XIO_DEVICE_NAME} 
    ${XIO_SDK_LIBRARIES}
)

pico_enable_stdio_usb(${XIO_DEVICE_NAME} 1)
pico_enable_stdio_uart(${XIO_DEVICE_NAME} 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(${XIO_DEVICE_NAME})

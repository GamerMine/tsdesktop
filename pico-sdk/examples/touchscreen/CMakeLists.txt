add_executable(touchscreen
        touchscreen.cpp
)

target_link_libraries(touchscreen
  media
  tsdesktop
  utils
)

pico_enable_stdio_usb(touchscreen 1)
pico_enable_stdio_uart(touchscreen 0)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(touchscreen)


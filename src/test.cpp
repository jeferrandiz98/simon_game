#include <iostream>
#include <unistd.h>
#include <vector>

#include "simon/simon_leds.hpp"
#include "simon/simon_buttons.hpp"

/*
arm-linux-gnueabihf-g++-8 src/test.cpp src/analog_bbb/analog_input.cpp src/state_monitor/state_monitor.cpp src/state_monitor/thread_conf.cpp src/util/util.cpp src/analog_bbb/PWMuniv.cpp src/gpio_bbb/GPIO.cpp src/simon/simon_leds.cpp src/simon/simon_buttons.cpp -o build/test -lpthread

scp build/test root@192.168.1.111:/root/targets/
*/

int main() {

    std::cout << "Starting program" << std::endl;

    SimonLeds simon_leds_out;
    SimonButtons simon_buttons_in;

    while(true) {
        SimonLeds::COLOR color;
        color = simon_leds_out.turn_on_random();
        std::vector<bool> status = simon_buttons_in.read_status(true);
        usleep(1000000);
        simon_leds_out.turn_off(color);
        usleep(1000000);
    }

    return 0;
}
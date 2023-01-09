#include "pico/stdlib.h"
#include "Device/DeviceWidget.hpp"
#include "TransportUsbHid.hpp"
#include "RP2040Log.hpp"

using namespace xiohw;

int main()
{
    stdio_init_all();
    for (int i = 0; i < 10; i++) {
        sleep_ms(250);
    }


#ifndef PICO_DEFAULT_LED_PIN
#warning blink example requires a board with a regular LED
#else

    DeviceDescriptor descriptor;
    descriptor.appVersion = "1";
    descriptor.deviceType = DeviceType::Widget;
    descriptor.productId = 1;
    descriptor.serialNumber = "123";
    DeviceWidget dev(descriptor);

    auto transport = std::make_shared<TransportUsbHid>();
    
    LOG_INFO("Dev Start");
	if (!dev.start(transport))
	{
		LOG_CRITICAL("Could not start widget device");
        while (true);
	}


    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true)
    {
        dev.spin();

        LOG_INFO("SPIN");

        gpio_put(LED_PIN, 1);
        sleep_ms(250);
        gpio_put(LED_PIN, 0);
        sleep_ms(250);
    }
#endif
}
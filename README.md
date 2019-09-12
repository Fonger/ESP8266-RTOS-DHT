# ESP8266-RTOS-DHT

ESP8266_RTOS_SDK library for DHT11, DHT22 or SI7021.
This is a port from esp-open-rtos for espressif official SDK ESP8266_RTOS_SDK.

## Compatibility

espressif/ESP8266_RTOS_SDK v3.2+

## Usage

Clone this project in your components folder.

```c

#include <stdio.h>

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include <esp_err.h>
#include <dht/dht.h>

#define DHT_GPIO 5 // D1 pin

void temperature_task(void *arg)
{
    ESP_ERROR_CHECK(dht_init(DHT_GPIO, false));
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    while (1)
    {
        int humidity = 0;
        int temperature = 0;
        if (dht_read_data(DHT_TYPE_DHT22, DHT_GPIO, &humidity, &temperature) == ESP_OK) {
            // e.g. in dht22, 604 = 60.4%, 252 = 25.2 C
            // If you want to print float data, you should run `make menuconfig`
            // to enable full newlib and call dht_read_float_data() here instead
            printf("Humidity: %d Temperature: %d\n", humidity, temperature);
        } else {
            printf("Fail to get dht temperature data\n")
        }
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}

void app_main() {
    xTaskCreate(temperature_task, "temperature task", 2048, NULL, tskIDLE_PRIORITY, NULL);
}

```

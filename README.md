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

#include <dht/dht.h>

#define DHT_GPIO 5 // D1 pin

void temperature_task(void *arg)
{
    ESP_ERROR_CHECK(dht_init(DHT_GPIO, false));
    vTaskDelay(2000 / portTICK_RATE_MS);
    while (1)
    {
        float humidity = 0;
        float temperature = 0;
        if (dht_read_float_data(DHT_TYPE_DHT22, DHT_GPIO, &humidity, &temperature) == ESP_OK) {
            printf("Humidity: g % Temperature: %g C\n", humidity, temperature);
        } else {
            printf("Fail to get dht temperature data\n")
        }
        vTaskDelay(5000 / portTICK_RATE_MS);
    }
    vTaskDelete(NULL);
}

void app_main() {
    xTaskCreate(temperature_task, "temperature task", 2048, NULL, tskIDLE_PRIORITY, NULL);
}

```

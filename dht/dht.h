#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <driver/gpio.h>
#include <esp_err.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Sensor type
 */
typedef enum
{
    DHT_TYPE_DHT11 = 0, //!< DHT11
    DHT_TYPE_DHT22,     //!< DHT22
    DHT_TYPE_SI7021     //!< Itead SI7021
} dht_sensor_type_t;


/**
 * Initialize Config dht pin to be read on specified pin
 * If you are usingPull up resistor
 */

/**
  * @brief  Initialize Config dht pin to be read on specified pin
  *
  * @param  pin GPIO number of dht sensor
  * 
  * @return
  *     - ESP_OK Success
  *     - ESP_ERR_INVALID_ARG Parameter error
  *     - ESP_FAIL Init error
  */
esp_err_t dht_init(gpio_num_t pin, bool pull_up);

/**
  * @brief  Read data from sensor on specified pin. dht_init must be called before reading it.
  *         Humidity and temperature is returned as integers.
  *         For example: humidity=625 is 62.5 %
  *                      temperature=244 is 24.4 degrees Celsius
  * 
  * @param  sensor_type
  * @param  pin GPIO number of dht sensor
  * @param  humidity output humidity
  * @param  temperature output temperature
  * 
  * @return
  *     - ESP_OK Success
  *     - ESP_FAIL Init error
  */
esp_err_t dht_read_data(dht_sensor_type_t sensor_type, gpio_num_t pin, int16_t *humidity, int16_t *temperature);


/**
  * @brief  Float version of dht_read_data. Read data from sensor on specified pin. dht_init must be called before reading it.
  *         Humidity and temperature is returned as float.
  *         For example: humidity=62.5 is 62.5 %
  *                      temperature=24.4 is 24.4 degrees Celsius
  * 
  * @param  sensor_type
  * @param  pin GPIO number of dht sensor
  * @param  humidity output humidity
  * @param  temperature output temperature
  * 
  * @return
  *     - ESP_OK Success
  *     - ESP_FAIL Init error
  */
esp_err_t dht_read_float_data(dht_sensor_type_t sensor_type, gpio_num_t pin, float *humidity, float *temperature);

#ifdef __cplusplus
}
#endif

#include <stdio.h>

#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "station";

void app_main(void)
{
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);

    uint32_t flash_size = 0;
    esp_err_t flash_result = esp_flash_get_size(NULL, &flash_size);

    ESP_LOGI(TAG, "station booting on ESP32-P4");
    ESP_LOGI(TAG, "CPU cores: %d", chip_info.cores);

    if (flash_result == ESP_OK) {
        ESP_LOGI(TAG, "Flash size: %lu MB", (unsigned long)(flash_size / (1024 * 1024)));
    } else {
        ESP_LOGW(TAG, "Unable to read flash size: %s", esp_err_to_name(flash_result));
    }

    while (true) {
        ESP_LOGI(TAG, "station heartbeat");
        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}

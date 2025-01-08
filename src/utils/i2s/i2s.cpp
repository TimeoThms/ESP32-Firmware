#include "i2s.h"

// #include <BluetoothA2DPSink.h>

#include <cmath>

#include "../../configs/config.h"

#define BUFFER_SIZE 1024

// BluetoothA2DPSink a2dp_sink;

int16_t mic_buffer[BUFFER_SIZE];
int16_t audio_buffer[BUFFER_SIZE];

void initI2S() {
    i2s_config_t i2s_config = {
        .mode = i2s_mode_t(I2S_MODE_MASTER | I2S_MODE_TX | I2S_MODE_RX),
        .sample_rate = 44100,
        .bits_per_sample = i2s_bits_per_sample_t(16),
        .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
        .communication_format = i2s_comm_format_t(I2S_COMM_FORMAT_STAND_I2S),
        .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
        .dma_buf_count = 4,
        .dma_buf_len = 512};

    i2s_pin_config_t pin_config = {
        .bck_io_num = I2S_SCK_PIN,
        .ws_io_num = I2S_WS_PIN,
        .data_out_num = I2S_SPK_DIN_PIN,
        .data_in_num = I2S_MIC_SD_PIN};

    i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);
    i2s_set_pin(I2S_NUM_0, &pin_config);
}

float rms_history[5];
int rms_history_index = 0;

float calculateAverageRMS() {
    float sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += rms_history[i];
    }
    return sum / 5;
}

float calculateRMS(int16_t* buffer, size_t len) {
    float sum = 0;
    for (size_t i = 0; i < len; i++) {
        sum += buffer[i] * buffer[i];
    }
    return sqrt(sum / len);
}

bool checkSound() {
    size_t bytesRead;
    i2s_read(I2S_NUM_0, (void*)mic_buffer, BUFFER_SIZE * sizeof(int16_t), &bytesRead, portMAX_DELAY);

    // Calcul du niveau sonore RMS pour détecter les bruits soudains
    float rms = calculateRMS(mic_buffer, bytesRead / sizeof(int16_t));

    rms_history[rms_history_index] = rms;
    rms_history_index = (rms_history_index + 1) % 5;
    float avg_rms = calculateAverageRMS();

    if (rms > avg_rms + 100) {  // THRESHOLD défini par l'utilisateur pour les bruits soudains
        return true;
    }

    
    return false;
}

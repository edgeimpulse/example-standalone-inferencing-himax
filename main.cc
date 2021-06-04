/* Edge Impulse ingestion SDK
 * Copyright (c) 2020 EdgeImpulse Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/* Include ----------------------------------------------------------------- */
#include "ei_run_classifier.h"
#include "hx_drv_tflm.h"

static const float features[] = {
    1.5100, 3.7600, 10.2400, 1.8200, 5.4800, 9.9500, 2.0400, 6.9800, 10.2900, 1.5100, 6.5000, 9.9300, 0.2500, 4.6300, 10.0000, -1.2100, 2.4600, 10.0500, -1.2100, 2.4600, 10.0500, -2.1000, 1.0100, 9.7800, -2.2600, -0.8700, 10.1400, -1.6200, -0.8400, 10.1600, -0.9100, -0.2000, 10.2300, -0.3500, 0.3600, 10.0600, 1.8100, 0.8200, 9.4900, 1.8100, 0.8200, 9.4900, 2.5600, -1.9800, 9.1300, 2.0700, -4.9000, 10.1000, 0.3800, -7.3400, 10.5400, 0.6000, -5.7300, 9.9900, 0.8400, -3.4300, 10.1800, 1.0900, -3.7900, 9.7000, 1.0900, -3.7900, 9.7000, 1.3500, -4.2600, 10.0400, 1.6000, -3.5800, 9.9400, 1.2400, -1.3200, 9.6000, 1.3500, -1.2600, 9.7600, 1.1300, -1.9200, 10.1400, 0.3200, -0.7300, 10.2100, 0.3200, -0.7300, 10.2100, 2.9500, -0.8200, 9.9000, 3.4400, 2.1700, 10.0200, 2.5300, 3.6700, 10.1800, 1.6400, 3.9100, 9.7000, 0.5100, 4.5900, 9.9800, 0.1600, 5.0400, 10.0900, 0.1600, 5.0400, 10.0900, 1.0600, 4.7000, 10.3300, 1.5900, 4.4000, 9.9400, 0.3900, 3.0200, 10.2600, 0.1000, 1.7800, 9.9900, -0.3700, 1.2800, 10.1500, -0.3700, 1.2800, 9.9100, -0.2000, 1.5200, 9.9100, -0.3300, 2.5200, 9.9600, 0.3600, 3.2800, 10.0300, 0.2300, 3.3400, 10.3300, -1.1100, 1.7400, 9.9100, -2.6200, -1.1100, 10.2900, -2.6200, -1.1100, 10.2900, -1.8700, -3.1100, 10.0000, -2.0900, -4.0700, 9.9400, -2.1200, -4.0100, 10.2100, -1.4100, -4.2000, 10.0900, -1.6900, -3.5100, 10.1500, 0.3500, -3.0000, 10.1300, 0.3500, -3.0000, 10.1300, -0.0500, -2.7300, 9.9400, 0.0200, -3.1800, 10.0700, 0.9200, -1.9000, 10.1700, 2.2100, -1.8700, 9.9700, 2.9500, -2.5600, 9.9800, 1.9400, -3.2000, 10.2200, 1.9400, -3.2000, 10.2200, 1.3400, -2.5700, 9.6700, 1.4300, -0.1200, 10.1100, 1.4300, 1.7100, 9.8200, 1.0400, 3.2000, 9.7500, 1.4900, 4.2400, 10.0100, 0.4400, 4.5200, 9.9900, 0.4400, 4.5200, 9.9900, 0.2000, 4.6100, 10.0700, -1.7500, 4.5500, 10.1900, -2.7800, 3.8400, 9.9700, -2.4100, 6.8100, 10.2100, -2.6200, 6.6100, 10.0100, -2.5500, 3.6900, 9.9800, -2.5500, 3.6900, 9.9800, -1.5300, -0.1100, 10.0300, -0.7700, -1.3900, 10.1900, -0.7500, -0.2500, 9.9300, -0.5000, 1.5100, 10.2800, -0.3600, 1.0900, 9.8600, 0.0000, -0.0900, 9.8100, 0.0000, -0.0900, 9.8100, 0.4700, -1.2800, 9.8700, -0.3000, -1.4700, 9.8900, 0.0100, -1.0100, 10.0300, 0.4000, -0.3100, 9.3500, 1.4400, -1.5900, 10.1700, 3.4200, -3.8200, 9.3300, 3.4200, -3.8200, 9.3300, 3.1300, -6.0200, 9.7800, 2.7100, -5.0600, 9.9900, 2.6100, -4.3400, 9.5700, 2.8000, -2.4700, 10.1500, 2.1400, -1.5300, 10.0500, 2.1000, -0.7400, 10.1800, 2.1000, -0.7400, 10.1800, 2.2400, -0.9800, 10.0100, 1.4600, -0.8800, 9.5800, 1.1500, 0.6100, 9.9500, 0.2300, 2.2000, 9.9000, -1.6100, 3.3300, 10.1100, -1.6100, 3.3300, 10.1100, -2.0800, 4.9400, 9.4500, -2.5800, 6.0800, 9.6200, -3.5000, 4.8000, 9.5500, -3.4500, 1.6200, 9.9600, -1.4000, 1.1200, 9.3100, 0.0100, 0.4700, 10.1500, 0.0100, 0.4700, 10.1500, 0.8300, 0.7500, 9.8500, 0.4000, 2.8100, 10.0700, 1.2100, 1.7800, 9.6500, 1.5000, 0.7100, 10.0000, 0.8300, 1.3800, 9.9000, 0.4700, 1.3400, 9.7300, 0.4700, 1.3400, 9.7300, 1.0200, 1.4500, 9.9100, 0.4200, 0.5000, 10.0600, -0.0500, -0.7300, 9.6900, 0.1500, -1.0500, 9.6400, 1.0700, -1.8400, 10.1000, 1.1500, -2.8100, 9.7100, 1.1500, -2.8100, 9.7100, 0.3500, -3.4200, 9.9100
};

int raw_feature_get_data(size_t offset, size_t length, float *out_ptr) {
    memcpy(out_ptr, features + offset, length * sizeof(float));
    return 0;
}

int main(void)
{
    hx_drv_uart_initial(UART_BR_115200);
    hx_drv_tick_start();

    while (1) {
        ei_printf("Edge Impulse standalone inferencing Himax WE-I Plus EVB\n");

        if (sizeof(features) / sizeof(float) != EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE) {
            ei_printf("The size of your 'features' array is not correct. Expected %d items, but had %u\n",
                EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE, sizeof(features) / sizeof(float));
            return 1;
        }

        ei_impulse_result_t result = { 0 };

        // the features are stored into flash, and we don't want to load everything into RAM at the same time
        // so we use a signal to wrap around the data
        ei::signal_t features_signal;
        features_signal.total_length = sizeof(features) / sizeof(features[0]);
        features_signal.get_data = &raw_feature_get_data;

        // invoke the impulse
        EI_IMPULSE_ERROR res = run_classifier(&features_signal, &result, true);
        ei_printf("run_classifier returned: %d\n", res);

        if (res != 0) return 1;

        ei_printf("Predictions (DSP: %d ms., Classification: %d ms., Anomaly: %d ms.): \n",
            result.timing.dsp, result.timing.classification, result.timing.anomaly);

        // print the predictions
        ei_printf("[");
        for (size_t ix = 0; ix < EI_CLASSIFIER_LABEL_COUNT; ix++) {
            ei_printf("%f", result.classification[ix].value);
    #if EI_CLASSIFIER_HAS_ANOMALY == 1
            ei_printf(", ");
    #else
            if (ix != EI_CLASSIFIER_LABEL_COUNT - 1) {
                ei_printf(", ");
            }
    #endif
        }
    #if EI_CLASSIFIER_HAS_ANOMALY == 1
        ei_printf_float(result.anomaly);
    #endif
        ei_printf("]\n");

        // And wait 5 seconds
        ei_sleep(5000);
    }

    return 0;
}

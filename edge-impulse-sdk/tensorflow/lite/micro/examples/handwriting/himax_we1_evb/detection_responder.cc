/* Copyright 2019 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "../../handwriting/detection_responder.h"

#include <iostream>
#include <string>


#include "../../handwriting/model_settings.h"
#include "hx_drv_tflm.h"

namespace {
uint8_t score_output[kCategoryCount];
}
void RespondToDetection(tflite::ErrorReporter* error_reporter, int8_t* score) {
  std::string output = "number";
  int maxScore = -255;
  int maxIndex = -1;
  for (int i = 0; i < kCategoryCount; i++) {
    output += "[" + std::to_string(i) + "]:" + std::to_string(score[i]) + ',';

    if (maxScore < score[i] && score[i] > 0) {
      maxScore = score[i];
      maxIndex = i;
    }

    score_output[i] = score[i] + 128;
  }

  output += "result:";
  if (maxIndex >= 0)
    output += std::to_string(maxIndex);
  else
    output += "unknown";

  //send result data out through SPI
  hx_drv_spim_send((uint32_t)score_output, sizeof(int8_t) * kCategoryCount,
                   SPI_TYPE_META_DATA);

  TF_LITE_REPORT_ERROR(error_reporter, output.c_str());
}

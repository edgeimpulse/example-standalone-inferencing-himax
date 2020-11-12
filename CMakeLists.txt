cmake_minimum_required(VERSION 3.12)

# set the project name
project(edge-impulse-standalone-himax)

# Toolchain
set(CMAKE_C_COMPILER ccac)
set(CMAKE_CXX_COMPILER ccac)
set(CMAKE_CROSSCOMPILING 1)

# add the sources
file(GLOB EI_SDK "edge-impulse-sdk/porting/himax/*.cpp"
				 "tflite-model/*.cpp")

file(GLOB TF "edge-impulse-sdk/tensorflow/lite/micro/*.cc"
			"edge-impulse-sdk/tensorflow/lite/micro/memory_planner/*.cc"
            "tflite-model/*.cpp"
			"edge-impulse-sdk/tensorflow/lite/micro/kernels/*.cc"
			"edge-impulse-sdk/tensorflow/lite/core/api/*.cc"
			"edge-impulse-sdk/tensorflow/lite/c/*.c"
			"edge-impulse-sdk/tensorflow/lite/kernels/internal/*.cc"
            "edge-impulse-sdk/tensorflow/lite/kernels/*.cc"
            "edge-impulse-sdk/tensorflow/lite/micro/kernels/arc_mli/*.cc")

file(GLOB DSP "edge-impulse-sdk/dsp/kissfft/*.cpp"
			"edge-impulse-sdk/dsp/dct/*.cpp")

SET(TF_SOURCE
edge-impulse-sdk/tensorflow/lite/micro/micro_interpreter.cc
edge-impulse-sdk/tensorflow/lite/micro/all_ops_resolver.cc
edge-impulse-sdk/tensorflow/lite/micro/simple_memory_allocator.cc
edge-impulse-sdk/tensorflow/lite/micro/memory_helpers.cc
edge-impulse-sdk/tensorflow/lite/micro/recording_micro_allocator.cc
edge-impulse-sdk/tensorflow/lite/micro/micro_error_reporter.cc
edge-impulse-sdk/tensorflow/lite/micro/micro_time.cc
edge-impulse-sdk/tensorflow/lite/micro/recording_simple_memory_allocator.cc
edge-impulse-sdk/tensorflow/lite/micro/micro_string.cc
edge-impulse-sdk/tensorflow/lite/micro/micro_profiler.cc
edge-impulse-sdk/tensorflow/lite/micro/micro_utils.cc
edge-impulse-sdk/tensorflow/lite/micro/micro_optional_debug_tools.cc
edge-impulse-sdk/tensorflow/lite/micro/test_helpers.cc
edge-impulse-sdk/tensorflow/lite/micro/micro_allocator.cc
edge-impulse-sdk/tensorflow/lite/micro/benchmarks/keyword_scrambled_model_data.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/logistic.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/arc_mli/conv.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/prelu.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/dequantize.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/l2norm.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/resize_nearest_neighbor.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/tanh.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/activations.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/arg_min_max.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/pad.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/reduce.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/unpack.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/sub.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/add.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/split.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/circular_buffer.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/kernel_runner.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/floor.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/round.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/ceil.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/svdf.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/hard_swish.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/arc_mli/pooling.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/concatenation.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/neg.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/quantize.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/ethosu.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/mul.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/maximum_minimum.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/reshape.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/strided_slice.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/softmax.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/pack.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/kernel_util.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/logical.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/elementwise.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/comparisons.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/arc_mli/fully_connected.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/arc_mli/depthwise_conv.cc
edge-impulse-sdk/tensorflow/lite/micro/memory_planner/linear_memory_planner.cc
edge-impulse-sdk/tensorflow/lite/micro/memory_planner/greedy_memory_planner.cc
edge-impulse-sdk/tensorflow/lite/micro/testing/test_conv_model.cc
edge-impulse-sdk/tensorflow/lite/c/common.c
edge-impulse-sdk/tensorflow/lite/core/api/error_reporter.cc
edge-impulse-sdk/tensorflow/lite/core/api/flatbuffer_conversions.cc
edge-impulse-sdk/tensorflow/lite/core/api/op_resolver.cc
edge-impulse-sdk/tensorflow/lite/core/api/tensor_utils.cc
edge-impulse-sdk/tensorflow/lite/kernels/internal/quantization_util.cc
edge-impulse-sdk/tensorflow/lite/kernels/kernel_util.cc
edge-impulse-sdk/tensorflow/lite/micro/testing/test_utils.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/arc_mli/conv.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/arc_mli/mli_slicers.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/arc_mli/scratch_buffers.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/arc_mli/scratch_buf_mgr.cc
edge-impulse-sdk/tensorflow/lite/micro/kernels/split_v.cc)


set(SOURCE_FILES ${EI_SDK} ${DSP} ${TF})

# include directories
include_directories(./)
include_directories(edge-impulse-sdk/)
include_directories(edge-impulse-sdk/classifier)
include_directories(edge-impulse-sdk/porting)
include_directories(edge-impulse-sdk/dsp)
include_directories(edge-impulse-sdk/dsp/kissfft)
include_directories(edge-impulse-sdk/dsp/dct)
include_directories(edge-impulse-sdk/third_party/flatbuffers/include/)
include_directories(edge-impulse-sdk/third_party/gemmlowp)
include_directories(edge-impulse-sdk/third_party/ruy)
include_directories(arc_mli_package/include)

# add the executable
add_executable(${PROJECT_NAME}.elf main.cc ${SOURCE_FILES})


set(CMAKE_C_FLAGS "\
-Wstrict-aliasing \
-DTF_LITE_STATIC_MEMORY \
-Werror \
-Wsign-compare \
-Wdouble-promotion \
-Wshadow \
-Wunused-variable \
-Wmissing-field-initializers \
-Wunused-function \
-DNDEBUG \
-O3 \
-fno-rtti \
-DSCRATCH_MEM_Z_SIZE=0 \
-DNDEBUG \
-g \
-DCPU_ARC \
-Hnosdata \
-DTF_LITE_STATIC_MEMORY \
-tcf=../arcem9d_wei_r16.tcf \
-Hnocopyr \
-Hpurge \
-Hcl \
-fslp-vectorize-aggressive \
-ffunction-sections \
-fdata-sections \
-tcf_core_config \
-DEIDSP_QUANTIZE_FILTERBANK=0 \
-DEI_CLASSIFIER_ALLOCATION=EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX \
-DEI_DSP_IMAGE_BUFFER_STATIC_SIZE=1024")

set(CMAKE_CXX_FLAGS "\
-DTF_LITE_STATIC_MEMORY \
-DNDEBUG \
-O3 \
-DNDEBUG \
-g \
-DCPU_ARC \
-Hnosdata \
-DTF_LITE_STATIC_MEMORY \
-DSCRATCH_MEM_Z_SIZE=0 \
-tcf=../arcem9d_wei_r16.tcf \
-Hnocopyr \
-Hpurge \
-Hcl \
-fslp-vectorize-aggressive \
-ffunction-sections \
-fdata-sections \
-tcf_core_config \
-DEIDSP_QUANTIZE_FILTERBANK=0 \
-DEI_CLASSIFIER_ALLOCATION=EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX \
-DEI_DSP_IMAGE_BUFFER_STATIC_SIZE=1024")


set(CMAKE_EXE_LINKER_FLAGS_INIT "${LINKER_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${LINKER_FLAGS} \
-Hheap=16384 \
-tcf=../arcem9d_wei_r16.tcf \
-Hnocopyr \
-m \
-Hldopt=-Coutput=${PROJECT_NAME}.map \
../memory.lcf \
-Hldopt=-Bgrouplib \
../libembarc.a \
../libbss.a \
../arc_mli_package/bin/himax_arcem9d_r16/release/libmli.a ")


add_custom_target(image DEPENDS ${PROJECT_NAME}.elf)
add_custom_command(TARGET image USES_TERMINAL
	COMMAND cp ${PROJECT_NAME}.elf ../image_gen_linux_v3
	COMMAND cp ${PROJECT_NAME}.map ../image_gen_linux_v3
	COMMAND ${CMAKE_COMMAND} ARGS -E chdir ../image_gen_linux_v3 image_gen -e ${PROJECT_NAME}.elf -m ${PROJECT_NAME}.map -o out.img
	COMMAND ${CMAKE_COMMAND} ARGS -E chdir ../image_gen_linux_v3 rm ${PROJECT_NAME}.elf
	COMMAND ${CMAKE_COMMAND} ARGS -E chdir ../image_gen_linux_v3 rm ${PROJECT_NAME}.map)

#add_custom_command(TARGET image USES_TERMINAL COMMAND cp ${PROJECT_NAME}.map ../image_gen_linux_v3)

#add_custom_command(TARGET image USES_TERMINAL COMMAND ${CMAKE_COMMAND} ARGS -E chdir ../image_gen_linux_v3 image_gen -e ${PROJECT_NAME}.elf -m ${PROJECT_NAME}.map -o out.img)

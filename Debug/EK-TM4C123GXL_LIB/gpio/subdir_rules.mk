################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
EK-TM4C123GXL_LIB/gpio/%.obj: ../EK-TM4C123GXL_LIB/gpio/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs1220/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me -O2 --include_path="C:/Users/RATTAN/Desktop/ccs workspace/blinky" --include_path="C:/Users/RATTAN/Desktop/ccs workspace/blinky" --include_path="C:/Users/RATTAN/Desktop/ccs workspace/blinky/EK-TM4C123GXL_LIB/gpio" --include_path="C:/Users/RATTAN/Desktop/ccs workspace/blinky/EK-TM4C123GXL_LIB/clock" --include_path="C:/ti/TivaWare_C_Series-2.2.0.295" --include_path="C:/ti/ccs1220/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=TARGET_IS_TM4C123_RB1 -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --ual --preproc_with_compile --preproc_dependency="EK-TM4C123GXL_LIB/gpio/$(basename $(<F)).d_raw" --obj_directory="EK-TM4C123GXL_LIB/gpio" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '



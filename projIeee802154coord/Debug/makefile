### Setting Erika's variables:
# ERIKA_FILES= ../../..
# APPBASE = .
# 
# EEOPT =


RTDRUID_CONFIGURATOR_NUMBER:=1277



############################################################################
#
# User options
#
############################################################################
EEOPT += DEBUG
EEOPT += __USE_SPI__
EEOPT += __ADD_LIBS__
EEOPT += USE_CC2420
EEOPT += USE_CONSOLE
EEOPT += USE_CONSOLE_SERIAL
EEOPT += __USE_UART__
EEOPT += EE_TYPETICK=EE_INT32
EEOPT += UWL_USE_SIMPLE_802154
EEOPT += UWL_GTS_MANIPULATION
EEOPT += UWL_NO_DYN_ASS


############################################################################
#
# Automatic options
#
############################################################################
EEOPT += __RTD_CYGWIN__
EEOPT += __PIC30__
EEOPT += __33FJ256MC710__
EEOPT += __PIC33FJ256MC710__
EEOPT += __EE_FLEX__
EEOPT += __USE_DEMOBOARD__
EEOPT += __USE_ACCELEROMETER__
EEOPT += __USE_ADC__
EEOPT += __USE_BUTTONS__
EEOPT += __USE_BUZZER__
EEOPT += __USE_DAC__
EEOPT += __USE_ENCODER__
EEOPT += __USE_IR__
EEOPT += __USE_LCD__
EEOPT += __USE_LEDS__
EEOPT += __USE_PWM__
EEOPT += __USE_PWM_MOTOR__
EEOPT += __USE_ANALOG_SENSORS__
EEOPT += __USE_TRIMMER__
EEOPT += __USE_USB__
EEOPT += __USE_ZIGBEE__
EEOPT += __MICROCHIP_DSPIC30__
EEOPT += __PIC30_ICD2__
EEOPT += __PIC30_SPLIM__
EEOPT += __FP__
EEOPT += __MONO__
EEOPT += __ALARMS__
EEOPT += __DISABLE_EEOPT_DEFINES__


############################################################################
#
# Erika base directory
#
############################################################################
ifdef ERIKA_FILES
ifdef EEBASE
    $(warning EEBASE is set, but it has been overridden by ERIKA_FILES)
endif
EEBASE := $(shell cygpath `cygpath -ms '${ERIKA_FILES}'`)

else # ERIKA_FILES

ifndef EEBASE
        EEBASE := $(shell cygpath `cygpath -ms 'C:\EE_RT-Druid-1.6.1-indigo-SR2-win32\eclipse\plugins\com.eu.evidence.ee_1.6.1.20120319_2002\ee_files'`)
else
        $(warning The usage of EEBASE is deprecated. Please use ERIKA_FILES)
endif
endif # ERIKA_FILES
# ERIKA_FILES has fulfilled its role. Make sure it's not used inside Erika makefiles
ERIKA_FILES :=
$(info Using erika files in $(EEBASE))


############################################################################
#
# PIC 30
#
############################################################################
APPBASE := 
OUTBASE := Debug

PIC30_ASMDIR := $(shell $(EEBASE)/pkg/cfg/arch/cc_pic30_detect.sh ASM "C:\Program Files (x86)\Microchip\MPLAB ASM30 Suite")
PIC30_GCCDIR := $(shell $(EEBASE)/pkg/cfg/arch/cc_pic30_detect.sh GCC "C:\Program Files (x86)\Microchip\MPLAB C30")


############################################################################
#
# Init MCU for PIC30 (PIC33FJ256MC710)
#
############################################################################
PIC30_MODEL           := 33FJ256MC710
PIC30_LINKERSCRIPT    := p33FJ256MC710.gld
PIC30_DEV_LIB         := libp33FJ256MC710-elf.a
PIC30_INCLUDE_C       := p33FJ256MC710.h
PIC30_INCLUDE_S       := p33FJ256MC710.inc


############################################################################
#
# Flags
#
############################################################################
CFLAGS  += 
ASFLAGS += 
LDFLAGS += --heap=512
LDDEPS  += 
LIBS    += 

LIB_OPT  += __LIB_MEMORY__
LIB_OPT  += __LIB_CC2420__
LIB_OPT  += __LIB_CONSOLE__
LIB_OPT  += __LIB_UWIRELESS__


############################################################################
#
# Sources
#
############################################################################
APP_SRCS += $(OUTBASE)/eecfg.c code.c check.S


############################################################################
#
# end
#
############################################################################
include $(EEBASE)/pkg/cfg/rules.mk

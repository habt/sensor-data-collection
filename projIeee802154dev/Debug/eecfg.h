#ifndef RTDH_EECFG_H
#define RTDH_EECFG_H


#define RTDRUID_CONFIGURATOR_NUMBER 1277



/***************************************************************************
 *
 * Common defines ( CPU 0 )
 *
 **************************************************************************/

    /* TASK definition */
    #define EE_MAX_TASK 11
    #define CHAT_SEND 0
    #define CHAT_RECEIVE 1
    #define LCD_WRITE 2
    #define UWL_EE_TASK_PHY_READ_DISPATCHER 3
    #define UWL_EE_TASK_MAC_PROCESS_RX_BEACON 4
    #define UWL_EE_TASK_MAC_PROCESS_RX_DATA 5
    #define UWL_EE_TASK_MAC_PROCESS_RX_COMMAND 6
    #define UWL_EE_TASK_MAC_TIMESLOT 7
    #define UWL_EE_TASK_MAC_BEFORE_TIMESLOT 8
    #define UWL_EE_TASK_MAC_BACKOFF_PERIOD 9
    #define UWL_EE_TASK_MAC_GTS_SEND 10

    /* MUTEX definition */
    #define EE_MAX_RESOURCE 8U
    #define LCD_MUTEX 0U
    #define RES_SCHEDULER 1U
    #define UWL_EE_RESOURCE_MAC_GTS_SEND_MUTEX 2U
    #define UWL_EE_RESOURCE_MAC_MUTEX 3U
    #define UWL_EE_RESOURCE_MAC_RX_BEACON_MUTEX 4U
    #define UWL_EE_RESOURCE_MAC_RX_COMMAND_MUTEX 5U
    #define UWL_EE_RESOURCE_MAC_RX_DATA_MUTEX 6U
    #define UWL_EE_RESOURCE_MAC_SEND_MUTEX 7U

    /* ALARM definition */
    #define EE_MAX_ALARM 6
    #define CHAT_SEND_ALARM 0
    #define LCD_WRITE_ALARM 1
    #define UWL_EE_ALARM_MAC_TIMESLOT 2
    #define UWL_EE_ALARM_MAC_BEFORE_TIMESLOT 3
    #define UWL_EE_ALARM_MAC_BACKOFF_PERIOD 4
    #define UWL_EE_ALARM_MAC_GTS_SEND 5

    /* COUNTER definition */
    #define EE_MAX_COUNTER 2
    #define TASK_COUNTER 0
    #define UWL_EE_TASK_COUNTER 1

    /* APPMODE definition */
    #define EE_MAX_APPMODE 0U

    /* CPUs */
    #define EE_MAX_CPU 1
    #define EE_CURRENTCPU 0

#ifndef __DISABLE_EEOPT_DEFINES__


/***************************************************************************
 *
 * User options
 *
 **************************************************************************/
#define __USE_SPI__
#define __ADD_LIBS__
#define USE_CC2420
#define EE_TYPETICK=EE_INT32
#define UWL_USE_SIMPLE_802154
#define UWL_GTS_MANIPULATION
#define UWL_NO_DYN_ASS


/***************************************************************************
 *
 * Automatic options
 *
 **************************************************************************/
#define __RTD_CYGWIN__
#define __PIC30__
#define __33FJ256MC710__
#define __PIC33FJ256MC710__
#define __EE_FLEX__
#define __USE_DEMOBOARD__
#define __USE_ACCELEROMETER__
#define __USE_ADC__
#define __USE_BUTTONS__
#define __USE_BUZZER__
#define __USE_DAC__
#define __USE_ENCODER__
#define __USE_IR__
#define __USE_LCD__
#define __USE_LEDS__
#define __USE_PWM__
#define __USE_PWM_MOTOR__
#define __USE_ANALOG_SENSORS__
#define __USE_TRIMMER__
#define __USE_USB__
#define __USE_ZIGBEE__
#define __MICROCHIP_DSPIC30__
#define __PIC30_ICD2__
#define __PIC30_SPLIM__
#define __FP__
#define __MONO__
#define __ALARMS__

#endif



#endif


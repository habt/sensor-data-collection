#include "ee.h"





/***************************************************************************
 *
 * Kernel ( CPU 0 )
 *
 **************************************************************************/
    /* Definition of task's body */
    DeclareTask(CHAT_SEND);
    DeclareTask(CHAT_RECEIVE);
    DeclareTask(LCD_WRITE);
    DeclareTask(UWL_EE_TASK_PHY_READ_DISPATCHER);
    DeclareTask(UWL_EE_TASK_MAC_PROCESS_RX_BEACON);
    DeclareTask(UWL_EE_TASK_MAC_PROCESS_RX_DATA);
    DeclareTask(UWL_EE_TASK_MAC_PROCESS_RX_COMMAND);
    DeclareTask(UWL_EE_TASK_MAC_TIMESLOT);
    DeclareTask(UWL_EE_TASK_MAC_BEFORE_TIMESLOT);
    DeclareTask(UWL_EE_TASK_MAC_BACKOFF_PERIOD);
    DeclareTask(UWL_EE_TASK_MAC_GTS_SEND);

    const EE_THREAD_PTR EE_hal_thread_body[EE_MAX_TASK] = {
        &FuncCHAT_SEND,		/* thread CHAT_SEND */
        &FuncCHAT_RECEIVE,		/* thread CHAT_RECEIVE */
        &FuncLCD_WRITE,		/* thread LCD_WRITE */
        &FuncUWL_EE_TASK_PHY_READ_DISPATCHER,		/* thread UWL_EE_TASK_PHY_READ_DISPATCHER */
        &FuncUWL_EE_TASK_MAC_PROCESS_RX_BEACON,		/* thread UWL_EE_TASK_MAC_PROCESS_RX_BEACON */
        &FuncUWL_EE_TASK_MAC_PROCESS_RX_DATA,		/* thread UWL_EE_TASK_MAC_PROCESS_RX_DATA */
        &FuncUWL_EE_TASK_MAC_PROCESS_RX_COMMAND,		/* thread UWL_EE_TASK_MAC_PROCESS_RX_COMMAND */
        &FuncUWL_EE_TASK_MAC_TIMESLOT,		/* thread UWL_EE_TASK_MAC_TIMESLOT */
        &FuncUWL_EE_TASK_MAC_BEFORE_TIMESLOT,		/* thread UWL_EE_TASK_MAC_BEFORE_TIMESLOT */
        &FuncUWL_EE_TASK_MAC_BACKOFF_PERIOD,		/* thread UWL_EE_TASK_MAC_BACKOFF_PERIOD */
        &FuncUWL_EE_TASK_MAC_GTS_SEND 		/* thread UWL_EE_TASK_MAC_GTS_SEND */

    };

    /* ready priority */
    const EE_TYPEPRIO EE_th_ready_prio[EE_MAX_TASK] = {
        0x1U,		/* thread CHAT_SEND */
        0x1U,		/* thread CHAT_RECEIVE */
        0x2U,		/* thread LCD_WRITE */
        0x20U,		/* thread UWL_EE_TASK_PHY_READ_DISPATCHER */
        0x10U,		/* thread UWL_EE_TASK_MAC_PROCESS_RX_BEACON */
        0x8U,		/* thread UWL_EE_TASK_MAC_PROCESS_RX_DATA */
        0x8U,		/* thread UWL_EE_TASK_MAC_PROCESS_RX_COMMAND */
        0x8U,		/* thread UWL_EE_TASK_MAC_TIMESLOT */
        0x8U,		/* thread UWL_EE_TASK_MAC_BEFORE_TIMESLOT */
        0x8U,		/* thread UWL_EE_TASK_MAC_BACKOFF_PERIOD */
        0x4U 		/* thread UWL_EE_TASK_MAC_GTS_SEND */
    };

    /* dispatch priority */
    const EE_TYPEPRIO EE_th_dispatch_prio[EE_MAX_TASK] = {
        0x1U,		/* thread CHAT_SEND */
        0x1U,		/* thread CHAT_RECEIVE */
        0x2U,		/* thread LCD_WRITE */
        0x20U,		/* thread UWL_EE_TASK_PHY_READ_DISPATCHER */
        0x10U,		/* thread UWL_EE_TASK_MAC_PROCESS_RX_BEACON */
        0x8U,		/* thread UWL_EE_TASK_MAC_PROCESS_RX_DATA */
        0x8U,		/* thread UWL_EE_TASK_MAC_PROCESS_RX_COMMAND */
        0x8U,		/* thread UWL_EE_TASK_MAC_TIMESLOT */
        0x8U,		/* thread UWL_EE_TASK_MAC_BEFORE_TIMESLOT */
        0x8U,		/* thread UWL_EE_TASK_MAC_BACKOFF_PERIOD */
        0x4U 		/* thread UWL_EE_TASK_MAC_GTS_SEND */
    };

    /* thread status */
    #if defined(__MULTI__) || defined(__WITH_STATUS__)
        EE_TYPESTATUS EE_th_status[EE_MAX_TASK] = {
            EE_READY,
            EE_READY,
            EE_READY,
            EE_READY,
            EE_READY,
            EE_READY,
            EE_READY,
            EE_READY,
            EE_READY,
            EE_READY,
            EE_READY
        };
    #endif

    /* next thread */
    EE_TID EE_th_next[EE_MAX_TASK] = {
        EE_NIL,
        EE_NIL,
        EE_NIL,
        EE_NIL,
        EE_NIL,
        EE_NIL,
        EE_NIL,
        EE_NIL,
        EE_NIL,
        EE_NIL,
        EE_NIL
    };

    EE_TYPEPRIO EE_th_nact[EE_MAX_TASK];
    /* The first stacked task */
    EE_TID EE_stkfirst = EE_NIL;

    /* The first task into the ready queue */
    EE_TID EE_rqfirst  = EE_NIL;

    /* system ceiling */
    EE_TYPEPRIO EE_sys_ceiling= 0x0000U;



/***************************************************************************
 *
 * Mutex
 *
 **************************************************************************/
    const EE_TYPEPRIO EE_resource_ceiling[EE_MAX_RESOURCE]= {
        0x2U,		/* resource LCD_MUTEX */
        0x20U,		/* resource RES_SCHEDULER */
        0x8U,		/* resource UWL_EE_RESOURCE_MAC_GTS_SEND_MUTEX */
        0x8U,		/* resource UWL_EE_RESOURCE_MAC_MUTEX */
        0x20U,		/* resource UWL_EE_RESOURCE_MAC_RX_BEACON_MUTEX */
        0x20U,		/* resource UWL_EE_RESOURCE_MAC_RX_COMMAND_MUTEX */
        0x20U,		/* resource UWL_EE_RESOURCE_MAC_RX_DATA_MUTEX */
        0x20U 		/* resource UWL_EE_RESOURCE_MAC_SEND_MUTEX */
    };

    EE_TYPEPRIO EE_resource_oldceiling[EE_MAX_RESOURCE];



/***************************************************************************
 *
 * Counters
 *
 **************************************************************************/
    EE_counter_RAM_type       EE_counter_RAM[EE_MAX_COUNTER] = {
        {0, -1},        /* TASK_COUNTER */
        {0, -1}         /* UWL_EE_TASK_COUNTER */
    };



/***************************************************************************
 *
 * Alarms
 *
 **************************************************************************/
    const EE_alarm_ROM_type   EE_alarm_ROM[] = {
        {0, EE_ALARM_ACTION_TASK    , CHAT_SEND, NULL},
        {0, EE_ALARM_ACTION_TASK    , LCD_WRITE, NULL},
        {1, EE_ALARM_ACTION_TASK    , UWL_EE_TASK_MAC_TIMESLOT, NULL},
        {1, EE_ALARM_ACTION_TASK    , UWL_EE_TASK_MAC_BEFORE_TIMESLOT, NULL},
        {1, EE_ALARM_ACTION_TASK    , UWL_EE_TASK_MAC_BACKOFF_PERIOD, NULL},
        {1, EE_ALARM_ACTION_TASK    , UWL_EE_TASK_MAC_GTS_SEND, NULL}
    };

    EE_alarm_RAM_type         EE_alarm_RAM[EE_MAX_ALARM];


#pragma once
#include<stdlib.h>
#include<iostream>
#include <cstddef>
#include<string>
//#include"Number.h"
using namespace std;
#ifndef byte
typedef unsigned char byte;
typedef byte cs_byte;
typedef unsigned char boolean;

#endif // !1


class ETH_S7SimensCommands
{
public:
    static  byte FIRST_HAND_SHAKE[]; //第一次握手
    static  byte SECOND_HAND_SHAKE[];//第二次握手 0x03, 0x00, 0x00, 0x19, 0x02, 0xf0, 0x80, 0x32, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x08, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x64, 0x00, 0x64, 0x03, 0xc0
    static  byte THIRD_HAND_SHAKE[]; //第三次握手
    static  byte CNC_ID[];
    static  byte CNC_TYPE[];
    static  byte READ_VAR_INFO[];
    static  byte MANUFACTURE_DATE[];
    static  byte CNC_MODE[];
    static  byte CNC_STATUS[];
    static  byte CNC_PRODUCTS[];
    static  byte CNC_SET_PRODUCTS[];
    static  byte CNC_FEEDSETSPEED[];
    static  byte CNC_FEEDACTSPEED[];
    static  byte CNC_FEEDRATE[];
    static  byte CNC_SPINDLESETSPEED[];
    static  byte CNC_SPINDLEACTSPEED[];
    static  byte CNC_SPINDRATE[];
    static  byte RUN_TIME[];
    static  byte REMAIN_TIME[];
    static  byte PROGRAM_NAME[];
    static  byte PROGRAM_CONTENT[];
    static  byte TOOL_NUMBER[];
    static  byte TOOL_D_NUMBER[];
    static  byte TOOL_H_NUMBER[];
    static  byte TOOL_X_LENGTH[];
    static  byte TOOL_Z_LENGTH[];
    static  byte TOOL_RADIU[];
    static  byte TOOL_EDG[];
    static  byte posflag[];
    static  byte MACHINE_POS[];
    static  byte RELATIVELY_POS[];
    static  byte REMAIN_POS[];
    static  byte AXIS_NAME[];
    static  byte DRIVE_VOLTAGE[];
    static  byte DRIVER_CURRENT[];
    static  byte CNC_SPLOAD[];
    static  byte DRIVER_LOAD1[];
    static  byte DRIVER_LOAD2[];
    static  byte DRIVER_LOAD3[];
    static  byte DRIVER_LOAD4[];
    static  byte DRIVER_TEMPER[];
    static  byte CNC_SPMotorTemperature[];
    static  byte CNC_ALARM_NUM[];
    static  byte CNC_ALARM[];
    static  byte CNC_T_WORK_SYSTEM[];
    static  byte CNC_M_WORK_SYSTEM[];
    static  byte CNC_READ_R[];
    static  byte CNC_WRITE_R[];
    static  byte R_Driver[];
    static  byte DRIVER_SPLOAD[];
    static  byte DRIVER_SPLOAD2[];
    static  byte CurrentPro[];




    byte* getCommands(byte* cmdName);
    ETH_S7SimensCommands();
    ~ETH_S7SimensCommands();

};


//**********************************************************************
//**                                                                  **
//**        (C)Copyright ASUSTEK Hunter_Chen   2009-01                **
//**                                                                  **
//**              All Rights Reserved.                                **
//**                                                                  **
//**********************************************************************

#ifndef CMDID_H
#define CMDID_H

#ifndef CMD_COUNT
#define CMD_COUNT 0x50 //Note:the cmd count must >max cmdid;
#endif

#ifndef CMD_SIGNATURE_LEN
#define CMD_SIGNATURE_LEN 0x10
#endif

//TODO:define cmdid in here
#define HELP_CMDID 0 //reserved cmdid
#define NOLOG_CMDID 1 //reserved cmdid
#define USER_CMD_BASE 2 

#define SAMPLE_CMDID CMD_COUNT-2 //Sample cmd
#define EXIT_CMDID CMD_COUNT-1//reserved cmdid

#endif//CMDID_H
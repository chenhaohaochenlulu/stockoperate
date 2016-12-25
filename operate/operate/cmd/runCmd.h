//**********************************************************************
//**                                                                  **
//**        (C)Copyright ASUSTEK Hunter_Chen   2009-08                **
//**                                                                  **
//**              All Rights Reserved.                                **
//**                                                                  **
//**********************************************************************
#ifndef RUNCMD_H
#define RUNCMD_H
#include "../cmd/cmd.h"
#include "../interpreter/interpreter.h"
class CRunCmd :public CCmdCallback
{
public:
	CRunCmd();
	char *cp;
	int dealCmd(Cmd *p);
	int help(int cmdid);
};

#endif
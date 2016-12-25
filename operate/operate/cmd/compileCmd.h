//**********************************************************************
//**                                                                  **
//**        (C)Copyright ASUSTEK Hunter_Chen   2009-08                **
//**                                                                  **
//**              All Rights Reserved.                                **
//**                                                                  **
//**********************************************************************

#ifndef COMPILECMD_H
#define COMPILECMD_H

#include "../cmd/cmd.h"
#include "../compile/compile.h"
class CCompileCmd :public CCmdCallback
{
public:
	char *cp;
	CCompileCmd();
	int dealCmd(Cmd *p);
	int help(int cmdid);
};
#endif
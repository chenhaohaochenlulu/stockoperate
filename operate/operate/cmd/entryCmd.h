//**********************************************************************
//**                                                                  **
//**        (C)Copyright ASUSTEK Hunter_Chen   2009-08                **
//**                                                                  **
//**              All Rights Reserved.                                **
//**                                                                  **
//**********************************************************************

#ifndef ENTRYCMD_H
#define ENTRYCMD_H
#include "../cmd/cmd.h"

class CEntryCmd :public CCmdCallback
{
public:
	CEntryCmd();
	char *cp;
	int dealCmd(Cmd *p);
	int help(int cmdid);
};

#endif
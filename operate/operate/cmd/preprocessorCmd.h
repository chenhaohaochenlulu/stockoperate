//**********************************************************************
//**                                                                  **
//**        (C)Copyright ASUSTEK Hunter_Chen   2009-08                **
//**                                                                  **
//**              All Rights Reserved.                                **
//**                                                                  **
//**********************************************************************

#ifndef preprocessorCmd_H
#define preprocessorCmd_H
#include "../cmd/cmd.h"
#include "../preprocessor/preprocessor.h"
class CPreprocessorCmd :public CCmdCallback
{
public:
	CPreprocessorCmd();
	char *cp;
	int dealCmd(Cmd *p);
	int help(int cmdid);
};

#endif
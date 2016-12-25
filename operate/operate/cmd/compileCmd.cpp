//**********************************************************************
//**                                                                  **
//**        (C)Copyright ASUSTEK Hunter_Chen   2009-08                **
//**                                                                  **
//**              All Rights Reserved.                                **
//**                                                                  **
//**********************************************************************

#include "compileCmd.h"

char tplSource[]="source";

CCompileCmd::CCompileCmd()
{
	this->cp=0;
}

int CCompileCmd::dealCmd(Cmd *p)
{
	unsigned int len=strlen("/C");
	if(strlen((char*)p->cmdStr)>len) this->cp=(char*)p->cmdStr+len;
	else this->cp=(char*)p->cmdStr+len+1;

	CSource source(this->cp);
	CCompile compile;
	return compile.complie(&source);
}

int CCompileCmd::help(int cmdid)
{
	cout<<"/C : specified the tpl compile(/C) source filename and the default is source. ie. /C source "<<endl;
	return NULL;
}
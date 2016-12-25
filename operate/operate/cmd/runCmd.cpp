//**********************************************************************
//**                                                                  **
//**        (C)Copyright ASUSTEK Hunter_Chen   2009-08                **
//**                                                                  **
//**              All Rights Reserved.                                **
//**                                                                  **
//**********************************************************************
#include "runCmd.h"

char strObject[]="object";

CRunCmd::CRunCmd()
{
	this->cp=0;
}

int CRunCmd::dealCmd(Cmd *p)
{
	unsigned int len=strlen("/R");
	if(strlen((char*)p->cmdStr)>len) this->cp=(char*)p->cmdStr+len;
	else this->cp=(char*)p->cmdStr+len+1;
	CInterpreter interpreter;
	return interpreter.run(this->cp);
}

int CRunCmd::help(int cmdid)
{
	cout<<"/R : specified the tpl programm Run(/R) tpl object filename.ie. /R object.tpl"<<endl;
	return NULL;
}
//**********************************************************************
//**                                                                  **
//**        (C)Copyright ASUSTEK Hunter_Chen   2009-08                **
//**                                                                  **
//**              All Rights Reserved.                                **
//**                                                                  **
//**********************************************************************
#include "entryCmd.h"

char tplEntry[]="main";

CEntryCmd::CEntryCmd()
{
	this->cp=0;
}

int CEntryCmd::dealCmd(Cmd *p)
{
	unsigned int len=strlen("/ENTRY");
	if(strlen((char*)p->cmdStr)>len) this->cp=(char*)p->cmdStr+len;
	else this->cp=(char*)p->cmdStr+len+1;
	return 0;
}

int CEntryCmd::help(int cmdid)
{
	cout<<"/ENTRY : specified the tpl programm entry function.default is main funcion. ie. /entry tplEntry"<<endl;
	return NULL;
}
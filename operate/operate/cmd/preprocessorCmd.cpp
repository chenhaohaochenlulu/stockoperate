//**********************************************************************
//**                                                                  **
//**        (C)Copyright ASUSTEK Hunter_Chen   2009-08                **
//**                                                                  **
//**              All Rights Reserved.                                **
//**                                                                  **
//**********************************************************************
#include "preprocessorCmd.h"


CPreprocessorCmd::CPreprocessorCmd()
{
	this->cp=0;
}

int CPreprocessorCmd::dealCmd(Cmd *p)
{
	unsigned int len=strlen("/P");
	if(strlen((char*)p->cmdStr)>len) this->cp=(char*)p->cmdStr+len;
	else this->cp=(char*)p->cmdStr+len+1;
	CPreProcessor prep;
	return prep.preprocessor(this->cp);
}

int CPreprocessorCmd::help(int cmdid)
{
	cout<<"/P : specified the tpl programm preprocessor filename ie. /P filename"<<endl;
	return NULL;
}
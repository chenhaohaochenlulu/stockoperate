//**********************************************************************
//**                                                                  **
//**        (C)Copyright ASUSTEK Hunter_Chen   2009-01                **
//**                                                                  **
//**              All Rights Reserved.                                **
//**                                                                  **
//**********************************************************************

#ifndef CMD_H
#define CMD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <ctype.h>
#include "cmdid.h" //This file use define you cmd.
#include "../object/object.h"
using namespace std;

#ifndef CMD_DEBUG
#define CMD_DEBUG 0//1
#endif
//cmd staus
#define SUCCESS 0
#define BUSY 1
#define ACHIEVE 2
#define EXCEPTION 3

//init flag
#define UNINITIALIZED 0
#define INIT_COMPLETE 1 
#define SPECIAL_CMD 1
#define CMD_FOUND 1
//cmd exception
#define NORMAL_CMD 0
#define COLLAPSE 1
#define ERROR_CMD 2
#define UNTREATED 3
#define ERROR_EXIT 4
#define CMDID_OVERFLOW 5
#define CMD_SIGNATURE_OVERFLOW 6
//support cmd struct count.

#ifndef CMD_COUNT
#define CMD_COUNT 50
#endif

#ifndef CMD_SIGNATURE_LEN
#define CMD_SIGNATURE_LEN 0x10
#endif

#ifndef HELP_CMDID
#define HELP_CMDID 0
#endif

#ifndef EXIT_CMDID
#define EXIT_CMDID CMD_COUNT-1
#endif

typedef struct CmdStruct{
	char signature[CMD_SIGNATURE_LEN];
	int argcIndex;
	void *cmdStr,*currentCp;
	int status,exception;
	int initFlag;
	int cmdid;
}Cmd;

class CCmdCallback:public Object
{
public:
	virtual	int dealCmd(Cmd *p);//{cerr<<"dealCmd:Help not available for base type."<<endl;return EOF;}
	virtual	int help(int cmdid);//{cerr<<"Error:Help not available for base type."<<endl;return EOF;}
};

class CCmd:public Object
{
	Cmd _cmd[CMD_COUNT];
	CCmdCallback * pCmdCallback[CMD_COUNT];
	int resetCmd(Cmd *pCmd); 
public:
	CCmd();
	int setException(int cmdid,int exception);
	int resetException(int cmdid);
	int setStatus(int cmdid,int status);
	int resetStatus(int cmdid);
	int registerCmd (char *signature,CCmdCallback *pCallback);
	int registerCmd(int cmdid,char *signature,CCmdCallback *pCallback);
	int detectCmd(int cmdid,char *src);
	int dealCmd(int cmdid);
	int isInit(int cmdid);//return UNINITIALIZED or INIT_COMPLETE 
	int isException(int cmdid);
	int help();
	int help(int cmdid);
	int traversalCmdLine(int argc,char *argv[]);
	int sendCmd(int cmdid);
	int dealAllCmd(int argc,char *argv[],int display=1);
	int dealSpecialCmd(int cmdid);
	int query(char * signature);//ret cmdid error:ret EOF

};

class CHelpCmd :public CCmdCallback
{
	int dealCmd(Cmd *p);//{return NULL;}//this is a special cmd id
	int help(int cmdid);//{cerr<<"Help."<<endl;return EOF;}
};

class CExitCmd :public CCmdCallback
{
	int dealCmd(Cmd *p);//{cout<<"Exit."<<endl;exit(NULL);return EOF;}
	int help(int cmdid);//{cout<<"Exit."<<endl;return EOF;}
};

class CNoLogCmd :public CCmdCallback
{
	int dealCmd(Cmd *p);
	int help(int cmdid);
};
#endif
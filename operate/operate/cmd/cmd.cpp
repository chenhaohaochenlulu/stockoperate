//**********************************************************************
//**                                                                  **
//**        (C)Copyright ASUSTEK Hunter_Chen   2009-01                **
//**                                                                  **
//**              All Rights Reserved.                                **
//**                                                                  **
//**********************************************************************

#include "cmd.h"

#if CMD_DEBUG
//step1 define one CMDID
//step2 create one sub class of CCmdCallback 
//step3 registerCmd one cmd 
class SampleCmd :public CCmdCallback
{
	int dealCmd(Cmd *p){printf("Sample amd deal.\n");return EOF;}
	int help(int cmdid){printf("Sample help.\n");return EOF;}
};

int main(int argc,char * argv[])
{
	CCmd cmd;
	SampleCmd sampleCmd;
	//cmd.traversalCmdLine(argc,argv);
	cmd.registerCmd(SAMPLE_CMDID,"SAMPLE",&sampleCmd);
	cmd.dealAllCmd(argc,argv);
	cmd.help();
	return NULL;
}
#endif //CMD_DEBUG

CHelpCmd helpCmd;
CExitCmd exitCmd;
CNoLogCmd noLogCmd;

int CCmdCallback::dealCmd(Cmd *p){printf("dealCmd:Help not available for base type.\n");return EOF;}
int CCmdCallback::help(int cmdid){printf("Error:Help not available for base type.\n");return EOF;}
int CHelpCmd::dealCmd(Cmd *p){return NULL;}
int CHelpCmd::help(int cmdid){printf("Help: list all cmd help information.\n");return NULL;}
int CExitCmd::dealCmd(Cmd *p){printf("Exit.\n");exit(NULL);return NULL;}
int CExitCmd::help(int cmdid){printf("Exit:exit the tpl cmd mode.\n");return NULL;}
int CNoLogCmd::dealCmd(Cmd *p){return NULL;}
int CNoLogCmd::help(int cmdid){printf("NOLOG.ignore the copyright information dislpay.\n");return NULL;}

CCmd::CCmd()
{
	resetCmd(_cmd);
	registerCmd(HELP_CMDID,"HELP",&helpCmd);
	//registerCmd(NOLOG_CMDID,"NOLOG",&noLogCmd);
	registerCmd(EXIT_CMDID,"EXIT",&exitCmd);
#if CMD_DEBUG
	printf("(C)Copyright ASUSTEK Hunter_Chen 2009.\n");
#endif
}

int CCmd::resetCmd(Cmd *pCmd)
{
	for(int n=0;n<CMD_COUNT;n++,pCmd++){
		pCmd->initFlag=UNINITIALIZED;
		pCmd->status=NORMAL_CMD;
		pCmd->exception=NORMAL_CMD;
	}
	return NULL;
}

int CCmd::dealAllCmd(int argc,char *argv[],int display)
{
	int cmdid=0,n;
	if(argc<2) return EOF;

	for(n=1;n<argc;n++){	
		for(cmdid=0;cmdid<CMD_COUNT;cmdid++){
			if(UNINITIALIZED==_cmd[cmdid].initFlag) continue;
			if(CMD_FOUND!=detectCmd(cmdid,argv[n])) continue;
			_cmd[cmdid].argcIndex=n;
			if(display) printf("-%s\n",argv[n]);
			dealCmd(cmdid);
		}
	}
	return NULL;
}

int CCmd::registerCmd (char *signature,CCmdCallback *pCallback)
{
	int cmdid;
	if(!signature) return EOF;
	for(cmdid=0;cmdid<CMD_COUNT;cmdid++){
		if(UNINITIALIZED==_cmd[cmdid].initFlag) break;
	}
	if(cmdid<CMD_COUNT){
		if(NULL==registerCmd(cmdid,signature,pCallback)) return cmdid;
	}
	return EOF;
}

int CCmd::registerCmd(int cmdid,char *signature,CCmdCallback *pCallback)
{
	if(_cmd[cmdid].initFlag==INIT_COMPLETE) return EOF;
	if(cmdid>CMD_COUNT){
		_cmd[cmdid].exception=CMDID_OVERFLOW; return EOF;
	}

	if(CMD_SIGNATURE_LEN<strlen(signature)){
		_cmd[cmdid].exception=CMD_SIGNATURE_OVERFLOW; return EOF;
	}

	_strupr(signature);

	strcpy(_cmd[cmdid].signature,signature);

	pCmdCallback[cmdid]=pCallback;
	_cmd[cmdid].cmdid=cmdid;
	_cmd[cmdid].status=NORMAL_CMD;
	_cmd[cmdid].exception=NORMAL_CMD;
	_cmd[cmdid].initFlag=INIT_COMPLETE;

	return NULL;
}

int CCmd::detectCmd(int cmdid,char *src)
{	
	if(NULL==src) return EOF;
	if(cmdid>CMD_COUNT){
		_cmd[cmdid].exception=CMDID_OVERFLOW;
		return EOF;
	}

	_cmd[cmdid].currentCp=strstr(src,_cmd[cmdid].signature);
	if(_cmd[cmdid].currentCp){
		_cmd[cmdid].cmdStr=src;
		return CMD_FOUND;
	}

	char buf[CMD_SIGNATURE_LEN];
	int size=strlen(src);
	if(size>CMD_SIGNATURE_LEN-1) size=CMD_SIGNATURE_LEN-1;
	memset(buf,'\0',CMD_SIGNATURE_LEN);
	memcpy(buf,src,size);

	_strupr(buf);
	_strupr(_cmd[cmdid].signature);
	_cmd[cmdid].currentCp=strstr(buf,_cmd[cmdid].signature);
	if(_cmd[cmdid].currentCp){
		_cmd[cmdid].cmdStr=src;
		return CMD_FOUND;
	}
	return NULL;	
}

int CCmd::dealCmd(int cmdid)
{
	if(cmdid>CMD_COUNT){
		_cmd[cmdid].exception=CMDID_OVERFLOW;
		return EOF;
	}	
	if(isException(cmdid)) return EOF;
	if(dealSpecialCmd(cmdid)) return NULL;
	pCmdCallback[cmdid]->dealCmd(&_cmd[cmdid]);
	return NULL;
}

int CCmd::dealSpecialCmd(int cmdid)
{	
	int isSpecial=NULL;
	if(HELP_CMDID==cmdid){help();isSpecial=SPECIAL_CMD;}
	return isSpecial;	
}

int CCmd::sendCmd(int cmdid)
{
	return dealCmd(cmdid);
}

int CCmd::help()
{
	for(int cmdid=0;cmdid<CMD_COUNT;cmdid++)
		help(cmdid);
	return NULL;
}

int CCmd::help(int cmdid)
{
	if(INIT_COMPLETE==isInit(cmdid)){
		//printf("commandid=%02d\t",cmdid);
		pCmdCallback[cmdid]->help(cmdid);
	}
	return NULL;
}

int CCmd::isException(int cmdid)
{
	if(cmdid>CMD_COUNT){
		_cmd[cmdid].exception=CMDID_OVERFLOW;
		return EOF;
	}
	return _cmd[cmdid].exception;
}

int CCmd::setException(int cmdid,int exception)
{
	if(cmdid>CMD_COUNT){
		_cmd[cmdid].exception=CMDID_OVERFLOW;
		return EOF;
	}
	_cmd[cmdid].status=EXCEPTION;
	_cmd[cmdid].exception=exception;
	return NULL;
}

int CCmd::resetException(int cmdid)
{
	if(cmdid>CMD_COUNT){
		_cmd[cmdid].exception=CMDID_OVERFLOW;
		return EOF;
	}
	_cmd[cmdid].exception=NORMAL_CMD;
	return NULL;
}

int CCmd::setStatus(int cmdid,int status)
{
	if(cmdid>CMD_COUNT){
		_cmd[cmdid].exception=CMDID_OVERFLOW;
		return EOF;
	}
	_cmd[cmdid].status=status;
	return NULL;
}

int CCmd::resetStatus(int cmdid)
{
	if(cmdid>CMD_COUNT){
		_cmd[cmdid].exception=CMDID_OVERFLOW;
		return EOF;
	}
	_cmd[cmdid].status=SUCCESS;
	return NULL;
}

int CCmd::isInit(int cmdid)
{
	if(cmdid>CMD_COUNT){
		_cmd[cmdid].exception=CMDID_OVERFLOW;
		return UNINITIALIZED;
	}
	return _cmd[cmdid].initFlag;
}

int CCmd::traversalCmdLine(int argc,char *argv[])
{
	if(argc<1) return EOF;
	for(int n=0;n<argc;n++)
		printf("argv[%d]=%s\n",n,argv[n]);
	return NULL;
}

int CCmd::query(char * signature)
{
	int cmdid;
	if(!signature) return EOF;
	for(cmdid=0;cmdid<CMD_COUNT;cmdid++){
		if(UNINITIALIZED==_cmd[cmdid].initFlag) continue;
		if(CMD_FOUND!=detectCmd(cmdid,signature)) continue;
		break;
	}
	if(cmdid<CMD_COUNT) return cmdid;
	return EOF;
}

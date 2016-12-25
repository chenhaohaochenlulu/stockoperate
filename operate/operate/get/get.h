//**********************************************************************
//**                                                                  **
//**        (C)Copyright ASUSTEK Hunter_Chen   2008-11                **
//**                                                                  **
//**              All Rights Reserved.                                **
//**                                                                  **
//**********************************************************************
#ifndef GET_H
#define GET_H
#include <ctype.h>
#include <stdio.h>
#include <memory.h>
#include "../object/object.h"
#include "../keyword/keywordParam.h"
#ifndef	 YES
#define YES 0xAA
#endif

#ifndef	NO
#define NO  0
#endif
#define BUF_SIZE 0x400
class CGet:public Object
{
public:
	char buf[BUF_SIZE];
	unsigned long line;

	CGet();
	static unsigned long getValue(char *cp,char endChar='\0',int skipSpace=0);//return getValue if 0==get NULL
	static char * getValue(char *cp,unsigned long *p,char endChar='\0',int skipSpace=0);//clear *p=0;return current *cp
	int getValueTo(char *cp,unsigned long *p ,int pLen,char endChar='\0');//return getValue to buf count 
	char * getString(char *src,char *dst,int dstLen);
	char * getStringX(char *src,char *dst,int dstLen);
	char * getLine(char *src,char *dst,int dstLen);
	char * getLine(char *src,char *dst,int dstLen,unsigned char endchar,char *endcp);
	char * getLine(char *src,char *endcp);//store line to buf
	char * getLineX(char *src,char *dst,int dstLen);
	char * getNextLine(char *src,char *dst,int dstLen);
	int chkString(char string[],char *start);
	char * strToken(char *start,char *end,char *delimit,int retStart=NULL);
	void setLine(unsigned long L);
	void clearBuf(int len=BUF_SIZE);
	bool getToken(char *cp);
	static bool getToken(char *cp,char * dst,int len);
	static char * getToken(CKeywordParam *p,char *dst ,int len);
	int getblock(char*src,char *dst,char *endSrc=0,int len=BUF_SIZE,char start='(',char end=')',int skipstart=0,void * *out=0);// like (abc... ...)
	int getblock(char*src,char *dst,char* end,int len=BUF_SIZE);
	char *getComment(char*start,char *end,char *e);
	void display();
};
#endif //#ifndef GET_H


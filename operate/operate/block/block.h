//**********************************************************************
//**                                                                  **
//**        (C)Copyright ASUSTEK Hunter_Chen   2009-07                **
//**                                                                  **
//**              All rights Reserved.                                **
//**                                                                  **
//**********************************************************************
#ifndef BLOCK_H_H
#define BLOCK_H_H

#ifndef BLOCK_DEBUG
#define BLOCK_DEBUG 0//1
#endif

#include <stdio.h>
#include <string.h>
#include "../object/object.h"
#include "../allotMem/AllotMEM.h"

class CBracket:public Object
{
public:
	int error;
	int leftRoundBracketCount;//'(', 
	int rightRoundBracketCount;//')',
	int leftQquareBracketCount;//'[',
	int rightQquareBracketCount;//']',
	int leftBraceCount;//'{',//{
	int rightBraceCount;//'}',//}
	char braceket;
	CBracket();
	~CBracket();
	int detectL(char *cp);//left detect
	int detectR(char *cp);//right detect
	int detect(char *cp);
	int isHalf(char *cp,char *cp1);
	char * getblock(char * start,char* end,char c='{',char *buf=NULL,int *pLen=0,int skip=0);//0: error // other true
	char * getend(char * start,char* end,char *e);
	char * getstart(char* start,char *end,char *s);
	int getError();
};

#endif
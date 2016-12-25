//**********************************************************************
//**                                                                  **
//**        (C)Copyright ASUSTEK Hunter_Chen   2009-07                **
//**                                                                  **
//**              All Rights Reserved.                                **
//**                                                                  **
//**********************************************************************
#ifndef KEYWORDPARAM_H
#define KEYWORDPARAM_H
#define KEYWORDPARAM_DEBUG 0

class CKeywordParam
{
public:
	char *cp_start;
	char *cp_current;
	char *cp_end;
public:
	CKeywordParam();
	CKeywordParam(CKeywordParam *p);
	void display(const char *str=0,char *end=0,int dispLen=0x100,char * re_current=0);//re_current use for replace current for display
	void skip(const char *skip=0);
	int get(CKeywordParam *src,char *end);//get to  start and end//like get(",;")
	int skipCheck(char *skip=0,char* syntax=0) ;
};

#endif
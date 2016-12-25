//**********************************************************************
//**                                                                  **
//**        (C)Copyright ASUSTEK Hunter_Chen   2009-07                **
//**                                                                  **
//**              All Rights Reserved.                                **
//**                                                                  **
//**********************************************************************
#ifndef KEYWORDPARAM_CPP
#define KEYWORDPARAM_CPP
#include "keywordParam.h"
#include "stdio.h"
#include "../block/block.h"
extern CBracket block;

#if KEYWORDPARAM_DEBUG
int main()
{
	return 0;
}
#endif

CKeywordParam::CKeywordParam()
{
	this->cp_current=0;
	this->cp_end=0;
	this->cp_start=0;
}
CKeywordParam::CKeywordParam(CKeywordParam *p)
{
	this->cp_current=p->cp_current;
	this->cp_end=p->cp_end;
	this->cp_start=p->cp_start;
}

void CKeywordParam::display(const char *str,char *end,int dispLen,char * re_current)
{
	if(str){ printf("%s",str); return;}//1.if str not display this
	if(!this->cp_current) return;

	char *cp=end;
	char *cp_current=this->cp_current;
	if(re_current) cp_current=re_current;//replace the current point.
	for(int n=0;cp_current<this->cp_end&&n<dispLen;cp_current++,n++){
		if(end==0)	{printf("%c",*cp_current); continue;}

		for(cp=end;*cp!='\0';cp++){//end !=0
				if(*cp_current==*cp) break;//find end char break.
			}

		if(*cp!='\0') break;
		printf("%c",*cp_current);
	}

	printf("\n");
	_flushall();
}

void CKeywordParam::skip(const char *skip)//skip some ASSCII 
{
	if(!skip) return;
	char *s;
	for(;this->cp_current&&this->cp_current<this->cp_end;this->cp_current++)//check this->cp_current not null
	{
		for(s=(char*)skip;*s!='\0';s++){//find in skip
			if(*s==*this->cp_current) break;
		}
		if(*s=='\0') break;
	}
}

int CKeywordParam::get(CKeywordParam *src ,char *end)//like get(", ;")
{
	this->cp_start=src->cp_start;
	this->cp_current=src->cp_current;
	this->cp_end=this->cp_current;
	this->cp_end=block.getend(this->cp_current,src->cp_end,end);
	return 0;
}

int CKeywordParam::skipCheck(char *skip,char* syntax) //pass return 0
{
	if(skip) this->skip(skip);//1.skip some char like  tab and space //test ok!
	else this->skip(" \t");

	if(!syntax) return 0;//skip return
	if(this->cp_current>=this->cp_end) return 1;

	char *cp;
	for(cp=syntax;*cp!='\0';cp++)  //2. syntax check
		if(*this->cp_current==*cp) break;
	if(*cp!='\0') return 0; //syntax check pass

	printf("Error:miss '%s' in line :",syntax); this->display(0,"\n\r");//display error
	return -1;
}

#endif //KEYWORDPARAM_CPP

//**********************************************************************
//**                                                                  **
//**        (C)Copyright ASUSTEK Hunter_Chen   2009-07                **
//**                                                                  **
//**              All Rights Reserved.                                **
//**                                                                  **
//**********************************************************************

#ifndef BLOCK_CPP
#define BLOCK_CPP
#include "block.h"

#if BLOCK_DEBUG
int main(int argc,char *argv[])
{
	if(argc<2)
	{
		printf("block.exe [filename]\n");
		return -1;
	}
	CAllotMem allot(argv[1]);
	CBracket b;
	b.getblock(allot.allot.start,allot.allot.end);//check file block

//	char *cp="dsfjhsd{jfsdsj{hdsdfjshd sds dsd sdsa}jhdj}as";
//	b.getblock(cp,cp+strlen(cp));
	return 0;
}
#endif//BLOCK_DEBUG

CBracket::CBracket()
{
	this->leftBraceCount=0;
	this->leftQquareBracketCount=0;
	this->leftRoundBracketCount=0;
	this->rightBraceCount=0;
	this->rightQquareBracketCount=0;
	this->rightRoundBracketCount=0;
	this->error=0;
	this->braceket=0;
}

CBracket::~CBracket()
{
}

int CBracket::isHalf(char *cp,char *cp1)
{
	if(*cp=='('&&*cp1==')'||*cp==')'&&*cp1=='(') return 1;
	if(*cp=='['&&*cp1==']'||*cp==']'&&*cp1=='[') return 2;
	if(*cp=='{'&&*cp1=='}'||*cp=='}'&&*cp1=='{') return 3;
	return 0;
}
int CBracket::detectL(char *cp)
{
	if(*cp=='('){
		this->leftRoundBracketCount++;
		this->braceket='(';
		return 1;
	}
	if(*cp=='['){
		this->leftQquareBracketCount++;
		this->braceket='[';
		return 2;
	}
	if(*cp=='{'){
		this->leftBraceCount++;
		this->braceket='{';
		return 3;
	}
	return 0;
}

int CBracket::detectR(char *cp)
{
	if(*cp==')'){
		this->rightRoundBracketCount++;
		this->braceket=')';
		return 1;
	}
	if(*cp==']'){
		this->rightQquareBracketCount++;
		this->braceket=']';
		return 2;
	}
	if(*cp=='}'){
		this->rightBraceCount++;
		this->braceket='}';
		return 3;
	}
	return 0;
}

int CBracket::detect(char *cp)
{
	int ret=0;
	ret=detectL(cp);
	if(ret) return ret;
	ret=detectR(cp);
	return ret;
}

int CBracket::getError()
{
	return this->error;
}
//get {xxx}  ie. xxx{...abc...{...def...}...ghi...}
char *CBracket::getblock(char * start,char* end,char c,char *buf,int *pLen,int skip)//this function can not return null
{
	int left=0,right=0,n;

	if(start>=end){
		printf("Error:CBracket::getblock->if(cp>=end)\n");
		return end;
	}
	char *cp;
	for(cp=start;*cp!=c&&cp<end;cp++);//1:skip xx{...abc...{...def...}...ghi...}

	for(n=0;cp<end;cp++)//2:check
	{
		if(buf&&pLen){ //check if or not shore to buf
			if(n<*pLen) buf[n]=*cp;
			n++;
		}

		if(*cp==c){ left++;continue;}
		if(this->isHalf(&c,cp)){
			right++;
			if(left==right) break;
		}
	}

	if(buf&&pLen) *pLen=n;//check if or not return store count

#if BLOCK_DEBUG
	printf("CBracket::getblock->left=%d right=%d *cp='%c'\n",left,right,*cp);
#endif 

	if(cp<end&&left==right){
		if(skip) return ++cp;
		return cp;
	}
	//3:display error
	this->error++;
	printf("Error:CBracket::getblock() miss block bracket.\nError Location:\"");
	for(cp=start;cp<end;cp++){
		printf("%c",*cp);//out error
	}
	printf("\"\n");
	return 0;
}
//(000,111,222({[,,,]}),333)
char *CBracket::getend(char * start,char* end,char *e)//*e point end chars string buf
{
	int i;
	char *cp=start;

    for(;(*cp==' '||*cp=='\t'||*cp=='\r'||*cp=='\n')&&cp<end;cp++); //skip  space and \r \n \t
	if(this->detectL(cp)) cp++; //skip L Bracket

	for(;cp<end;cp++){
		if(this->detectL(cp)){
			cp=this->getblock(cp,end,*cp,0,0,1);//cp point ),],}
			if(!cp) return 0;
			cp++;//cp point ),],} ++
		}

		for(i=0;e[i]!='\0';i++){
			if(*cp==e[i]) break;
		}
		if(e[i]!='\0') break;
	}
	return cp;
}

char * CBracket::getstart(char* start,char *end,char *s)
{
	int i;
	for(;start<end;start++)
	{
		for(i=0;s[i]!='\0';i++){
			if(*start==s[i]) break;
		}
		if(s[i]!='\0') break;
	}
	return start;
}

#endif//BLOCK_CPP


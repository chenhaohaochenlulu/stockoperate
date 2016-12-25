//**********************************************************************
//**                                                                  **
//**        (C)Copyright ASUSTEK Hunter_Chen   2008-11                **
//**                                                                  **
//**              All Rights Reserved.                                **
//**                                                                  **
//**********************************************************************
#include "get.h"

#if GET_DEBUG
int main()
{
	printf("get.cpp int main()\n");
	CGet get;
	return 0;
}
#endif

CGet::CGet()
{
#if GET_DEBUG
	printf("CGet::CGet()\n");
#endif
	this->line=1;
	this->clearBuf();
}

unsigned long CGet::getValue(char *cp,char endChar,int skipSpace)
{
	unsigned long data;
	for(data=0;*cp!=endChar;cp++){
		if(isspace(*cp)&&skipSpace) continue;  
		if(!isxdigit(*cp)) break;
		data<<=4;
		if(isdigit(*cp))
			data=data|((unsigned long)*cp&0xFF)-0x30;
		else
			data=data|((unsigned long)toupper(*cp)&0xFF)-0x37;	
	}
	return data;
}

char * CGet::getValue(char *cp,unsigned long *p,char endChar,int skipSpace)
{
	for(*p=0;*cp!=endChar;cp++){
		if(isspace(*cp)&&skipSpace) continue;  
		if(!isxdigit(*cp)) break;
		*p<<=4;
		if(isdigit(*cp))
			*p=*p|((unsigned long)*cp&0xFF)-0x30;
		else
			*p=*p|((unsigned long)toupper(*cp)&0xFF)-0x37;	
	}
	return cp;
}

int CGet::getValueTo(char *cp,unsigned long *p ,int pLen,char endChar)	
{	
	int n;
	for(n=0;*cp&&n<pLen&&*cp!=endChar;cp++){  
		if(!isxdigit(*cp)) continue;
		*p=0;
		cp=getValue(cp,p,endChar); //printf("*p=%lXh\n",*p);//test line (ok)
		p++;n++;
		if(*cp==endChar) break;
	}
	return n;	
}

char * CGet::getString(char *src,char *dst,int dstLen)
{
	for(;dstLen>1;src++,dst++,dstLen--){
		if(isprint(*src)){*dst=*src;continue;}
			break;
	}
	*dst='\0';
//	if(*src=='\0') return NULL;
	return src;
}

char * CGet::getStringX(char *src,char *dst,int dstLen)
{
	for(;dstLen>1;src++,dst++,dstLen--){
		if(*src=='\t'){*dst=*src;continue;}
		if(isprint(*src)){*dst=*src;continue;}
			break;
	}
	*dst='\0';
	return src;
}

char * CGet::getNextLine(char *src,char *dst,int dstLen)
{
	while( isprint(*src))src++;//set cp to 
	while(!isprint(*src))src++;
	src=getStringX(src,dst,dstLen);
	return src;
}

char * CGet::getLine(char *src,char *dst,int dstLen)
{
	while(!isprint(*src))src++;//
	src=getString(src,dst,dstLen);
	return src;
}

char * CGet::getLine(char *src,char *dst,int dstLen,unsigned char endchar,char *endcp)
{
	while((!isprint(*src)||isspace(*src))&&src<endcp){
		if(*src=='\n')line++; 
		src++;
	}//
	for(;dstLen>1&&src<endcp;src++,dst++,dstLen--){
		if(*src=='\n')line++;
		if(*src==endchar) break;
		*dst=*src;
	}
	*dst='\0';
	return src;
}

char *CGet::getLine(char *src,char * end)
{
	return this->getLine(src,this->buf,BUF_SIZE,'\r',end);
}

void CGet::setLine(unsigned long L)
{
	line=L;
}
char * CGet::getLineX(char *src,char *dst,int dstLen)
{
	while(!isprint(*src))src++;//
	src=getStringX(src,dst,dstLen);
	return src;
}

int CGet::chkString(char string[],char *start)// cmp string
{
	char *cp;
	for(cp=string;*cp&&isprint(*start);start++){	//note *cp=ture
		if(toupper(*cp)==toupper(*start)){cp++; continue;}//printf("*cp=%c\n",*cp);//test
		if(isspace(*start)){start++;continue;}
		break;
	}
	
	if(!*cp) return 1;
	//printf("return NULL\n");
	return NULL;
}

char * CGet::strToken(char *cp,char *end,char *delimit,int retStart)//return fail:NULL,start,current
{
	char *dl,*start;
	int findFlag;
	
	for(;cp<end;cp++){
		for(findFlag=NO,dl=delimit;*dl;dl++){	//skip delimit
			if(*cp==*dl){
				findFlag=YES;break;
			}
		}
		if(findFlag==YES) continue;
		break;
	}
	start=cp;
	for(findFlag=NO;cp<end;cp++){
		printf("%c",*cp);
		for(findFlag=NO,dl=delimit;*dl;dl++){	//find delimit
			if(*cp==*dl){
				findFlag=YES;break;
			}
		}
		if(findFlag==YES) break;
	}
	if(findFlag==NO) return NULL;
	if(retStart) return start;
	return cp;
}

void CGet::clearBuf(int len)
{
	if(len>BUF_SIZE) len=BUF_SIZE;
	memset(this->buf,'\0',len);
}

bool CGet::getToken(char *cp)
{
	return (bool) getToken(cp,this->buf,BUF_SIZE);
}

char * CGet::getToken(CKeywordParam *p,char *dst ,int len)
{
	int n;
	if(!p->cp_current) return 0;//check not null
	for(;p->cp_current<p->cp_end;p->cp_current++){
		if(!isspace(*p->cp_current)) break;
	}

	for(n=0;n<len-1&&p->cp_current<p->cp_end;n++,p->cp_current++){
		if(isalnum(*p->cp_current)||*p->cp_current=='_'){
			dst[n]=*p->cp_current;continue;
		}
		break;
	}
	dst[n]='\0';
	if(dst[0]=='\0') return 0;
	return p->cp_current;
}

bool CGet::getToken(char *cp,char * dst,int len)
{
	int n;
	for(;*cp!='\0'&&(*cp==' '||*cp=='\t');cp++);
	for(n=0;n<len-1;n++,cp++){
		if(isalnum(*cp)||*cp=='_'){
			dst[n]=*cp;continue;
		}
		break;
	}
	dst[n]='\0';
	if(dst[0]=='\0') return false;
	return true;
}

int CGet::getblock(char*src,char *dst,char *endSrc,int len,char start,char end,int skipstart,void * *out)
{
	int n=0;

	if(endSrc){// get to start point
		for(;*src!=start&&src<endSrc;src++);//if end point exist use end
		if(src >= endSrc) return 0; //check if or not find
	}
	else{
			for(;*src!=start&&*src!='\0';src++);//if end point not exist use '\0' end 
			if(*src=='\0') return 0;//check if or not find
	}
	if(*src!=start) return 0;//can not find start char

	src++;//skip start char.

	if(endSrc){
		for(;n<len-1&&*src!=end&&src<endSrc;n++,src++){
			dst[n]=*src;
		}
	}else{
		for(;n<len-1&&*src!=end&&*src!='\0';n++,src++){
			dst[n]=*src;
		}
	}

	dst[n]=0;//0 end
	//printf("CGet::getblock=%s\n",dst);//test ok

    if(out&&n) *out =(void *)src;
	return n;//return count
}

int CGet::getblock(char*src,char *dst,char* end,int len)
{
		int n=0;
		for(;n<len-1&&src<end;src++,n++) 	dst[n]=*src;//copy data
		dst[n]=0;//0 end
		return n;
}

char * CGet::getComment(char*start,char *end,char *e)
{
	int i;
	for(;start<end;start++){
		if(*start=='/'&&(*(start+1)=='*'||*(start+1)=='/')) break;
		
		for(i=0;e[i]!='\0';i++){
			if(*start==e[i]) break;
		}

		if(e[i]!='\0') return 0;
	}
	return start;
}

void CGet::display()
{
	printf("%s\n",this->buf);
}
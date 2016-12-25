//**********************************************************************
//**                                                                  **
//**        (C)Copyright Prophet Hunter_Chen   2015-10                **
//**                                                                  **
//**              All Rights Reserved.                                **
//**                                                                  **
//**********************************************************************

#include "parseini.h"

#if PARSEINI_TEST
int main(int argc,char *argv[])
{
	Cparseini ini;
	ini.parse("op.ini");

	//ini.travelH(ini.head); //test
	printf("count=%d\n",ini.count);//test

	Ciniformat* i=ini.find("szzs30",kdj,min30,parse_action);
	if(i) i->display();

	return 0;
}
#endif

void Ciniformat::init()
{
	int n=0;
	for(;n<TOKEN_LEN;n++)	this->name[n]=0;
	this->action=-1;
	this->value_count=0;
	this->next=0;
}

Ciniformat::Ciniformat()
{
	this->init();
}

Cparseini::Cparseini()
{
	this->head=0;
	this->tail=0;
	this->current=0;
	this->next=0;
}

Cparseini::~Cparseini()
{
	this->freeH(this->head);
}

void Ciniformat::display()
{
	this->output();
}
void Ciniformat::output()
{
	if(!this->name[0]) return ;

	printf("(%s,",this->name);
	switch(this->norm)
	{
	case boll:
			printf("boll,");
		break;
	case macd:
			printf("macd,");
		break;
	case kdj:
			printf("kdj,");
		break;
	case cci:
			printf("cci,");
		break;
	case rsi:
			printf("rsi,");
		break;
	case dma:
			printf("dma,");
		break;
	case roc:
			printf("roc,");
	case vol:
			printf("vol,");
		break;
	case ma:
			printf("ma,");
		break;
	case wr:
			printf("wr,");
		break;
	case cr:
			printf("cr,");
		break;
	case vr:
			printf("vr,");
		break;
	default:
		break;
	}

	switch(this->period)
	{
	case all_period:
			printf("all,");
		break;
	case year:
			printf("year,");
		break;
	case month:
			printf("month,");
		break;
	case week:
			printf("week,");
		break;
	case day:
			printf("day,");
		break;
	case hour4:
			printf("hour4,");
		break;
	case hour1:
			printf("hour1,");
		break;
	case min45:
			printf("min45,");
	case min30:
			printf("min30,");
		break;
	case min15:
			printf("min15,");
		break;
	case min10:
			printf("min10,");
		break;
	case min5:
			printf("min5,");
		break;
	default:
		break;
	}

	switch(this->action)
	{
	case all_action:
			printf("all");
		break;
	case setting_action:
			printf("setting");
		break;
	case parse_action:
			printf("parse");
		break;
	default:
		break;
	}

	for(int n=0;n<this->value_count;n++)	printf(",%0.2f",this->value[n]);
	printf(")\n");
	
}

void Cparseini::freeH(Ciniformat *head)
{
	Ciniformat *f;
	if(!head)	return ;
	for(;head;)
	{
		f=head;
		head=head->next;
		free(f);
	}
}

void Cparseini::travelH(Ciniformat *head)
{
	Ciniformat *f;
	for(;head;)
	{
		f=head;
		head=head->next;
		f->display();
	}
}

Ciniformat *Cparseini::find(char * name,int	 norm,int period,int action)
{
	Ciniformat *p;
	for(p=this->head;p;)
	{
		if(p->norm==norm&&(p->action==action||p->action==all_action||action==all_action)&&(p->period==all_period||p->period==period))
		{
			if(strcmp(p->name,name)==0)	return p;//check name == ?
		}
		p=p->next;
	}
	return 0;
}

/*
enum Period{all,year,month,week,day,
	hour4,//4h/H H4 hour4,hour4
	hour1,//1h/H H/h1 hour1 hour1
	min45,//45m/M min45 MIN45
	min30,//30m/M M/m30 min30 min30
	min15,//15m/M min15 MIN15
	min10,//10m/M min10 MIN10
	min5,//min5 Min5
};
*/
int Cparseini::period(char *cp)
{
	//printf("period->cp=%s\n",cp); //test ok
	switch(*cp)
	{
	case 'A'://all
	case 'a':
		return all_period;
	case 'y'://year
	case 'Y':
		return year;
	case 'm'://month
	case 'M':
		if(cp[1]=='3'||cp[3]=='3')	return min30;
		if(cp[1]=='4'||cp[3]=='4')	return min45;
		if(cp[1]=='1'&&cp[2]=='5'||cp[3]=='1'&&cp[4]=='5')	return min15;
		if(cp[1]=='1'&&cp[2]=='0'||cp[3]=='1'&&cp[4]=='0')	return min10;
		if(cp[1]=='5'||cp[3]=='5')	return min5;
		if(cp[1]=='6'||cp[3]=='6')	return hour1;
		return month;
	case 'w'://week
	case 'W':
		return week;
	case 'd'://day
	case 'D':
		return day;
	case '4'://hour4
		if(cp[1]=='5')	return min45;
		return hour4;
	case '1'://hour1 , min15
	case '6'://hour1 , 60min
		if(cp[0]=='1'&&cp[1]=='5')	return min15;
		if(cp[0]=='1'&&cp[1]=='0')	return min10;
		return hour1;
	case 'h':
	case 'H':
		if(cp[1]=='4'||cp[4]=='4')	return hour4;
		if(cp[1]=='1'||cp[4]=='1')	return hour1;
		break;
	case '3'://min30
		return min30;
	case '5'://wr
		return min5;
	default:
			break;
	}
	printf("error: period:%s\n",cp);
	return -1;
}

int Cparseini::norm(char *cp)
{
	switch(*cp)
	{
	case 'b'://boll
	case 'B':
		if((cp[1]=='o'||cp[1]=='O')&&(cp[2]=='l'||cp[2]=='L')&&(cp[3]=='l'||cp[3]=='L'))	return boll;
		break;
	case 'm'://macd , ma
	case 'M':
		if((cp[1]=='a'||cp[1]=='A')&&(cp[2]=='c'||cp[2]=='C')&&(cp[3]=='d'||cp[3]=='D'))	return macd;
		else{if(cp[1]=='a'||cp[1]=='A') return ma;}
		break;
	case 'k'://kdj
	case 'K':
		if((cp[1]=='d'||cp[1]=='D')&&(cp[2]=='j'||cp[2]=='J'))	return kdj;
		break;
	case 'c'://cci ,cr
	case 'C':
		if((cp[1]=='c'||cp[1]=='C')&&(cp[2]=='i'||cp[2]=='I'))	return cci;
		if((cp[1]=='r'||cp[1]=='R'))		return cr;
		break;
	case 'r'://rsi ,roc
	case 'R':
		if((cp[1]=='s'||cp[1]=='S')&&(cp[2]=='i'||cp[2]=='I'))		return rsi;
		if((cp[1]=='o'||cp[1]=='O')&&(cp[2]=='c'||cp[2]=='C'))	return roc;
		break;
	case 'd'://dma
	case 'D':
		if((cp[1]=='m'||cp[1]=='M')&&(cp[2]=='a'||cp[2]=='A'))		return dma;
		break;
	case 'w'://wr
	case 'W':
		if((cp[1]=='r'||cp[1]=='R'))		return wr;
		break;
	case 'v'://vr vol
	case 'V':
		if((cp[1]=='o'||cp[1]=='O'))		return vol;
		if((cp[1]=='r'||cp[1]=='R'))		return vr;
		break;
	default:
			break;
	}

	return -1;
}

//1. systax: (op object,norm,period,action,value[n] )
int Cparseini::parse(char *cp,Ciniformat *pini) //return pini->value_count
{
	//printf("cp=%s\n",cp);
	for(;*cp==' '||*cp=='\t';cp++);//skip space
	if(cp[0]=='/'&&cp[1]=='/') return 0;//check start comment

	int n=0;
	for(;cp[n]!=0;n++)//skip comment //
	{
		if(cp[n]=='/'&&cp[n+1]=='/')
		{
				cp[n]=0;
				break;
		}
	}

//	printf("cp=%s\n",cp); //test ok

	for(;*cp!='('&&*cp!=0;cp++);
	if(*cp=='(')	cp++;
	if(*cp==0)	return 0;

	//printf("cp=%s\n",cp);//test
	CGet get;
	get.getToken(cp,pini->name,TOKEN_LEN);//get pini->name

	//printf("pini->name=%s\n",pini->name);

	//norm string :	boll=1,macd,kdj,cci,rsi,dma,roc,vol,ma,wr,cr,vr,
	for(;*cp!=','&&*cp!=0;cp++);
	if(*cp==',')	cp++;
	if(*cp==0)	return 0;

	for(;*cp==' '||*cp=='\t';cp++);
	if(*cp==0)	return 0;

	//printf("cp=%s pini->norm=%d\n",cp,pini->norm);//test ok
	pini->norm=this->norm(cp);
	//period :all,year,month,week,day,240min, 60min,min45,min30,min15,min10,min5
	for(;*cp!=','&&*cp!=0;cp++);
	if(*cp==',')	cp++;
	if(*cp==0)	return 0;

	for(;*cp==' '||*cp=='\t';cp++);
	if(*cp==0)	return 0;
	pini->period=this->period(cp);
	//printf("cp=%s pini->period=%d\n",cp,pini->period);//test

//action: all,setting, parse
	for(;*cp!=','&&*cp!=0;cp++);
	if(*cp==',')	cp++;
	if(*cp==0)	return 0;

	for(;*cp==' '||*cp=='\t';cp++);
	if(*cp==0)	return 0;
	//printf("action:cp=%s\n",cp);//test
	switch(*cp)
	{
	case 'a'://all_action
	case 'A':
		pini->action=all_action;
		break;
	case 's'://setting_action
	case 'S':
		pini->action=setting_action;
		break;
	case 'p'://parse_action
	case 'P':
		pini->action=parse_action;
		break;
	default:
			break;
	}

//value[n]: value for current norm setting(xyz ,xxx,xxx,xxx,xx)
	for(;*cp!=','&&*cp!=0;cp++);
	if(*cp==',')	cp++;
	if(*cp==0)	return 1; //for no setting value

	for(;*cp==' '||*cp=='\t';cp++);
	if(*cp==0)	return 1;//for non seting value 
	
	for(n=0;n<VALUE_COUNT;n++)
	{
		pini->value[n]=atof(cp);
		//printf("pini->value[%d]=%0.2f\n",n,pini->value[n]);//test 
		//next value
		for(;*cp!=','&&*cp!=')'&&*cp!=0;cp++);
		if(*cp==',')	cp++;
		//printf("cp=%s\n",cp);//test ok
		if(*cp==0||*cp==')')	break;
	}

	pini->value_count=n+1;
	//printf("pini->value_count=%d\n",pini->value_count);//test
	return pini->value_count;
}

int Cparseini::parse(char *file)
{
//	printf("parseini file=%s\n",file);//test ok
	CAllotMem allot(file);
	CGet get;
	char *src=allot.allot.start;

	if((this->head=(Ciniformat*)malloc(sizeof(Ciniformat)))==NULL){ //will fill zero
		printf("Error:if((this->head=(Ciniformat*)malloc(sizeof(Ciniformat)))==NULL)\n");
		return -1;
	}
	this->head->init();

	this->count=0;
	this->current=this->head;
	for(;src<allot.allot.end&&src;)
	{
		src=get.getLine(src,allot.allot.end);
		if(!this->parse(get.buf,this->current)) continue; //no use current  continue
		this->count++;

		if((this->next=(Ciniformat*)malloc(sizeof(Ciniformat)))==NULL){ //will fill zero
			printf("Error:if((this->next=(Ciniformat*)malloc(sizeof(Ciniformat)))==NULL)\n");
			this->freeH(this->head);
			return -1;
		}

		this->next->init(); //init 
		//set link 
		this->current->next=this->next;
		this->next->before=this->current;
		this->current=this->next;
		this->tail=this->next;
	}
	return this->count;	
}

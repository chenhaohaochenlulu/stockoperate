//**********************************************************************
//**                                                                  **
//**        (C)Copyright Prophet Hunter_Chen   2015-10                **
//**                                                                  **
//**              All Rights Reserved.                                **
//**                                                                  **
//**********************************************************************

#ifndef PARSEINI_H
#define PARSEINI_H
#define PARSEINI_TEST	 0
#include "allotMem/AllotMEM.h"
#include "get/get.h"

#define TOKEN_LEN	50
#define VALUE_COUNT	20

//norm string :	boll=1,macd,kdj,cci,rsi,dma,roc,ma,wr,cr,vr,
enum Norm
{
	boll=1,
	macd,
	kdj,
	cci,
	rsi,
	dma,
	roc,
	vol,
	ma,
	wr,
	cr,
	vr,
};
/*
//period :all,year,month,week,day,4hour, 1hour,min45,30min,15min,5min
enum Period
{
	all_period,//all
	year,
	month,
	week,
	day,
	hour4,//4h/H H4 4hour,hour4
	hour1,//1h/H H/h1 1hour hour1
	min45,//45m/M M/m45 45min min45
	min30,//30m/M M/m30 30min min30
	min15,//15m/M min15 MIN15
	min10,//10m/M min10 MIN10
	min5,//5min Min5
};
*/
//period :all,year,month,week,day,4hour, 1hour,min45,30min,15min,5min
enum Period
{
	none_period,
	all_period=0x7FF,//all
	year=1,
	month=2,
	week=4,
	day=8,
	hour4=0x10,//4h/H H4 4hour,hour4
	hour1=0x20,//1h/H H/h1 1hour hour1
	min45=0x40,//45m/M M/m45 45min min45
	min30=0x800,//30m/M M/m30 30min min30
	min15=0x100,//15m/M min15 MIN15
	min10=0x200,//10m/M min10 MIN10
	min5=0x400,//5min Min5
};

//action: setting, parse
enum Action
{
	all_action,
	setting_action,
	parse_action,
};

class Ciniformat
{
public:
	char	name[TOKEN_LEN];
	int	 norm;
	int period;
	int	action;
	double value[VALUE_COUNT];
	int value_count;//value count
	Ciniformat *before,* next;
public:
	Ciniformat();
	void init();
	void display();
	void output();
};


class Cparseini
{
public:
		Ciniformat *head,*tail,*current,*next;
		int count;// Ciniformat count
public:
	Cparseini();
	~Cparseini();
	void freeH(Ciniformat *head);
	void travelH(Ciniformat *head);
	Ciniformat *find(char * name,int	 norm,int period,int action);
	int period(char *cp);
	int norm(char *cp);
	int parse(char *file);//return item count :this->count ,0:null ,-1 : error
	int parse(char *cp,Ciniformat *pini);//1. systax: (op object,norm,period,action,value[n] )
};

#endif//PARSEINI_H
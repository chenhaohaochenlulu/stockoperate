#ifndef OPERATE_SETTING_H
#define OPERATE_SETTING_H
#include < stdio.h >
#include < stdlib.h >
#include <string.h>

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
//(object,norm,period,action,value[n] )
#define VALUE_LEN	10
class CoperateSetting
{
public:
	int period;
	double value[VALUE_LEN];
public:
	CoperateSetting();
	~CoperateSetting();
	static void set_period(int index,CoperateSetting *p);
	static int add(FILE *fp,char *obj,char * norm,char * period, double *p , int len);
	static int add(FILE *fp,char *obj,char * norm,int period, double *p , int len);
	static int add(char *cpFileName,char *obj,char * norm,int period, double *p , int len);// (object,ma,all,setting)	
};

#endif //OPERATE_SETTING_H

#include "stdafx.h"
#include "operateSetting.h"

CoperateSetting::CoperateSetting()
{
	this->period=none_period;
}


CoperateSetting::~CoperateSetting()
{

}
/*enum Period
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
};*/
//0:ALL 1:Year 2:Month 3:Week 4:Day 5:4Hour 6:1Hour 7:45Min 8:30Min 9:15Min15 10:10Min 11:5Min
 void CoperateSetting::set_period(int index, CoperateSetting *p)
{
			if(p->period==all_period)	return ;
			if(index==-1) return;
			if(index==0)	p->period|=all_period;
			if(index==1)	p->period|=year;
			if(index==2)	p->period|=month;	
			if(index==3)	p->period|=week;
			if(index==4)	p->period|=day;
			if(index==5)	p->period|=hour4;
			if(index==6)	p->period|=hour1;	
			if(index==7)	p->period|=min45;
			if(index==8)	p->period|=min30;
			if(index==9)	p->period|=min15;	
			if(index==10)	p->period|=min10;
			if(index==11)	p->period|=min5;	
}

//1. systax: (object,norm,period,action,value[n] )
 int CoperateSetting::add(FILE *fp,char *obj,char * norm,char * period, double *p , int len)
 {
 		int n;
		fprintf(fp,"(%s,%s,%s,setting",obj,norm,period);	
		
		for(n=0;n<len;n++)
		{
			fprintf(fp,",%0.2f",p[n]);
		}

		fprintf(fp,")\n");
		fflush(fp);
		return 0;
 }
//year,month,week,day,hour4,hour1,min45,min30,min15,min10,min5,
int CoperateSetting::add(FILE *fp,char *obj,char * norm,int period, double *p , int len)
{
	if(period==all_period) return CoperateSetting::add(fp,obj,norm,"all",p,len);
	if(period&year) CoperateSetting::add(fp,obj,norm,"year",p,len);
	if(period&month) CoperateSetting::add(fp,obj,norm,"month",p,len);
	if(period&week) CoperateSetting::add(fp,obj,norm,"week",p,len);
	if(period&day) CoperateSetting::add(fp,obj,norm,"day",p,len);
	if(period&hour4) CoperateSetting::add(fp,obj,norm,"hour4",p,len);
	if(period&hour1) CoperateSetting::add(fp,obj,norm,"hour1",p,len);
	if(period&min45) CoperateSetting::add(fp,obj,norm,"min45",p,len);
	if(period&min30) CoperateSetting::add(fp,obj,norm,"min30",p,len);
	if(period&min15) CoperateSetting::add(fp,obj,norm,"min15",p,len);
	if(period&min10) CoperateSetting::add(fp,obj,norm,"min10",p,len);
	if(period&min5) CoperateSetting::add(fp,obj,norm,"min5",p,len);
	return 0;
}

int CoperateSetting::add(char *cpFileName,char *obj,char * norm,int period, double *p , int len)// (object,ma,all,setting)
{
	FILE *fp;
	if(!(fp=fopen(cpFileName,"a"))){
		printf("Error:can not open the %s file.\n",cpFileName);
		return EOF;
	}
	
	CoperateSetting::add(fp,obj,norm,period,p,len);

	fclose(fp);
	return 0;
}
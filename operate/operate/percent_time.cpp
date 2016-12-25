#include "percent_time.h"

#if PERCENT_TIME_DEBUG
int main(int argc, char* argv[])
{
	CpercentDate pd;
/*
//	pd.display();
	pd.parse();
	printf("percent-time:\t%d/%02d/%02d  week:%d  day:%d\t",pd.gmt->tm_year+1900,pd.gmt->tm_mon+1,pd.gmt->tm_mday,pd.gmt->tm_wday,pd.gmt->tm_yday);
	
	if(pd.buy_sell >0)		printf("[buy+]:");
	if(pd.buy_sell <0)		printf("[sell-]:");
	if(pd.buy_sell==0)	printf("[stop]:");
	printf("%d\tpercent:%d%%\n",pd.buy_sell,pd.per);
*/
	if(argc>1) pd.predict(atol(argv[1]));
	else pd.predict(30);
	//pd.predict(365,2016,1,1,5,1);//test ok //predict(int count,int year,int  mon,int mday,int wday,int yday,int yearEnd=365);
	return 0;
}
#endif //PERCENT_TIME_DEBUG

CpercentDate::CpercentDate()
{
	this->t= time(NULL); 
	this->area = localtime(&this->t); 
	this->gmt = gmtime(&this->t); 
	this->count=0;
	this->per=0;
	this->buy_sell=0;
	this->pre_per=0;
	this->inc_count=0;
	this->inc_per=0;
	this->initPercent();
}

CpercentDate::~CpercentDate()
{

}

void CpercentDate::initPercent()
{
/*
01.January		01-10		0%	(stop/sell)
					10-20		0%	(stop/sell)
					20-end		0->20%(buy +  )*/
	this->add_percent(1,1,20,0,0);
	this->add_percent(1,21,31,20,1);
/*
02.February	01-10		20->50%(buy +  )
					10-20		50->100%(buy +  )
					20-end		100%(buy +  ) */
	this->add_percent(2,1,10,50,1);
	this->add_percent(2,11,20,80,1);
	this->add_percent(2,21,29,100,1);

/*
03.March		01-10		100%
					10-20		100% 
					20-end		100%	*/
	this->add_percent(3,1,31,100,1);

/*
04.April		01-10		100%
					11-20		100%->30% (sell -)
					20-end		30-0% 4/25(must =0%)
*/
		this->add_percent(4,1,10,100,0);
		this->add_percent(4,11,20,30,-1);
		this->add_percent(4,21,30,0,-1);
/*
05.May			01-10		0->30% (buy+ and change blue)
					10-20		30->0% (sell - 5.15 must=0% wednesday)
					20-end		0% */
		this->add_percent(5,1,10,30,2);
		this->add_percent(5,11,20,30,-1);
		this->add_percent(5,21,31,0,0);
/*
 06.June		01-10		0->20%
					10-20		20->0% (6.15 +-  wednesday)
					20-end		0% (6.22 must=0%)*/
		this->add_percent(6,1,10,20,2);
		this->add_percent(6,11,20,0,-1);
		this->add_percent(6,21,31,0,0);
/*
07.July			01-10		0%
					10-20		0%
					20-end		0%*/
		this->add_percent(7,1,31,0,-1);
/*
08.August		01-10		0%
					10-20		0%
					20-end		0->30%*/
		this->add_percent(8,1,25,0,0);
		this->add_percent(8,26,31,30,1);
/*
09.September	01-10	30-100%
						10-20	100%
						20-end	100->0% (9.25 must=%0 wednesday)*/
		this->add_percent(9,1,10,100,1);
		this->add_percent(9,11,20,100,0);
		this->add_percent(9,21,31,0,-1);
/*
10.October		01-10	0->50%
						10-20	50->100%
						20-end	100% */
		this->add_percent(10,1,10,50,1);
		this->add_percent(10,11,20,100,1);
		this->add_percent(10,21,31,100,0);
/*
11.November	01-10	100%
						10-20	100->20% (or 11.15->0% wednesday)
						20-end	20->0% (11.22 must=0%)*/
		this->add_percent(11,1,10,100,0);
		this->add_percent(11,11,20,20,-1);
		this->add_percent(11,21,31,0,0);
/*
12.Devember		01-10	0%
						10-20	0%
						20-end	0%*/
		this->add_percent(12,1,31,0,-1);
}

void CpercentDate::display()
{
	int n;
	printf("%d/%02d/%02d  week:%d  day:%d\n",this->gmt->tm_year+1900,this->gmt->tm_mon+1,this->gmt->tm_mday,this->gmt->tm_wday,this->gmt->tm_yday);
	
	for(n=0;n<this->count;n++)
	{
		printf("month:%02d\t%02d-%02d\t%3d%%\t",this->percent[n].mon,this->percent[n].sday,this->percent[n].eday,this->percent[n].per);
		switch(this->percent[n].buy_sell)
		{
		case -1:		printf("sell\n");
			break;
		case	0:		printf("stop\n");
			break;
		case 1:		printf("buy\n");
			break;
		case 2:		printf("change\n");
			break;
		default:
			printf("operate:%d\n",this->percent[n].buy_sell);
		}
	}
}

int CpercentDate::add_percent(int mon,int sday,int eday,int per,int buy_sell)
{
	if(this->count+1>PERCENT_COUNT)	return -1;
	this->percent[this->count].mon=mon;
	this->percent[this->count].sday=sday;
	this->percent[this->count].eday=eday;
	this->percent[this->count].per=per;
	this->percent[this->count].buy_sell=buy_sell;
	this->count++;
	return 0;
}

int CpercentDate::parse(int year,int mon,int mday,int wday,int yday)
{
	int buy_sell=0,n,mod;
	this->per=0;
	this->inc_count++;

	//printf("year=%d,mon=%d,mday=%d,wday=%d,yday=%d\n",year,mon,mday,wday,yday);//test ok
	if(yday<1*STEP_DAYS||yday>=7*STEP_DAYS||yday>=3*STEP_DAYS&&yday<5*STEP_DAYS)	buy_sell-=2;//1:sell 46days  //7-8 sell //3-4 sell
	if(yday>=1*STEP_DAYS&&yday<3*STEP_DAYS||yday>=5*STEP_DAYS&&yday<7*STEP_DAYS)	buy_sell+=2;//2-3 buy //5-6 buy

	for(n=0;n<this->count;n++)
	{
		if(mon==this->percent[n].mon&&mday>=this->percent[n].sday&&mday<=this->percent[n].eday)
		{
			if(this->percent[n].buy_sell>0)
			{
				buy_sell+=1;	
				if(wday==2)	buy_sell+=1;
			}

			if(this->percent[n].buy_sell<0)
			{
				buy_sell-=1;
			}

			if(mday>=(this->percent[n].sday+(this->percent[n].eday-this->percent[n].sday)/2))
			{
				if(this->percent[n].buy_sell>0) buy_sell+=1;
				if(this->percent[n].buy_sell<0) buy_sell-=1;			
			}

			this->inc_per=this->percent[n].per-this->per;	
			this->per=this->percent[n].per;
			if(this->inc_per!=0) 
			{
				this->inc_per/=this->inc_count;
				this->inc_count=0;
			}

			mod=year%5;
			//printf("mod=%d\n",mod);//test ok

			if(mod<2||mod>3) //year mode
			{
				buy_sell+=1;
				if(this->percent[n].buy_sell>0) buy_sell+=1;	
			}
			else//if(mod>=2&&mod<=3)
			{
				buy_sell-=1;	
				if(this->percent[n].buy_sell<0) buy_sell-=1;
			}

			break;
		}//end if for
	}

	//mday
	if(mday>25)	buy_sell-=1;	

	if(mday>=15&&wday>=4) buy_sell-=1;
	if(mday>=20&&wday>=3) buy_sell-=1;

	//month
	if(mon==1||mon==7||mon==8||mon==12) buy_sell-=1;
	if(mon==2||mon==9) buy_sell+=1;
	if((mon==6||mon==11)&&mday>=20&&wday>=3) buy_sell-=1;
	
	//year
	mod=year%10;
	if(mod<1||mod>8) buy_sell+=1;//year mode

	//printf("CpercentDate:buy_sell=%d per=%d%%\n",buy_sell,per);//test ok
	this->buy_sell=buy_sell;
	return buy_sell;
}

int CpercentDate::parse()
{
	return this->parse(this->gmt->tm_year+1900,this->gmt->tm_mon+1,this->gmt->tm_mday,this->gmt->tm_wday+1,this->gmt->tm_yday);
}

void CpercentDate::display(int year,int mon,int mday,int wday,int yday)
{
	printf("phase[%d]:\t%d/%02d/%02d  week[%02d]:%d  day:%3d\t",(yday/STEP_DAYS)+1,year,mon,mday,yday/7+1,wday,yday);
	if(this->buy_sell >0)		printf("[buy+]:");
	if(this->buy_sell <0)		printf("[sell-]:");
	if(this->buy_sell==0)	printf("[stop]:");
	printf("%d\t%3d%%",this->buy_sell,this->per);//percent
	if(buy_sell==0||buy_sell<-4)	printf("  [warning]");
	printf("\n");
	//printf("this->inc_per=%d,this->per=%d,this->inc_count=%d\n",this->inc_per,this->per,this->inc_count); //test ok
}

int CpercentDate::predict(int count,int year,int  mon,int mday,int wday,int yday,int yearEnd)
{
	int n;
	//printf("year=%d,mon=%d,mday=%d,wday=%d,yday=%d\n",year,mon,mday,wday,yday);//test ok
	for(mday,wday,yday,n=0;n<count;n++,mday++,wday++,yday++) //skip current day.
	{
		if(mon==1||mon==3||mon==5||mon==7||mon==8||mon==10||mon==12){
			if(mday>31)	{mday=1;	mon++;}
		}
		else{
			if(mon==4||mon==6||mon==9||mon==11){
				if(mday>30)	{mday=1;	mon++;}
			}
			else {
				if(mon==2&&((year%4)==0&&(year%100)!=0||year%400==0) ){
					if(mday>29)	{mday=1;mon++;}
					yearEnd=366;
				}
				else{
					if(mday>28)	{mday=1;	mon++;}
					yearEnd=365;
				}
			}
		}
		if(mon>12){mon=1;year++;}

		if(wday>7)	wday=1;
		if(yday>yearEnd)	 yday=1;
		
		if(wday<6)
		{
			//printf("\nyear=%d,mon=%d,mday=%d,wday=%d,yday=%d\n",year,mon,mday,wday,yday);//test ok
			this->parse(year, mon, mday, wday, yday);
			if(wday==1)	printf("\n");
			this->display(year, mon, mday, wday, yday);
		}
	}

	return 0;
}

int CpercentDate::predict(int count)
{
	return this->predict(count,this->gmt->tm_year+1900,this->gmt->tm_mon+1,this->gmt->tm_mday,this->gmt->tm_wday,this->gmt->tm_yday+1);
}
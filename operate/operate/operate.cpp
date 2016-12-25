//**********************************************************************
//**                                                                  **
//**        (C)Copyright Prophet Hunter_Chen   2015-10                **
//**                                                                  **
//**              All Rights Reserved.                                **
//**                                                                  **
//**********************************************************************

// operate.cpp : Defines the entry point for the console application.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "operate.h"

int all_count=0;
double all_bottom[PRICE_COUNT],all_middle[PRICE_COUNT],all_top[PRICE_COUNT];

Crange::Crange()
{
	this->reset();
}

void Crange::set_all_bmt(double low,double mid,double upper) //set bottom middle top 
{
	if(all_count<PRICE_COUNT)
	all_bottom[all_count]=low;
	all_middle[all_count]=mid;
	all_top[all_count]=upper;
	all_count++;
}

AV_TYPE Crange::average(AV_TYPE *p,int n) //n:number of p //return 0 is error
{
	int i;//index
	AV_TYPE vol;
	if(n<1) return 0;
	for(vol=0,i=0;i<n;i++) vol+=p[i];
	//printf("vol=%0.2f,n=%d,vol/n=%0.2f\n",vol,n,vol/n);//test ok
	return vol/n;
}

void Crange::reset()
{
	int n=0;
	this->top=100;
	this->bottom=-100;
	this->middle=0;
	this->buy_line=(double)-0.005;
	this->sell_line=(double)1.005;
	this->stop_line=0;
	this->mid_location=0.1;
	this->direction=0;
	this->init_flag=0;
	this->dir_line=0;

	all_count=0;
	for(n=0;n<PRICE_COUNT;n++)
	{
		all_bottom[n]=NO_INIT;
		all_middle[n]=NO_INIT;
		all_top[n]=NO_INIT;
	}
}

void Crange::display()
{
	printf("dir=%d,bottom=%0.2f,top=%0.2f,middle=%0.2f,buy_line=%0.2f,sell_line=%0.2f,\ninit_flag=%d,dir_line=%0.2f.\n",this->direction,this->bottom,this->top,this->middle,this->buy_line,this->sell_line,this->init_flag,this->dir_line);
}

void Crange::display(double * p , int n,char *name)
{
	int i;
	printf("%s",name);
	for(i=0;i<n;i++)
	{
			printf("%0.2f  ",p[i]);
	}
	printf("\n",p[i]);
}

void Crange::set(double top,double middle,double bottom)
{
	this->bottom=bottom;
	this->middle=middle;
	this->top=top;
}

void Crange::set(double buy_line,double sell_line)
{
	this->sell_line=sell_line;
	this->buy_line=buy_line;
}

double Crange::location(double current,double top,double bottom)
{
	return	(current-bottom)/(top-bottom);
}

double Crange::location(double current)
{
	return	(current-this->bottom)/(this->top-this->bottom);
}

double Crange::mid_line(double high,double low)
{
	return (high-low)/2+low;
}

double Crange::buy(double buy_line)//build buy data point
{
	return this->bottom*(1+buy_line);
}

double Crange::sell(double sell_line)//build sell point
{
	return this->top*(1+sell_line);
}


double Crange::buy_mid()
{
	return this->middle-(this->middle-this->bottom)*this->mid_location;
}

double Crange::sell_mid()
{
	return this->middle+(this->top-this->middle)*this->mid_location;
}


Cprice::Cprice()
{
}

void Cprice::reset()
{
	Crange::reset();
}

double Cprice::location()
{
	return Crange::location(this->price);
}

double Cprice::location(double top,double bottom)
{
	return Crange::location(this->price,top,bottom);
}

void Cprice::init(int dir ,double price,double low, double mid, double upper,double buy,double sell)
{
	this->price=price;
	this->direction=dir;
	this->bottom=low;
	this->middle=mid;
	this->top=upper;
	this->buy_line=buy;
	this->sell_line=sell;
	if(all_count==0) this->set_all_bmt(price,price,price);
	this->set_all_bmt(low,mid,upper);

	this->init_flag=1;
}

int Cprice::parse(char *cycle)
{
	int buy_sell=0;
	if(!this->init_flag) return 0;

	if(this->price<this->bottom) buy_sell+=1;
	if(this->price>this->top) buy_sell-=1;
	double loc;
	if(this->direction<0) //down
	{
		if(this->price>this->middle) buy_sell-=1;
		if(this->price>this->top) buy_sell-=1;//twice
		if(this->location()>this->sell_line) buy_sell -=2;
		//top->mid parse
		loc=this->location(this->top,this->middle);
		if(loc>1) buy_sell-=1;
		if(loc<1&&loc>0.5) buy_sell-=1;
		//mid-bottom
		loc=this->location(this->middle,this->bottom);
		if(loc>1.1&&loc<1.2) buy_sell-=1;
		if(loc>0.8&&loc<1)	buy_sell+=1;
	}
	else //up
	{
		if(this->price<this->middle) buy_sell+=1;
		if(this->price<this->bottom) buy_sell+=1;//twice
		if(this->location()<this->buy_line) buy_sell+=2;
		//top->mid parse
		loc=this->location(this->top,this->middle);
		if(loc<0.1&&loc>0) buy_sell+=1;
		//mid-bottom
		loc=this->location(this->middle,this->bottom);
		if(loc<0) buy_sell+=1;
		if(loc>0&&loc<0.1)	buy_sell+=1;
	}

	if(this->price>this->top*(1+0.005)&&this->direction>0)	this->direction=0;
	if(this->price<this->top*(1-0.005)&&this->direction<0)		this->direction=0;

	if(buy_sell >0)  	printf("%s price  parse \t:  buy[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);
	if(buy_sell <0)  	printf("%s price  parse \t: sell[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);
	if(buy_sell == 0)	printf("%s price  parse \t: stop[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);
	return buy_sell;
}

int compare( const void *arg1, const void *arg2 )
{
   /* Compare all of both strings: */
	if(*(double*)arg1>*(double*)arg2) return 1;
	if(*(double*)arg1<*(double*)arg2) return -1;
	if(*(double*)arg1==*(double*)arg2) return 0;
	return 0;
}

int Cprice::parse_all_price(int buy_sell,int direction)
{
	if(!all_count) return 0;
	double avg[3];//average:0 bottom 1 middle 2 top

	qsort( (void *)all_bottom, (size_t)all_count, sizeof( double), compare );
	qsort( (void *)all_middle, (size_t)all_count, sizeof( double), compare );
	qsort( (void *)all_top, (size_t)all_count, sizeof( double), compare );
	
	//Crange::display(all_bottom,all_count,"all_bottom:");//test ok
	//Crange::display(all_bottom,all_count,"all_middle:");//test ok
	//Crange::display(all_bottom,all_count,"all_top:");//test ok

	avg[0]=this->average(all_bottom,all_count);
	avg[1]=this->average(all_middle,all_count);
	avg[2]=this->average(all_top,all_count);

	printf("\n[average]: \tbottom=%0.2f\tmiddle=%0.2f\ttop=%0.2f\n",avg[0],avg[1],avg[2]);

	printf("refer_all:\t");
	if(buy_sell>0&&direction>0)
	{
		printf("buy[1]:%0.2f\tbuy[2]:%0.2f\tclear:%0.2f\n",all_bottom[0],all_middle[0],all_top[all_count-1]);
		printf("refer_average:\tbuy[1]:%0.2f\tbuy[2]:%0.2f\tclear:%0.2f\n",avg[0],avg[1],avg[2]);
	}

	if(buy_sell >0&&direction<0||buy_sell==0&&direction>0||buy_sell>0&&direction==0)
	{
		printf("buy[1]:%0.2f\tclear:%0.2f\n",all_bottom[0],all_middle[0]);
		printf("refer_average:\tbuy[1]:%0.2f\tclear:%0.2f\n",avg[0],avg[1]);
	}

	if(buy_sell<0&&direction<0)
	{
		printf("sell[1]:%0.2f\tsell[2]:%0.2f\tclear:%0.2f\n",all_top[all_count-1],all_middle[all_count-1],all_bottom[0]);
		printf("refer_average:\tsell[1]:%0.2f\tsell[2]:%0.2f\tclear:%0.2f\n",avg[2],avg[1],avg[0]);
	}

	if(buy_sell<0&&direction>0||buy_sell==0&&direction<0||buy_sell<0&&direction==0)
	{
		printf("sell[1]:%0.2f\tclear:%0.2f\n",all_top[all_count-1],all_middle[all_count-1]);
		printf("refer_average:\tsell[1]:%0.2f\tclear:%0.2f\n",avg[2],avg[1]);
	}

	return 0;
}

void Cprice::display(int buy_sell,char *cycle,int dir)
{
	if(!this->init_flag) return;
	int direction;
	
	if(dir!=0)	direction=dir;
	else	direction=this->direction;
	
	if(buy_sell>0)	printf("%s:buy:%d\t",cycle,buy_sell);
	if(buy_sell<0)	printf("%s:sell:%d\t",cycle,buy_sell);	
	if(buy_sell==0)	printf("%s:stop:%d\t",cycle,buy_sell);	

	if(direction>0)
	{
		printf("dir[%d]:buy\t",direction);
		if(buy_sell>=0) printf("buy[1] =%0.2f,buy[2] =%0.2f\tclear:%0.2f\n",this->bottom,this->buy_mid(),this->sell());
		if(buy_sell<0) printf("sell[1]=%0.2f\tclear:%0.2f\n",this->sell(),this->middle);
	}

	if(direction<0)
	{
		printf("dir[%d]:sell\t",direction);
		if(buy_sell<=0) printf("sell[1]=%0.2f,sell[2]=%0.2f\tclear:%0.2f\n",this->top,this->sell_mid(),this->buy());
		if(buy_sell>0) printf("buy[1] =%0.2f\tclear:%0.2f\n",this->buy(),this->middle);
	}

	if(direction==0)	{		
		printf("dir[%d]:sell\t",direction);
		if(buy_sell>0) printf("buy[1] =%0.2f\tclear:%0.2f\n",this->buy(),this->middle);
		if(buy_sell<0) printf("sell[1]=%0.2f\tclear:%0.2f\n",this->sell(),this->middle);
		if(buy_sell==0) 		printf("stop\n");
	}

}

Ctrend::Ctrend()
{
	this->value=0;
	this->cross_line=0.5;
	this->zero_line=0.3;
}

void Ctrend::reset()
{
	Crange::reset();
	Ctrend();
}

void Ctrend::init(int dir,double macd,double dif,double dea,double buy,double sell,double low,double mid,double upper,double cross_line,double zero_line)
{
	this->direction=dir;
	this->value=macd;
	this->buy_line=buy;
	this->sell_line=sell;
	this->bottom=low;
	this->middle=mid;
	this->top=upper;
	this->dif=dif;
	this->dea=dea;
	this->cross_line=cross_line;
	this->zero_line=zero_line;
	
	this->init_flag=1;
}

int Ctrend::parse(char *cycle)
{
	int buy_sell=0;
	if(!this->init_flag) return 0;
	
	if(this->direction>0)
	{
		if(this->value<this->top&&this->value>this->bottom) buy_sell+=1;
		if(this->dif<this->buy_line&&this->dif>this->dea) buy_sell+=1;
		if(this->dea<this->buy_line) buy_sell+=1;
		if(this->dif>this->dea&&fabs(this->dif)>this->cross_line) buy_sell+=1;
		if(fabs(this->value)<this->zero_line) buy_sell+=1;
		if(fabs(this->dif-this->dea)<this->zero_line) buy_sell+=1;
		if(this->dif>this->dea&&this->dif<this->middle&&this->dea<this->middle)	buy_sell+=1;
		
	}
	
	if(this->direction<0)
	{
			if(this->value<this->top&&this->value>this->bottom) buy_sell-=1;
			if(this->dif>this->sell_line&&this->dif<this->dea) buy_sell-=1;
			if(this->dea>this->sell_line) buy_sell-=1;
			if(this->dif<this->dea&&fabs(this->dif)>this->cross_line) buy_sell-=1;
			if(fabs(this->value)<this->zero_line) buy_sell-=1;
			if(fabs(this->dif-this->dea)<this->zero_line) buy_sell-=1;
			if(this->dif<this->dea&&this->dif>this->middle&&this->dea>this->middle)	buy_sell-=1;			
	}

	if(buy_sell >0)  	printf("%s trend parse \t: buy[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);
	if(buy_sell <0)  	printf("%s trend parse \t: sell[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);
	if(buy_sell == 0)	printf("%s trend parse \t: stop[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);

	return buy_sell;
}


Cmessage::Cmessage()
{
	this->bad=0;
	this->good=0;
}

int Cmessage::set(int good,int bad)
{
	this->good=good;
	this->bad=bad;
	return this->good-this->bad;
}

int Cmessage::parse()
{
	return this->good-this->bad;
}

Ckdj::Ckdj()
{
	this->bottom=1;
	this->middle=50;
	this->top=99;
	this->buy_line=2;
	this->sell_line=95;
	this->buy_cross=20;
	this->sell_cross=80;
}

void Ckdj::reset()
{
	Crange::reset();
	Ckdj();
}

void Ckdj::init(int direction,double k,double d,double j,double buy_cross,double sell_cross)
{
	this->k=k;
	this->d=d;
	this->j=j;
	this->direction=direction;
	this->buy_cross=buy_cross;
	this->sell_cross=sell_cross;

	this->init_flag=1;
}

int Ckdj::parse(char *cycle)
{
	int buy_sell=0;
	if(!this->init_flag) return 0;
	
	if(fabs(this->j-this->d)<30)//
	{
		if(this->j<this->bottom) buy_sell+=1;
		if(this->j>this->top) buy_sell-=1;

		if(fabs(this->j-this->k)<20)
		{
			if(this->d>this->middle+20)	buy_sell-=1;
			if(this->d<this->middle-20)	buy_sell+=1;
		}
	}

	if(this->k>this->top||this->k>this->sell_line) buy_sell-=2;
	if(this->d>this->top||this->d>this->sell_line) buy_sell-=2;

	if(this->k<this->bottom||this->k<this->buy_line) buy_sell+=2;
	if(this->d<this->bottom||this->d<this->buy_line) buy_sell+=2;

	if(this->k<this->middle&&this->j<this->middle&&this->d<this->middle&&this->j>this->k&&this->k>this->d) buy_sell+=2; //buy x
	if(this->k>this->middle&&this->j>this->middle&&this->d>this->middle&&this->j<this->k&&this->k<this->d) buy_sell-=2; //sell x
	
	if(this->k<this->buy_cross) buy_sell+=1;
	if(this->d<this->buy_cross) buy_sell+=2;

	if(this->k>this->sell_cross) buy_sell-=1;
	if(this->d>this->sell_cross) buy_sell-=2;

	if(fabs(this->j-this->middle)<10) //40 -60
	{
		if(this->j<this->middle&&this->k>this->middle&&this->d>this->middle&&this->j<this->k&&(fabs(this->j-this->k)>fabs(this->k-this->d))) buy_sell-=1;
		if(this->j>this->middle&&this->k<this->middle&&this->d<this->middle&&this->j>this->k&&(fabs(this->j-this->k)>fabs(this->k-this->d))) buy_sell+=1;
	}

	if(fabs(this->j-this->d)<10)
	{
		if(fabs(this->d-this->buy_cross)<10) buy_sell+=2;
		if(fabs(this->d-this->sell_cross)<10)  buy_sell-=2;
	}
	
	if(this->direction<0)
	{
		if(this->j<this->k||this->j<this->d)
		{
			if(this->j>this->middle)   		buy_sell-=1;
			if(this->d>this->middle+10)		buy_sell-=1;
			if(this->k>this->middle+10)		buy_sell-=1;
		}

		if(this->k>65&&this->d>65&&this->j>65)
		{
			if(this->j-10<this->k)		buy_sell-=1;
			if(this->j-10<this->d)		buy_sell-=1;
			if(this->k-10<this->d)	buy_sell-=1;
		}
	}

	if(this->direction>0)
	{
		if(this->j>this->k||this->j>this->d)
		{
			if(this->j<this->middle)   		buy_sell+=1;
			if(this->d<this->middle-10)		buy_sell+=1;
			if(this->k<this->middle-10)		buy_sell+=1;
		}

		if(this->k<35&&this->d<35&&this->j<35)
		{
			if(this->j+10>this->k)	buy_sell+=1;
			if(this->j+10>this->d)	buy_sell+=1;
			if(this->k+10>this->d)	buy_sell+=1;
		}
	}
	
	if(this->j>this->top&&this->k>(this->middle+25)&&this->direction>0)	this->direction=0;//change direction
	if(this->j<this->bottom&&this->k<(this->middle-25)&&this->direction<0)	this->direction=0;//change direction

	if(buy_sell >0) 	printf("%s kdj parse \t: buy[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);
	if(buy_sell <0) 	printf("%s kdj parse \t: sell[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);
	if(buy_sell == 0)	printf("%s kdj parse \t: stop[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);

	return buy_sell;
}
Cwr::Cwr()
{
	this->bottom=5;
	this->top=95;
	this->middle=50;
	this->buy_line=85;
	this->sell_line=15;
	this->negative=IS_NEG; //negative norm
}

void Cwr::reset()
{
	Crange::reset();
	Cwr();
}

void Cwr::init(int direction,double wr,double wr_long,double bottom,double middle,double top,int negative)
{
	this->wr=wr;
	this->wr_long=wr_long;
	this->direction=direction;
	this->bottom=bottom;
	this->middle=middle;
	this->top=top;
	this->negative=negative;
	this->init_flag=1;
	
}

void Cwr::deal_negative()
{
	double chg;
	this->buy_line=fabs(this->buy_line);
	this->sell_line=fabs(this->sell_line);
	this->middle=fabs(this->middle);

	this->bottom=fabs(this->bottom);
	this->top=fabs(this->top);

	this->wr=fabs(this->wr);
	if(this->wr_long!=UN_INIT)	this->wr_long=fabs(this->wr_long);

	if(this->direction>0)	this->direction=-1;
	if(this->direction<0)	this->direction=1;

	if(this->buy_line<this->sell_line)//chg
	{
		chg=this->buy_line;
		this->buy_line=this->sell_line;
		this->sell_line=chg;
	}

	if(this->top<this->bottom)//chg
	{
		chg=this->top;
		this->top=this->bottom;
		this->bottom=chg;		
	}

}

int Cwr::parse(char * cycle)
{
	int buy_sell=0;
	if(!this->init_flag)	return 0;
	//this->display(); //test
	//printf("this->direction=%d,this->wr=%0.2f,this->wr_long=%0.2f , this->negative=%d\n",this->direction,this->wr,this->wr_long,this->negative);
	if(this->negative>0)//not negative [-100,0]
	{
		this->deal_negative();
	}
	
	if(this->wr<this->buy_line&&this->wr>this->sell_line)
	{
		if(this->direction>0)	buy_sell-=1;//sell
		if(this->direction<0)	buy_sell+=1;//buy
	}

	if(this->wr_long!=UN_INIT&&this->wr_long>this->buy_line&&this->wr_long<this->sell_line)
	{
		if(this->direction>0)	buy_sell-=1;//sell
		if(this->direction<0)	buy_sell+=1;//buy
	}

	if(fabs(this->wr-this->middle)<25)
	{
		if(this->direction>0)	buy_sell-=1;//sell
		if(this->direction<0)	buy_sell+=1;//buy		
	}

	if(this->wr_long!=UN_INIT&&fabs(this->wr_long-this->middle)<20)
	{
		if(this->direction>0)	buy_sell-=1;//sell
		if(this->direction<0)	buy_sell+=1;//buy		
	}
	
	if(this->wr_long!=UN_INIT)//wr x wr_long
	{
		if(this->wr<this->middle&&this->wr_long<this->middle&&this->wr>this->wr_long)	buy_sell-=1;
		if(this->wr>this->middle&&this->wr_long>this->middle&&this->wr<this->wr_long)	buy_sell+=1;
	}

	if(this->wr_long!=UN_INIT)//chage direction
	{
		if(this->wr_long<this->bottom||this->wr_long>this->top)//chage direction
		{
			if(this->direction>0)	this->direction-=1;
			if(this->direction<0)	this->direction+=1;
		}
	}
	else{
		if(this->wr<this->bottom||this->wr>this->top)//chage direction
		{
			if(this->direction>0)	this->direction-=1;
			if(this->direction<0)	this->direction+=1;
		}
	}

	//change direction for total dir 

	if(this->direction>0)	this->direction=-1; //>0 sell
	else if(this->direction<0)	this->direction=1;//<0 buy 

	if(buy_sell >0) 	printf("%s W&R parse \t: buy[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);
	if(buy_sell <0) 	printf("%s W&R parse \t: sell[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);
	if(buy_sell == 0)	printf("%s W&R parse \t: stop[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);	
	
	return buy_sell;
}

Crsi::Crsi()
{
	this->bottom=15;
	this->middle=50;
	this->top=85;
}

void Crsi::reset()
{
	Crange::reset();
	Crsi();
}

void Crsi::init(int direction,double rsi_short,double rsi_middle,double rsi_long,double bottom,double top)
{
	this->direction=direction;
	this->rsi_short=rsi_short;
	this->rsi_middle=rsi_middle;
	this->rsi_long=rsi_long;
	this->bottom=bottom;
	this->top=top;
	this->init_flag=1;
}

int Crsi::parse(char * cycle)
{
	int buy_sell=0;
	if(!this->init_flag)	return 0;
//	this->display();
//	printf("rsi_short=%0.2f,rsi_middle=%0.2f,rsi_long=%0.2f\n",this->rsi_short,this->rsi_middle,this->rsi_long);
	if(this->direction>0)
	{
		if(this->rsi_short<40&&this->rsi_middle<40&&this->rsi_short>this->rsi_middle)	buy_sell+=1;
		if(this->rsi_short>this->rsi_long&&fabs(this->rsi_short-this->rsi_long)>25) buy_sell-=1;
		
		if(this->rsi_short<60&&this->rsi_short>20)
		{
			if(this->rsi_middle>this->rsi_long&&this->rsi_short>this->rsi_middle)	buy_sell+=1;
		}
		if(this->rsi_middle<this->middle-10) buy_sell+=1;
		if(this->rsi_long<this->middle-15) buy_sell+=1;
		if(this->rsi_short<this->middle-10) buy_sell+=1;//40
		if(this->rsi_short<this->middle+15&&this->rsi_short>this->middle+5)  buy_sell+=1;// 55->65

		if(this->rsi_short-this->rsi_long>40) buy_sell-=1;

		if(this->rsi_long<40&&this->rsi_middle<40&&this->rsi_long<40)
		{
				if(this->rsi_short+10>this->rsi_middle)	buy_sell+=1;
				if(this->rsi_short+10>this->rsi_long)	buy_sell+=1;
				if(this->rsi_middle+10>this->rsi_long)	buy_sell+=1;
		}
	}
	
	if(this->direction<0)
	{
		if(this->rsi_short>60&&this->rsi_middle>60&&this->rsi_short<this->rsi_middle)	buy_sell-=1;
		if(this->rsi_short<this->rsi_long&&fabs(this->rsi_short-this->rsi_long)>25) buy_sell+=1;
	
		if(this->rsi_short<60&&this->rsi_short>20)
		{
			if(this->rsi_middle<this->rsi_long&&this->rsi_short<this->rsi_middle)	buy_sell-=1;
		}

		if(this->rsi_middle>this->middle+10) buy_sell-=1;
		if(this->rsi_long>this->middle+10) buy_sell-=1;
		if(this->rsi_short>this->middle+10) buy_sell-=1; //60
		if(this->rsi_short>this->middle-25&&this->rsi_short<this->middle-5) buy_sell-=1; //45->25

		if(this->rsi_short-this->rsi_long<-40) buy_sell+=1;

		if(this->rsi_long>60&&this->rsi_middle>60&&this->rsi_long>60)
		{
			if(this->rsi_short-10<this->rsi_middle)	buy_sell-=1;
			if(this->rsi_short-10<this->rsi_long)	buy_sell-=1;
			if(this->rsi_middle-10<this->rsi_long)	buy_sell-=1;
		}
	}

	if(this->rsi_short>this->top)		buy_sell-=1;
	if(this->rsi_middle>(this->top-10))	
	{
		if(this->direction>0)	this->direction=0;
		buy_sell-=1;
	}

	if(this->rsi_long>(this->top-10))
	{
		if(this->direction>0)	this->direction=0;
		buy_sell-=2;
	}
	
	if(this->rsi_short<this->bottom)		buy_sell+=1;
	if(this->rsi_middle<(this->bottom+10))
	{
		if(this->direction<0)	this->direction=0;
		buy_sell+=1;
	}

	if(this->rsi_long<(this->bottom+10))
	{
		if(this->direction<0)	this->direction=0;
		buy_sell+=2;
	}

	if(buy_sell >0) 	printf("%s RSI parse \t: buy[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);
	if(buy_sell <0) 	printf("%s RSI parse \t: sell[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);
	if(buy_sell == 0)	printf("%s RSI parse \t: stop[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);	
	return buy_sell;	
}

Cvr::Cvr()
{
	this->middle=100;
	this->top=150;
	this->bottom=50;
	this->diff=40;
}

void Cvr::reset()
{
	Crange::reset();
	Cvr();
}

void Cvr::init(int direction,double vr_short,double vr_long,double diff ,double bottom,double middle ,double top)
{
	this->direction=direction;
	this->vr_short=vr_short;
	this->vr_long=vr_long;
	this->diff=diff;	
	this->bottom=bottom;
	this->middle=middle;
	this->top=top;
	this->init_flag=1;
}

int Cvr::parse(char * cycle)
{
	int buy_sell=0;
	if(!this->init_flag)	return 0;

	if(this->vr_long>this->top&&this->vr_short<this->vr_long)   	buy_sell-=2;
	if(this->vr_long<this->bottom&&this->vr_short>this->vr_long)	buy_sell+=2;
	
	if(this->direction>0)
	{
		if(this->vr_long<this->bottom&&this->vr_long<this->middle)	 buy_sell+=1;
		if(this->vr_long>this->bottom&&this->vr_long<this->middle&&this->vr_short>this->vr_long)	buy_sell+=1;
		if(this->vr_long>this->middle&&this->vr_long<this->top&&this->vr_short>this->vr_long)	 buy_sell+=1;
		if(fabs(this->vr_short-this->vr_long)>this->diff)
		{
			if(this->vr_short<this->vr_long)	 buy_sell+=1;
		}
	}
	
	if(this->direction<0)
	{
		if(this->vr_long<this->top&&this->vr_long>this->middle)	 buy_sell-=1;
		if(this->vr_long<this->top&&this->vr_long>this->middle&&this->vr_short<this->vr_long)	 buy_sell-=1;
		if(this->vr_long<this->middle&&this->vr_long>this->bottom&&this->vr_short<this->vr_long)	 buy_sell-=1;
		
		if(fabs(this->vr_short-this->vr_long)>this->diff)
		{
			if(this->vr_short>this->vr_long)	 buy_sell-=1;
		}		
	}
	
	if(this->direction==0)
	{
		if(this->vr_long>this->top)	buy_sell-=1;
		if(this->vr_long<this->bottom)	buy_sell+=1;		
	}

	if(this->vr_long>this->top&&this->vr_short<this->vr_long&&this->direction>0)   	this->direction=0;
	if(this->vr_long<this->bottom&&this->vr_short>this->vr_long&&this->direction<0)	this->direction=0;

	if(buy_sell >0) 	printf("%s vr parse \t: buy[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);
	if(buy_sell <0) 	printf("%s vr parse \t: sell[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);
	if(buy_sell == 0)	printf("%s vr parse \t: stop[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);		
	
	return buy_sell;	
}

Croc::Croc()//hour(+-2) min30(+-1.5,+-3) min15(+-1,+-2)
{
	this->middle=0;
	this->bottom=-3;
	this->top=3;
}

void Croc::reset()
{
	Crange::reset();
	Croc();
}

void Croc::init(int direction,double roc,double roc_ma,double bottom,double top)
{
	this->direction=direction;
	this->roc=roc;
	this->roc_ma=roc_ma;
	this->bottom=bottom;
	this->top=top;
	this->init_flag=1;
}


int Croc::parse(char * cycle)
{
	int buy_sell=0;
	if(!this->init_flag)	return 0;
	
	if(this->direction==0)
	{
		if(this->roc_ma >1) 	buy_sell-=1;
		if(this->roc_ma <-1)	buy_sell+=1;		
	}
	
	if(this->direction>0)
	{
		if(this->roc_ma<this->middle)	buy_sell+=1;
		if(fabs(this->roc_ma-this->middle)<1)	buy_sell+=1;
		if(fabs(this->roc_ma-this->top)<0.2)	buy_sell+=1;
		if(fabs(this->roc-this->roc_ma)>1&&fabs(this->roc_ma)>1)
		{
			if(this->roc>this->roc_ma)	buy_sell-=1;
			if(this->roc<this->roc_ma)	buy_sell+=1;
		}
		if(fabs(this->roc-this->roc_ma)<0.5&&this->roc_ma<this->middle)
		{
			if(this->roc>this->roc_ma)	buy_sell+=2;
		}		
	}
	
	if(this->direction<0)
	{
		if(this->roc_ma>this->middle)	buy_sell-=1;
		if(fabs(this->roc_ma-this->middle)<1)	buy_sell-=1;
		if(fabs(this->roc_ma-this->top)<0.2)	buy_sell-=1;
		if(fabs(this->roc-this->roc_ma)>1&&fabs(this->roc_ma)>1)
		{
			if(this->roc>this->roc_ma)	buy_sell+=1; 
			if(this->roc<this->roc_ma)	buy_sell-=1;
		}
		if(fabs(this->roc-this->roc_ma)<0.4&&this->roc_ma>this->middle)
		{
			if(this->roc>this->roc_ma)	buy_sell-=2;
		}	 
	}

	if(this->roc>this->top&&this->roc<this->roc_ma&&this->direction>0)			this->direction=0;
	if(this->roc<this->bottom&&this->roc>this->roc_ma&&this->direction<0)	this->direction=0;

	if(buy_sell >0) 	printf("%s roc parse \t: buy[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);
	if(buy_sell <0) 	printf("%s roc parse \t: sell[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);
	if(buy_sell == 0)	printf("%s roc parse \t: stop[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);	
	
	return buy_sell;		
}

Ccr::Ccr()
{
	this->bottom=50;
	this->middle=100;
	this->top=150;
	this->diff=30;
}

void Ccr::reset()
{
	Crange::reset();
	Ccr();
}

void Ccr::init(int direction,double cr, double a,double b,double c,double diff,double bottom,double middle,double top) //oil:diff=30, 50,100,150
{
	this->direction=direction;
	this->cr=cr;
	this->a=a;
	this->b=b;
	this->c=c;
	this->diff=diff;
	this->bottom=bottom;
	this->middle=middle;
	this->top=top;
	this->init_flag=1;
}

int Ccr::parse(char * cycle)
{
	int buy_sell=0;
	if(!this->init_flag)	return 0;	
	
	if(fabs(this->a-this->top)<10)  	buy_sell-=1;
	if(fabs(this->b-this->top)<10)  	buy_sell-=2;
	if(fabs(this->c-this->top)<10)  	buy_sell-=3;
	
	if(fabs(this->a-this->bottom)<10)	buy_sell-=1;
	if(fabs(this->b-this->bottom)<10)	buy_sell-=2;
	if(fabs(this->c-this->bottom)<10)	buy_sell-=3;	
	
	if(this->direction>0)
	{
		if(this->a<this->middle&&this->b<this->middle&&this->cr>this->a&&this->a>this->b)	buy_sell+=1;//a,b <mid &&cr>a>b
		if(this->a<this->top&&this->b<this->middle&&fabs(this->cr-this->a)<20)	buy_sell+=1;		
		if(this->cr>top&&this->a>this->middle&&this->b>this->middle&&fabs(this->cr-this->a)>this->diff&&this->cr>this->a)	buy_sell-=1;//a,b <mid &&cr>a>b
	}
	
	if(this->direction<0)
	{
		if(this->a>this->middle&&this->b>this->middle&&this->cr<this->a&&this->a<this->b)	buy_sell-=1;//a,b <mid &&cr>a>b	
		if(this->cr>this->bottom&&fabs(this->cr-this->bottom)>10&&this->b>this->middle&&fabs(this->cr-this->a)<20)	buy_sell-=1;		
		if(fabs(this->cr-this->bottom)<5&&this->a<this->middle&&this->b<this->middle&&fabs(this->cr-this->a)>this->diff&&this->cr<this->a)	buy_sell+=1;//a,b <mid &&cr>a>b
	}
	
	if(this->direction==0)
	{
		if(fabs(this->top-this->a)<20&&this->a>this->b&&this->a>this->middle&&this->b>this->middle)	buy_sell-=1;
		if((this->bottom-this->a)<20&&this->a<this->b&&this->a<this->middle&&this->b<this->middle)	buy_sell+=1;		
	}
	
	if(buy_sell >0) 	printf("%s cr parse \t: buy[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);
	if(buy_sell <0) 	printf("%s cr parse \t: sell[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);
	if(buy_sell == 0)	printf("%s cr parse \t: stop[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);	
	
	return buy_sell;		
}

Cdma::Cdma()
{

}

void Cdma::reset()
{
	Crange::reset();
	Cdma();
}

void Cdma::init(int direction,double dma,double ama,double bottom,double middle,double top,double dir_line)
{
	this->direction=direction;
	this->dma=dma;
	this->ama=ama;
	this->bottom=bottom;
	this->middle=middle;
	this->top=top;
	this->dir_line=dir_line;
	this->init_flag=1;
}

int Cdma::parse(char * cycle)
{
	int buy_sell=0;
	if(!this->init_flag)	return 0;	
	
	if(this->direction>0)
	{
		if(this->ama<this->middle&&fabs(this->ama)>this->dir_line&&this->dma>this->ama)	buy_sell+=1;
	}
	
	if(this->direction<0)
	{
		if(this->ama>this->middle&&fabs(this->ama)>this->dir_line&&this->dma<this->ama)	buy_sell-=1;
	}

	if(this->dma>this->ama&&this->ama<this->bottom&&fabs(this->ama)>this->dir_line)
	{
		if(this->direction<0)	this->direction=0;		//change direction
		buy_sell+=2;
	}

	if(this->dma<this->ama&&this->ama>this->top&&fabs(this->ama)>this->dir_line)	 
	{
		if(this->direction>0)	this->direction=0;		//change direction
		buy_sell-=2;
	}

	if(buy_sell >0) 	printf("%s dma parse \t: buy[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);
	if(buy_sell <0) 	printf("%s dma parse \t: sell[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);
	if(buy_sell == 0)	printf("%s dma parse \t: stop[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);	
	
	return buy_sell;		
}

Ccci::Ccci()
{
}

void Ccci::reset()
{
	Crange::reset();
	Ccci();
}

void Ccci::init(int direction, double cci, double bottom, double middle, double top, double dir_line)
{
	
	this->direction=direction;
	this->cci=cci;
	this->bottom=bottom;
	this->middle=middle;
	this->top=top;
	this->dir_line=dir_line;
	this->init_flag=1;
}

int Ccci::parse(char * cycle)
{
	int buy_sell=0;
	if(!this->init_flag)	return 0;	
	
	if(this->direction>0)
	{
		if(fabs(this->cci)>this->dir_line&&this->cci<this->middle)		buy_sell+=1;
		if(this->cci<this->bottom)	buy_sell+=1;
		if(this->cci<this->middle)	buy_sell+=1; 
		if(this->cci>this->middle&&this->cci<this->middle+15)		buy_sell+=1; 
		if(this->cci<this->middle&&this->cci<this->middle-25)		buy_sell+=1; 
	}
	
	if(this->direction<0)
	{
		if(fabs(this->cci)>this->dir_line&&this->cci>this->middle)		buy_sell+=1;
		if(this->cci>this->top)	buy_sell-=1;
		if(this->cci>this->middle)	buy_sell-=1; 
		if(this->cci<this->middle&&this->cci>this->middle-15)		buy_sell-=1; 
		if(this->cci>this->middle&&this->cci>this->middle+25)		buy_sell-=1; 

	}

	if(buy_sell >0) 	printf("%s cci parse \t: buy[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);
	if(buy_sell <0) 	printf("%s cci parse \t: sell[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);
	if(buy_sell == 0)	printf("%s cci parse \t: stop[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);	
	
	return buy_sell;		
}

Cma::Cma()
{
	int n;
	for(n=0;n<CYCLE_COUNT;n++)
	{
		this->ma[n]=UN_INIT;
		this->ma_dir[n]=0;
	}
	this->direction=0;
	this->count=0;
	this->price=0;
}

void Cma::reset()
{
	Crange::reset();
	Cma();
}

void Cma::init(double * p,int count)//p[0]=ma dir ,p[1]=ma ...
{
	int n,i,j;
	//printf("Cma::init(double * p,int count)\n"); //testok
	double buf[5];
	if(count%2==1) 
	{
		count-=1;
		this->price=p[count];
	}
	else{
		if(this->price==0){
			printf("error :Cma::init no price init. \n");
			return ;
		}
	}
	//printf("this->price=%0.2f\n",this->price); //test ok
	if(count <2)	return ;

	for(n=0,i=0,j=0;n<count&&i<CYCLE_COUNT;n+=2,i++)
	{
		this->ma_dir[i]=(int)p[n];
		this->ma[i]=p[n+1];

		if(i<5){ //shore to buf for set_all_bmt
			buf[i]=this->ma[i];
			j++;
		}
	}

	if(j>2)
	{
		qsort( (void *)buf, (size_t)j, sizeof( double), compare );
		if(j>4){
			this->set_all_bmt(buf[0],this->average(&buf[1],3),buf[4]);
		}
		else{
			if(j>3){
				this->set_all_bmt(buf[0],this->average(&buf[1],2),buf[3]);
			}			
			else{
				if(j>2) this->set_all_bmt(buf[0],buf[1],buf[2]);
			}
		}
	}

	this->init_flag=1;
	this->count=i;
}

int Cma::parse(char * cycle)
{
	int n,buy_sell=0;
	double percent;
	if(!this->init_flag||!this->count)	return 0;	//enable parse should set this value !=0 
	
	for(n=0;n<this->count;n++)//calculate direction
	{
		this->direction+=this->ma_dir[n];
	}
	if(this->direction>0) this->direction=1;
	if(this->direction<0) this->direction=-1;
	//ma[0]
	if(this->count<1)		goto MA_EXIT;

	percent=fabs(this->price-this->ma[0])/fabs(this->ma[0]);
	if(percent<MA_DIFF_PERCENT) 
	{
			if(this->ma_dir[0]>0) buy_sell+=1;
			if(this->ma_dir[0]<0) buy_sell-=1;
	}

	if(percent>0.1)	//>10%
	{
		if(this->price>this->ma[1])		buy_sell-=1;
		if(this->price<this->ma[1])		buy_sell+=1;
	}

	//ma[0] ma[1]
	if(!(this->count>1))		goto MA_EXIT;

	percent=fabs(this->ma[0]-this->ma[1])/fabs(this->ma[1]);
	if(percent<MA_DIFF_PERCENT)
	{
		if(this->ma[0]>=this->ma[1])//buy  x
		{
			if(this->ma_dir[0]>0)	buy_sell+=1;
			if(this->ma_dir[1]>0)buy_sell+=1;
		}

		if(this->ma[0]<this->ma[1])//sell x
		{
			if(this->ma_dir[0]<0)	buy_sell-=1;
			if(this->ma_dir[1]<0)buy_sell-=1;
		}
	}

	percent=fabs(this->price-this->ma[1])/fabs(this->ma[1]);
	if(percent<MA_DIFF_PERCENT)
	{
		if(this->ma_dir[0]>0&&this->ma_dir[1]>0)//price down to ma1 
		{
			if(this->price>this->ma[1])	buy_sell+=1;
		}

		if(this->ma_dir[0]<0&&this->ma_dir[1]<0) //price up to ma1
		{
			if(this->price<this->ma[1])	buy_sell-=1;
		}
	}

	if(percent>0.20)	//>20%
	{
		if(this->price>this->ma[1])		buy_sell-=1;
		if(this->price<this->ma[1])		buy_sell+=1;
	}

	//ma[0] ma[1] ma[2] 
	if(!(this->count>2))		goto MA_EXIT;

	percent=fabs(this->ma[1]-this->ma[2])/fabs(this->ma[2]);
	if(percent<MA_DIFF_PERCENT)
	{
		if(this->ma[1]>=this->ma[2])//buy  x
		{
			if(this->ma_dir[1]>0)	buy_sell+=1;
			if(this->ma_dir[2]>0)buy_sell+=1;
		}

		if(this->ma[1]<this->ma[2])//sell x
		{
			if(this->ma_dir[1]<0)	buy_sell-=1;
			if(this->ma_dir[2]<0)buy_sell-=1;
		}
	}

	percent=fabs(this->price-this->ma[2])/fabs(this->ma[2]);
	if(percent<MA_DIFF_PERCENT)
	{
		if(this->ma_dir[2]>0)
		{
			if(this->price>this->ma[2])	buy_sell+=1;
		}

		if(this->ma_dir[2]<0)
		{
			if(this->price<this->ma[2])	buy_sell-=1;
		}
	}

	if(percent>0.25)	//>25%
	{
		if(this->price>this->ma[2])		buy_sell-=1;
		if(this->price<this->ma[2])		buy_sell+=1;
	}

	if(percent<0.03)//3%
	{
		if(this->ma_dir[1]>0&&this->ma_dir[2]>0&&this->ma_dir[0]>0)		buy_sell+=1;
		if(this->ma_dir[1]<0&&this->ma_dir[2]<0&&this->ma_dir[0]<0)		buy_sell-=1;
	}

	//ma[0] ma[1] ma[2]  ma[3]
	if(!(this->count>3))		goto MA_EXIT;

	percent=fabs(this->ma[2]-this->ma[3])/fabs(this->ma[3]);
	if(percent<MA_DIFF_PERCENT)
	{
		if(this->ma[2]>=this->ma[3])//buy  x
		{
			if(this->ma_dir[2]>0)	buy_sell+=1;
			if(this->ma_dir[3]>0)buy_sell+=1;
		}

		if(this->ma[2]<this->ma[3])//sell x
		{
			if(this->ma_dir[2]<0)	buy_sell-=1;
			if(this->ma_dir[3]<0)buy_sell-=1;
		}
	}

	percent=fabs(this->price-this->ma[3])/fabs(this->ma[3]);
	if(this->ma_dir[3]>0)
	{
		if(this->price>this->ma[3]&&percent<MA_DIFF_PERCENT)	buy_sell+=1;
		if(this->price<this->ma[3])		buy_sell+=1;
	}

	if(this->ma_dir[3]<0)
	{
		if(this->price<this->ma[3]&&percent<MA_DIFF_PERCENT)	buy_sell-=1;
		if(this->price>this->ma[3])		buy_sell-=1;
	}

	if(percent>0.30)	//>30%
	{
		if(this->price>this->ma[3])		buy_sell-=1;
		if(this->price<this->ma[3])		buy_sell+=1;
	}

	if(percent<0.03)//10%
	{
		if(this->ma_dir[0]>0&&this->ma_dir[1]>0&&this->ma_dir[2]>0&&this->ma_dir[3]>0)		buy_sell+=1;
		if(this->ma_dir[0]<0&&this->ma_dir[1]<0&&this->ma_dir[2]<0&&this->ma_dir[3]<0)		buy_sell-=1;
	}

	//ma[0] ma[1] ma[2]  ma[3]  ma[4]
	if(!(this->count>4))		goto MA_EXIT;

	percent=fabs(this->ma[3]-this->ma[4])/fabs(this->ma[4]);
	if(percent<MA_DIFF_PERCENT)
	{
		if(this->ma[3]>=this->ma[4])//buy  x
		{
			if(this->ma_dir[3]>0)	buy_sell+=1;
			if(this->ma_dir[4]>0)buy_sell+=1;
		}

		if(this->ma[3]<this->ma[4])//sell x
		{
			if(this->ma_dir[3]<0)	buy_sell-=1;
			if(this->ma_dir[4]<0)buy_sell-=1;
		}
	}

	percent=fabs(this->price-this->ma[4])/fabs(this->ma[4]);
	if(this->ma_dir[4]>0)
	{
		if(this->price>this->ma[4]&&percent<MA_DIFF_PERCENT)	buy_sell+=1;
		if(this->price<this->ma[4])		buy_sell+=1;
	}

	if(this->ma_dir[4]<0)
	{
		if(this->price<this->ma[4]&&percent<MA_DIFF_PERCENT)	buy_sell-=1;
		if(this->price>this->ma[4])		buy_sell-=1;
	}

	if(percent>0.40)	//>40%
	{
		if(this->price>this->ma[4])		buy_sell-=1;
		if(this->price<this->ma[4])		buy_sell+=1;
	}

	if(percent<0.05)//5%
	{
		if(this->ma_dir[0]>0&&this->ma_dir[1]>0&&this->ma_dir[2]>0&&this->ma_dir[3]>0&&this->ma_dir[4]>0)		buy_sell+=1;
		if(this->ma_dir[0]<0&&this->ma_dir[1]<0&&this->ma_dir[2]<0&&this->ma_dir[3]<0&&this->ma_dir[4]<0)		buy_sell-=1;
	}

	//ma[0] ma[1] ma[2]  ma[3]  ma[4] ma[5]
	if(!(this->count>5))		goto MA_EXIT;

	percent=fabs(this->ma[4]-this->ma[5])/fabs(this->ma[5]);
	if(percent<MA_DIFF_PERCENT)
	{
		if(this->ma[4]>=this->ma[5])//buy  x
		{
			if(this->ma_dir[4]>0)	buy_sell+=1;
			if(this->ma_dir[5]>0)buy_sell+=1;
		}

		if(this->ma[4]<this->ma[5])//sell x
		{
			if(this->ma_dir[4]<0)	buy_sell-=1;
			if(this->ma_dir[5]<0)buy_sell-=1;
		}
	}

	percent=fabs(this->price-this->ma[5])/fabs(this->ma[5]);
	if(this->ma_dir[5]>0)
	{
		if(this->price>this->ma[5]&&percent<MA_DIFF_PERCENT)	buy_sell+=1;
		if(this->price<this->ma[5])		buy_sell+=1;
	}

	if(this->ma_dir[5]<0)
	{
		if(this->price<this->ma[5]&&percent<MA_DIFF_PERCENT)	buy_sell-=1;
		if(this->price>this->ma[5])		buy_sell-=1;
	}

	if(percent>0.40)	//>40%
	{
		if(this->price>this->ma[5])		buy_sell-=1;
		if(this->price<this->ma[5])		buy_sell+=1;
	}

	if(percent<0.10)//10%
	{
		if(this->ma_dir[0]>0&&this->ma_dir[1]>0&&this->ma_dir[2]>0&&this->ma_dir[3]>0&&this->ma_dir[4]>0&&this->ma_dir[5]>0)		buy_sell+=1;
		if(this->ma_dir[0]<0&&this->ma_dir[1]<0&&this->ma_dir[2]<0&&this->ma_dir[3]<0&&this->ma_dir[4]<0&&this->ma_dir[5]<0)		buy_sell-=1;
	}

	//ma[0] ma[1] ma[2]  ma[3]  ma[4] ma[5] ma[6]
	if(!(this->count>6))		goto MA_EXIT;

	percent=fabs(this->ma[5]-this->ma[6])/fabs(this->ma[6]);
	if(percent<MA_DIFF_PERCENT) //
	{
		if(this->ma[5]>=this->ma[6])//buy  x
		{
			if(this->ma_dir[5]>0)	buy_sell+=1;
			if(this->ma_dir[6]>0)buy_sell+=1;
		}

		if(this->ma[5]<this->ma[6])//sell x
		{
			if(this->ma_dir[5]<0)	buy_sell-=1;
			if(this->ma_dir[6]<0)buy_sell-=1;
		}
	}

	percent=fabs(this->price-this->ma[6])/fabs(this->ma[6]);
	if(this->ma_dir[6]>0)
	{
		if(this->price>this->ma[6]&&percent<MA_DIFF_PERCENT)	buy_sell+=1;
		if(this->price<this->ma[6])		buy_sell+=1;
	}

	if(this->ma_dir[6]<0)
	{
		if(this->price<this->ma[6]&&percent<MA_DIFF_PERCENT)	buy_sell-=1;
		if(this->price>this->ma[6])		buy_sell-=1;
	}

	if(percent>0.50)	//>50%
	{
		if(this->price>this->ma[6])		buy_sell-=1;
		if(this->price<this->ma[6])		buy_sell+=1;
	}

	if(percent<0.10) //10%
	{
		if(this->ma_dir[0]>0&&this->ma_dir[1]>0&&this->ma_dir[2]>0&&this->ma_dir[3]>0&&this->ma_dir[4]>0&&this->ma_dir[5]>0&&this->ma_dir[6]>0)		buy_sell+=1;
		if(this->ma_dir[0]<0&&this->ma_dir[1]<0&&this->ma_dir[2]<0&&this->ma_dir[3]<0&&this->ma_dir[4]<0&&this->ma_dir[5]<0&&this->ma_dir[6]<0)		buy_sell-=1;
	}

MA_EXIT:
	if(buy_sell >0) 	printf("%s MA parse \t: buy[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);
	if(buy_sell <0) 	printf("%s MA parse \t: sell[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);
	if(buy_sell == 0)	printf("%s MA parse \t: stop[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);	
	
	return buy_sell;
}

Cvol::Cvol()
{
	this->vol_short=0;
	this->vol_long=0;
	this->dir_short=0;
	this->dir_long=0;
}

void Cvol::reset()
{
	Crange::reset();
	Cvol();
}

void Cvol::init(int dir_short,double vol_short,int dir_long,double vol_long)
{
	this->dir_long=dir_long;
	this->dir_short=dir_short;
	this->vol_short=vol_short;
	this->vol_long=vol_long;
	this->init_flag=1;
}

int Cvol::parse(char * cycle)
{
	int buy_sell=0;
	if(!this->init_flag)	return 0;	
	if(this->vol_long<=0||this->vol_short<=0)	return 0;

	if(this->dir_short!=this->dir_long)	this->direction=0;
	else this->direction=this->dir_short;

	if(this->vol_short>=this->vol_long)
	{
		if(this->dir_short>0||this->dir_long>0)
		{
			buy_sell+=1;
			this->direction=1;
		}
	}

	if(this->vol_short<this->vol_long)
	{
		if(this->dir_short<0||this->dir_long<0)
		{
			buy_sell-=1;
			this->direction=-1;
		}
	}

	if(buy_sell >0) 	printf("%s VOL parse \t: buy[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);
	if(buy_sell <0) 	printf("%s VOL parse \t: sell[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);
	if(buy_sell == 0)	printf("%s VOL parse \t: stop[%d] \tdir[%d]\n",cycle,buy_sell,this->direction);	
	
	return buy_sell;		
}


Coperate::Coperate()
{
	this->buy_sell_m=0;//month
	this->buy_sell_w=0;//week
	this->buy_sell_d=0;//day
	this->buy_sell_h4=0;//4 hour 
	this->buy_sell_h=0;//hour
	this->buy_sell_m45=0;//min 45
	this->buy_sell_m30=0;//min 30
	this->buy_sell_m15=0;//min 15
	this->buy_sell_m10=0;//min 10
	this->buy_sell_m05=0;//min 05
	this->buy_sell_ma=0;//ma

	this->dir_month=0;//month
	this->dir_week=0;//week
	this->dir_day=0;//day
	this->dir_hour4=0;//4 hour 
	this->dir_hour=0;//hour
	this->dir_m45=0;//min 45
	this->dir_m30=0;//min 30
	this->dir_m15=0;//min 15
	this->dir_m10=0;//min 10
	this->dir_m05=0;//min 05
	this->dir_ma=0;//ma dir
	this->price=0;
	this->enable[0]=0xFFFFFFFF; //enable all (macd,boll,kdj,wr)
	this->enable[1]=0xFFFFFFFF; //enable2 all(rsi)
	this->enable[2]=0xFFFFFFFF; //enable2 all(rsi)
}

void Coperate::reset()
{
	Coperate();
	this->month_price.reset();
	this->month_kdj.reset();
	this->month_trend.reset();
	this->month_wr.reset();
	this->month_rsi.reset();
	this->month_roc.reset();
	this->month_vr.reset();
	this->month_cr.reset();
	this->month_dma.reset();
	this->month_cci.reset();

	this->week_price.reset();
	this->week_kdj.reset();
	this->week_trend.reset();
	this->week_wr.reset();
	this->week_rsi.reset();
	this->week_roc.reset();
	this->week_vr.reset();
	this->week_cr.reset();
	this->week_dma.reset();
	this->week_cci.reset();

	this->day_price.reset();
	this->day_kdj.reset();
	this->day_trend.reset();
	this->day_wr.reset();
	this->day_rsi.reset();
	this->day_roc.reset();
	this->day_vr.reset();
	this->day_cr.reset();
	this->day_dma.reset();
	this->day_cci.reset();

	this->hour4_price.reset();
	this->hour4_kdj.reset();
	this->hour4_trend.reset();
	this->hour4_wr.reset();
	this->hour4_rsi.reset();
	this->hour4_roc.reset();
	this->hour4_vr.reset();
	this->hour4_cr.reset();
	this->hour4_dma.reset();
	this->hour4_cci.reset();

	this->hour_price.reset();
	this->hour_kdj.reset();
	this->hour_trend.reset();
	this->hour_wr.reset();
	this->hour_rsi.reset();
	this->hour_roc.reset();
	this->hour_vr.reset();
	this->hour_cr.reset();
	this->hour_dma.reset();
	this->hour_cci.reset();

	this->m45_price.reset();
	this->m45_kdj.reset();
	this->m45_trend.reset();
	this->m45_wr.reset();
	this->m45_rsi.reset();
	this->m45_roc.reset();
	this->m45_vr.reset();
	this->m45_cr.reset();
	this->m45_dma.reset();
	this->m45_cci.reset();

	this->m30_price.reset();
	this->m30_kdj.reset();
	this->m30_trend.reset();
	this->m30_wr.reset();
	this->m30_rsi.reset();
	this->m30_roc.reset();
	this->m30_vr.reset();
	this->m30_cr.reset();
	this->m30_dma.reset();
	this->m30_cci.reset();

	this->m15_price.reset();
	this->m15_kdj.reset();
	this->m15_trend.reset();
	this->m15_wr.reset();
	this->m15_rsi.reset();
	this->m15_roc.reset();
	this->m15_vr.reset();
	this->m15_cr.reset();
	this->m15_dma.reset();
	this->m15_cci.reset();

	this->m10_price.reset();
	this->m10_kdj.reset();
	this->m10_trend.reset();
	this->m10_wr.reset();
	this->m10_rsi.reset();
	this->m10_roc.reset();
	this->m10_vr.reset();
	this->m10_cr.reset();
	this->m10_dma.reset();
	this->m10_cci.reset();

	this->m05_price.reset();
	this->m05_kdj.reset();
	this->m05_trend.reset();
	this->m05_wr.reset();
	this->m05_rsi.reset();
	this->m05_roc.reset();
	this->m05_vr.reset();
	this->m05_cr.reset();
	this->m05_dma.reset();
	this->m05_cci.reset();

	this->ma_cycle1.reset();
	this->ma_cycle2.reset();
	this->ma_cycle3.reset();
	this->ma_cycle4.reset();
	this->ma_cycle5.reset();
	this->ma_cycle6.reset();
	this->ma_cycle7.reset();
	this->ma_cycle8.reset();
	this->ma_cycle9.reset();
	this->ma_cycle10.reset();
	this->ma_cycle11.reset();
}

int Coperate::all_direction()
{
	this->dir_month=	this->month_price.direction+this->month_kdj.direction+this->month_trend.direction+this->month_wr.direction+\
								this->month_rsi.direction+this->month_roc.direction+this->month_vr.direction+this->month_cr.direction+\
								this->month_dma.direction+this->month_cci.direction+this->month_vol.direction;
	this->dir_week=	this->week_price.direction+this->week_kdj.direction+this->week_trend.direction+this->week_wr.direction+\
								this->week_rsi.direction+this->week_roc.direction+this->week_vr.direction+this->week_cr.direction+\
								this->week_dma.direction+this->week_cci.direction+this->week_vol.direction;
	this->dir_day=		this->day_price.direction+this->day_kdj.direction+this->day_trend.direction+this->day_wr.direction+\
								this->day_rsi.direction+this->day_roc.direction+this->day_vr.direction+this->day_cr.direction+\
								this->day_dma.direction+this->day_cci.direction+this->day_vol.direction;
	this->dir_hour4=	this->hour4_price.direction+this->hour4_kdj.direction+this->hour4_trend.direction+this->hour4_wr.direction+\
								this->hour4_rsi.direction+this->hour4_roc.direction+this->hour4_vr.direction+this->hour4_cr.direction+\
								this->hour4_dma.direction+this->hour4_cci.direction+this->hour4_vol.direction;
	this->dir_hour=		this->hour_price.direction+this->hour_kdj.direction+this->hour_trend.direction+this->hour_wr.direction+\
								this->hour_rsi.direction+this->hour_roc.direction+this->hour_vr.direction+this->hour_cr.direction+\
								this->hour_dma.direction+this->hour_cci.direction+this->hour_vol.direction;
	this->dir_m45=		this->m45_price.direction+this->m45_kdj.direction+this->m45_trend.direction+this->m45_wr.direction+\
								this->m45_rsi.direction+this->m45_roc.direction+this->m45_vr.direction+this->m45_cr.direction+\
								this->m45_dma.direction+this->m45_cci.direction+this->m45_vol.direction;
	this->dir_m30=		this->m30_price.direction+this->m30_kdj.direction+this->m30_trend.direction+this->m30_wr.direction+\
								this->m30_rsi.direction+this->m30_roc.direction+this->m30_vr.direction+this->m30_cr.direction+\
								this->m30_dma.direction+this->m30_cci.direction+this->m30_vol.direction;
	this->dir_m15=		this->m15_price.direction+this->m15_kdj.direction+this->m15_trend.direction+this->m15_wr.direction+\
								this->m15_rsi.direction+this->m15_roc.direction+this->m15_vr.direction+this->m15_cr.direction+\
								this->m15_dma.direction+this->m15_cci.direction+this->m15_vol.direction;
	this->dir_m10=		this->m10_price.direction+this->m10_kdj.direction+this->m10_trend.direction+this->m10_wr.direction+\
								this->m10_rsi.direction+this->m10_roc.direction+this->m10_vr.direction+this->m10_cr.direction+\
								this->m10_dma.direction+this->m10_cci.direction+this->m10_vol.direction;
	this->dir_m05=		this->m05_price.direction+this->m05_kdj.direction+this->m05_trend.direction+this->m05_wr.direction+\
								this->m05_rsi.direction+this->m05_roc.direction+this->m05_vr.direction+this->m05_cr.direction+\
								this->m05_dma.direction+this->m05_cci.direction+this->m05_vol.direction;

	this->dir_ma=this->ma_cycle1.direction+this->ma_cycle2.direction+this->ma_cycle3.direction+this->ma_cycle4.direction+\
						 this->ma_cycle5.direction+this->ma_cycle6.direction+this->ma_cycle7.direction+this->ma_cycle8.direction+this->ma_cycle9.direction+\
						 this->ma_cycle10.direction+this->ma_cycle11.direction;

	this->direction=this->dir_month+this->dir_week+this->dir_day+this->dir_hour4+this->dir_hour+this->dir_m45+this->dir_m30+this->dir_m15+this->dir_m10+this->dir_m05+this->dir_ma;
	return	this->direction;
}

void Coperate::display()
{
	printf("\n[result_report]:\n");
	if(this->direction >0 ) printf("direction = %d buy\n",this->direction);
	if(this->direction <0 ) printf("direction = %d sell\n",this->direction);
	if(this->direction==0) printf("direction = %d stop\n",this->direction);

	if(this->direction >0&&this->buy_sell<0)	printf("warning:[stop] direction=buy ,buy_sell=sell\n");
	if(this->direction <0&&this->buy_sell>0)	printf("warning:[stop] direction=sell ,buy_sell=buy\n");	

	if(this->buy_sell >0) printf("buy_sell  = %d buy\n\n",this->buy_sell);
	if(this->buy_sell <0) printf("buy_sell  = %d sell\n\n",this->buy_sell);
	if(this->buy_sell==0) printf("buy_sell  = %d stop\n\n",this->buy_sell);

	if( (this->enable[0]&MONTH_CYCLE_EN) || (this->enable[1]&MONTH_CYCLE_EN2) ||(this->enable[2]&MONTH_CYCLE_EN3) )	
	{
		this->month_price.display(this->buy_sell_m,"month1",this->dir_month);
	}

	if( (this->enable[0]&WEEK_CYCLE_EN) || (this->enable[1]&WEEK_CYCLE_EN2) || (this->enable[2]&WEEK_CYCLE_EN3) ) 	
	{
		this->week_price.display(this->buy_sell_w,"week01",this->dir_week);
	}
	
	if((this->enable[0]&DAY_CYCLE_EN)  || (this->enable[1]&DAY_CYCLE_EN2) || (this->enable[2]&DAY_CYCLE_EN3) )  	
	{
		this->day_price.display(this->buy_sell_d,"day 01",this->dir_day);
	}

	if( (this->enable[0]&HOUR_CYCLE_EN) || (this->enable[1]&HOUR_CYCLE_EN2) || (this->enable[2]&HOUR_CYCLE_EN3) ) 	//4 hour use hour enable
	{
		this->hour4_price.display(this->buy_sell_h4,"hour04",this->dir_hour4);
	}
	
	if( (this->enable[0]&HOUR_CYCLE_EN) || (this->enable[1]&HOUR_CYCLE_EN2) || (this->enable[2]&HOUR_CYCLE_EN3) ) 	
	{
		this->hour_price.display(this->buy_sell_h,"hour01",this->dir_hour);
	}

	if( (this->enable[0]&M30_CYCLE_EN)  ||(this->enable[1]&M30_CYCLE_EN2) || (this->enable[2]&M30_CYCLE_EN3) )  //min 45  use min 30 enable
	{
		this->m45_price.display(this->buy_sell_m45,"min 45",this->dir_m45);
	}

	if( (this->enable[0]&M30_CYCLE_EN)  ||(this->enable[1]&M30_CYCLE_EN2) || (this->enable[2]&M30_CYCLE_EN3) )  	
	{
		this->m30_price.display(this->buy_sell_m30,"min 30",this->dir_m30);
	}
	
	if( (this->enable[0]&M15_CYCLE_EN)  ||(this->enable[1]&M15_CYCLE_EN2) || (this->enable[2]&M15_CYCLE_EN3) )
	{
		this->m15_price.display(this->buy_sell_m15,"min 15",this->dir_m15);
	}
	
	if( (this->enable[0]&M10_CYCLE_EN)  || (this->enable[1]&M10_CYCLE_EN2) || (this->enable[2]&M10_CYCLE_EN3) )
	{
		this->m10_price.display(this->buy_sell_m10,"min 10",this->dir_m10);
	}
	
	if( (this->enable[0]&M05_CYCLE_EN) || (this->enable[1]&M05_CYCLE_EN2) || (this->enable[2]&M05_CYCLE_EN3) )
	{
		this->m05_price.display(this->buy_sell_m05,"min 05",this->dir_m05);
	}
	
}

int Coperate::parse() //stop ,buy,sell
{
	this->buy_sell=0;

	//boll
	if(this->m05_price.init_flag||this->m10_price.init_flag||this->m15_price.init_flag||this->m30_price.init_flag||this->m45_price.init_flag||\
		this->hour_price.init_flag||this->hour4_price.init_flag||this->day_price.init_flag||this->week_price.init_flag||this->month_price.init_flag)
	{
		printf("\nprice.parse:\n");
	}
	if(this->enable[0]&M05_PRICE_EN)	this->buy_sell_m05+=this->m05_price.parse("05 min ");
	if(this->enable[0]&M10_PRICE_EN)	this->buy_sell_m10+=this->m10_price.parse("10 min ");
	if(this->enable[0]&M15_PRICE_EN)	this->buy_sell_m15+=this->m15_price.parse("15 min ");
	if(this->enable[0]&M30_PRICE_EN)	this->buy_sell_m30+=this->m30_price.parse("30 min ");
	if(this->enable[0]&M30_PRICE_EN)	this->buy_sell_m45+=this->m45_price.parse("45 min ");//use min 30 enable
	if(this->enable[0]&HOUR_PRICE_EN)	this->buy_sell_h+=this->hour_price.parse("60 min ");
	if(this->enable[0]&HOUR_PRICE_EN)	this->buy_sell_h4+=this->hour4_price.parse("4  hour ");//use hour enable 
	if(this->enable[0]&DAY_PRICE_EN)	this->buy_sell_d+=this->day_price.parse("one day");
	if(this->enable[0]&WEEK_PRICE_EN)	this->buy_sell_w+=this->week_price.parse("week");
	if(this->enable[0]&MONTH_PRICE_EN)	this->buy_sell_m+=this->month_price.parse("month");


	//macd
	if(this->m05_trend.init_flag||this->m10_trend.init_flag||this->m15_trend.init_flag||this->m30_trend.init_flag||this->m45_trend.init_flag||\
		this->hour_trend.init_flag||this->hour4_trend.init_flag||this->day_trend.init_flag||this->week_trend.init_flag||this->month_trend.init_flag)
	{
		printf("\ntrend.parse:\n");
	}
	if(this->enable[0]&M05_TREND_EN)	this->buy_sell_m05+=this->m05_trend.parse("05 min ");
	if(this->enable[0]&M10_TREND_EN)	this->buy_sell_m10+=this->m10_trend.parse("10 min ");
	if(this->enable[0]&M15_TREND_EN)	this->buy_sell_m15+=this->m15_trend.parse("15 min ");
	if(this->enable[0]&M30_TREND_EN)	this->buy_sell_m30+=this->m30_trend.parse("30 min ");
	if(this->enable[0]&M30_TREND_EN)	this->buy_sell_m45+=this->m45_trend.parse("45 min ");//use min 30 enable
	if(this->enable[0]&HOUR_TREND_EN)	this->buy_sell_h+=this->hour_trend.parse("60 min ");
	if(this->enable[0]&HOUR_TREND_EN)	this->buy_sell_h4+=this->hour4_trend.parse("4  hour ");//use hour enable 
	if(this->enable[0]&DAY_TREND_EN)	this->buy_sell_d+=this->day_trend.parse("one day");
	if(this->enable[0]&WEEK_TREND_EN)	this->buy_sell_w+=this->week_trend.parse("week ");
	if(this->enable[0]&MONTH_TREND_EN)	this->buy_sell_m+=this->month_trend.parse("month");

	//kdj
	if(this->m05_kdj.init_flag||this->m10_kdj.init_flag||this->m15_kdj.init_flag||this->m30_kdj.init_flag||this->m45_kdj.init_flag||\
		this->hour_kdj.init_flag||this->hour4_kdj.init_flag||this->day_kdj.init_flag||this->week_kdj.init_flag||this->month_kdj.init_flag)
	{
		printf("\nkdj.parse:\n");
	}
	if(this->enable[0]&M05_KDJ_EN) 	this->buy_sell_m05+=this->m05_kdj.parse("05 min ");
	if(this->enable[0]&M10_KDJ_EN) 	this->buy_sell_m10+=this->m10_kdj.parse("10 min ");
	if(this->enable[0]&M15_KDJ_EN) 	this->buy_sell_m15+=this->m15_kdj.parse("15 min ");
	if(this->enable[0]&M30_KDJ_EN) 	this->buy_sell_m30+=this->m30_kdj.parse("30 min ");
	if(this->enable[0]&M30_KDJ_EN) 	this->buy_sell_m45+=this->m45_kdj.parse("45 min ");//use min 30 enable
	if(this->enable[0]&HOUR_KDJ_EN)	this->buy_sell_h+=this->hour_kdj.parse("60 min ");
	if(this->enable[0]&HOUR_KDJ_EN)	this->buy_sell_h4+=this->hour4_kdj.parse("4  hour ");//use hour enable 
	if(this->enable[0]&DAY_KDJ_EN) 	this->buy_sell_d+=this->day_kdj.parse("one day");
	if(this->enable[0]&WEEK_KDJ_EN)	this->buy_sell_w+=this->week_kdj.parse("week ");
	if(this->enable[0]&MONTH_KDJ_EN)	this->buy_sell_m+=this->month_kdj.parse("month");

	//wr
	if(this->m05_wr.init_flag||this->m10_wr.init_flag||this->m15_wr.init_flag||this->m30_wr.init_flag||this->m45_wr.init_flag||\
		this->hour_wr.init_flag||this->hour4_wr.init_flag||this->day_wr.init_flag||this->week_wr.init_flag||this->month_wr.init_flag)
	{
		if(this->enable[0]&ALL_WR_EN)		printf("\nwr.parse:\n");
	}
	if(this->enable[0]&M05_WR_EN)  	this->buy_sell_m05+=this->m05_wr.parse("05 min ");
	if(this->enable[0]&M10_WR_EN)  	this->buy_sell_m10+=this->m10_wr.parse("10 min ");
	if(this->enable[0]&M15_WR_EN)  	this->buy_sell_m15+=this->m15_wr.parse("15 min ");
	if(this->enable[0]&M30_WR_EN)  	this->buy_sell_m30+=this->m30_wr.parse("30 min ");
	if(this->enable[0]&M30_WR_EN)  	this->buy_sell_m45+=this->m45_wr.parse("45 min ");//use min 30 enable
	if(this->enable[0]&HOUR_WR_EN) 	this->buy_sell_h+=this->hour_wr.parse("60 min ");
	if(this->enable[0]&HOUR_WR_EN) 	this->buy_sell_h4+=this->hour4_wr.parse("4  hour ");//use hour enable 
	if(this->enable[0]&DAY_WR_EN)  	this->buy_sell_d+=this->day_wr.parse("one day");
	if(this->enable[0]&WEEK_WR_EN) 	this->buy_sell_w+=this->week_wr.parse("week ");
	if(this->enable[0]&MONTH_WR_EN)	this->buy_sell_m+=this->month_wr.parse("month");	

	//rsi
	if(this->m05_rsi.init_flag||this->m10_rsi.init_flag||this->m15_rsi.init_flag||this->m30_rsi.init_flag||this->m45_rsi.init_flag||\
		this->hour_rsi.init_flag||this->hour4_rsi.init_flag||this->day_rsi.init_flag||this->week_rsi.init_flag||this->month_rsi.init_flag)
	{
		if(this->enable[1]&ALL_RSI_EN)	printf("\nrsi.parse:\n");
	}
	if(this->enable[1]&M05_RSI_EN)	this->buy_sell_m05+=this->m05_rsi.parse("05 min ");
	if(this->enable[1]&M10_RSI_EN)	this->buy_sell_m10+=this->m10_rsi.parse("10 min ");
	if(this->enable[1]&M15_RSI_EN)	this->buy_sell_m15+=this->m15_rsi.parse("15 min ");
	if(this->enable[1]&M30_RSI_EN)	this->buy_sell_m30+=this->m30_rsi.parse("30 min ");
	if(this->enable[1]&M30_RSI_EN)	this->buy_sell_m45+=this->m45_rsi.parse("45 min ");//use min 30 enable
	if(this->enable[1]&HOUR_RSI_EN)	this->buy_sell_h+=this->hour_rsi.parse("60 min ");
	if(this->enable[1]&HOUR_RSI_EN)	this->buy_sell_h4+=this->hour4_rsi.parse("4  hour ");//use hour enable 
	if(this->enable[1]&DAY_RSI_EN)	this->buy_sell_d+=this->day_rsi.parse("one day");
	if(this->enable[1]&WEEK_RSI_EN)	this->buy_sell_w+=this->week_rsi.parse("week ");
	if(this->enable[1]&MONTH_RSI_EN) this->buy_sell_m+=this->month_rsi.parse("month");
	
	//roc
	if(this->m05_roc.init_flag||this->m10_roc.init_flag||this->m15_roc.init_flag||this->m30_roc.init_flag||this->m45_roc.init_flag||\
		this->hour_roc.init_flag||this->hour4_roc.init_flag||this->day_roc.init_flag||this->week_roc.init_flag||this->month_roc.init_flag)
	{
		if(this->enable[1]&ALL_ROC_EN)  	printf("\nroc.parse:\n");
	}
	if(this->enable[1]&M05_ROC_EN)  	this->buy_sell_m05+=this->m05_roc.parse("05 min ");
	if(this->enable[1]&M10_ROC_EN)  	this->buy_sell_m10+=this->m10_roc.parse("10 min ");
	if(this->enable[1]&M15_ROC_EN)  	this->buy_sell_m15+=this->m15_roc.parse("15 min ");
	if(this->enable[1]&M30_ROC_EN)  	this->buy_sell_m30+=this->m30_roc.parse("30 min ");
	if(this->enable[1]&M30_ROC_EN)  	this->buy_sell_m45+=this->m45_roc.parse("45 min ");//use min 30 enable
	if(this->enable[1]&HOUR_ROC_EN) 	this->buy_sell_h+=this->hour_roc.parse("60 min ");
	if(this->enable[1]&HOUR_ROC_EN) 	this->buy_sell_h4+=this->hour4_roc.parse("4  hour ");//use hour enable 
	if(this->enable[1]&DAY_ROC_EN)  	this->buy_sell_d+=this->day_roc.parse("one day");
	if(this->enable[1]&WEEK_ROC_EN) 	this->buy_sell_w+=this->week_roc.parse("week ");
	if(this->enable[1]&MONTH_ROC_EN)	this->buy_sell_m+=this->month_roc.parse("month");
	
	//vr
	if(this->m05_vr.init_flag||this->m10_vr.init_flag||this->m15_vr.init_flag||this->m30_vr.init_flag||this->m45_vr.init_flag||\
		this->hour_vr.init_flag||this->hour4_vr.init_flag||this->day_vr.init_flag||this->week_vr.init_flag||this->month_vr.init_flag)
	{
		if(this->enable[1]&ALL_VR_EN)	printf("\nvr.parse:\n");
	}
	if(this->enable[1]&M05_VR_EN)	this->buy_sell_m05+=this->m05_vr.parse("05 min ");
	if(this->enable[1]&M10_VR_EN)	this->buy_sell_m10+=this->m10_vr.parse("10 min ");
	if(this->enable[1]&M15_VR_EN)	this->buy_sell_m15+=this->m15_vr.parse("15 min ");
	if(this->enable[1]&M30_VR_EN)	this->buy_sell_m30+=this->m30_vr.parse("30 min ");
	if(this->enable[1]&M30_VR_EN)	this->buy_sell_m45+=this->m45_vr.parse("45 min ");//use min 30 enable
	if(this->enable[1]&HOUR_VR_EN)	this->buy_sell_h+=this->hour_vr.parse("60 min ");
	if(this->enable[1]&HOUR_VR_EN)	this->buy_sell_h4+=this->hour4_vr.parse("4  hour ");//use hour enable 
	if(this->enable[1]&DAY_VR_EN)	this->buy_sell_d+=this->day_vr.parse("one day");
	if(this->enable[1]&WEEK_VR_EN)	this->buy_sell_w+=this->week_vr.parse("week ");
	if(this->enable[1]&MONTH_VR_EN)	this->buy_sell_m+=this->month_vr.parse("month");
	//cr
	if(this->m05_cr.init_flag||this->m10_cr.init_flag||this->m15_cr.init_flag||this->m30_cr.init_flag||this->m45_cr.init_flag||\
		this->hour_cr.init_flag||this->hour4_cr.init_flag||this->day_cr.init_flag||this->week_cr.init_flag||this->month_cr.init_flag)
	{
		if(this->enable[1]&ALL_CR_EN)	printf("\ncr.parse:\n");
	}
	if(this->enable[1]&M05_CR_EN)	this->buy_sell_m05+=this->m05_cr.parse("05 min ");
	if(this->enable[1]&M10_CR_EN)	this->buy_sell_m10+=this->m10_cr.parse("10 min ");
	if(this->enable[1]&M15_CR_EN)	this->buy_sell_m15+=this->m15_cr.parse("15 min ");
	if(this->enable[1]&M30_CR_EN)	this->buy_sell_m30+=this->m30_cr.parse("30 min ");
	if(this->enable[1]&M30_CR_EN)	this->buy_sell_m45+=this->m45_cr.parse("45 min ");//use min 30 enable
	if(this->enable[1]&HOUR_CR_EN)	this->buy_sell_h+=this->hour_cr.parse("60 min ");
	if(this->enable[1]&HOUR_CR_EN)	this->buy_sell_h4+=this->hour4_cr.parse("4  hour ");//use hour enable 
	if(this->enable[1]&DAY_CR_EN)	this->buy_sell_d+=this->day_cr.parse("one day");
	if(this->enable[1]&WEEK_CR_EN)	this->buy_sell_w+=this->week_cr.parse("week ");
	if(this->enable[1]&MONTH_CR_EN)	this->buy_sell_m+=this->month_cr.parse("month");

	//dma
	if(this->m05_dma.init_flag||this->m10_dma.init_flag||this->m15_dma.init_flag||this->m30_dma.init_flag||this->m45_dma.init_flag||\
		this->hour_dma.init_flag||this->hour4_dma.init_flag||this->day_dma.init_flag||this->week_dma.init_flag||this->month_dma.init_flag)
	{
		if(this->enable[2]&ALL_DMA_EN)	printf("\ndma.parse:\n");
	}
	if(this->enable[2]&M05_DMA_EN)	this->buy_sell_m05+=this->m05_dma.parse("05 min ");
	if(this->enable[2]&M10_DMA_EN)	this->buy_sell_m10+=this->m10_dma.parse("10 min ");
	if(this->enable[2]&M15_DMA_EN)	this->buy_sell_m15+=this->m15_dma.parse("15 min ");
	if(this->enable[2]&M30_DMA_EN)	this->buy_sell_m30+=this->m30_dma.parse("30 min ");
	if(this->enable[2]&M30_DMA_EN)	this->buy_sell_m45+=this->m45_dma.parse("45 min ");//use min 30 enable
	if(this->enable[2]&HOUR_DMA_EN)	this->buy_sell_h+=this->hour_dma.parse("60 min ");
	if(this->enable[2]&HOUR_DMA_EN)	this->buy_sell_h4+=this->hour4_dma.parse("4  hour ");//use hour enable 
	if(this->enable[2]&DAY_DMA_EN)	this->buy_sell_d+=this->day_dma.parse("one day");
	if(this->enable[2]&WEEK_DMA_EN)	this->buy_sell_w+=this->week_dma.parse("week ");
	if(this->enable[2]&MONTH_DMA_EN)	this->buy_sell_m+=this->month_dma.parse("month");

	//cci
	if(this->m05_cci.init_flag||this->m10_cci.init_flag||this->m15_cci.init_flag||this->m30_cci.init_flag||this->m45_cci.init_flag||\
		this->hour_cci.init_flag||this->hour4_cci.init_flag||this->day_cci.init_flag||this->week_cci.init_flag||this->month_cci.init_flag)
	{
		if(this->enable[2]&ALL_CCI_EN)	printf("\ncci.parse:\n");
	}
	if(this->enable[2]&M05_CCI_EN)	this->buy_sell_m05+=this->m05_cci.parse("05 min ");
	if(this->enable[2]&M10_CCI_EN)	this->buy_sell_m10+=this->m10_cci.parse("10 min ");
	if(this->enable[2]&M15_CCI_EN)	this->buy_sell_m15+=this->m15_cci.parse("15 min ");
	if(this->enable[2]&M30_CCI_EN)	this->buy_sell_m30+=this->m30_cci.parse("30 min ");
	if(this->enable[2]&M30_CCI_EN)	this->buy_sell_m45+=this->m45_cci.parse("45 min ");//use min 30 enable
	if(this->enable[2]&HOUR_CCI_EN)	this->buy_sell_h+=this->hour_cci.parse("60 min ");
	if(this->enable[2]&HOUR_CCI_EN)	this->buy_sell_h4+=this->hour4_cci.parse("4  hour ");//use hour enable 
	if(this->enable[2]&DAY_CCI_EN)	this->buy_sell_d+=this->day_cci.parse("one day");
	if(this->enable[2]&WEEK_CCI_EN)	this->buy_sell_w+=this->week_cci.parse("week ");
	if(this->enable[2]&MONTH_CCI_EN)	this->buy_sell_m+=this->month_cci.parse("month");

	//ma
	if(this->ma_cycle1.init_flag||this->ma_cycle2.init_flag||this->ma_cycle3.init_flag||this->ma_cycle4.init_flag||this->ma_cycle5.init_flag||\
		this->ma_cycle6.init_flag||this->ma_cycle7.init_flag||this->ma_cycle8.init_flag||this->ma_cycle9.init_flag||this->ma_cycle10.init_flag||this->ma_cycle11.init_flag)
	{
		printf("\nma.parse:\n");
	}
	this->buy_sell_ma+=this->ma_cycle1.parse("5   min ");
	this->buy_sell_ma+=this->ma_cycle2.parse("10  min");
	this->buy_sell_ma+=this->ma_cycle3.parse("15 min");
	this->buy_sell_ma+=this->ma_cycle4.parse("30 min");
	this->buy_sell_ma+=this->ma_cycle5.parse("45 min");
	this->buy_sell_ma+=this->ma_cycle6.parse("60 min");
	this->buy_sell_ma+=this->ma_cycle7.parse("4  hour");
	this->buy_sell_ma+=this->ma_cycle8.parse("one day");
	this->buy_sell_ma+=this->ma_cycle9.parse("week   ");
	this->buy_sell_ma+=this->ma_cycle10.parse("month ");
	this->buy_sell_ma+=this->ma_cycle11.parse(" year  ");
	//Cvol
	if(this->m05_vol.init_flag||this->m10_vol.init_flag||this->m15_vol.init_flag||this->m30_vol.init_flag||this->m45_vol.init_flag||\
		this->hour_vol.init_flag||this->hour4_vol.init_flag||this->day_vol.init_flag||this->week_vol.init_flag||this->month_vol.init_flag)
	{
		printf("\nvol.parse:\n");
	}
	this->buy_sell_m05+=this->m05_vol.parse("05 min ");
	this->buy_sell_m10+=this->m10_vol.parse("10 min ");
	this->buy_sell_m15+=this->m15_vol.parse("15 min ");
	this->buy_sell_m30+=this->m30_vol.parse("30 min ");
	this->buy_sell_m45+=this->m45_vol.parse("45 min ");
	this->buy_sell_h+=this->hour_vol.parse("60 min ");
	this->buy_sell_h4+=this->hour4_vol.parse("4  hour ");
	this->buy_sell_d+=this->day_vol.parse("one day");
	this->buy_sell_w+=this->week_vol.parse("week ");
	this->buy_sell_m+=this->month_vol.parse("month");


	this->buy_sell=this->buy_sell_m+this->buy_sell_w+this->buy_sell_d+this->buy_sell_h4+this->buy_sell_h+this->buy_sell_m45+this->buy_sell_m30+this->buy_sell_m15+this->buy_sell_m10+this->buy_sell_m05+this->buy_sell_ma;

	this->direction=this->all_direction();

	this->display();
	
	return this->buy_sell;
}

int Coperate::operate()
{
	int msg=this->msg.parse();
	int buy_sell=this->parse();
	printf("\n[operate]: ");
	if(msg>0) //good
	{
		if(buy_sell>0)	
			printf("buy\n");
		else
			printf("stop\n");
	}

	if(msg<0) //bad
	{
		if(buy_sell<0)	
			printf("sell\n");
		else
			printf("stop\n");	
	}

	if(msg==0)//null
	{
		if(buy_sell>1)	printf("buy\n");
		if(buy_sell<-1)	printf("sell\n");
		if(buy_sell<1&&buy_sell>-1)	printf("stop\n");
	}

	if(this->hour_price.init_flag)
	{	
		printf("\n[refer]:\n");
		if(abs(this->buy_sell_m30+this->dir_m30)>3||abs(this->buy_sell_h+this->dir_hour)>3)
		{
			if(abs(this->buy_sell_m30+this->dir_m30)>abs(this->buy_sell_h+this->dir_hour))
			{	this->m30_price.display(this->buy_sell_m30,"min 30",this->dir_m30);}
			else
			{	this->hour_price.display(this->buy_sell_h,"hour01",this->dir_hour);}

			if(this->m15_price.init_flag&&abs(this->buy_sell_m15)+this->dir_m15>20)
			{
				this->m15_price.display(this->buy_sell_m15,"refer2: min 15",this->dir_m15);
			}
		}
		else
		{
			if(abs(this->buy_sell_m15)+this->dir_m15>5)	this->m15_price.display(this->buy_sell_m15,"min 15",this->dir_m15);
			else this->hour_price.display(this->buy_sell_h,"hour01",this->dir_hour);
		}
	}

	this->hour_price.parse_all_price(this->buy_sell,this->direction);

	return 0;
}


#if OPERATE_TEST
void Cmarket::nyme_oil_parse()//nyme
{
	printf("\nnyme oil_parse:\n");	
	Coperate op ;
	op.price=264.2;
//message int Cmessage::set( good, bad)
	op.msg.set(0,0);
//set disable
	op.enable[0]&=(~(M05_CYCLE_EN|WEEK_CYCLE_EN|MONTH_CYCLE_EN|ALL_WR_EN));//disable 5 ,10 
	op.enable[1]&=(~(M05_CYCLE_EN2|WEEK_CYCLE_EN2|MONTH_CYCLE_EN2));
	
//boll:void Cprice::init( dir, price, low, mid, upper, buy=-0.1, sell=0.1);
//	op.day_price.init(DIR_DOWN ,price, 252.76 , 291.47 , 330.18);//day
	op.hour4_price.init(DIR_DOWN,op.price, 258.11 , 263.93 , 268.71 );//4 hour
	op.hour_price.init(DIR_DOWN,op.price, 258.11 , 263.93 , 268.71 );//hour
	op.m45_price.init(DIR_UPER ,op.price, 261.43 , 262.20 , 264.11 );//45 min
	op.m30_price.init(DIR_UPER ,op.price, 261.43 , 262.20 , 264.11 );//30 min
	op.m15_price.init(DIR_UPER ,op.price, 260.87 , 262.60 , 264.3 );//15 min
	op.m10_price.init(DIR_UPER ,op.price, 260.87 , 262.60 , 264.3 );//10 min

//macd:void      init( dir     ,macd   , dif   ,   dea,   buy , sell, low ,mid,  upper,cross_line,zero_line=0.3);
//	op.day_trend.init(DIR_UPER , -0.15 , -16.17,-16.01 , -1.5 , 1.5 , -2  , 0 ,  2  ,  1.5  ,  0.2 );//day
	op.hour4_trend.init(DIR_UPER, 0.37  , -0.63 , -1.00 , -0.25 , 0.25 , -0.3, 0 ,0.3, 0.2   ,  0.05);//4 hour
	op.hour_trend.init(DIR_UPER, 0.37  , -0.63 , -1.00 , -0.25 , 0.25 , -0.3, 0 ,0.3, 0.2   ,  0.05);//hour
	op.m45_trend.init(DIR_UPER , 0.4   , -0.09 , -0.31 , -0.25 , 0.25 , -0.3, 0 ,0.3, 0.2   ,  0.03);//45 min
	op.m30_trend.init(DIR_UPER , 0.4   , -0.09 , -0.31 , -0.25 , 0.25 , -0.3, 0 ,0.3, 0.2   ,  0.03);//30 min
	op.m15_trend.init(DIR_UPER , 0.29  , 0.49  , 0.2   , -0.20 , 0.20 , -0.3, 0 ,0.3, 0.15  ,  0.03);//15 min
	op.m10_trend.init(DIR_UPER , 0.29  , 0.49  , 0.2   , -0.20 , 0.20 , -0.3, 0 ,0.3, 0.15  ,  0.03);//15 min

//kdj:void Ckdj::init( k, d, j,buy_cross, sell_cross)
//	op.day_kdj.init(DIR_UPER , 15 ,13 ,19); //day
	op.hour4_kdj.init(DIR_UPER , 73 , 63 , 92 );//4 hour
	op.hour_kdj.init(DIR_UPER , 73 , 63 , 92 );//hour
	op.m30_kdj.init(DIR_DOWN  , 76 , 63 , 102 );//45 min
	op.m30_kdj.init(DIR_DOWN  , 76 , 63 , 102 );//min 30
	op.m15_kdj.init(DIR_DOWN  , 84 , 78 , 95 );//min 15
	op.m10_kdj.init(DIR_DOWN  , 84 , 78 , 95 );//min 10
//wr:void init(direction,wr,bottom=3,middle=50,top=97)

//rsi:init(direction,rsi_short,rsi_middle,rsi_long,bottom=15,top=85);
//	op.day_rsi.init(DIR_UPER , 30 , 18 , 26 ) ;//day
	op.hour4_rsi.init(DIR_DOWN, 78 , 72 , 32 ) ;//4 hour
	op.hour_rsi.init(DIR_DOWN, 78 , 72 , 32 ) ;//hour
	op.m45_rsi.init(DIR_DOWN , 95 , 70 , 58) ;//min 45
	op.m30_rsi.init(DIR_DOWN , 95 , 70 , 58) ;//min 30
	op.m15_rsi.init(DIR_DOWN , 83 , 72 , 64 ) ;//min 15
	op.m10_rsi.init(DIR_DOWN , 83 , 72 , 64 ) ;//min 10	

//roc:void init(DIR_UPER/DIR_UPER/DIR_NONE,roc,roc_ma,bottom=-3,double top=3);
//	op.day_roc.init(DIR_UPER , -7.28 , -8.98 , -10,10);
	op.hour4_roc.init(DIR_UPER , 0.79 , 0.18 , -2.5,2.5);
	op.hour_roc.init(DIR_UPER , 0.79 , 0.18 , -2.5,2.5);
	op.m45_roc.init(DIR_UPER  , 0.86 , 0.45 , -3, 3);
	op.m30_roc.init(DIR_UPER  , 0.86 , 0.45 , -3, 3);
	op.m15_roc.init(DIR_DOWN  , 0.81 , 0.69 , -1, 1);
	op.m10_roc.init(DIR_DOWN  , 0.81 , 0.69 , -1, 1);

//vr:void init(direction,vr_short,vr_long,diff=40);	
	op.hour4_vr.init(DIR_UPER , 72 , 65 ,30);
	op.hour_vr.init(DIR_UPER , 72 , 65 ,30);
	op.m45_vr.init(DIR_DOWN  , 238 , 215 ,30);
	op.m30_vr.init(DIR_DOWN  , 238 , 215 ,30);
	op.m10_vr.init(DIR_DOWN  , 238 , 215 ,30);

//cr:void init(direction,cr,a,c,diff=30,bottom=50,middle=100,top=150); //oil
	op.hour4_cr.init(DIR_UPER , 58 , 56 , 64 , 0 ,SPARATE 30 , 50 , 100 , 150); //diff->30,50,100,150
	op.hour_cr.init(DIR_UPER , 58 , 56 , 64 , 0 ,SPARATE 30 , 50 , 100 , 150); //diff->30,50,100,150
	op.m45_cr.init( DIR_UPER , 159 , 106 , 87 , 69 ,SPARATE 80 , 50 , 125 , 200); //diff->80,50,125,200	
	op.m30_cr.init( DIR_UPER , 159 , 106 , 87 , 69 ,SPARATE 80 , 50 , 125 , 200); //diff->80,50,125,200	
	op.m10_cr.init( DIR_UPER , 159 , 106 , 87 , 69 ,SPARATE 80 , 50 , 125 , 200); //diff->80,50,125,200	

//dma: void init(direction, dma, ama, bottom=-4, middle=0, top=4, dir_line=1); //oil
	op.hour4_dma.init( DIR_UPER , -6.8 , -6.9 ,		-4 , 0 , 4 , 1.5);
	op.hour_dma.init( DIR_UPER , -6.8 , -6.9 ,		-4 , 0 , 4 , 1.5);
	op.m45_dma.init( DIR_UPER , -4.1 , -5.0 ,		-4 , 0 , 4 , 2.0);
	op.m30_dma.init( DIR_UPER , -4.1 , -5.0 ,		-4 , 0 , 4 , 2.0);
	op.m15_dma.init( DIR_DOWN , -0.3 , -0.2 ,		-4 , 0 , 4 , 3.0);
	op.m10_dma.init( DIR_DOWN , -0.3 , -0.2 ,		-4 , 0 , 4 , 3.0);

//wr:void init( direction, wr, wr_long, bottom=3, middle=50, top=97,negative=-1); 
	op.hour4_wr.init(DIR_UPER , -94	,-97,	5, 50 ,95 , NO_NEG );	
	op.hour_wr.init(DIR_UPER , -94	,-97,	5, 50 ,95 , NO_NEG );	
	op.m45_wr.init(DIR_UPER , -9.97	,-8.76,	5, 50 ,95 , NO_NEG );	
	op.m30_wr.init(DIR_UPER , -9.97	,-8.76,	5, 50 ,95 , NO_NEG );	
	op.m15_wr.init(DIR_UPER , -14.29	,-9.97,	5, 50 ,95 , NO_NEG );	
	op.m10_wr.init(DIR_UPER , -14.29	,-9.97,	5, 50 ,95 , NO_NEG );	

//cci: init(int direction,double cci,double bottom=-400,double middle=0,double top=400,double dir_line=100)
	op.hour4_cci.init( DIR_UPER , -3.1 ,	 	-200 , 0 , 200 , 100);
	op.hour_cci.init( DIR_UPER , -3.1 ,	 	-200 , 0 , 200 , 100);
	op.m45_cci.init( DIR_DOWN , -1 , 		-200, 0 , 200 , 100);
	op.m30_cci.init( DIR_DOWN , -1 , 		-200, 0 , 200 , 100);
	op.m15_cci.init( DIR_UPER , -0.3 ,		-200, 0 , 200 , 100);
	op.m10_cci.init( DIR_UPER , -0.3 ,		-200, 0 , 200 , 100);

//opeate output
	op.operate();		

//nyme oil_parse end
}

void Cmarket::huaxia_oil_parse()//hua xia
{
	printf("\nhua xia oil_parse:\n");	
	Coperate op ;
	op.price=283.6;
//message int Cmessage::set( good, bad)
	op.msg.set(0,0);
//set disable
	op.enable[0]&=(~(M05_CYCLE_EN|M10_CYCLE_EN|WEEK_CYCLE_EN|MONTH_CYCLE_EN));//disable 5 ,10 
	op.enable[1]&=(~(M05_CYCLE_EN2|M10_CYCLE_EN2|WEEK_CYCLE_EN2|MONTH_CYCLE_EN2));
	
//boll://void Cprice::init( dir, price, low, mid, upper, buy=-0.1, sell=0.1);
//	op.day_price.init(DIR_DOWN ,price, 247.6 , 267.3 , 287);//day
	op.hour_price.init(DIR_DOWN,op.price, 282 , 284.5 , 288);//hour
	op.m30_price.init(DIR_UPER ,op.price, 281 , 283.6 , 286 );//30 min
	op.m15_price.init(DIR_UPER ,op.price, 283 , 284 , 285 );//15 min

//macd:void      init( dir     ,macd   , dif   ,   dea,   buy , sell, low ,mid,  upper,cross_line,zero_line=0.3);
//	op.day_trend.init(DIR_UPER , 0.19  , -15.81 ,   -15.99,  -15  , 15  , -0.6 , 0 , 0.6);	//day
	op.hour_trend.init( DIR_UPER , -0.3 ,-0.7  , -0.34 , -1.5  ,1.5  , -3   , 0 , 3   ,  2 , 0.3 );//hour
	op.m30_trend.init( DIR_UPER  , 0.02 , -0.7,  -0.72 ,  -1.7 , 1.7  ,-3    ,0  , 3   ,1.5 , 0.3);//30 min
	op.m15_trend.init(DIR_UPER , 0.12 ,-0.3  , -0.4 , -1.5  , 1.5  , -2    ,0  , 2   ,1.3 , 0.3 );//15 min

//kdj:void Ckdj::init( k, d, j,buy_cross, sell_cross)
//	op.day_kdj.init(DIR_UPER  , 13.57 ,13.2 ,15); //day
	op.hour_kdj.init(DIR_UPER ,29 , 30 , 28 );//hour
	op.m30_kdj.init(DIR_UPER  , 54 , 41 , 77 );//min 30
	op.m15_kdj.init(DIR_DOWN  , 60 , 57 , 52 );//min 15

//wr:void init(direction,wr,bottom=3,middle=50,top=97)

//rsi:init(direction,rsi_short,rsi_middle,rsi_long,bottom=15,top=85);
//	op.day_rsi.init(DIR_UPER , 1.3 , 19 , 23 ) ;//day
	op.hour_rsi.init(DIR_DOWN , 30 , 33 , 37 ) ;//hour
	op.m30_rsi.init(DIR_DOWN , 52 , 34 , 44) ;//min 30
	op.m15_rsi.init(DIR_DOWN , 62 , 52 , 37 ) ;//min 15
	
//roc:void init(DIR_UPER/DIR_UPER/DIR_NONE,roc,roc_ma,bottom=-3,double top=3);
//	op.day_roc.init(DIR_UPER , -7.28 , -8.98 , -10,10);
	op.hour_roc.init(DIR_UPER , 1.24, -0.4, -2.5,2.5);
	op.m30_roc.init(DIR_UPER  ,-0.8 , -0.6 , -3, 3);
	op.m15_roc.init(DIR_DOWN  , -0.11 ,-0.15 , -1, 1);

//vr:void init(direction,vr_short,vr_long,diff=40);	
	op.hour_vr.init(DIR_DOWN , 79 , 83  ,	30);
	op.m30_vr.init(DIR_UPER  , 115 , 112 ,	30);
	op.m15_vr.init(DIR_UPER  , 65 , 75 ,	30);

//cr:void init(direction,cr,a,c,diff=30,bottom=50,middle=100,top=150); //oil
//	op.hour_cr.init(DIR_UPER , 127 , 114 , 103 , 115 ,SPARATE 30 , 50 , 100 , 150); //diff->30,50,100,150
//	op.m30_cr.init( DIR_UPER , 282 , 172 , 136 , 114 ,SPARATE 80 , 50 , 125 , 200); //diff->80,50,125,200	
//	op.m15_cr.init( DIR_UPER , 282 , 172 , 136 , 114 ,SPARATE 80 , 50 , 125 , 200); //diff->80,50,125,200	

//dma: void init(direction, dma, ama, bottom=-4, middle=0, top=4, dir_line=1); //oil
	op.hour_dma.init( DIR_DOWN , -1.29 , -0.34 ,		-4 , 0 , 4 , 1.5);
	op.m30_dma.init( DIR_UPER , -2.5 , -2.6 ,		-4 , 0 , 4 , 2.0);
	op.m15_dma.init( DIR_UPER ,-1.35 , -1.31 ,		-4 , 0 , 4 , 3.0);
/*
//wr:void init( direction, wr, wr_long, bottom=3, middle=50, top=97,negative=-1); 
	op.hour_wr.init(DIR_DOWN , -28 , -14 ,	5, 50 ,95 , NO_NEG );	
	op.m30_wr.init(DIR_DOWN , -36	,-28,	5, 50 ,95 , NO_NEG );	
	op.m15_wr.init(DIR_DOWN , -66	,-28,	5, 50 ,95 , NO_NEG );	

//cci: init(int direction,double cci,double bottom=-400,double middle=0,double top=400,double dir_line=100)
	op.hour_cci.init( DIR_DOWN , 155 ,	 	-200 , 0 , 200 , 100);
	op.m30_cci.init( DIR_DOWN , 144 , 		-200, 0 , 200 , 100);
	op.m15_cci.init( DIR_DOWN , 84 ,		-200, 0 , 200 , 100);
*/
//opeate output

	op.operate();	
	//hua xia oil_parse end
}

void Cmarket::huaxia_silver_parse()
{
	printf("\nhuaxia_silver_parse:\n");	
	Coperate op ;
	op.price=3164;
//message int Cmessage::set( good, bad)
	op.msg.set(0,0);
//set disable
	op.enable[0]&=(~(M05_CYCLE_EN|M10_CYCLE_EN|WEEK_CYCLE_EN|MONTH_CYCLE_EN));//disable 5 ,10 
	op.enable[1]&=(~(M05_CYCLE_EN2|M10_CYCLE_EN2|WEEK_CYCLE_EN2|MONTH_CYCLE_EN2));
	
//boll://void Cprice::init( dir, price, low, mid, upper, buy=-0.1, sell=0.1);
//	op.day_price.init(DIR_DOWN ,op.price, 247.6 , 267.3 , 287);//day
	op.hour_price.init(DIR_UPER,op.price, 3130 , 3147 , 3165 );//hour
	op.m30_price.init(DIR_DOWN ,op.price, 3139 , 3153 , 3167 );//30 min
	op.m15_price.init(DIR_UPER ,op.price, 3143 , 3156 , 3170 );//15 min

//macd:void      init( dir     ,macd   , dif   ,   dea,   buy , sell, low ,mid,  upper,cross_line,zero_line=0.3);
//	op.day_trend.init(DIR_UPER , 0.19  , -15.81 ,   -15.99,  -15  , 15  , -0.6 , 0 , 0.6);	//day
	op.hour_trend.init(DIR_DOWN, -0.45 , 16.78 , 17.23 , -9 , 9  , -15   , 0 , 15  ,  10 , 2.5 );//hour
	op.m30_trend.init(DIR_DOWN , 0.68 , 7.66,  6.98 , -9 , 9  , -15   , 0 , 15  ,  10 , 2.5 );//30 min
	op.m15_trend.init(DIR_DOWN , 1.28 , 5.20 ,3.93 , -9 , 9  , -20   , 0 ,  20  ,  10 , 2.5 );//15 min

//kdj:void Ckdj::init( k, d, j,buy_cross, sell_cross)
//	op.day_kdj.init(DIR_UPER  , 13.57 ,13.2 ,15); //day
	op.hour_kdj.init(DIR_UPER , 71 , 67 , 80 );//hour
	op.m30_kdj.init(DIR_UPER  , 70 , 63 , 83 );//min 30
	op.m15_kdj.init(DIR_UPER  , 73 , 63 , 90 );//min 15

//wr:void init(direction,wr,bottom=3,middle=50,top=97)

//rsi:init(direction,rsi_short,rsi_middle,rsi_long,bottom=15,top=85);
//	op.day_rsi.init(DIR_UPER , 1.3 , 19 , 23 ) ;//day
	op.hour_rsi.init(DIR_UPER, 73 , 70 , 68 ) ;//hour
	op.m30_rsi.init(DIR_UPER , 90 , 64 , 63) ;//min 30
	op.m15_rsi.init(DIR_UPER , 81 , 78 , 60 ) ;//min 15
	
//roc:void init(DIR_UPER/DIR_UPER/DIR_NONE,roc,roc_ma,bottom=-3,double top=3);
//	op.day_roc.init(DIR_UPER , -7.28 , -8.98 , -10,10);
	op.hour_roc.init(DIR_DOWN , 1.02 , 0.77 , -2.5,2.5);
	op.m30_roc.init(DIR_UPER  ,0.54 , 0.45 , -2, 2);
	op.m15_roc.init(DIR_DOWN  , 0.31 ,0.54 , -2,2);

//vr:void  init(direction,vr_short, vr_long, diff=40, bottom=50,double middle=100 ,double top=150);
	op.hour_vr.init(DIR_UPER , 103, 88 ,	40 , 50 , 125 , 200 );
	op.m30_vr.init(DIR_UPER  , 115 , 114    ,	40 , 50 , 125 , 200);
	
//cr:void init(direction,cr,a,c,diff=30,bottom=50,middle=100,top=150); //oil
	op.hour_cr.init(DIR_DOWN , 173 , 186 , 226 , 207 ,SPARATE 30 , 50 , 125 , 200); //diff->30,50,100,150
	op.m30_cr.init( DIR_DOWN , 105 , 125 , 133 , 146 ,SPARATE 80 , 50 , 125 , 200); //diff->80,50,125,200	

//dma: void init(direction, dma, ama, bottom=-4, middle=0, top=4, dir_line=1); //oil
	op.hour_dma.init( DIR_DOWN , 57 , 62 ,		-50 , 0 , 50 , 25);
	op.m30_dma.init( DIR_UPER , 18.5 , 18.2 ,		-50 , 0 , 50 , 25);
	op.m15_dma.init( DIR_UPER , 12.08 , 8.15 ,		-50 , 0 , 50 , 25);

//wr:void init( direction, wr, wr_long, bottom=3, middle=50, top=97,negative=-1); //wr_long is long ,wr is short cycle ,dir =wr_long
	op.hour_wr.init(DIR_UPER , -8.76	,-53.79,	5, 50 ,95 , NO_NEG );	
	op.m30_wr.init(DIR_UPER , -9.97	,-8.76,	5, 50 ,95 , NO_NEG );	
	op.m15_wr.init(DIR_UPER , -14.29	,-9.97,	5, 50 ,95 , NO_NEG );	

//opeate output

	op.operate();	
//huaxia_silver_parse end
}


void Cmarket::stock_parse()
{
	printf("\nstock_parse:\n");
	Coperate op ;
	op.price=3086;
//message int Cmessage::set( good, bad)
	op.msg.set(0,0);
//set disable	
	op.enable[0]&=(~(M05_CYCLE_EN|M10_CYCLE_EN|M15_CYCLE_EN));//disable 5 ,10 
	op.enable[1]&=(~(M05_CYCLE_EN2|M10_CYCLE_EN2|M15_CYCLE_EN2|ALL_ROC_EN|ALL_VR_EN|ALL_CR_EN));

//boll://void Cprice::init( dir, price, low, mid, upper, buy=-0.1, sell=0.1);
	op.week_price.init(DIR_DOWN,op.price, 2812 , 3989 , 5166 );//week
	op.day_price.init(DIR_DOWN,op.price , 2787 , 3208 , 3629 );//day
	op.hour_price.init(DIR_UPER,op.price, 2961 , 3100 , 3256 );//hour
	op.m30_price.init(DIR_UPER,op.price,2936,3080,3225);//30 min

//macd:void init(dir,macd,dif,dea,buy=-2.15,sell=2.15,low=-0.06,mid=0,upper=0.06,cross_line=0.5,zero_line=0.3);
	op.week_trend.init(  DIR_DOWN  , -331 , -131 , 34 ,SPARATE	-300,300,-100,0,100,150,30);	//week
	op.day_trend.init(    DIR_UPER   , 30 , -158 , -173 ,SPARATE	-200,200,-40,0,40,50,20);	//day
	op.hour_trend.init(   DIR_UPER   , 21 , -10 , -21 ,SPARATE	-100,100,-15,0,15,40,15);//hour
	op.m30_trend.init(   DIR_DOWN   ,  24  ,  15  ,  4  ,  SPARATE -100,100,-15,0,15,30,10);//30 min

//kdj:void Ckdj::init(direction, k, d, j,buy_cross, sell_cross)
	op.week_kdj.init(  DIR_UPER  ,  22  , 24  , 18  );
	op.day_kdj.init(    DIR_DOWN  ,  46  , 51  , 35  ); //day
	op.hour_kdj.init(  DIR_DOWN  ,  67  , 59  , 82  );//hour
	op.m30_kdj.init(   DIR_DOWN  ,  60  ,  75  , 29 );//min 30

//wr:void init( direction, wr, wr_long, bottom=3, middle=50, top=97,negative=-1);
	op.week_wr.init(  DIR_UPER , 82  	, UN_INIT);//wr_long UN_INIT
	op.day_wr.init(  DIR_UPER  , 62	,UN_INIT );	
	op.hour_wr.init(  DIR_UPER  , 53  	,UN_INIT );		
	op.m30_wr.init(  DIR_UPER  , 64  	,UN_INIT );		

//rsi:init(direction,rsi_short,rsi_middle,rsi_long,bottom=15,top=85);
	op.week_rsi.init(DIR_DOWN , 26 , 36 , 44 ) ;//day
	op.day_rsi.init(DIR_DOWN , 41 , 39 , 40 ) ;//day
	op.hour_rsi.init(DIR_DOWN, 43 , 46 , 45 ) ;//hour
	op.m30_rsi.init(DIR_DOWN , 36 , 45 , 47) ;//min 30

//opeate output
	op.operate();	

//stock_parse end
}

//2.1 boll: ( dir, price, low, mid, upper, buy=-0.1, sell=0.1);
//boll-setting: (object,boll,period,setting,buy,sell)	
//boll-parse : (object,boll,period,parse,dir,price,low,mid,upper)
//Cprice	month_price,week_price,day_price,hour4_price,hour_price,m45_price,m30_price,m15_price,m10_price,m05_price;//30,5,1 
int Cmarket::set_op_boll_param(Coperate *op ,Ciniformat *i,Ciniformat *p ) //i:ini setting file ,p:parse file
{

	if(p->value_count<5)
	{
		printf("boll parse error:");p->display();
		return -1;
	}

	if(i->value_count<2)
	{
		printf("boll setting error:");i->display();
		return -1;
	}
	op->price=p->value[1]; //set op.price 
	switch(p->period)
	{
	case year:
		break;
	case month:
		op->month_price.init((int)p->value[0],p->value[1],p->value[2],p->value[3],p->value[4],i->value[0],i->value[1]);
		break;
	case week:
		op->week_price.init((int)p->value[0],p->value[1],p->value[2],p->value[3],p->value[4],i->value[0],i->value[1]);
		break;
	case day:
		op->day_price.init((int)p->value[0],p->value[1],p->value[2],p->value[3],p->value[4],i->value[0],i->value[1]);
		break;
	case hour4:
		op->hour4_price.init((int)p->value[0],p->value[1],p->value[2],p->value[3],p->value[4],i->value[0],i->value[1]);
		break;
	case hour1:
		op->hour_price.init((int)p->value[0],p->value[1],p->value[2],p->value[3],p->value[4],i->value[0],i->value[1]);
		break;
	case min45:
		op->m45_price.init((int)p->value[0],p->value[1],p->value[2],p->value[3],p->value[4],i->value[0],i->value[1]);
		break;
	case min30:
		op->m30_price.init((int)p->value[0],p->value[1],p->value[2],p->value[3],p->value[4],i->value[0],i->value[1]);
		break;
	case min15:
		op->m15_price.init((int)p->value[0],p->value[1],p->value[2],p->value[3],p->value[4],i->value[0],i->value[1]);
		break;
	case min10:
		op->m10_price.init((int)p->value[0],p->value[1],p->value[2],p->value[3],p->value[4],i->value[0],i->value[1]);
		break;
	case min5:
		op->m05_price.init((int)p->value[0],p->value[1],p->value[2],p->value[3],p->value[4],i->value[0],i->value[1]);
		break;
	case all_period:
	default:
		break;
	}
	return 0;
}
//2.2 macd: (dir, macd, dif, dea, buy=-2.15, sell=2.15, low=-0.06, mid=0, upper=0.06, cross_line=0.5, zero_line=0.3);
//macd-setting: (object,macd,period,setting,buy,sell,low,mid,upper,cross_line,zero_line)	
//macd-parse : (object,macd,period,parse,dir,macd,dif,dea)
//Ctrend	month_trend,week_trend,day_trend,hour4_trend,hour_trend,m45_trend,m30_trend,m15_trend,m10_trend,m05_trend;
int Cmarket::set_op_macd_param(Coperate *op ,Ciniformat *i,Ciniformat *p ) //i:ini setting file ,p:parse file
{
	if(p->value_count<4)
	{
		printf("macd parse error:");p->display();
		return -1;
	}

	if(i->value_count<7)
	{
		printf("macd setting error:");i->display();
		return -1;
	}

	switch(p->period)
	{
	case year:
		break;
	case month:
		op->month_trend.init((int)p->value[0],p->value[1],p->value[2],p->value[3],i->value[0],i->value[1],i->value[2],i->value[3],i->value[4],i->value[5],i->value[6]);
		break;
	case week:
		op->week_trend.init((int)p->value[0],p->value[1],p->value[2],p->value[3],i->value[0],i->value[1],i->value[2],i->value[3],i->value[4],i->value[5],i->value[6]);
		break;
	case day:		
		op->day_trend.init((int)p->value[0],p->value[1],p->value[2],p->value[3],i->value[0],i->value[1],i->value[2],i->value[3],i->value[4],i->value[5],i->value[6]);
		break;
	case hour4:		
		op->hour4_trend.init((int)p->value[0],p->value[1],p->value[2],p->value[3],i->value[0],i->value[1],i->value[2],i->value[3],i->value[4],i->value[5],i->value[6]);
		break;
	case hour1:		
		op->hour_trend.init((int)p->value[0],p->value[1],p->value[2],p->value[3],i->value[0],i->value[1],i->value[2],i->value[3],i->value[4],i->value[5],i->value[6]);
		break;
	case min45:		
		op->m45_trend.init((int)p->value[0],p->value[1],p->value[2],p->value[3],i->value[0],i->value[1],i->value[2],i->value[3],i->value[4],i->value[5],i->value[6]);
		break;
	case min30:		
		op->m30_trend.init((int)p->value[0],p->value[1],p->value[2],p->value[3],i->value[0],i->value[1],i->value[2],i->value[3],i->value[4],i->value[5],i->value[6]);
		break;
	case min15:		
		op->m15_trend.init((int)p->value[0],p->value[1],p->value[2],p->value[3],i->value[0],i->value[1],i->value[2],i->value[3],i->value[4],i->value[5],i->value[6]);
		break;
	case min10:		
		op->m10_trend.init((int)p->value[0],p->value[1],p->value[2],p->value[3],i->value[0],i->value[1],i->value[2],i->value[3],i->value[4],i->value[5],i->value[6]);
		break;
	case min5:		
		op->m05_trend.init((int)p->value[0],p->value[1],p->value[2],p->value[3],i->value[0],i->value[1],i->value[2],i->value[3],i->value[4],i->value[5],i->value[6]);
		break;
	case all_period:
	default:
		break;
	}
	return 0;
}
//2.3 kdj: (dir, k, d, j, buy_cross=20, sell_cross=80);
//kdj-setting: (object,kdj,period,setting,buy_cross,sell_cross)	
//kdj-parse : (object,kdj,period,parse,dir,k,d,j)
//Ckdj 	month_kdj,week_kdj,day_kdj,hour4_kdj,hour_kdj,m45_kdj,m30_kdj,m15_kdj,m10_kdj,m05_kdj;
int Cmarket::set_op_kdj_param(Coperate *op ,Ciniformat *i,Ciniformat *p ) //i:ini setting file ,p:parse file
{
	if(p->value_count<4)
	{
		printf("kdj parse error:");p->display();
		return -1;
	}

	if(i->value_count<2)
	{
		printf("kdj setting error:");i->display();
		return -1;
	}
	switch(p->period)
	{
	case year:
		break;
	case month:
		op->month_kdj.init((int)p->value[0],p->value[1],p->value[2],p->value[3],i->value[0],i->value[1]);
		break;
	case week:
		op->week_kdj.init((int)p->value[0],p->value[1],p->value[2],p->value[3],i->value[0],i->value[1]);
		break;
	case day:
		op->day_kdj.init((int)p->value[0],p->value[1],p->value[2],p->value[3],i->value[0],i->value[1]);
		break;
	case hour4:
		op->hour4_kdj.init((int)p->value[0],p->value[1],p->value[2],p->value[3],i->value[0],i->value[1]);
		break;
	case hour1:
		op->hour_kdj.init((int)p->value[0],p->value[1],p->value[2],p->value[3],i->value[0],i->value[1]);
		break;
	case min45:
		op->m45_kdj.init((int)p->value[0],p->value[1],p->value[2],p->value[3],i->value[0],i->value[1]);
		break;
	case min30:
		op->m30_kdj.init((int)p->value[0],p->value[1],p->value[2],p->value[3],i->value[0],i->value[1]);
		break;
	case min15:
		op->m15_kdj.init((int)p->value[0],p->value[1],p->value[2],p->value[3],i->value[0],i->value[1]);
		break;
	case min10:
		op->m10_kdj.init((int)p->value[0],p->value[1],p->value[2],p->value[3],i->value[0],i->value[1]);
		break;
	case min5:
		op->m05_kdj.init((int)p->value[0],p->value[1],p->value[2],p->value[3],i->value[0],i->value[1]);
		break;
	case all_period:
	default:
		break;
	}
	return 0;
}
//2.10 cci: (int dir, cci, bottom=-400, middle=0, top=400, dir_line=100); //oil
//cci-setting: (object,cci,period,setting,bottom,middle,top,dir_line)	
//cci-parse : (object,cci,period,parse,dir,cci)
//	Ccci 	month_cci,week_cci,day_cci,hour4_cci,hour_cci,m45_cci,m30_cci,m15_cci,m10_cci,m05_cci;
int Cmarket::set_op_cci_param(Coperate *op ,Ciniformat *i,Ciniformat *p ) //i:ini setting file ,p:parse file
{
	if(p->value_count<2)
	{
		printf("cci parse error:");p->display();
		return -1;
	}

	if(i->value_count<4)
	{
		printf("cci setting error:");i->display();
		return -1;
	}
	switch(p->period)
	{
	case year:
		break;
	case month:
		op->month_cci.init((int)p->value[0],p->value[1],i->value[0],i->value[1],i->value[2],i->value[3]);
		break;
	case week:
		op->week_cci.init((int)p->value[0],p->value[1],i->value[0],i->value[1],i->value[2],i->value[3]);
		break;
	case day:
		op->day_cci.init((int)p->value[0],p->value[1],i->value[0],i->value[1],i->value[2],i->value[3]);
		break;
	case hour4:
		op->hour4_cci.init((int)p->value[0],p->value[1],i->value[0],i->value[1],i->value[2],i->value[3]);
		break;
	case hour1:
		op->hour_cci.init((int)p->value[0],p->value[1],i->value[0],i->value[1],i->value[2],i->value[3]);
		break;
	case min45:
		op->m45_cci.init((int)p->value[0],p->value[1],i->value[0],i->value[1],i->value[2],i->value[3]);
		break;
	case min30:
		op->m30_cci.init((int)p->value[0],p->value[1],i->value[0],i->value[1],i->value[2],i->value[3]);
		break;
	case min15:
		op->m15_cci.init((int)p->value[0],p->value[1],i->value[0],i->value[1],i->value[2],i->value[3]);
		break;
	case min10:
		op->m10_cci.init((int)p->value[0],p->value[1],i->value[0],i->value[1],i->value[2],i->value[3]);
		break;
	case min5:
		op->m05_cci.init((int)p->value[0],p->value[1],i->value[0],i->value[1],i->value[2],i->value[3]);
		break;
	case all_period:
	default:
		break;
	}
	return 0;
}
//2.5 rsi : ( dir, rsi_short, rsi_middle, rsi_long, bottom=15, top=85);
//rsi-setting: (object,rsi,period,setting,bottom,top)	
//rsi-parse : (object,rsi,period,parse,dir,rsi_short,rsi_middle,rsi_long) 
//	Crsi	month_rsi,week_rsi,day_rsi,hour4_rsi,hour_rsi,m45_rsi,m30_rsi,m15_rsi,m10_rsi,m05_rsi;
int Cmarket::set_op_rsi_param(Coperate *op ,Ciniformat *i,Ciniformat *p ) //i:ini setting file ,p:parse file
{
	if(p->value_count<4)
	{
		printf("rsi parse error:");p->display();
		return -1;
	}

	if(i->value_count<2)
	{
		printf("rsi setting error:");i->display();
		return -1;
	}
	switch(p->period)
	{
	case year:
		break;
	case month:
		op->month_rsi.init((int)p->value[0],p->value[1],p->value[2],p->value[3],i->value[0],i->value[1]);
		break;
	case week:
		op->week_rsi.init((int)p->value[0],p->value[1],p->value[2],p->value[3],i->value[0],i->value[1]);
		break;
	case day:
		op->day_rsi.init((int)p->value[0],p->value[1],p->value[2],p->value[3],i->value[0],i->value[1]);
		break;
	case hour4:
		op->hour4_rsi.init((int)p->value[0],p->value[1],p->value[2],p->value[3],i->value[0],i->value[1]);
		break;
	case hour1:
		op->hour_rsi.init((int)p->value[0],p->value[1],p->value[2],p->value[3],i->value[0],i->value[1]);
		break;
	case min45:
		op->m45_rsi.init((int)p->value[0],p->value[1],p->value[2],p->value[3],i->value[0],i->value[1]);
		break;
	case min30:
		op->m30_rsi.init((int)p->value[0],p->value[1],p->value[2],p->value[3],i->value[0],i->value[1]);
		break;
	case min15:
		op->m15_rsi.init((int)p->value[0],p->value[1],p->value[2],p->value[3],i->value[0],i->value[1]);
		break;
	case min10:
		op->m10_rsi.init((int)p->value[0],p->value[1],p->value[2],p->value[3],i->value[0],i->value[1]);
		break;
	case min5:
		op->m05_rsi.init((int)p->value[0],p->value[1],p->value[2],p->value[3],i->value[0],i->value[1]);
		break;
	case all_period:
	default:
		break;
	}
	return 0;
}
//2.9	dma:(int dir, dma, ama, bottom=-4, middle=0, top=4, dir_line=1); //oil
//dma-setting: (object,dma,period,setting,diff,bottom,middle,top,dir_line)	
//dma-parse : (object,dma,period,parse,dir,dma,ama)
//Cdma 	month_dma,week_dma,day_dma,hour4_dma,hour_dma,m45_dma,m30_dma,m15_dma,m10_dma,m05_dma;
int Cmarket::set_op_dma_param(Coperate *op ,Ciniformat *i,Ciniformat *p ) //i:ini setting file ,p:parse file
{
	if(p->value_count<5)
	{
		printf("dma parse error:");p->display();
		return -1;
	}

	if(i->value_count<3)
	{
		printf("dma setting error:");i->display();
		return -1;
	}
	switch(p->period)
	{
	case year:
		break;
	case month:
		op->month_dma.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1],i->value[3],i->value[4]);
		break;
	case week:
		op->week_dma.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1],i->value[3],i->value[4]);
		break;
	case day:
		op->day_dma.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1],i->value[3],i->value[4]);
		break;
	case hour4:
		op->hour4_dma.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1],i->value[3],i->value[4]);
		break;
	case hour1:
		op->hour_dma.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1],i->value[3],i->value[4]);
		break;
	case min45:
		op->m45_dma.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1],i->value[3],i->value[4]);
		break;
	case min30:
		op->m30_dma.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1],i->value[3],i->value[4]);
		break;
	case min15:
		op->m15_dma.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1],i->value[3],i->value[4]);
		break;
	case min10:
		op->m10_dma.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1],i->value[3],i->value[4]);
		break;
	case min5:
		op->m05_dma.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1],i->value[3],i->value[4]);
		break;
	case all_period:
	default:
		break;
	}
	return 0;
}
//2.7 roc :(dir, roc, roc_ma, bottom=-3, top=3);
//roc-setting: (object,roc,period,setting,bottom,top)	
//roc-parse : (object,roc,period,parse,dir,roc,roc_ma)
//	Croc	month_roc,week_roc,day_roc,hour4_roc,hour_roc,m45_roc,m30_roc,m15_roc,m10_roc,m05_roc;
int Cmarket::set_op_roc_param(Coperate *op ,Ciniformat *i,Ciniformat *p ) //i:ini setting file ,p:parse file
{
	if(p->value_count<3)
	{
		printf("roc parse error:");p->display();
		return -1;
	}

	if(i->value_count<2)
	{
		printf("roc setting error:");i->display();
		return -1;
	}
	switch(p->period)
	{
	case year:
		break;
	case month:
		op->month_roc.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1]);
		break;
	case week:
		op->week_roc.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1]);
		break;
	case day:
		op->day_roc.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1]);
		break;
	case hour4:
		op->hour4_roc.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1]);
		break;
	case hour1:
		op->hour_roc.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1]);
		break;
	case min45:
		op->m45_roc.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1]);
		break;
	case min30:
		op->m30_roc.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1]);
		break;
	case min15:
		op->m15_roc.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1]);
		break;
	case min10:
		op->m10_roc.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1]);
		break;
	case min5:
		op->m05_roc.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1]);
		break;
	case all_period:
	default:
		break;
	}
	return 0;
}
//vol
int Cmarket::set_op_vol_param(Coperate *op ,Ciniformat *i,Ciniformat *p ) //i:ini setting file ,p:parse file
{
//	printf("set_op_vol_param\n");
	if(p->value_count<4)
	{
		printf("vol parse error:");p->display();
		return -1;
	}
	switch(p->period)
	{
	case year:
		break;
	case month:
		op->month_vol.init((int)p->value[0],p->value[1],(int)p->value[2],p->value[3]);
		break;
	case week:
		op->week_vol.init((int)p->value[0],p->value[1],(int)p->value[2],p->value[3]);
		break;
	case day:
		op->day_vol.init((int)p->value[0],p->value[1],(int)p->value[2],p->value[3]);
		break;
	case hour4:
		op->hour4_vol.init((int)p->value[0],p->value[1],(int)p->value[2],p->value[3]);
		break;
	case hour1:
		op->hour_vol.init((int)p->value[0],p->value[1],(int)p->value[2],p->value[3]);
		break;
	case min45:
		op->m45_vol.init((int)p->value[0],p->value[1],(int)p->value[2],p->value[3]);
		break;
	case min30:
		op->m30_vol.init((int)p->value[0],p->value[1],(int)p->value[2],p->value[3]);
		break;
	case min15:
		op->m15_vol.init((int)p->value[0],p->value[1],(int)p->value[2],p->value[3]);
		break;
	case min10:
		op->m10_vol.init((int)p->value[0],p->value[1],(int)p->value[2],p->value[3]);
		break;
	case min5:
		op->m05_vol.init((int)p->value[0],p->value[1],(int)p->value[2],p->value[3]);
		break;
	case all_period:
	default:
		break;
	}
//	printf("set_op_vol_param end!\n");
	return 0;
}

int Cmarket::set_op_ma_param(Coperate *op ,Ciniformat *i,Ciniformat *p ) //i:ini setting file ,p:parse file
{
	if(p->value_count<2)
	{
		printf("ma parse error:");p->display();
		return -1;
	}

	switch(p->period)
	{
	case year:
		op->ma_cycle11.init(p->value,p->value_count);//year
		break;
	case month:
		op->ma_cycle10.init(p->value,p->value_count);//month
		break;
	case week:
		op->ma_cycle9.init(p->value,p->value_count);//week
		break;
	case day:
		op->ma_cycle8.init(p->value,p->value_count);//day
		break;
	case hour4:
		op->ma_cycle7.init(p->value,p->value_count);//hour4
		break;
	case hour1:
		op->ma_cycle6.init(p->value,p->value_count);//hour1
		break;
	case min45:
		op->ma_cycle5.init(p->value,p->value_count);//min45
		break;
	case min30:
		op->ma_cycle4.init(p->value,p->value_count);//min30		
		break;
	case min15:
		op->ma_cycle3.init(p->value,p->value_count);//min15
		break;
	case min10:
		op->ma_cycle2.init(p->value,p->value_count);//min10
		break;
	case min5:
		op->ma_cycle1.init(p->value,p->value_count);//min5
		break;
	case all_period:
	default:
		break;
	}
	return 0;
}
//2.4 wr :(dir, wr, wr_long, bottom=3, middle=50, top=97,int negative=IS_NEG);
//negative:NO_NEG	1 (oil use ) ,IS_NEG	-1(default) (stock use)
//wr-setting: (object,wr,period,setting,bottom,middle,top,negative)	
//wr-parse : (object,wr,period,parse,dir,wr,wr_long)//wr_long :is option
//Cwr 	month_wr,week_wr,day_wr,hour4_wr,hour_wr,m45_wr,m30_wr,m15_wr,m10_wr,m05_wr;
int Cmarket::set_op_wr_param(Coperate *op ,Ciniformat *i,Ciniformat *p ) //i:ini setting file ,p:parse file
{
	if(p->value_count<3)
	{
		printf("wr parse error:");p->display();
		return -1;
	}

	if(i->value_count<4)
	{
		printf("wr setting error:");i->display();
		return -1;
	}
	if(p->value[2]<-200||p->value[2]>200)	p->value[2]=UN_INIT;
	switch(p->period)
	{
	case year:
		break;
	case month:
		op->month_wr.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1],i->value[2],(int)i->value[3]);
		break;
	case week:
		op->week_wr.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1],i->value[2],(int)i->value[3]);
		break;
	case day:
		op->day_wr.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1],i->value[2],(int)i->value[3]);
		break;
	case hour4:
		op->hour4_wr.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1],i->value[2],(int)i->value[3]);
		break;
	case hour1:
		op->hour_wr.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1],i->value[2],(int)i->value[3]);
		break;
	case min45:
		op->m45_wr.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1],i->value[2],(int)i->value[3]);
		break;
	case min30:
		op->m30_wr.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1],i->value[2],(int)i->value[3]);
		break;
	case min15:
		op->m15_wr.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1],i->value[2],(int)i->value[3]);
		break;
	case min10:
		op->m10_wr.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1],i->value[2],(int)i->value[3]);
		break;
	case min5:
		op->m05_wr.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1],i->value[2],(int)i->value[3]);
		break;
	case all_period:
	default:
		break;
	}
	return 0;
}
//2.8 cr:(int dir, cr,  a, b, c, diff=30, bottom=50, middle=100, top=150); //oil
//cr-setting: (object,cr,period,setting,diff,bottom,middle,top)	
//cr-parse : (object,cr,period,parse,dir,cr,a,b,c)
//	Ccr 	month_cr,week_cr,day_cr,hour4_cr,hour_cr,m45_cr,m30_cr,m15_cr,m10_cr,m05_cr;
int Cmarket::set_op_cr_param(Coperate *op ,Ciniformat *i,Ciniformat *p ) //i:ini setting file ,p:parse file
{
	if(p->value_count<5)
	{
		printf("cr parse error:");p->display();
		return -1;
	}

	if(i->value_count<4)
	{
		printf("cr setting error:");i->display();
		return -1;
	}
	switch(p->period)
	{
	case year:
		break;
	case month:
		op->month_cr.init((int)p->value[0],p->value[1],p->value[2],p->value[3],p->value[4],i->value[0],i->value[1],i->value[2],i->value[3]);
		break;
	case week:
		op->week_cr.init((int)p->value[0],p->value[1],p->value[2],p->value[3],p->value[4],i->value[0],i->value[1],i->value[2],i->value[3]);
		break;
	case day:
		op->day_cr.init((int)p->value[0],p->value[1],p->value[2],p->value[3],p->value[4],i->value[0],i->value[1],i->value[2],i->value[3]);
		break;
	case hour4:
		op->hour4_cr.init((int)p->value[0],p->value[1],p->value[2],p->value[3],p->value[4],i->value[0],i->value[1],i->value[2],i->value[3]);
		break;
	case hour1:
		op->hour_cr.init((int)p->value[0],p->value[1],p->value[2],p->value[3],p->value[4],i->value[0],i->value[1],i->value[2],i->value[3]);
		break;
	case min45:
		op->m45_cr.init((int)p->value[0],p->value[1],p->value[2],p->value[3],p->value[4],i->value[0],i->value[1],i->value[2],i->value[3]);
		break;
	case min30:
		op->m30_cr.init((int)p->value[0],p->value[1],p->value[2],p->value[3],p->value[4],i->value[0],i->value[1],i->value[2],i->value[3]);
		break;
	case min15:
		op->m15_cr.init((int)p->value[0],p->value[1],p->value[2],p->value[3],p->value[4],i->value[0],i->value[1],i->value[2],i->value[3]);
		break;
	case min10:
		op->m10_cr.init((int)p->value[0],p->value[1],p->value[2],p->value[3],p->value[4],i->value[0],i->value[1],i->value[2],i->value[3]);
		break;
	case min5:
		op->m05_cr.init((int)p->value[0],p->value[1],p->value[2],p->value[3],p->value[4],i->value[0],i->value[1],i->value[2],i->value[3]);
		break;
	case all_period:
	default:
		break;
	}
	return 0;
}
//2.6 vr :(dir, vr_short, vr_long, diff=40, bottom=50, middle=100 , top=150);
//vr-setting: (object,vr,period,setting,diff,bottom,middle,top)	
//vr-parse : (object,vr,period,parse,dir,vr_short,vr_long)
//Cvr 	month_vr,week_vr,day_vr,hour4_vr,hour_vr,m45_vr,m30_vr,m15_vr,m10_vr,m05_vr;
int Cmarket::set_op_vr_param(Coperate *op ,Ciniformat *i,Ciniformat *p ) //i:ini setting file ,p:parse file
{
	if(p->value_count<3)
	{
		printf("vr parse error:");p->display();
		return -1;
	}

	if(i->value_count<4)
	{
		printf("vr setting error:");i->display();
		return -1;
	}
	switch(p->period)
	{
	case year:
		break;
	case month:
		op->month_vr.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1],i->value[2],i->value[3]);
		break;
	case week:
		op->week_vr.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1],i->value[2],i->value[3]);
		break;
	case day:
		op->day_vr.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1],i->value[2],i->value[3]);
		break;
	case hour4:
		op->hour4_vr.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1],i->value[2],i->value[3]);
		break;
	case hour1:
		op->hour_vr.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1],i->value[2],i->value[3]);
		break;
	case min45:
		op->m45_vr.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1],i->value[2],i->value[3]);
		break;
	case min30:
		op->m30_vr.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1],i->value[2],i->value[3]);
		break;
	case min15:
		op->m15_vr.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1],i->value[2],i->value[3]);
		break;
	case min10:
		op->m10_vr.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1],i->value[2],i->value[3]);
		break;
	case min5:
		op->m05_vr.init((int)p->value[0],p->value[1],p->value[2],i->value[0],i->value[1],i->value[2],i->value[3]);
		break;
	case all_period:
	default:
		break;
	}
	return 0;
}

int Cmarket::set_op_param(Coperate *op ,Ciniformat *i,Ciniformat *p ) //i:ini setting file ,p:parse file
{
	switch(p->norm)
	{
	case boll:
		this->set_op_boll_param(op,i,p);
		break;
	case macd:
		this->set_op_macd_param(op,i,p);
		break;
	case kdj:
		this->set_op_kdj_param(op,i,p);
		break;
	case cci:
		this->set_op_cci_param(op,i,p);
		break;	
	case vol:
		this->set_op_vol_param(op,i,p);
		break;
	case rsi:
		this->set_op_rsi_param(op,i,p);
		break;
	case dma:
		this->set_op_dma_param(op,i,p);
		break;
	case roc:
		this->set_op_roc_param(op,i,p);
		break;
	case ma:
		this->set_op_ma_param(op,i,p);
		break;
	case wr:
		this->set_op_wr_param(op,i,p);
		break;
	case cr:
		this->set_op_cr_param(op,i,p);
		break;
	case vr:
		this->set_op_vr_param(op,i,p);
		break;
	default:
		break;
	}
	return 0;
}

void Cmarket::parse(char * ini_f,char *p_f,char *name)//ini:setting file , p_f:parse file ,name :
{
	Cparseini ini,inf;//ini file, input file
	Ciniformat* i ,*p; //i: ini  f:p_f
	Coperate op;

	if(!ini.parse(ini_f)) return; //null or error setting file return
	if(!inf.parse(p_f)) return;//null or error input return
//	ini.travelH(ini.head);//test ok
//	inf.travelH(inf.head);//test ok
	for(p=inf.head;p;)
	{
		if(name&&strcmp(p->name,name))//only parse point name
		{
			p=p->next;
			continue;
		}

		i=ini.find(p->name,p->norm,p->period,all_action);//use all_action ignore setting  action cmp.
		if(i)	this->set_op_param(&op,i,p);//set current parameter to Coperate class

		if(!name&&p->next&&strcmp(p->name,p->next->name))//no point name and p->name block end, new block start
		{
			op.operate();
			op.reset();
		}
		p=p->next;
	}
	if(name)	op.operate();
}

void Cmarket::parse(char *p_f,char *name)//ini:setting file=op.ini , p_f:parse file ,name :
{
	this->parse("op.ini",p_f,name);
}

int main(int argc, char* argv[])// obj ,parse file , seting file
{
	Cmarket market;
//	market.stock_parse();
//	market.nyme_oil_parse();
//	market.huaxia_oil_parse();
//	market.huaxia_silver_parse();
	
	char * obj="szzs";
	char * s_f="opsetting.ini";
	char * p_f="parse.txt";

	if(argc >1) obj=argv[1];
	if(argc >2)	 s_f=argv[2];
	if(argc >3)	 p_f=argv[3];
	
	printf("Object=%s,Setting=%s ,Parse=%s \n",obj,s_f,p_f);

	market.parse(s_f,p_f,obj);

	return 0;
}
#endif
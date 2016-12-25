#ifndef PERCENT_TIME_H
#define PERCENT_TIME_H

#define PERCENT_TIME_DEBUG	1
#define STEP_DAYS	46 //46*8=365+3

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

/*
item					info			percent
01.January			01-10		0%
						10-20		0%
						20-end		0->20%(buy +  )

02.February		01-10		20->50%(buy +  )
						10-20		50->100%(buy +  )
						20-end		100%(buy +  )

03.March			01-10		100%
						10-20		100% 
						20-end		100%
 
04.April			01-10		100%
						10-20		100%->0% (sell -)
						20-end		0% 4/25(must =0%)

05.May				01-10		0->30% (buy+ and change blue)
						10-20		30->0% (sell - 5.15 must=0% wednesday)
						20-end		0%
 
 06.June			01-10		0->20%
						10-20		20->0% (6.15 +-  wednesday)
						20-end		0% (6.22 must=0%)

07.July				01-10		0%
						10-20		0%
						20-end		0%

08.August			01-10		0%
						10-20		0%
						20-end		0->30%

09.September	01-10		30-100%
						10-20		100%
						20-end		100->0% (9.25 must=%0 wednesday)

10.October		01-10		0->50%
						10-20		50->100%
						20-end		100%

11.November	01-10		100%
						10-20		100->20% (or 11.15->0% wednesday)
						20-end		20->0% (11.22 must=0%)
 
 
12.Devember		01-10		0%
						10-20		0%
						20-end		0%
 */

struct s_percent
{
	int mon;//month
	int sday;//start mday 
	int eday;//end mday
	int per; //percent
	int buy_sell;//1 buy .-1 sell 0 keep 2 change blue
};
#define PERCENT_COUNT 36
class CpercentDate
{
public:
	time_t t; 
	struct tm *gmt, *area; 
	s_percent percent[PERCENT_COUNT];
	int count;//point current++ index for add_percent //private  value do not change.
	int per,buy_sell;
	int pre_per,inc_count,inc_per; //previous percent ,current percent ,next percent,increase percent
public:
	CpercentDate();
	~CpercentDate();
	void initPercent();
	void display();
	void display(int year,int mon,int mday,int wday,int yday);
	int add_percent(int mon,int sday,int eday,int per,int buy_sell);
	int parse (int year,int mon,int mday,int wday,int yday);
	int parse();
	int predict(int count,int year,int  mon,int mday,int wday,int yday,int yearEnd=365);
	int predict(int count);//days count
};


#endif
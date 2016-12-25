//**********************************************************************
//**                                                                  **
//**        (C)Copyright Prophet Hunter_Chen   2015-10                **
//**                                                                  **
//**              All Rights Reserved.                                **
//**                                                                  **
//**********************************************************************

#ifndef OPERATE_H
#define OPERATE_H

#define OPERATE_TEST	 1

#include "percent_time.h"

#if PERCENT_TIME_DEBUG
#undef  OPERATE_TEST
#define OPERATE_TEST	 0
#endif //PERCENT_TIME_DEBUG

#include "parseini.h"

#define DIR_UPER 1
#define DIR_DOWN -1
#define DIR_NONE 0


#define SPARATE		
#define UN_INIT	0x7FFFFFF
#define NO_INIT 0x5555AAAA
#define NO_NEG	1
#define IS_NEG	-1

#define CYCLE_COUNT	13	//year ,season,month,week,day,4hour,hour,min45,min 30,min 15,min 10,min 5
#define PRICE_COUNT (CYCLE_COUNT*5)
#define MA_DIFF_PERCENT 0.03

//operate pasre enable bit
#define ENABLE_FLAG_COUNT		5
//BOLL
#define M05_PRICE_EN 0x1 		//bit0
#define M10_PRICE_EN 0x2 		//bit1
#define M15_PRICE_EN 0x4 		//bit2
#define M30_PRICE_EN 0x8 		//bit3
#define HOUR_PRICE_EN 0x10 		//bit4
#define DAY_PRICE_EN 0x20 		//bit5
#define WEEK_PRICE_EN 0x40 		//bit6
#define MONTH_PRICE_EN 0x80		//bit7
#define ALL_PRICE_EN	(M05_PRICE_EN|M10_PRICE_EN|M15_PRICE_EN|M30_PRICE_EN|HOUR_PRICE_EN|DAY_PRICE_EN|WEEK_PRICE_EN|MONTH_PRICE_EN)

//MACD
#define M05_TREND_EN 0x100  		//bit8
#define M10_TREND_EN 0x200  		//bit9
#define M15_TREND_EN 0x400   		//bit10
#define M30_TREND_EN 0x800  		//bit11
#define HOUR_TREND_EN 0x1000 		//bit12
#define DAY_TREND_EN 0x2000 		//bit13
#define WEEK_TREND_EN 0x4000 		//bit14
#define MONTH_TREND_EN 0x8000		//bit15
#define ALL_TREND_EN	(M05_TREND_EN|M10_TREND_EN|M15_TREND_EN|M30_TREND_EN|HOUR_TREND_EN|DAY_TREND_EN|WEEK_TREND_EN|MONTH_TREND_EN)

//KDJ
#define M05_KDJ_EN 0x10000  		//bit16
#define M10_KDJ_EN 0x20000  		//bit17
#define M15_KDJ_EN 0x40000  		//bit18
#define M30_KDJ_EN 0x80000  		//bit19
#define HOUR_KDJ_EN 0x100000		//bit20
#define DAY_KDJ_EN 0x200000 		//bit21
#define WEEK_KDJ_EN 0x400000		//bit22
#define MONTH_KDJ_EN 0x800000		//bit23
#define ALL_KDJ_EN	(M05_KDJ_EN|M10_KDJ_EN|M15_KDJ_EN|M30_KDJ_EN|HOUR_KDJ_EN|DAY_KDJ_EN|WEEK_KDJ_EN|MONTH_KDJ_EN)

//WR
#define M05_WR_EN 0x1000000 		//bit24
#define M10_WR_EN 0x2000000 		//bit25
#define M15_WR_EN 0x4000000 		//bit26
#define M30_WR_EN 0x8000000 		//bit27
#define HOUR_WR_EN 0x10000000		//bit28
#define DAY_WR_EN 0x20000000		//bit29
#define WEEK_WR_EN 0x40000000		//bit30
#define MONTH_WR_EN 0x80000000		//bit31
#define ALL_WR_EN	(M05_WR_EN|M10_WR_EN|M15_WR_EN|M30_WR_EN|HOUR_WR_EN|DAY_WR_EN|WEEK_WR_EN|MONTH_WR_EN)

//CYCLE
#define M05_CYCLE_EN	(M05_WR_EN|M05_KDJ_EN|M05_TREND_EN|M05_PRICE_EN)
#define M10_CYCLE_EN	(M10_WR_EN|M10_KDJ_EN|M10_TREND_EN|M10_PRICE_EN)
#define M15_CYCLE_EN	(M15_WR_EN|M15_KDJ_EN|M15_TREND_EN|M15_PRICE_EN)
#define M30_CYCLE_EN	(M30_WR_EN|M30_KDJ_EN|M30_TREND_EN|M30_PRICE_EN)
#define HOUR_CYCLE_EN	(HOUR_WR_EN|HOUR_KDJ_EN|HOUR_TREND_EN|HOUR_PRICE_EN)
#define DAY_CYCLE_EN	(DAY_WR_EN|DAY_KDJ_EN|DAY_TREND_EN|DAY_PRICE_EN)
#define WEEK_CYCLE_EN	(WEEK_WR_EN|WEEK_KDJ_EN|WEEK_TREND_EN|WEEK_PRICE_EN)
#define MONTH_CYCLE_EN	(MONTH_WR_EN|MONTH_KDJ_EN|MONTH_TREND_EN|MONTH_PRICE_EN)

//operate enable[1] bit
//RSI
#define M05_RSI_EN 0x1  		//bit0
#define M10_RSI_EN 0x2  		//bit1
#define M15_RSI_EN 0x4  		//bit2
#define M30_RSI_EN 0x8  		//bit3
#define HOUR_RSI_EN 0x10		//bit4
#define DAY_RSI_EN 0x20 		//bit5
#define WEEK_RSI_EN 0x40		//bit6
#define MONTH_RSI_EN 0x80		//bit7
#define ALL_RSI_EN	(M05_RSI_EN|M10_RSI_EN|M15_RSI_EN|M30_RSI_EN|HOUR_RSI_EN|DAY_RSI_EN|WEEK_RSI_EN|MONTH_RSI_EN)

//ROC
#define M05_ROC_EN 0x100		//bit8
#define M10_ROC_EN 0x200		//bit9
#define M15_ROC_EN 0x400		//bit10
#define M30_ROC_EN 0x800		//bit11
#define HOUR_ROC_EN 0x1000		//bit12
#define DAY_ROC_EN 0x2000		//bit13
#define WEEK_ROC_EN 0x4000		//bit14
#define MONTH_ROC_EN 0x8000		//bit15
#define ALL_ROC_EN	(M05_ROC_EN|M10_ROC_EN|M15_ROC_EN|M30_ROC_EN|HOUR_ROC_EN|DAY_ROC_EN|WEEK_ROC_EN|MONTH_ROC_EN)
//VR
#define M05_VR_EN 0x10000		//bit16
#define M10_VR_EN 0x20000		//bit17
#define M15_VR_EN 0x40000		//bit17
#define M30_VR_EN 0x80000		//bit18
#define HOUR_VR_EN 0x100000 	//bit20
#define DAY_VR_EN 0x200000		//bit21
#define WEEK_VR_EN 0x400000		//bit22
#define MONTH_VR_EN 0x800000	//bit23
#define ALL_VR_EN	(M05_VR_EN|M10_VR_EN|M15_VR_EN|M30_VR_EN|HOUR_VR_EN|DAY_VR_EN|WEEK_VR_EN|MONTH_VR_EN)

//CR
#define M05_CR_EN   0x1000000 		//bit24
#define M10_CR_EN   0x2000000 		//bit25
#define M15_CR_EN   0x4000000 		//bit26
#define M30_CR_EN   0x8000000 		//bit27
#define HOUR_CR_EN  0x10000000   	//bit28
#define DAY_CR_EN   0x20000000		//bit29
#define WEEK_CR_EN  0x40000000		//bit30
#define MONTH_CR_EN 0x80000000  	//bit31
#define ALL_CR_EN	(M05_CR_EN|M10_CR_EN|M15_CR_EN|M30_CR_EN|HOUR_CR_EN|DAY_CR_EN|WEEK_CR_EN|MONTH_CR_EN)

//CYCLE2
#define M05_CYCLE_EN2	(M05_RSI_EN|M05_ROC_EN|M05_VR_EN|M05_CR_EN)
#define M10_CYCLE_EN2	(M10_RSI_EN|M10_ROC_EN|M10_VR_EN|M10_CR_EN)
#define M15_CYCLE_EN2	(M15_RSI_EN|M15_ROC_EN|M15_VR_EN|M15_CR_EN)
#define M30_CYCLE_EN2	(M30_RSI_EN|M30_ROC_EN|M30_VR_EN|M30_CR_EN)
#define HOUR_CYCLE_EN2	(HOUR_RSI_EN|HOUR_ROC_EN|HOUR_VR_EN|HOUR_CR_EN)
#define DAY_CYCLE_EN2	(DAY_RSI_EN|DAY_ROC_EN|DAY_VR_EN|DAY_CR_EN)
#define WEEK_CYCLE_EN2	(WEEK_RSI_EN|WEEK_ROC_EN|WEEK_VR_EN|WEEK_CR_EN)
#define MONTH_CYCLE_EN2	(MONTH_RSI_EN|MONTH_ROC_EN|MONTH_VR_EN|MONTH_CR_EN)

//operate enable[2] bit
#define M05_DMA_EN 0x1  		//bit0
#define M10_DMA_EN 0x2  		//bit1
#define M15_DMA_EN 0x4  		//bit2
#define M30_DMA_EN 0x8  		//bit3
#define HOUR_DMA_EN 0x10		//bit4
#define DAY_DMA_EN 0x20 		//bit5
#define WEEK_DMA_EN 0x40		//bit6
#define MONTH_DMA_EN 0x80		//bit7
#define ALL_DMA_EN	(M05_DMA_EN|M10_DMA_EN|M15_DMA_EN|M30_DMA_EN|HOUR_DMA_EN|DAY_DMA_EN|WEEK_DMA_EN|MONTH_DMA_EN)

//operate enable[2] bit
#define M05_CCI_EN 0x1  		//bit0
#define M10_CCI_EN 0x2  		//bit1
#define M15_CCI_EN 0x4  		//bit2
#define M30_CCI_EN 0x8  		//bit3
#define HOUR_CCI_EN 0x10		//bit4
#define DAY_CCI_EN 0x20 		//bit5
#define WEEK_CCI_EN 0x40		//bit6
#define MONTH_CCI_EN 0x80		//bit7
#define ALL_CCI_EN	(M05_CCI_EN|M10_CCI_EN|M15_CCI_EN|M30_CCI_EN|HOUR_CCI_EN|DAY_CCI_EN|WEEK_CCI_EN|MONTH_CCI_EN)

//CYCLE3
#define M05_CYCLE_EN3	(M05_DMA_EN|M05_CCI_EN)
#define M10_CYCLE_EN3	(M10_DMA_EN|M10_CCI_EN)
#define M15_CYCLE_EN3	(M15_DMA_EN|M15_CCI_EN)
#define M30_CYCLE_EN3	(M30_DMA_EN|M30_CCI_EN)
#define HOUR_CYCLE_EN3	(HOUR_DMA_EN|HOUR_CCI_EN)
#define DAY_CYCLE_EN3	(DAY_DMA_EN|DAY_CCI_EN)
#define WEEK_CYCLE_EN3	(WEEK_DMA_EN|WEEK_CCI_EN)
#define MONTH_CYCLE_EN3	(MONTH_DMA_EN|MONTH_CCI_EN)

//CRange
typedef double AV_TYPE;
class Crange
{
public:
	double top;
	double middle;
	double bottom;
	double sell_line;
	double buy_line;
	double stop_line;
	double mid_location;
	int init_flag; //init flag
	int direction; //+ - 0 
	double dir_line;
public:
	Crange();
	AV_TYPE average(AV_TYPE *p,int n);
	void set_all_bmt(double low,double mid,double upper);//bottom=low, middle=mid,top =upper
	void reset();
	void set(double top,double middle,double bottom);
	void set(double buy_line,double sell_line);
	double location(double current,double top,double bottom);
	double location(double current); //(-50,0,+50)  <-50, >50
	double buy(double buy_line=-0.003);//build buy data
	double sell(double sell_line=0.003);//build sell 
	double mid_line(double high,double low);
	double buy_mid();
	double sell_mid();
	void display();
	void display(double * p , int n,char *name);
};

class Cboll
{
public:
	double upper;
	double middle;
	double lower;
};
class Cprice:public Crange //1BOLL
{
public:
	double price;
public:
	Cprice();
	void reset();
	double location(); //(-50,0,+50)  <-50, >50
	double location(double top,double bottom);
	int parse(char *cycle); //>0 buy <0 sell ==0 stop
	void init(int dir,double price,double low,double mid,double upper,double buy=-0.1,double sell=0.1);
	int parse_all_price(int buy_sell,int direction);
	void display(int buy_sell,char *cycle,int dir=0);
};

class Ctrend:public Crange //2MACD
{
public:
	double value;
	double dif;
	double dea;
	double cross_line;
	double zero_line;
public:
	Ctrend();
	void reset();
	int parse(char *cycle); 
	void init(int dir,double macd,double dif,double dea,double buy=-2.15,double sell=2.15,double low=-0.06,double mid=0,double upper=0.06,double cross_line=0.5,double zero_line=0.3);
};

class Ckdj:public Crange
{
public:
	double k;
	double d;
	double j;
	double buy_cross;
	double sell_cross;
public:
	Ckdj();
	void reset();
	int parse(char *cycle); 
	void init(int direction,double k,double d,double j,double buy_cross=20,double sell_cross=80);
};

class Cwr:public Crange
{
public:
	double wr,wr_long;
	int negative; //wr negative //default is -1
public:
	Cwr();
	void reset();
	void init(int direction,double wr,double wr_long,double bottom=3,double middle=50,double top=97,int negative=IS_NEG);
	void deal_negative();
	int parse(char * cycle);
};

class Crsi:public Crange
{
public:
	double rsi_short,rsi_middle,rsi_long;
public:
	Crsi();
	void reset();
	void init(int direction,double rsi_short,double rsi_middle,double rsi_long,double bottom=15,double top=85);
	int parse(char * cycle);
};

class Cvr:public Crange
{
public:
	double vr_short,vr_long,diff;
public:
	Cvr();
	void reset();
	void init(int direction,double vr_short,double vr_long,double diff=40,double bottom=50,double middle=100 ,double top=150);
	int parse(char * cycle);
};

class Croc:public Crange
{
public:
	double roc,roc_ma;
public:
	Croc();
	void reset();
	void init(int direction,double roc,double roc_ma,double bottom=-3,double top=3);
	int parse(char * cycle);
};

class Ccr:public Crange
{
public:
	double cr,a,b,c,diff;
public:
	Ccr();
	void reset();
	void init(int direction,double cr, double a,double b,double c,double diff=30,double bottom=50,double middle=100,double top=150); //oil
	int parse(char * cycle);
};


class Cdma:public Crange
{
public:
	double dma,ama;
public:
	Cdma();
	void reset();
	void init(int direction,double dma,double ama,double bottom=-4,double middle=0,double top=4,double dir_line=1); //oil
	int parse(char * cycle);
};

class Ccci:public Crange
{
public:
	double cci;
public:
	Ccci();
	void reset();
	void init(int direction,double cci,double bottom=-400,double middle=0,double top=400,double dir_line=100); //oil
	int parse(char * cycle);
};

class Cma:public Crange
{
public:
	double price;
	double ma[CYCLE_COUNT];
	int ma_dir[CYCLE_COUNT];//8 short to long cycle .like : 5 ,10,15,20,30,45,50,60,
	int count; //current init cycle count
public:
	Cma();
	void reset();
	void init(double * p,int count);//p[0]=ma dir ,p[1]=ma ...
	int parse(char * cycle);
};

class Cvol:public Crange
{
public:
	double vol_short,vol_long;
	int dir_short,dir_long;
public:
	Cvol();
	void reset();
	void init(int dir_short,double vol_short,int dir_long,double vol_long); 
	int parse(char * cycle);
};

class Cmessage //3
{
public:
	Cmessage();
	int good;//good value
	int bad;//bad value
	int set(int good,int bad);//return + good >bad ; 0 good==bad - good<bad
	int parse();
};

class Coperate//3-high;3-low={h,m30,m15}  middle->message
{
public:
	double price;
	Cmessage msg;
	//m:month  w:week d:day h4:4hour h:hour m:minute 45,30 ,15,10 5
	Cprice	month_price,week_price,day_price,hour4_price,hour_price,m45_price,m30_price,m15_price,m10_price,m05_price;//30,5,1 
	Ctrend	month_trend,week_trend,day_trend,hour4_trend,hour_trend,m45_trend,m30_trend,m15_trend,m10_trend,m05_trend;
	Ckdj 	month_kdj,week_kdj,day_kdj,hour4_kdj,hour_kdj,m45_kdj,m30_kdj,m15_kdj,m10_kdj,m05_kdj;
	Cwr 	month_wr,week_wr,day_wr,hour4_wr,hour_wr,m45_wr,m30_wr,m15_wr,m10_wr,m05_wr;
	Crsi	month_rsi,week_rsi,day_rsi,hour4_rsi,hour_rsi,m45_rsi,m30_rsi,m15_rsi,m10_rsi,m05_rsi;
	Croc	month_roc,week_roc,day_roc,hour4_roc,hour_roc,m45_roc,m30_roc,m15_roc,m10_roc,m05_roc;
	Cvr 	month_vr,week_vr,day_vr,hour4_vr,hour_vr,m45_vr,m30_vr,m15_vr,m10_vr,m05_vr;
	Ccr 	month_cr,week_cr,day_cr,hour4_cr,hour_cr,m45_cr,m30_cr,m15_cr,m10_cr,m05_cr;
	Cdma 	month_dma,week_dma,day_dma,hour4_dma,hour_dma,m45_dma,m30_dma,m15_dma,m10_dma,m05_dma;
	Ccci 	month_cci,week_cci,day_cci,hour4_cci,hour_cci,m45_cci,m30_cci,m15_cci,m10_cci,m05_cci;
	Cma 	ma_cycle1,ma_cycle2,ma_cycle3,ma_cycle4,ma_cycle5,ma_cycle6,ma_cycle7,ma_cycle8,ma_cycle9,ma_cycle10,ma_cycle11;//like:5 ,10,15 ,30,45,60,240,day,week,month,year
	Cvol 	month_vol,week_vol,day_vol,hour4_vol,hour_vol,m45_vol,m30_vol,m15_vol,m10_vol,m05_vol;

	int buy_sell_m,buy_sell_w,buy_sell_d,buy_sell_h4,buy_sell_h,buy_sell_m45,buy_sell_m30,buy_sell_m15,buy_sell_m10,buy_sell_m05,buy_sell_ma;
	int dir_month,dir_week,dir_day,dir_hour4,dir_hour,dir_m45,dir_m30,dir_m15,dir_m10,dir_m05,dir_ma;//case by case dir
	unsigned long enable[ENABLE_FLAG_COUNT];
public:
	int direction;
	int buy_sell;
	int buy;
	int sell;
	int percent;
public:
	Coperate();
	void reset();
	int all_direction();
	void display();
	int operate();
	int parse();
};

class Cperiod: public Coperate //cycle
{

};

class Cmarket
{
public:
	void nyme_oil_parse();//nyme
	void huaxia_oil_parse();//hua xia
	void huaxia_silver_parse();//silver huaxia
	void stock_parse();//szzs
	int set_op_boll_param(Coperate *op ,Ciniformat *i,Ciniformat *p );
	int set_op_macd_param(Coperate *op ,Ciniformat *i,Ciniformat *p ) ;
	int set_op_kdj_param(Coperate *op ,Ciniformat *i,Ciniformat *p );
	int set_op_cci_param(Coperate *op ,Ciniformat *i,Ciniformat *p ) ;
	int set_op_vol_param(Coperate *op ,Ciniformat *i,Ciniformat *p ) ;
	int set_op_rsi_param(Coperate *op ,Ciniformat *i,Ciniformat *p ) ;
	int set_op_dma_param(Coperate *op ,Ciniformat *i,Ciniformat *p );
	int set_op_roc_param(Coperate *op ,Ciniformat *i,Ciniformat *p ) ;
	int set_op_ma_param(Coperate *op ,Ciniformat *i,Ciniformat *p );
	int set_op_wr_param(Coperate *op ,Ciniformat *i,Ciniformat *p );
	int set_op_cr_param(Coperate *op ,Ciniformat *i,Ciniformat *p );
	int set_op_vr_param(Coperate *op ,Ciniformat *i,Ciniformat *p ) ;
	int set_op_param(Coperate *op ,Ciniformat *i,Ciniformat *p ); //i:ini setting file ,p:parse file
	void parse(char * ini_f,char *p_f,char *name);//ini_f:setting file , p_f:parse file ,name :
	void parse(char *p_f,char *name);//ini:setting file=op.ini , p_f:parse file ,name :
};
#endif
#ifndef TAB_DATA_H
#define TAB_DATA_H
#include < stdio.h >
#include < stdlib.h >
#include <string.h>

#define MA_COUNT	10
#define OBJECT_LEN	0x100
class CtabData
{
public:

	int ma_dir[MA_COUNT];//MA
	double ma[MA_COUNT];
	int ma_init[MA_COUNT];

	int vol_dir[2];//VOL
	double vol[2];
	int vol_init;

	int boll_dir;//BOLL
	double boll_low,boll_mid,boll_upper;
	int boll_init;

	int macd_dir;//MACD
	double macd_macd,macd_dif,macd_dea;
	int macd_init;

	int kdj_dir;//KDJ
	double kdj_k,kdj_d,kdj_j;
	int kdj_init;

	int rsi_dir;//RSI
	double rsi_short,rsi_middle,rsi_long;
	int rsi_init;

	int wr_dir;//WR
	double wr1,wr2;
	int wr_init;

	int roc_dir;//ROC
	double roc,roc_ma;
	int roc_init;

	int vr_dir;//VR
	double vr_short,vr_long;
	int vr_init;

	int dma_dir;//DMA
	double dma,dma_ama;
	int dma_init;

	int cr_dir;//CR
	double cr,cr_a,cr_b,cr_c;
	int cr_init;

	int cci_dir;//CCI
	double cci;
	int cci_init;

public:
	CtabData();
	void reset();
	int out(FILE *fp,char *obj,double price,char *cycle);
	int out(char *cpFileName,char *obj,double price,char *cycle);
};


#endif //TAB_DATA_H
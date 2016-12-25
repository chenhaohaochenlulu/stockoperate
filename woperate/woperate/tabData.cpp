
#include "stdafx.h"
#include "tabData.h"

CtabData::CtabData()
{
	int n;
	//MA
	for(n=0;n<MA_COUNT;n++)
	{
		this->ma_dir[n]=0;
		this->ma[n]=0;
		this->ma_init[n]=0;
	}
	//VOL
	this->vol[0]=0;
	this->vol_dir[0]=0;
	this->vol[1]=0;
	this->vol_dir[1]=0;
	this->vol_init=0;
	//BOLL
	this->boll_dir=0;
	this->boll_low=0;
	this->boll_mid=0;
	this->boll_upper=0;
	this->boll_init=0;
	//MACD
	this->macd_dir=0;
	this->macd_macd=0;
	this->macd_dif=0;
	this->macd_dea=0;
	this->macd_init=0;
	//KDJ
	this->kdj_dir=0;
	this->kdj_k=0;
	this->kdj_d=0;
	this->kdj_j=0;
	this->kdj_init=0;
	//RSI
	this->rsi_dir=0;
	this->rsi_short=0;
	this->rsi_middle=0;
	this->rsi_long=0;
	this->rsi_init=0;
	//WR
	this->wr_dir=0;
	this->wr1=0;
	this->wr2=0;
	this->wr_init=0;
	//ROC
	this->roc_dir=0;
	this->roc=0;
	this->roc_ma=0;
	this->roc_init=0;
	//VR
	this->vr_dir=0;
	this->vr_short=0;
	this->vr_long=0;
	this->vr_init=0;
	//DMA
	this->dma_dir=0;
	this->dma=0;
	this->dma_ama=0;
	this->dma_init=0;
	//CR
	this->cr_dir=0;
	this->cr=0;
	this->cr_a=0;
	this->cr_b=0;
	this->cr_c=0;
	this->cr_init=0;
	//CCI
	this->cci_dir=0;
	this->cci=0;
	this->cci_init=0;
}

void CtabData::reset()
{
	CtabData();
}

int CtabData::out(FILE *fp,char *obj,double price,char *cycle)
{
	int n,flag;
	if(!strlen(obj)) return -1;
	if(!strlen(cycle)) return -1;	
	
	//(object,ma,period,parse,dir[0],ma[0],dir[1],ma[1]...dir[n],ma[n],price)
	for(n=0,flag=0;n<MA_COUNT;n++){ //check if or not init
		if(this->ma_dir[n])	{flag=1;break;}//ma init flag =true
	}

	if(flag){//ma init flag =true
			fprintf(fp,"(%s,ma,%s,parse",obj,cycle);
			for(n=0,flag=0;n<MA_COUNT;n++){ 
				if(this->ma_dir[n]||this->ma_dir[n]){
					fprintf(fp,",%d,%0.2f",this->ma_dir[n],this->ma[n]);
				}
			}
			fprintf(fp,",%0.f)\n",price);
	}
	//vol-parse : (object,vol,period,parse,dir_short,vol_short,dir_long,vol_long)
	if(this->vol_dir[0]||this->vol_dir[1]||this->vol[0]||this->vol[1])
	{
		fprintf(fp,"(%s,vol,%s,parse,%d,%0.2f,%d,%0.2f)\n",obj,cycle,this->vol_dir[0],this->vol[0],this->vol_dir[1],this->vol[1]);
	}
	//boll-parse : (object,boll,period,parse,dir,price,low,mid,upper)	
	if(this->boll_dir||this->boll_low||this->boll_mid||this->boll_upper)
	{
		fprintf(fp,"(%s,boll,%s,parse,%d,%0.2f,%0.2f,%0.2f,%0.2f)\n",obj,cycle,this->boll_dir,price,this->boll_low,this->boll_mid,this->boll_upper);
	}
	//macd-parse : (object,macd,period,parse,dir,macd,dif,dea)
	if(this->macd_dir||this->macd_macd||this->macd_dif||this->macd_dea)
	{
		fprintf(fp,"(%s,macd,%s,parse,%d,%0.2f,%0.2f,%0.2f)\n",obj,cycle,this->macd_dir,this->macd_macd,this->macd_dif,this->macd_dea);
	}
	//kdj-parse : (object,kdj,period,parse,dir,k,d,j)
	if(this->kdj_dir||this->kdj_k||this->kdj_d||this->kdj_j)
	{
		fprintf(fp,"(%s,kdj,%s,parse,%d,%0.2f,%0.2f,%0.2f)\n",obj,cycle,this->kdj_dir,this->kdj_k,this->kdj_d,this->kdj_j);
	}
	//rsi-parse : (object,rsi,period,parse,dir,rsi_short,rsi_middle,rsi_long)
	if(this->rsi_dir||this->rsi_short||this->rsi_middle||this->rsi_long)
	{
		fprintf(fp,"(%s,rsi,%s,parse,%d,%0.2f,%0.2f,%0.2f)\n",obj,cycle,this->rsi_dir,this->rsi_short,this->rsi_middle,this->rsi_long);	
	}
	//wr-parse : (object,wr,period,parse,dir,wr,wr_long/1000)//wr_long :is not exist  setting>200 or<-200 .ie 1000
	if(this->wr_dir||this->wr1||this->wr2)
	{
		if(this->wr2)
			fprintf(fp,"(%s,wr,%s,parse,%d,%0.2f,%0.2f)\n",obj,cycle,this->wr_dir,this->wr1,this->wr2);	
		else
			fprintf(fp,"(%s,wr,%s,parse,%d,%0.2f,9999)\n",obj,cycle,this->wr_dir,this->wr1);	
	}
	//roc-parse : (object,roc,period,parse,dir,roc,roc_ma)
	if(this->roc_dir||this->roc||this->roc_ma)
	{
		fprintf(fp,"(%s,roc,%s,parse,%d,%0.2f,%0.2f)\n",obj,cycle,this->roc_dir,this->roc,this->roc_ma);	
	}
	//vr-parse : (object,vr,period,parse,dir,vr_short,vr_long)
	if(this->vr_dir||this->vr_short||this->vr_long)
	{
		fprintf(fp,"(%s,vr,%s,parse,%d,%0.2f,%0.2f)\n",obj,cycle,this->vr_dir,this->vr_short,this->vr_long);	
	}
	//dma-parse : (object,dma,period,parse,dir,dma,ama)
	if(this->dma_dir||this->dma||this->dma_ama)
	{
		fprintf(fp,"(%s,dma,%s,parse,%d,%0.2f,%0.2f)\n",obj,cycle,this->dma_dir,this->dma,this->dma_ama);	
	}
	//cr-parse : (object,cr,period,parse,dir,cr,a,b,c)
	if(this->cr_dir||this->cr||this->cr_a||this->cr_b||this->cr_c)
	{
		fprintf(fp,"(%s,cr,%s,parse,%d,%0.2f,%0.2f,%0.2f,%0.2f)\n",obj,cycle,this->cr_dir,this->cr,this->cr_a,this->cr_b,this->cr_c);	
	}
	//cci-parse : (object,cci,period,parse,dir,cci)
	if(this->cci_dir||this->cci)
	{
		fprintf(fp,"(%s,cci,%s,parse,%d,%0.2f)\n",obj,cycle,this->cci_dir,this->cci);	
	}
	fflush(fp);
	return 0;
}

int CtabData::out(char *cpFileName,char *obj,double price,char *cycle)
{
	FILE *fp;
	if(!(fp=fopen(cpFileName,"a"))){
		printf("Error:can not open the %s file.\n",cpFileName);
		return EOF;
	}
	
	this->out(fp,obj,price,cycle);

	fclose(fp);
	return 0;
}
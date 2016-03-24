# stockoperate


//2.norm
//systax: (object,norm,period,action,value[n])
//period:all,year,month,week,day,hour4,hour1,min45,min30,min15,min10,min5,

//2.1 boll: ( dir, price, low, mid, upper, buy=-0.1, sell=0.1);
//boll-setting: (object,boll,period,setting,buy,sell)	

(szzs,boll,all,setting,-0.1,0.1)	

//2.2 macd: (dir, macd, dif, dea, buy=-2.15, sell=2.15, low=-0.06, mid=0, upper=0.06, cross_line=0.5, zero_line=0.3);
//macd-setting: (object,macd,period,setting,buy,sell,low,mid,upper,cross_line,zero_line)	

(szzs,macd,month,setting,-200,200,-150,0,150,100,20)	
(szzs,macd,week,setting,-300,300,-200,0,2000,150,30)	
(szzs,macd,day,setting,-200,200,-200,0,200,150,20)	
(szzs,macd,hour1,setting,-100,100,-20,0,20,40,20)

//2.3 kdj: (dir, k, d, j, buy_cross=20, sell_cross=80);
//kdj-setting: (object,kdj,period,setting,buy_cross,sell_cross)	

 (szzs,kdj,month,setting,30,70)	
 (szzs,kdj,week,setting,20,80)	
 (szzs,kdj,day,setting,20,80)	
 (szzs,kdj,hour1,setting,20,80)
 
 
 //2.4 wr :(dir, wr, wr_long, bottom=3, middle=50, top=97,int negative=IS_NEG);
//negative:NO_NEG	1 (oil use ) ,IS_NEG	-1(default) (stock use)
//wr-setting: (object,wr,period,setting,bottom,middle,top,negative)	

(szzs,wr,month,setting,3,50,97,-1)
(szzs,wr,week,setting,2,50,98,-1)
(szzs,wr,day,setting,3,50,97,-1)
(szzs,wr,hour1,setting,5,50,95,-1)

//2.5 rsi : ( dir, rsi_short, rsi_middle, rsi_long, bottom=15, top=85);
//rsi-setting: (object,rsi,period,setting,bottom,top)	

 (szzs,rsi,month,setting,30,70)
 (szzs,rsi,week,setting,25,75)
 (szzs,rsi,day,setting,20,80)
 (szzs,rsi,hour1,setting,25,75)
 
//2.12 vol: (dir_short, vol_short,dir_long, vol_long)
//vol-setting: (object,vol,all,setting)	

(szzs,vol,all,setting)	
 
 //2.11 ma: n<9
//ma-setting: (object,ma,all,setting)	

(szzs,ma,all,setting)





stock-operate

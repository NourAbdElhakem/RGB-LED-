
#include "RGP_LED.h"
#include "STDTYPS.h"
#include "MEMMAP.h"
#include "UTILS.h"
#include "timer.h"

/*****************************CONFG**************************************/

void RGB_INIT(void)
{
	TIMER0_Init(TIMER0_FASTPWM_MODE,TIMER0_SCALER_8);
	Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_8);
	Timer1_OCRA1Mode(OCRA_NON_INVERTING);
	Timer1_OCRB1Mode(OCRB_NON_INVERTING);
	TIMER0_OC0Mode(OC0_NON_INVERTING);
	ICR1=255;
}



static u8 arr_RGB[COLORS][RGB]={
	/* R         G            B*/
	{	0	,	0	,	0      },//COLOR 0 BLACK
	{	254	,	0	,	0       },//COLOR 1 RED
	{	0	,  254	,   0       },//COLOR 2 GREEN
	{	0	,	0	,  254      },//COLOR 3 BLUE
	{	0	,	0	,	0       },//COLOR 4
	{	254	,	0	,	0       },//COLOR 5
	{	15	,  15	,   15      },//COLOR 6
	{	30	,	30	,  30       },//COLOR 7
	{	45	,	45	,	45      },//COLOR 8
	{	60	,	60	,	60      },//COLOR 9
	{	75	,  75	,   75      },//COLOR 10
	{	90	,	90	,  90       },//COLOR 11
	{	105	,  105	,	105     },//COLOR 12
	{	120	,	120	,	 120    },//COLOR 13
	{	135	,	135	,	 135    },//COLOR 14
	{	150	,	150	,	 150    },//COLOR 15
	{	165	,	165	,	 165    },//COLOR 16
	{	180	,	180	,	 180    },//COLOR 17
	{	195	,	195	,	 195    },//COLOR 18
	{	210	,	210	,	 210    },//COLOR 19
	{	225	,	225	,	 225    },//COLOR 20
	{	240	,	240	,	 240    },//COLOR 21
	{	254	,	254	,	 254    },//COLOR 22
	{	254	,	240	,	 0	    },//COLOR 24
	{	254	,	225	,	 0    },//COLOR 24
	{	254	,	210	,	 0    },//COLOR 25
	{	254	,	195	,	 0    },//COLOR 26
	{	254	,	180	,	 0    },//COLOR 27
	{	254	,	165	,	 0    },//COLOR 28
	{	254	,	150	,	 0    },//COLOR 29
	{	254	,	135	,	 0    },//COLOR 30
	{	254	,	120	,	 0    },//COLOR 31
	{	254	,	105	,	 0    },//COLOR 32
	{	254	,	90	,	 0    },//COLOR 33
	{	254	,	75	,	 0    },//COLOR 34
	{	254	,	60	,	 0    },//COLOR 35
	{	254	,	45	,	 0    },//COLOR 36
	{	254	,	30	,	 0    },//COLOR 37
	{	254	,	15	,	 0    },//COLOR 38
	{	0   ,	254	,	240	  },//COLOR 39
	{ 240  ,	 0  ,  254	  },//COLOR 55
	{ 225	,	 0  ,  254	  },//COLOR 56
	{ 210	,	 0  ,  254 	  },//COLOR 57
	{ 195	,	 0  ,  254	  },//COLOR 58
	{ 180	,	 0  ,  254	  },//COLOR 59
	{ 165	,	 0  ,  254	  },//COLOR 60
	{ 150	,	 0  ,  254    },//COLOR 61
	{ 135	,	 0  ,  254	  },//COLOR 62
	{ 120	,	 0	,  254	  },//COLOR 63
	{ 105	,	 0  ,  254    },//COLOR 64
	{ 90	,	 0  ,  254	  },//COLOR 65
	{ 75	,	 0  ,  254	  },//COLOR 66
	{ 60	,	 0  ,  254	  },//COLOR 67
	{ 45	,	 0  ,  254    },//COLOR 68
	{ 30	,	 0  ,  254	  },//COLOR 69
	{ 15	,	 0  ,  254    },//COLOR 70
	{	0   ,	254	,	225   },//COLOR 40
	{	0   ,	254	,	210   },//COLOR 41
	{	0   ,   254	,	195	  },//COLOR 42
	{	0   ,	254	,	180   },//COLOR 43
	{	0   ,	254	,	165	  },//COLOR 44
	{	0   ,	254	,	150   },//COLOR 45
	{	0   ,	254	,	135   },//COLOR 46
	{	0   ,	254	,	120   },//COLOR 47
	{	0   ,	254	,	105   },//COLOR 48
	{	0   ,	254	,	90	  },//COLOR 49
	{	0   ,	254	,	75    },//COLOR 50
	{	0   ,	254	,	60    },//COLOR 51
	{	0   ,   254	,	45    },//COLOR 52
	{	0   ,	254	,	30	  },//COLOR 53
	{	0   ,   254	,	15    },//COLOR 54
};
void RGB_SETCOLOR(u8 color)
{
	OCR0=arr_RGB[color][0];
	OCR1A=arr_RGB[color][1];
	OCR1B=arr_RGB[color][2];
}
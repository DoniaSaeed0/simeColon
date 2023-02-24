
#include"main_headers.h"
extern type_states g_states;
static RTC_Typestates RTC_state =RTC_initstate;

//static time RTCTime;

void RTCInitState()
{
	while(1){};
}

void RTCOnState()
{
	while(1){};
}



void RTCState()
{
	while(g_states==RTC)
	{
		switch(RTC_state)
		{
		case RTC_initstate:
			RTCInitState();
			break;
		case RTC_ONstate:
			RTCOnState();
			break;
		}
	}

}

/*********************************************************************
*
*  HC-SR 초음파 거리 측정 후 이동 방향 변
*   
*********************************************************************/
#include <stdio.h>
#include <wiringPi.h>

//- 센서 연결 핀 번호 선언 ------------------------------------------------------------------------------------------------------------------------------------
#define TRIG_PIN				28
#define ECHO_PIN				29

#define IN1_PIN				1
#define IN2_PIN				4
#define IN3_PIN				8
#define IN4_PIN				9


//- 모터 동작 값  선언 ------------------------------------------------------------------------------------------------------------------------------------------
#define INIT_VALUE  		HIGH, HIGH, HIGH , HIGH, "INIT"
#define GO_VALUE  		    HIGH, LOW,   HIGH , LOW,   "GO"
#define BACK_VALUE  		LOW,   HIGH, LOW ,   HIGH, "BACK"
#define LEFT_VALUE  		LOW,   HIGH, HIGH , LOW,   "LEFT"
#define RIGHT_VALUE  		HIGH, LOW,   LOW ,   HIGH, "RIGHT"
#define STOP_VALUE  		LOW,   LOW,   LOW ,   LOW,   "STOP"

#define LIMIT_DISTANCE  20



//- 함수  선언 ---------------------------------------------------------------------------------------------------------------------------------------------------------------
void controlMotor(int _IN1, int _IN2, int _IN3, int _IN4, char *msg);
void initSensor();
void checkUltra();

//- 전역변수 선언 -------------------------------------------------------------------------------------------------------------------------------------------------------
int gDetect = 0;   
int gCnt = 5;

//- 기능 구현  ----------------------------------------------------------------------------------------------------------------------------------------------------------------
int main(void)
{
	 //- 라이브러리 초기화
	if(wiringPiSetup() == -1)    return 0;
	
	//- 센서 및 모듈 초기
    initSensor();
    
	
	while(gCnt>0)
	{
		   controlMotor(GO_VALUE);	
		   delay(1000);
	         gCnt--;
	}
	
	controlMotor(STOP_VALUE);	
	delay(1000);
	return 0;
}


//- 센서 초기화 ------------------------------------------------------------------------------------------------------------
void initSensor()
{
	//- 초음파 센서 초기화
	pinMode(TRIG_PIN, OUTPUT);
	pinMode(ECHO_PIN, INPUT);


    //- DC 모터 초기화
	pinMode(IN1_PIN, OUTPUT);
	pinMode(IN2_PIN, OUTPUT);
	pinMode(IN3_PIN, OUTPUT);
	pinMode(IN4_PIN, OUTPUT);	
	
	controlMotor(INIT_VALUE);
	delay(1000);
	
}

//---------------------------------------------------------------------------------------------------------------------------------------
//- 모터 제어 관련 함수
//---------------------------------------------------------------------------------------------------------------------------------------
void controlMotor(int _IN1, int _IN2, int _IN3, int _IN4, char *msg)
{
		digitalWrite(IN1_PIN, _IN1);
		digitalWrite(IN2_PIN, _IN2);
		digitalWrite(IN3_PIN, _IN3);
		digitalWrite(IN4_PIN, _IN4);			
		printf("STATE - %s\n", msg) ;			
}



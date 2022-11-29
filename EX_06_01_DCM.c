/*********************************************************************
*
*  L298N  DC Motor 제어 
*   
*********************************************************************/
#include <stdio.h>
#include <wiringPi.h>

#define IN1_PIN		1
#define IN2_PIN		4
#define IN3_PIN		5
#define IN4_PIN		6

/*
#define	MOTOR_INIT			 	digitalWrite(1, HIGH);	digitalWrite(4,HIGH);	digitalWrite(5, HIGH);	digitalWrite(6,HIGH)
#define 	MOTOR_GO_FORWARD   	digitalWrite(1,HIGH);	digitalWrite(4,LOW);	digitalWrite(5,HIGH);	digitalWrite(6,LOW)
#define 	MOTOR_GO_BACK	      	digitalWrite(4,HIGH);	digitalWrite(1,LOW);	digitalWrite(6,HIGH);	digitalWrite(5,LOW)
#define 	MOTOR_GO_RIGHT	    digitalWrite(1,HIGH);	digitalWrite(4,LOW);	digitalWrite(6,HIGH);	digitalWrite(5,LOW)
#define 	MOTOR_GO_LEFT	      	digitalWrite(4,HIGH);	digitalWrite(1,LOW);	digitalWrite(5,HIGH);	digitalWrite(6,LOW)
#define 	MOTOR_GO_STOP	      	digitalWrite(1, LOW);	digitalWrite(4,LOW);	digitalWrite(5, LOW);	digitalWrite(6,LOW)
*/
void initDCMotor();
void goForward();
void goBackward();
void goLeft();
void goRight();
void stopDCMotor();

int gCnt = 3;

int main(void)
{
	if(wiringPiSetup() == -1)
		return 0;
	
	pinMode(IN1_PIN, OUTPUT);
	pinMode(IN2_PIN, OUTPUT);
	pinMode(IN3_PIN, OUTPUT);
	pinMode(IN4_PIN, OUTPUT);
	
	initDCMotor();
	
	while(gCnt>0)
	{
		    goForward();
		    delay(500);
		 
	    	goBackward();
	        delay(500);
	       
	        goLeft();
	        delay(500);
	        
	        
	        goRight();
	        delay(500);
	        
	        
	        stopDCMotor();
	        delay(1000);
	        
	        gCnt--;
	}
		
	return 0;
}


void initDCMotor()
{
		digitalWrite(IN1_PIN, HIGH);
		digitalWrite(IN2_PIN, HIGH);
		digitalWrite(IN3_PIN, HIGH);
		digitalWrite(IN4_PIN, HIGH);						
}


void goForward()
{
		digitalWrite(IN1_PIN, HIGH);
		
		digitalWrite(IN2_PIN, LOW);
		digitalWrite(IN3_PIN, HIGH);
		digitalWrite(IN4_PIN, LOW);		
		printf("전진\n");
}	

void goBackward()
{
		digitalWrite(IN1_PIN, LOW);
	
		digitalWrite(IN2_PIN, HIGH);
		digitalWrite(IN3_PIN, LOW);
		digitalWrite(IN4_PIN, HIGH);		
		printf("후진\n");
}	
	
	
void goLeft()
{
		digitalWrite(IN1_PIN, LOW);
		digitalWrite(IN2_PIN, HIGH);
		digitalWrite(IN3_PIN, HIGH);
		digitalWrite(IN4_PIN, LOW);		
		printf("좌회전\n");
}	

void goRight()
{
		digitalWrite(IN1_PIN, HIGH);
		digitalWrite(IN2_PIN, LOW);
		digitalWrite(IN3_PIN, LOW);
		digitalWrite(IN4_PIN, HIGH);		
		printf("우회전\n");
}	

void stopDCMotor()
{
		digitalWrite(IN1_PIN, LOW);
		digitalWrite(IN2_PIN, LOW);
		digitalWrite(IN3_PIN, LOW);
		digitalWrite(IN4_PIN, LOW);		
		printf("정지\n");
}	
	

#include <Servo.h>
int buttonStateG = 0;
int buttonStateY = 0;
int buttonStateO = 0;
int buttonStateB = 0;

int lastButtonStateG = 0;
int lastButtonStateY = 0;
int lastButtonStateO = 0;
int lastButtonStateB = 0;

int password = 23241;

int correct = 1;

Servo servo;

void setup()
{
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(12, OUTPUT);
  digitalWrite(12, LOW);
  servo.attach(6);
  servo.write(0);
  password = Reverse(password);
}

void loop()
{
  if(correct>0)
  {
  ////////////////////////////////////////
  buttonStateG = digitalRead(2);
  if (buttonStateG != lastButtonStateG) {
    if (buttonStateG == HIGH) {
      if(password%10==1)
      {
        correct++;
        password /=10;
      } else if(correct>0) {correct*=(-1);}
    }
    delay(5);
  }
  lastButtonStateG = buttonStateG;
  ////////////////////////////////////////
  ////////////////////////////////////////
  buttonStateY = digitalRead(3);
  if (buttonStateY != lastButtonStateY) {
    if (buttonStateY == HIGH) {
      if(password%10==2)
      {
        correct++;
        password /=10;
      } else if(correct>0) {correct*=(-1);}
    }
    delay(5);
  }
  lastButtonStateY = buttonStateY;
  ////////////////////////////////////////
  ////////////////////////////////////////
  buttonStateO = digitalRead(4);
  if (buttonStateO != lastButtonStateO) {
    if (buttonStateO == HIGH) {
      if(password%10==3)
      {
        correct++;
        password /=10;
      } else if(correct>0) {correct*=(-1);}
    }
    delay(5);
  }
  lastButtonStateO = buttonStateO;
  ////////////////////////////////////////
  ////////////////////////////////////////
  buttonStateB = digitalRead(5);
  if (buttonStateB != lastButtonStateB) {
    if (buttonStateB == HIGH) {
      if(password%10==4)
      {
        correct++;
        password /=10;
      } else if(correct>0) {correct*=(-1);}
    }
    delay(5);
  }
  lastButtonStateB = buttonStateB;
  ////////////////////////////////////////
  if (correct-1 == 5)
  {
    servo.write(180);
    digitalWrite(12, HIGH);
  };
  };
}


int Reverse(int num){
  int rev_num = 0; 
    while(num > 0) 
    { 
        rev_num = rev_num*10 + num%10; 
        num = num/10; 
    } 
    return rev_num; 
}
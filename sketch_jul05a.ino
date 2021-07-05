char ch;
int EN1=D5;
int EN2=D6;
int motorR[]={D0,D1};
int motorL[]={D3,D4};


void setup() 
{
    
    pinMode(EN1,OUTPUT);
    pinMode(EN2,OUTPUT);
    pinMode(motorL[0],OUTPUT);
    pinMode(motorL[1],OUTPUT);
    pinMode(motorR[0],OUTPUT);
    pinMode(motorR[1],OUTPUT);
    digitalWrite(EN1,HIGH);
    digitalWrite(EN2,HIGH);
    Serial.begin(115200); 
    
  
}

void loop() 
{
   while(Serial.available())
  {
    ch=Serial.read();
    
    if(ch=='f'|| ch=='F')
    {
      forward();
      Serial.println("Moving forward");
    }
    else if(ch=='b'||ch=='B')
    {
      backward();
      Serial.println("Moving Backward");
    }
     else if(ch=='r'||ch=='R')
    {
      right();
      Serial.println("Moving Right");
    }
       else if(ch=='l'||ch=='L')
    {
      left();
      Serial.println("Moving Left");
    }
    else if(ch=='s'||ch=='S')
    {
      nomove();
      Serial.println("No movement");
    }
  }
}

void forward()
{
      digitalWrite(motorL[0],HIGH);
      digitalWrite(motorL[1],LOW);
      digitalWrite(motorR[0],HIGH);
      digitalWrite(motorR[1],LOW);
}
void backward()
{
      digitalWrite(motorL[0],LOW);
      digitalWrite(motorL[1],HIGH);
      digitalWrite(motorR[0],LOW);
      digitalWrite(motorR[1],HIGH);
}
void right()
{
      digitalWrite(motorL[0],LOW);
      digitalWrite(motorL[1],LOW);
      digitalWrite(motorR[0],HIGH);
      digitalWrite(motorR[1],LOW);
}
void left()
{
      digitalWrite(motorL[0],HIGH);
      digitalWrite(motorL[1],LOW);
      digitalWrite(motorR[0],LOW);
      digitalWrite(motorR[1],LOW);
}
void nomove()
{
      digitalWrite(motorL[0],LOW);
      digitalWrite(motorL[1],LOW);
      digitalWrite(motorR[0],LOW);
      digitalWrite(motorR[1],LOW);
}

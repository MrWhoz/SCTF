int ahead = 2;
int right = 3;
int left = 4;
int red = 5;
int blue = 6;
int white = 7;
int count = 0;
int temp;
int temp1;
int temp2;
int temp3;
void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(ahead, OUTPUT);
    pinMode(right, OUTPUT);
    pinMode(left, OUTPUT);
    pinMode(red, OUTPUT);
    pinMode(blue, OUTPUT);
    pinMode(white, OUTPUT);
    digitalWrite(ahead, HIGH);
    digitalWrite(right, HIGH);
    digitalWrite(left, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(white, LOW);
}

void AllOff()
{
    digitalWrite(ahead, HIGH);
    digitalWrite(right, HIGH);
    digitalWrite(left, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(white, LOW);  
}
void RedAheadOn()
{
    digitalWrite(ahead, LOW);
    digitalWrite(red, HIGH);
}
void BlueAheadOn()
{
    digitalWrite(ahead, LOW);
    digitalWrite(blue, HIGH);
}
void WhiteAheadOn()
{
    digitalWrite(ahead, LOW);
    digitalWrite(white, HIGH);
}
void RedRightOn()
{
    digitalWrite(right, LOW);
    digitalWrite(red, HIGH);
}
void BlueRightOn()
{
    digitalWrite(right, LOW);
    digitalWrite(blue, HIGH);
}
void WhiteRightOn()
{
    digitalWrite(right, LOW);
    digitalWrite(white, HIGH);
}
void RedLeftOn()
{
    digitalWrite(left, LOW);
    digitalWrite(red, HIGH);
}
void BlueLeftOn()
{
    digitalWrite(left, LOW);
    digitalWrite(blue, HIGH);
}
void WhiteLeftOn()
{
    digitalWrite(left, LOW);
    digitalWrite(white, HIGH);
}

void loop() {

  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) 
  {
    temp = Serial.read();
    if (temp == 51)
     {
        AllOff();
        count = 0;
        temp = 0;
        temp1 = 0;
        temp2 = 0;
        temp3 = 0; 
     } 
     else if (count == 0)
     {
        temp1 = temp;
        count = 1;   
     }
     else if (count == 1)
     {
        temp2 = temp;
        count = 2;
     }
     else if (count == 2)
     {
        temp3 = temp;
        count = 0;
     }
  }

    AllOff();
    if (temp1 == 48)
    {
      RedAheadOn();
    }
    if (temp1 == 49)
    {
      BlueAheadOn();
    } 
    if (temp1 == 50)
    {
      WhiteAheadOn();
    }
    delay (6);
    AllOff();
    if (temp2 == 48)
    {
      RedRightOn();
    }
    if (temp2 == 49)
    {
      BlueRightOn();
    } 
    if (temp2 == 50)
    {
      WhiteRightOn();
    }
    delay (6);
     AllOff();
    if (temp3 == 48)
    {
      RedLeftOn();
    }
    if (temp3 == 49)
    {
      BlueLeftOn();
    } 
    if (temp3 == 50)
    {
      WhiteLeftOn();
    }  
    delay (6);
}

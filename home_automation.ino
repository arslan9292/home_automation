/*

@author: Arslan Ahmad 

Pin Description:
 0,1 - GSM Module (PD0,PD1)
 2 - LDR (PD2)
 3,4,5 - Hall Sensor (PD3,PD4,PD5)
 6 - Temp Sensor (PD6)
 7 - Custom Sensor (PD7)
 8,9 - DTMF (PB0,PB1)
 10,11 - IR pair A (PB2,PB3)
 12,13 - IR pair B (PB4,PB5)
 14,15 - IR pair C (PB6,PB7)
 16 - Buzzer (PC0)
 17,18 - LED + Fan (Room) (PC1,PC2)
 19,20 - LED + Fan (Living Room) (PC3,PC4)
 21 - LED (Kitchen) (PC5)
 22 - LED (Lawn) (PC6)
 23 - Tank (PC7)
 24 - Switch Control (PA0)
 25,26 - Reset for LED + Fan (Room) (PA1,PA2)
 27,28 - Reset for LED + Fan (Living Room) (PA3,PA4)
 29 - Reset for LED (Kitchen) (PA5)
 30 - Reset for LED (Lawn) (PA6)
 31 - Reset for Tank (PA7) 
 
DTMF receiver Mode:
00- Manual
01- Secure
10- Long secure
11- Smart

*/

int DTMFa = 8;
int DTMFb = 9;
int TsopA1 = 10;
int TsopA2 = 11;
int TsopB1 = 12;
int TsopB2 = 13;
int TsopC1 = 14;
int TsopC2 = 15;
int buzzer = 16;
int led1 = 17;
int fan1 = 18;
int led2 = 19;
int fan2 = 20;
int led3 = 21;
int led4 = 22;
int tank = 23;
int key = 24;
int reset_led1 = 25;
int reset_fan1 = 26;
int reset_led2 = 27;
int reset_fan2 = 28;
int reset_led3 = 29;
int reset_led4 = 30;
int reset_tank = 31;
int a,b,c,d,e,f;  //   for storing the values for tsop sensors
int g=0;  // Counter variables
int h=0;
int i=0;
int j,k;  // for storing the values for LDR and Custom sensor respectively.
int tempMin = 25;   // the temperature to start the fan
int temp;

const int ldr = 2;
const int hall1 = 3;
const int hall2 = 4;
const int hall3 = 5;
const int tempPin = 6;
const int custom = 7;

int timesTosend = 1;
int count = 0;
char phone_no[]= "8954868489"; // Phone Number

void setup()
{
  Serial.begin(9600);
  delay(2000);
  Serial.println("AT+CMGF=1");  // Set GSM to text mode
  delay(200);
  pinMode(buzzer, OUTPUT);
  pinMode(key, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(fan1, OUTPUT);
  pinMode(fan2, OUTPUT);
  pinMode(tank, OUTPUT);
  pinMode(reset_led1, OUTPUT);
  pinMode(reset_led2, OUTPUT);
  pinMode(reset_led3, OUTPUT);
  pinMode(reset_led4, OUTPUT);
  pinMode(reset_fan1, OUTPUT);
  pinMode(reset_fan2, OUTPUT);
  pinMode(reset_tank, OUTPUT);
}

void loop()
{
  j = analogRead(ldr);  // controlling the inside and outside (lawn) lights.
  k = analogRead(custom);  // For over head tank
  
  if ((digitalRead(DTMFa)==0) && (digitalRead(DTMFb)==0))    //Manual Mode
  {
    digitalWrite(key, HIGH);
    a = digitalRead(TsopA1);
    c = digitalRead(TsopB1);
    e = digitalRead(TsopC1);
    if ( a==1 || c==1 || e==1) 
    {
      delay(50);
      b = digitalRead(TsopA2);
      d = digitalRead(TsopB2);
      f = digitalRead(TsopC2);
      if ( b==1 || d==1 || f==1) 
      {
        if (a==1 && b==1){g++;}
        if (c==1 && d==1){h++;}
        if (e==1 && f==1){i++;}
      }
    }
    
    b = digitalRead(TsopA2);
    d = digitalRead(TsopB2);
    f = digitalRead(TsopC2);
    if ( b==1 || d==1 || f==1)  
    {
      delay(50);
      a = digitalRead(TsopA1);
      c = digitalRead(TsopB1);
      e = digitalRead(TsopC1);
      if ( a==1 || c==1 || e==1) 
      {
        if (a==1 && b==1)
        {
          if ( g!=0 )
          { g--; }
          else {digitalWrite(buzzer, HIGH);}
        }
        if (c==1 && d==1)
        {
          if ( h!=0 )
          { h-- ;}
          else {digitalWrite(buzzer, HIGH);}
        }
        if (e==1 && f==1)
        {
          if ( i!=0 )
          { i-- ;}
          else {digitalWrite(buzzer, HIGH);}
        }
      }
    }
  }
  
  if ((digitalRead(DTMFa)==0) && (digitalRead(DTMFb)==1))    //Secure Mode
 {
    g=0;
    h=0;
    i=0;
    digitalWrite(key, HIGH);
    a = digitalRead(TsopA1);
    c = digitalRead(TsopB1);
    e = digitalRead(TsopC1);
    if ( a==1 || c==1 || e==1) 
    {
      delay(50);
      b = digitalRead(TsopA2);
      d = digitalRead(TsopB2);
      f = digitalRead(TsopC2);
      if ( b==1 || d==1 || f==1) 
      {
        if (a==1 && b==1)
        {
          while (count<timesTosend)
           {
            delay(1500);
            Serial.print("AT+CMGS=");
            Serial.print('"');
            Serial.print(phone_no);
            Serial.println('"');
    
              while(Serial.read()=='>')
              {
                Serial.print("Alert...!! Security breach.");
                delay(500);
                Serial.write(0x1A);  // sends ctrl+z i.e. end of msg
                Serial.write(0x0D);  // Carriage return in HEX
                Serial.write(0x0A);  // Line feed in HEX
                digitalWrite(buzzer, HIGH);
                delay(5000);
               }
               count++;
            }
        }  
        if (c==1 && d==1)
        {
          while (count<timesTosend)
           {
            delay(1500);
            Serial.print("AT+CMGS=");
            Serial.print('"');
            Serial.print(phone_no);
            Serial.println('"');
    
              while(Serial.read()=='>')
              {
                Serial.print("Alert...!! Security breach.");
                delay(500);
                Serial.write(0x1A);  // sends ctrl+z i.e. end of msg
                Serial.write(0x0D);  // Carriage return in HEX
                Serial.write(0x0A);  // Line feed in HEX
                digitalWrite(buzzer, HIGH);
                delay(5000);
               }
               count++;
           }
        }
        if (e==1 && f==1)
        {
          while (count<timesTosend)
           {
            delay(1500);
            Serial.print("AT+CMGS=");
            Serial.print('"');
            Serial.print(phone_no);
            Serial.println('"');
    
              while(Serial.read()=='>')
              {
                Serial.print("Alert...!! Security breach.");
                delay(500);
                Serial.write(0x1A);  // sends ctrl+z i.e. end of msg
                Serial.write(0x0D);  // Carriage return in HEX
                Serial.write(0x0A);  // Line feed in HEX
                digitalWrite(buzzer, HIGH);
                delay(5000);
               }
               count++;
           }
        }
      }
    }
    
    
   if (analogRead(hall1)>=20 && analogRead(hall1)<=255)
   {
    while (count<timesTosend)
     {
      delay(1500);
      Serial.print("AT+CMGS=");
      Serial.print('"');
      Serial.print(phone_no);
      Serial.println('"');
    
       while(Serial.read()=='>')
        {
         Serial.print("Alert...!! Security breach.");
         delay(500);
         Serial.write(0x1A);  // sends ctrl+z i.e. end of msg
         Serial.write(0x0D);  // Carriage return in HEX
         Serial.write(0x0A);  // Line feed in HEX
         digitalWrite(buzzer, HIGH);
         delay(5000);
        }
        count++;
      }
   }
   
   if (analogRead(hall2)>=20 && analogRead(hall2)<=255)
   {
    while (count<timesTosend)
     {
      delay(1500);
      Serial.print("AT+CMGS=");
      Serial.print('"');
      Serial.print(phone_no);
      Serial.println('"');
    
       while(Serial.read()=='>')
        {
         Serial.print("Alert...!! Security breach.");
         delay(500);
         Serial.write(0x1A);  // sends ctrl+z i.e. end of msg
         Serial.write(0x0D);  // Carriage return in HEX
         Serial.write(0x0A);  // Line feed in HEX
         digitalWrite(buzzer, HIGH);
         delay(5000);
        }
        count++;
      }
   }
   
   if (analogRead(hall3)>=20 && analogRead(hall3)<=255)
   {
    while (count<timesTosend)
     {
      delay(1500);
      Serial.print("AT+CMGS=");
      Serial.print('"');
      Serial.print(phone_no);
      Serial.println('"');
    
       while(Serial.read()=='>')
        {
         Serial.print("Alert...!! Security breach.");
         delay(500);
         Serial.write(0x1A);  // sends ctrl+z i.e. end of msg
         Serial.write(0x0D);  // Carriage return in HEX
         Serial.write(0x0A);  // Line feed in HEX
         digitalWrite(buzzer, HIGH);
         delay(5000);
        }
        count++;
      }
   }
 }
 
  if ((digitalRead(DTMFa)==1) && (digitalRead(DTMFb)==0))  // Long Secure Mode
  {
    g=0;
    h=0;
    i=0;
    digitalWrite(key, HIGH);
    a = digitalRead(TsopA1);
    c = digitalRead(TsopB1);
    e = digitalRead(TsopC1);
    if ( a==1 || c==1 || e==1) 
    {
      delay(50);
      b = digitalRead(TsopA2);
      d = digitalRead(TsopB2);
      f = digitalRead(TsopC2);
      if ( b==1 || d==1 || f==1) 
      {
        if (a==1 && b==1)
        {
          while (count<timesTosend)
           {
            delay(1500);
            Serial.print("AT+CMGS=");
            Serial.print('"');
            Serial.print(phone_no);
            Serial.println('"');
    
              while(Serial.read()=='>')
              {
                Serial.print("Alert...!! Security breach.");
                delay(500);
                Serial.write(0x1A);  // sends ctrl+z i.e. end of msg
                Serial.write(0x0D);  // Carriage return in HEX
                Serial.write(0x0A);  // Line feed in HEX
                digitalWrite(buzzer, HIGH);
                delay(5000);
               }
               count++;
            }
        }  
        if (c==1 && d==1)
        {
          while (count<timesTosend)
           {
            delay(1500);
            Serial.print("AT+CMGS=");
            Serial.print('"');
            Serial.print(phone_no);
            Serial.println('"');
    
              while(Serial.read()=='>')
              {
                Serial.print("Alert...!! Security breach.");
                delay(500);
                Serial.write(0x1A);  // sends ctrl+z i.e. end of msg
                Serial.write(0x0D);  // Carriage return in HEX
                Serial.write(0x0A);  // Line feed in HEX
                digitalWrite(buzzer, HIGH);
                delay(5000);
               }
               count++;
           }
        }
        if (e==1 && f==1)
        {
          while (count<timesTosend)
           {
            delay(1500);
            Serial.print("AT+CMGS=");
            Serial.print('"');
            Serial.print(phone_no);
            Serial.println('"');
    
              while(Serial.read()=='>')
              {
                Serial.print("Alert...!! Security breach.");
                delay(500);
                Serial.write(0x1A);  // sends ctrl+z i.e. end of msg
                Serial.write(0x0D);  // Carriage return in HEX
                Serial.write(0x0A);  // Line feed in HEX
                digitalWrite(buzzer, HIGH);
                delay(5000);
               }
               count++;
           }
        }
      }
    }
    
   if (analogRead(hall1)>=20 && analogRead(hall1)<=255)
   {
    while (count<timesTosend)
     {
      delay(1500);
      Serial.print("AT+CMGS=");
      Serial.print('"');
      Serial.print(phone_no);
      Serial.println('"');
    
       while(Serial.read()=='>')
        {
         Serial.print("Alert...!! Security breach.");
         delay(500);
         Serial.write(0x1A);  // sends ctrl+z i.e. end of msg
         Serial.write(0x0D);  // Carriage return in HEX
         Serial.write(0x0A);  // Line feed in HEX
         digitalWrite(buzzer, HIGH);
         delay(5000);
        }
        count++;
      }
   }
   
   if (analogRead(hall2)>=20 && analogRead(hall2)<=255)
   {
    while (count<timesTosend)
     {
      delay(1500);
      Serial.print("AT+CMGS=");
      Serial.print('"');
      Serial.print(phone_no);
      Serial.println('"');
    
       while(Serial.read()=='>')
        {
         Serial.print("Alert...!! Security breach.");
         delay(500);
         Serial.write(0x1A);  // sends ctrl+z i.e. end of msg
         Serial.write(0x0D);  // Carriage return in HEX
         Serial.write(0x0A);  // Line feed in HEX
         digitalWrite(buzzer, HIGH);
         delay(5000);
        }
        count++;
      }
   }
   
   if (analogRead(hall3)>=20 && analogRead(hall3)<=255)
   {
    while (count<timesTosend)
     {
      delay(1500);
      Serial.print("AT+CMGS=");
      Serial.print('"');
      Serial.print(phone_no);
      Serial.println('"');
    
       while(Serial.read()=='>')
        {
         Serial.print("Alert...!! Security breach.");
         delay(500);
         Serial.write(0x1A);  // sends ctrl+z i.e. end of msg
         Serial.write(0x0D);  // Carriage return in HEX
         Serial.write(0x0A);  // Line feed in HEX
         digitalWrite(buzzer, HIGH);
         delay(5000);
        }
        count++;
      }
   }
   if ( j>=0 && j<=170 ){digitalWrite(led4, HIGH);}
   else if ( j>=171 && j<=255 ){digitalWrite(reset_led4, HIGH);}
   
   k = analogRead(custom);  // For over head tank
   if (k>=171 && k<=255){digitalWrite(tank, HIGH);}
   else if (k>=0 && k<=170){digitalWrite(reset_tank, HIGH);}
 }
 
 
 if ((digitalRead(DTMFa)==1) && (digitalRead(DTMFb)==1))  // Smart Mode
 {
   digitalWrite(key, LOW);
   temp = analogRead(tempPin);     // get the temperature
   temp = temp * 0.48828125;
   if (( j>=0 && j<=170 ) && (temp >= tempMin))  // switching on and off the lights when it is night.
   {
    a = digitalRead(TsopA1);
    c = digitalRead(TsopB1);
    e = digitalRead(TsopC1);
    if ( a==1 || c==1 || e==1) 
    {
      delay(50);
      b = digitalRead(TsopA2);
      d = digitalRead(TsopB2);
      f = digitalRead(TsopC2);
      if ( b==1 || d==1 || f==1) 
      {
        if (a==1 && b==1)
        {
          g++;
          digitalWrite(led1, HIGH);
          digitalWrite(fan1, HIGH);
        }
        if (c==1 && d==1)
        {
          h++;
          digitalWrite(led2, HIGH);
          digitalWrite(fan2, HIGH);
        }
        if (e==1 && f==1)
        {
          i++;
          digitalWrite(led3, HIGH);
        }
      }
    }
    
    b = digitalRead(TsopA2);
    d = digitalRead(TsopB2);
    f = digitalRead(TsopC2);
    if ( b==1 || d==1 || f==1) 
    {
      delay(50);
      a = digitalRead(TsopA1);
      c = digitalRead(TsopB1);
      e = digitalRead(TsopC1);
      if ( a==1 || c==1 || e==1) 
      {
        if (a==1 && b==1)
        {
          if ( g!=0 )
          { g--; }
          else 
          {
          digitalWrite(reset_led1, HIGH);
          digitalWrite(reset_fan1, HIGH);
          }
        }
        if (c==1 && d==1)
        {
          if ( h!=0 )
          { h-- ;}
          else 
          {
          digitalWrite(reset_led2, HIGH);
          digitalWrite(reset_fan2, HIGH);
          }
        }
        if (e==1 && f==1)
        {
          if ( i!=0 )
          { i-- ;}
          else 
          {
          digitalWrite(reset_led3, HIGH);
          }
        }
      }
    }
  }
  if (( j>=0 && j<=170 ) && (temp < tempMin))  // switching on and off the lights when it is night.
   {
    a = digitalRead(TsopA1);
    c = digitalRead(TsopB1);
    e = digitalRead(TsopC1);
    if ( a==1 || c==1 || e==1) 
    {
      delay(50);
      b = digitalRead(TsopA2);
      d = digitalRead(TsopB2);
      f = digitalRead(TsopC2);
      if ( b==1 || d==1 || f==1) 
      {
        if (a==1 && b==1)
        {
          g++;
          digitalWrite(led1, HIGH);
          digitalWrite(reset_fan1, HIGH);
        }
        if (c==1 && d==1)
        {
          h++;
          digitalWrite(led2, HIGH);
          digitalWrite(reset_fan2, HIGH);
        }
        if (e==1 && f==1)
        {
          i++;
          digitalWrite(led3, HIGH);
        }
      }
    }
    
    b = digitalRead(TsopA2);
    d = digitalRead(TsopB2);
    f = digitalRead(TsopC2);
    if ( b==1 || d==1 || f==1) 
    {
      delay(50);
      a = digitalRead(TsopA1);
      c = digitalRead(TsopB1);
      e = digitalRead(TsopC1);
      if ( a==1 || c==1 || e==1) 
      {
        if (a==1 && b==1)
        {
          if ( g!=0 )
          { g--; }
          else 
          {
          digitalWrite(reset_led1, HIGH);
          digitalWrite(reset_fan1, HIGH);
          }
        }
        if (c==1 && d==1)
        {
          if ( h!=0 )
          { h-- ;}
          else 
          {
          digitalWrite(reset_led2, HIGH);
          digitalWrite(reset_fan2, HIGH);
          }
        }
        if (e==1 && f==1)
        {
          if ( i!=0 )
          { i-- ;}
          else 
          {
          digitalWrite(reset_led3, HIGH);
          }
        }
      }
    }
  }
 }
 
 
 
} // Final End

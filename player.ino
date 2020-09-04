/*
 * This project uses Df mp3 player to play mp3 music from sd card and display smiley in a 8*8 led matrix
 * TX(arduino) -> RX(DF)
 * RX - > TX
 * speaker pins connected to SPK1 & SPK2 of DF_module...
 * MAX7219 displays facial expressions and song numbers ....
 * It connects through following pins ....
 * DIN - pin 7
 * CLK - pin 6 
 * CS - pin 5
 * For digital inputs pins 2 & 3 are used 
 * For analog input pin A0 is used
 *  Based on the following library:
   GitHub | riyas-org/max7219  https://github.com/riyas-org/max7219
 */
#include <MaxMatrix.h>
#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

int DIN = 7,CLK =6, CS= 5,maxInUse = 1;   // DIN pin of MAX7219 module // CLK pin of MAX7219 module // CS pin of MAX7219 module
MaxMatrix m(DIN, CS, CLK, maxInUse); 
SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini df;
int x[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

 char Oface[] =
{8,8,
B00000000,   
B11100111,    
B10100101,      
B11100111,     
B00000000,
B01111110,
B01000010,
B01111110};
char blnk_face[] =
{8,8,
B00000000,
B11100111,
B10100101,
B11100111,
B00000000,
B00000000,
B01111110,
B00000000};
char O_srt[] = 
{8,8,
B00000000,
B11100111,
B10100101,
B11100111,
B00000000,
B00111100,
B00100100,
B00111100};
char smile[] =
{8,8,
B00000000,
B11100111,
B10100101,
B11100111,
B00000000,
B01000010,
B00100100,
B00111100};
char n1[] = 
{8,8,
B00000000,    
B00001000,
B00011000,
B00101000,
B00001000,
B00001000,
B00111110,
B00000000};
char n2[]= 
{8,8,
B00000000,    
B00111000,
B01001000,
B01001000,
B00011000,
B00100000,
B01111100,
B00000000};
 char n3[]= 
{8,8,
B00000000,    
B00111100,
B00000100,
B00000100,
B00011100,
B00000100,
B00000100,
B00111100};
 char n4[]= 
{8,8,
B00000000,    
B00100100,
B00100100,
B00100100,
B00111100,
B00000100,
B00000100,
B00000100};
 char n5[]= 
{8,8,
B00000000,    
B00111100,
B00100000,
B00100000,
B00111100,
B00000100,
B00000100,
B00111100};
char n6[]= 
{8,8,
B00000000,    
B00111100,
B00100000,
B00100000,
B00111100,
B00100100,
B00111100,
B00000000};
char n7[]= 
{8,8,
B00000000,    
B00111100,
B00000100,
B00000100,
B00001000,
B00010000,
B00010000,
B00010000};
char n8[]= 
{8,8,
B00000000,    
B00111100,
B00100100,
B00100100,
B00011000,
B00100100,
B00100100,
B00111100};
char n9[]= 
{8,8,
B00000000,    
B00011100,
B00100100,
B00100100,
B00011100,
B00000100,
B00000100,
B00000100};
 char n10[]= 
{8,8,
B00000000,    
B01011110,
B01010010,
B01010010,
B01010010,
B01010010,
B01011110,
B00000000};
 char n11[]= 
{8,8,
B00000000,    
B01000100,
B01000100,
B01000100,
B01000100,
B01000100,
B01000100,
B00000000};
 char n12[]= 
{8,8,
B00000000,    
B01011110,
B01000010,
B01000100,
B01001000,
B01010000,
B01011110,
B00000000};
 char n13[]= 
{8,8,
B00000000,    
B01011110,
B01000010,
B01001110,
B01000010,
B01000010,
B01011110,
B00000000};
 char n14[]= 
{8,8,
B00000000,    
B01010010,
B01010010,
B01010010,
B01001110,
B01000010,
B01000010,
B00000000};
 char n15[]= 
{8,8,
B00000000,    
B01011110,
B01010000,
B01010000,
B01001100,
B01000010,
B01011110,
B00000000};
 char n16[]= 
{8,8,
B00000000,    
B01011110,
B01010000,
B01010000,
B01011110,
B01010010,
B01011110,
B00000000};
char fire1[] =
{8,8,     
B00000000,
B00000000,
B00100100,
B10101100,
B10111100,
B11111110,
B11111111,
B11111111};

char fire2[]=
{8,8,    
B00000000,
B00000000,
B00010001,
B01010001,
B01110101,
B11111111,
B11111111,
B11111111};

char fire3[]=
{8,8,     
B00001000,
B00001000,
B00001001,
B10001101,
B10101111,
B11101111,
B11111111,
B11111111};

void setup() {
  mySoftwareSerial.begin(9600); // put your setup code here, to run onc
  df.begin(mySoftwareSerial);
  df.volume(18);
  df.EQ(DFPLAYER_EQ_NORMAL);
  df.outputDevice(DFPLAYER_DEVICE_SD);
  m.init();
  m.setIntensity(9);
  pinMode(3, INPUT);
  pinMode(2, INPUT);
  pinMode(A1,INPUT);
  pinMode(A0,INPUT);

  delay(500);
  if(digitalRead(2) == LOW)
  {
        df.play(1234);
        m.writeSprite(0,0,blnk_face);
        delay(1300);
         m.writeSprite(0,0,Oface);
        delay(230);
         m.writeSprite(0,0,O_srt);
        delay(607);
         m.writeSprite(0,0,Oface);
        delay(15);
         m.writeSprite(0,0,O_srt);
        delay(890);
        m.writeSprite(0,0,Oface);
        delay(300); 
        m.writeSprite(0,0,O_srt);
        delay(700); 
        m.writeSprite(0,0,Oface);
        delay(100);
         m.writeSprite(0,0,Oface);
        delay(1200);
         m.writeSprite(0,0,O_srt);
        delay(200);
         m.writeSprite(0,0,Oface);
        delay(500);
         m.writeSprite(0,0,O_srt);
        delay(300);
        m.writeSprite(0,0,Oface);
        delay(950);
         m.writeSprite(0,0,O_srt);
        delay(1050);
        m.writeSprite(0,0,smile);
        delay(3000);
}}
void slide(int w,int z)
{
  do 
  {
    m.writeSprite(0,0,fire1);
    delay(500);
    m.writeSprite(0,0,fire2);
    delay(500);
    m.writeSprite(0,0,fire3);
    delay(500);
   if(digitalRead(2) == LOW) df.volumeDown();
   if(digitalRead(3) == LOW) df.volumeUp();
  }while(analogRead(A0) >=w && analogRead(A0) <z);
}
void music(int a,int y,int u)
{
   int j  = 100;
   delay(100);
   if(j == a) slide(y,u);
   df.play(a);
   j = a;
   slide(y,u);
}
void loop() {
 void music(int a,int,int);
 if (analogRead(A0) >= 0 && analogRead(A0) <63)
    {
     m.writeSprite(0,0,n1);
      delay(1000);
     music(x[0],0,63);
    } //Play song 1
    if (analogRead(A0) >= 63  && analogRead(A0) <127)
    {
     m.writeSprite(0,0,n2);
delay(1000);
        music(x[1],63,127);
    }
    if (analogRead(A0) >= 126 && analogRead(A0) <191)
    {
   m.writeSprite(0,0,n3);
delay(1000);
        music(x[2],126,191);
    }
    if (analogRead(A0) >= 189 && analogRead(A0) <255)
    {
     m.writeSprite(0,0,n4);
delay(1000);
        music(x[3],189,255);
    } 
    if (analogRead(A0) >= 225 && analogRead(A0) <319)
    {
      m.writeSprite(0,0,n5);
delay(1000);
        music(x[4],225,319);
    }
    if (analogRead(A0) >= 319 && analogRead(A0) <383)
    {
      m.writeSprite(0,0,n6);
delay(1000);
         music(x[5],319,383);
    }
    if (analogRead(A0) >= 383 && analogRead(A0) <447)
    {
    m.writeSprite(0,0,n7);
delay(1000);
        music(x[6],383,447);
    }
    if (analogRead(A0) >= 447 && analogRead(A0) <511)
    {
       m.writeSprite(0,0,n8);
delay(1000);
        music(x[7],447,511);
    }
    if (analogRead(A0) >= 511 && analogRead(A0) <575)
    {
        m.writeSprite(0,0,n9);  
delay(1000);
        music(x[8],511,575);
    }
    if (analogRead(A0) >= 575 && analogRead(A0) <639)
    {
       m.writeSprite(0,0,n10);
delay(1000);
    music(x[9],575,639);
    }
    if (analogRead(A0) >= 639 && analogRead(A0) <703)
    {
       m.writeSprite(0,0,n11);
delay(1000);
       music(x[10],639,703);
    }
    if (analogRead(A0) >= 703 && analogRead(A0) <767)
    {
       m.writeSprite(0,0,n12);  
delay(1000);
      music(x[11],703,767);
    }
    if (analogRead(A0) >= 767 && analogRead(A0) <831)
    {  
      m.writeSprite(0,0,n13); 
delay(1000);
       music(x[12],767,831);
    }
    if (analogRead(A0) >= 831 && analogRead(A0) <895)
    {
     m.writeSprite(0,0,n14);
delay(1000);
     music(x[13],831,895);
    }
    if (analogRead(A0) >= 895 && analogRead(A0) <959)
    {
       m.writeSprite(0,0,n15);
delay(1000);
       music(x[14],895,959);
    }
    if (analogRead(A0) >= 959 && analogRead(A0) <1023)
    {
       m.writeSprite(0,0,n16);  
delay(1000);
      music(x[15],959,1023);
    }
}

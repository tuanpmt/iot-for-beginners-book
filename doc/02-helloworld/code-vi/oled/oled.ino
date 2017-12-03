#include <Wire.h>
#include "SSD1306.h"

SSD1306  display(0x3c, 4, 5);
int thoi_gian = 0;
void setup()
{
  Serial.begin(115200);
  display.init();
  //display.flipScreenVertically(); //đảo chiều 
  display.setFont(ArialMT_Plain_10);
  display.drawString(0, 0, "Hello world");
  display.display();
  delay(1000);
  display.clear();
}

void loop()
{
  int gio, phut, giay;
  
  
  delay(1000);
  thoi_gian ++;

  gio = thoi_gian/3600;
  phut = (thoi_gian%3600)/60;
  giay = thoi_gian % 60;
  display.clear();
  display.drawString(0, 0, String(gio) + ":" + String(phut) + ":" + String(giay));
  display.display();
}

#include <Adafruit_NeoPixel.h>
int acceleration;
int leds = 10;
int red = 0;
int green = 0;
int blue = 0;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(leds, 1, NEO_GRB + NEO_KHZ800);

void setup() {
  acceleration = 0;
  strip.begin();
  strip.setBrightness(10);
  strip.show();
}

void loop() {
  acceleration = analogRead(1);
  acceleration = acceleration - (acceleration % 3);//each color is grouped for 3 acceleration values
  if(acceleration<342){
    red = 10;
    green = 10;
    blue = 10;
  }
  /*colors are assigned according to the proper linear equation.
  This allows for a wide range of colors to be utilized.*/
  else if(acceleration<354){ //red to yellow                                 
    red = 255;
    green = acceleration * 21.25 - 7267.5;
    blue = 0;
  }
  else if(acceleration<366){ //yellow to green                        
    red = acceleration * (-21.25) + 7777.5;
    green = 255;
    blue = 0;
  }
  else if(acceleration<378){                                      
    red = 0;
    green = 255;
    blue = acceleration * 21.25 - 7777.5;
  }
  else if(acceleration<390){                                       
    red = 0;
    green = acceleration * (-21.25) + 8287.5;
    blue = 255;
  }
  else if(acceleration<402){                                       
    red = acceleration * 21.25 - 8287.5;
    green = 0;
    blue = 255;
  }
  else if(acceleration<414){                                       
    red = 255;
    green = 0;
    blue = acceleration * (-21.25) + 8797.5;
  }
  else if (acceleration>413){//white at any value above 416, this is a rare case
    red = 255;
    green = 255;
    blue = 255; 
  }
  for (int i=0;i<leds;i=1+i) {
      strip.setPixelColor(i,red, green, blue);
    }
    strip.show();
}

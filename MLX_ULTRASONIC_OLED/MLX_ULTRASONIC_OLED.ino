// ------CODE---- by Judhi Prasetyo, March 2020 for The Arduino Day

#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

Adafruit_SSD1306 display(-1);
//Adafruit_SSD1306 display(128,64, &Wire, -1);

float roomTemp; // ambient temperature
float objectTemp, stemp; // object temperature

int readcount = 0;
float threshold= 5.6 ;

// --------- Ultrasonic Sensor preparation

void setup() {
 
  Serial.begin(9600);
  // setting up the OLED display
  display.begin(SSD1306_SWITCHCAPVCC,0x3C) ;
  delay(1000);
  display.clearDisplay();
  display.setTextColor(WHITE);
}

void loop()

{
  
  
  // reading object and ambient  temperature
  objectTemp = threshold + mlx.readObjectTempC() ;  
  roomTemp = mlx.readAmbientTempC() ;  

  // print to Serial port
 Serial.println("Object:" + String(objectTemp) + ", Ambient:" + String(roomTemp));

 
  // display on OLED
  display.clearDisplay();
  display.setTextSize(1);

  display.setCursor(65,25);
  display.print("Room:" + String(roomTemp).substring(0, 4)  + "C");
  display.display();
  display.setTextSize(2);
 display.setCursor(0, 0);
 
  display.display();
 
  Serial.println("count  :"+String(readcount));
 }

 void disptemp()
 {
      objectTemp = stemp / 5;       // get the average reading of temp
      display.setTextSize(1);
      display.print("YOUR TEMP:");
      display.setTextSize(2);
      display.setCursor(60,5);
      display.print(String(objectTemp).substring(0, 4) + "C");
      display.display();
      readcount = 0;
      stemp = 0;
      if (objectTemp >= 37.5) {
        play_alert();
      } else {
        play_ok();
      }
      dtime = 5000; // wait for 5 seconds
 }

void play_ok() {  // play three sequential notes when object temperature is below 37.5C
  tone(3, 600, 1000);  // pin,frequency,duration
  delay(200);
  tone(3, 750, 500);
  delay(100);
  tone(3, 1000, 500);
  delay(200);
  noTone(3);
}

void play_alert() { // beep 3x when object temperature is >= 37.5C
  tone(3, 2000, 1000);
  delay(1000);
  tone(3, 3000, 1000);
  delay(1000);
  tone(3, 4000, 1000);
  delay(1000);
  noTone(3);
}

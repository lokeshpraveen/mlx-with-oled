
 #include <Adafruit_I2CDevice.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET    -1 // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); //Declaring the display name (display)
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {  

    Serial.begin(9600);
    mlx.begin(); 

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //Start the OLED display
  display.clearDisplay();
  display.display();

}

void loop() {
  display.clearDisplay();
  Serial.println(mlx.readAmbientTempF(),1);
  display.setTextSize(1);                    
  display.setTextColor(WHITE);             
  display.setCursor(0,4);                
  display.println("Ambient"); 
  
  display.setTextSize(2);
  display.setCursor(50,0);
  display.println(mlx.readAmbientTempF(),1);
 
  display.setCursor(110,0);
  display.println("F");
  
  display.setTextSize(1);                    
  display.setTextColor(WHITE);             
  display.setCursor(0,20);                
  display.println("Target"); 
  
  display.setTextSize(2);
  display.setCursor(50,17);
  display.println(mlx.readObjectTempF(),1);
  
  display.setCursor(110,17);
  display.println("F");
  
  display.display();
  
  delay(1000);

}

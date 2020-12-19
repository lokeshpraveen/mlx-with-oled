#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

#define OLED_RESET -1
Adafruit_SH1106 display(OLED_RESET); /* Object of class Adafruit_SSD1306 */

void setup() {
  display.begin(SH1106_SWITCHCAPVCC, 0x3C); /* Initialize display with address 0x3C */
  display.clearDisplay(); /* Clear display */
  display.setTextColor(WHITE);
  display.setTextSize(2); /* Select font size of text. Increases with size of argument. */
  display.setCursor(15,5);
  display.println("alselectro");
  display.display();
  delay(500);
   
}

void loop() {
  
  
}

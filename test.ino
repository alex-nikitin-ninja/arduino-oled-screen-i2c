#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <VirtualWire.h>

#define OLED_RESET -1
Adafruit_SSD1306 display(OLED_RESET);

char incomingByte;
String inputLine;
String recvMessage;
uint8_t buf [VW_MAX_MESSAGE_LEN];
uint8_t buflen = VW_MAX_MESSAGE_LEN;



String toString(uint8_t *str){
    return String((char *)str);
}

void setup()   {
    Serial.begin(9600);
    vw_setup(500);
    vw_set_rx_pin(7);

    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    display.clearDisplay();

    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("Loaded");

    // display.drawPixel(64, 32, WHITE);
    // display.drawRoundRect(10, 10, 128-10*2, 64-10*2, 8, WHITE);
    // display.drawRoundRect(0, 0, 128, 64, 4, WHITE);

    display.display();
}

void processMessage() {

}

void loop() {
    vw_rx_start();
    buflen = VW_MAX_MESSAGE_LEN;

    if (vw_have_message()) {
        if (vw_get_message(buf, &buflen)) {
            recvMessage = toString(buf);
            
            display.clearDisplay();
            display.setCursor(0, 0);
            
            display.println(recvMessage);
            display.display();
        }
    }

    // if (Serial.available() > 0) {
    //     incomingByte = Serial.read();

    //     display.clearDisplay();
    //     display.setCursor(0, 0);

    //     Serial.print("I received: ");
    //     Serial.println(incomingByte);
    //     if (incomingByte == ';') {

    //         display.println(inputLine);
    //         display.display();
    //         inputLine = "";
    //     } else {
    //         inputLine = inputLine + incomingByte;
    //     }
    // }
}



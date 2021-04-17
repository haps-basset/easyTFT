#include "easyTFT.h"
#include "FontsMed.h"

easyTFT eTFT = easyTFT();

void setup(){
    Serial.begin(115200);
    eTFT.begin();
    eTFT.setCursor(10,10);
    eTFT.setFont(FontsMed); 
    eTFT.setCursor(10,10);
    eTFT.printES("This is a test 1");
    eTFT.setCursor(10,70);
    eTFT.printESf("This is a test %d",2);
    eTFT.printCenterES("00:00:00");
    eTFT.printCenterES(210,"99:999:99");
    delay(2000);
    eTFT.cls();
    eTFT.printCenterESf("Test 3 %02d-%02d-%02d",1,2,3);
    eTFT.printCenterESf(210,"Test 4 %02d-%02d-%02d",3,2,1);
}

void loop(){

}


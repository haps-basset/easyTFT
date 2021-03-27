#pragma once

#include <TFT_eSPI.h>
#include <SPI.h>

#define DEBUG

#ifdef DEBUG
#define PRINTP(x)  Serial.println("POINTER => "+String((unsigned long int)&x,HEX))
#define DEBUGPRINT(x)  Serial.println (String(x) + " debug heap " + String(ESP.getHeapSize(),HEX) + "  " + String(ESP.getFreeHeap(),HEX))
#else
#define PRINTP(x)
#define DEBUGPRINT(x)
#endif

class easyTFT : public TFT_eSPI {
  private:
    uint8_t   maxCharWidth = 0;
    uint32_t  background = TFT_BLACK;
    uint32_t  color     = TFT_WHITE;  
  public:
    TFT_eSprite sprite = TFT_eSprite(this);
    void begin();
    void cls();
    void setFont(const uint8_t *value);
    void printES(String value);
    void printESf(const char *format, ...);
    void printCenterES(String value);
    void printCenterES(int y,String value);
    void printCenterESf(const char *format, ...);
    void printCenterESf(int y,const char *format, ...);
};

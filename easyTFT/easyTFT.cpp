#include <easyTFT.h>

void easyTFT::begin(){
#define defaultFontWidth 6
    TFT_eSPI::begin();
    setRotation(3);
    sprite.setColorDepth(16);
    fillScreen(background);
    maxCharWidth = width()/defaultFontWidth;
};

void easyTFT::cls(){
    fillScreen(background);
};

void  easyTFT::setFont(const uint8_t *value){
    sprite.unloadFont();
    sprite.loadFont(value);
};

void easyTFT::printCenterES(String value){
    int _textWidth = sprite.textWidth(value);
    int _textHeight = sprite.fontHeight();
    setCursor((width()-_textWidth)/2, (height()-_textHeight)/2);
    printES(value);
}

void easyTFT::printCenterES(int y,String value){
    int _textWidth = sprite.textWidth(value);
    setCursor((width()-_textWidth)/2, y);
    printES(value);
}

void easyTFT::printCenterESf(const char *format, ...){
  char buffer[maxCharWidth];
  va_list args;
  va_start (args, format);
  vsnprintf (buffer, maxCharWidth, format, args);
  printCenterES(buffer);
  va_end (args);
};

void easyTFT::printCenterESf(int y, const char *format, ...){
  char buffer[maxCharWidth];
  va_list args;
  va_start (args, format);
  vsnprintf (buffer, maxCharWidth, format, args);
  printCenterES(y, buffer);
  va_end (args);
};

void easyTFT::setType(bool value){
	type = value;
}

void easyTFT::printES(String value){
	if (type)
		_printESS(value);
	else
		_printES(value);
}

void easyTFT::printESf(const char *format, ...){
  char buffer[maxCharWidth];
  va_list args;
  va_start (args, format);
  vsnprintf (buffer, maxCharWidth, format, args);
  printES(buffer);
  va_end (args);
};

void easyTFT::_printESS(String value){   
    sprite.setTextDatum(TL_DATUM);
    sprite.setTextColor(color, background); 
	sprite.printToSprite(" "+value+" ");
};

void easyTFT::_printES(String value){
  #define M 8
  #define MM 0
    int _textWidth = sprite.textWidth(value);
    int _textHeight = sprite.fontHeight();
    sprite.createSprite(_textWidth+M, _textHeight+M);   
    sprite.setTextDatum(TL_DATUM);
    sprite.setTextColor(color, background); 
    sprite.fillSprite(background);
    sprite.drawString(value);
    sprite.pushSprite(getCursorX(), getCursorY());  
    sprite.deleteSprite(); 
};



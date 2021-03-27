# easyTFT

**easyTFT  is a small extension to TFT_eSPI  simplifying printing formatted strings, numbers etc.**

Usage:

    void begin();	// internalization easyTFT
    void cls();	// clear screen
    void setFont(const uint8_t *value);	//register new fonts
    void printES(String value);		//print text
    void printESf(const char *format, ...);	//print formatted text
    void printCenterES(String value);	//print text in the middle of screen
    void printCenterES(int y,String value);	//print text in the middle of line
    void printCenterESf(const char *format, ...); //print formatted text in the middle of selected screen
    void printCenterESf(int y, const char *format, ...); //print formatted text in the middle of selected line 

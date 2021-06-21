
#include "ui_gLCD.h"

void wait(void)
{
    ST7565_Clear();
    ST7565_Print(1, 1, "WELLCOME", &Font_16x28, 1, 1);
}
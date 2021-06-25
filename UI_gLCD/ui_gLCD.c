#include "main.h"
#include "ST7565.h"
#include "ui_gLCD.h"

void UIwait(void)
{
    ST7565_Print(8, 1, "WELLCOME", &Font_7x9, 2, BLACK);
    ST7565_Print(43, 26, "PLEASE", &Font_7x9, 1, BLACK);
    ST7565_Print(9, 40, "swipe card",&Font_11x18, 1, BLACK);
    HAL_Delay(500);
    ST7565_Print(9, 40, "          ",&Font_11x18, 1, BLACK);
    HAL_Delay(100);
    
}

void showKQ(void)
{
  ST7565_Print(1, 1, "Height=", &Font_7x9, 1, 1);
  ST7565_Print(1, 1+9+2, "Weight=", &Font_7x9, 1, 1);
  ST7565_Print(1, 1+(9+2)*2, "Temp=", &Font_7x9, 1, 1);
  ST7565_Print(1, 1+(9+2)*3, "CardID=", &Font_7x9, 1, 1);
}
void startUp(void)
{

}

void UImeas_pressure(void)
{
    ST7565_Print(1, 1, "SYS", &Font_11x18, 1, BLACK);
    ST7565_Print(1, 20, "DIA", &Font_11x18, 1, BLACK);
    ST7565_Print(1, 40, "PULSE", &Font_11x18, 1, BLACK);
    // duong ke doc
    ST7565_DrawLine(109, 1, 109, 64, BLACK);
    ST7565_DrawLine(110, 1, 110, 64, BLACK);

    // ket qua SYS
    ST7565_Print(44, 1, "..8", &Font_11x18, 1, BLACK);
    ST7565_Print(80, 8, "mmHg", &Font_7x9, 1, BLACK);
    // ket qua DIA
    ST7565_Print(44, 20, "..8", &Font_11x18, 1, BLACK);
    ST7565_Print(80, 27, "mmHg", &Font_7x9, 1, BLACK);
    // ket qua PULSE
    ST7565_Print(66, 40, "..", &Font_11x18, 1, BLACK);
    //
}

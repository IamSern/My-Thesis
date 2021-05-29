#ifndef HX711_H_
#define HX711_H_

//#inlcude "gpio.h"
#include "main.h"
#include "Timer_Delay.h"

#define Channel_A 24
#define Channel_B 25

void HX711_init(void);
uint32_t HX711_value(int Channel);
uint32_t HX711_valueAve(uint16_t sample, int Channel);
float HX711_getWeight(void);
#endif



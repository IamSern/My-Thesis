#ifndef HX711_H_
#define HX711_H_

//#inlcude "gpio.h"
#include "main.h"
#include "Timer_Delay.h"

uint8_t sysMax, diasMin, pressure;
typedef enum {Channel_A, Channel_B} Channel_t;


void HX711_init(void);
uint32_t HX711_value(Channel_t Channel, uint8_t Gain);
uint32_t HX711_valueAve(uint16_t sample, Channel_t Channel, uint8_t Gain);
float getWeight(void);
unsigned long get_noLoad(void);
uint8_t getPressure(void);
void measurePress(void);
void SYS_measure(void);
void DIAS_measure(void);
unsigned long HX711_Read(void);

#endif



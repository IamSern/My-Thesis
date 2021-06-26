#include "hx711.h"
#include "Config.h"
#include "Timer_Delay.h"
#include "math.h"
#include "ui_gLCD.h"

#if (_HX711_USE_FREERTOS == 1)
#include "cmsis_os.h"
#define HX711_delay(x)    osDelay(x)
#else
#define HX711_delay(x)    HAL_Delay(x)
#endif



typedef enum {ON = 1, OFF = 0} state;
typedef enum {WAIT,SYS, DIAS, PULSE} measureState_t;
typedef enum {START, INFLATE, DEFLATE, STOP} pumpState_t;
static pumpState_t currentState = START;
static measureState_t measureState = WAIT;
//#############################################################################################
__STATIC_INLINE void HX711_delay_us(uint32_t microseconds)
{
  uint32_t clk_cycle_start = DWT->CYCCNT;
  microseconds *= (HAL_RCC_GetHCLKFreq() / 1000000);
  while ((DWT->CYCCNT - clk_cycle_start) < microseconds);
}
/**
 * @brief init hx711
 * 
 */
void  HX711_init(void)
{
  GPIO_InitTypeDef  gpio;
  gpio.Mode = GPIO_MODE_OUTPUT_PP;
  gpio.Pull = GPIO_NOPULL;
  gpio.Speed = GPIO_SPEED_FREQ_HIGH;
  gpio.Pin = SCK_GPIO_PIN;
  HAL_GPIO_Init(SCK_GPIO_PORT, &gpio);
  gpio.Mode = GPIO_MODE_INPUT;
  gpio.Pull = GPIO_NOPULL;
  gpio.Speed = GPIO_SPEED_FREQ_HIGH;
  gpio.Pin = Dout_GPIO_PIN;
  HAL_GPIO_Init(Dout_GPIO_PORT, &gpio);
  HAL_GPIO_WritePin(SCK_GPIO_PORT, SCK_GPIO_PIN, GPIO_PIN_SET);
  HX711_delay(10);
  HAL_GPIO_WritePin(SCK_GPIO_PORT, SCK_GPIO_PIN, GPIO_PIN_RESET);
  HX711_delay(10);
  HX711_valueAve(8, Channel_A, 128);
  HX711_delay(10);
  HX711_valueAve(8, Channel_B, 32);
}
/**
 * @brief get data from HX711
 * 
 * @param Channel 
 * @return uint32_t 
 */
uint32_t HX711_value(Channel_t Channel, uint8_t Gain)
{
  uint32_t data = 0;
  uint32_t  startTime = HAL_GetTick();
  while(HAL_GPIO_ReadPin(Dout_GPIO_PORT, Dout_GPIO_PIN) == GPIO_PIN_SET);

  for(int8_t i=0; i < 24 ; i++)
  {
    HAL_GPIO_WritePin(SCK_GPIO_PORT, SCK_GPIO_PIN, GPIO_PIN_SET);
    delay_us(1);
//    HX711_delay_us(1);
    data = data << 1;
    HAL_GPIO_WritePin(SCK_GPIO_PORT, SCK_GPIO_PIN, GPIO_PIN_RESET);
    delay_us(1);
//    HX711_delay_us(1);
    if(HAL_GPIO_ReadPin(Dout_GPIO_PORT, Dout_GPIO_PIN) == GPIO_PIN_SET)
      data ++;
  }
  data = data ^ 0x800000;
  HAL_GPIO_WritePin(SCK_GPIO_PORT, SCK_GPIO_PIN, GPIO_PIN_SET);
  delay_us(1);
//  HX711_delay_us(1);
  HAL_GPIO_WritePin(SCK_GPIO_PORT, SCK_GPIO_PIN, GPIO_PIN_RESET);
  delay_us(1);
//  HX711_delay_us(1);
  return data;
}




uint32_t HX711_valueAve(uint16_t sample, Channel_t Channel, uint8_t Gain)
{
  uint64_t  ave = 0;

  for(uint16_t i=0 ; i < sample ; i++)
    ave += HX711_value(Channel, Gain);
  return (int32_t)(ave / sample);
}
//#############################################################################################
 float HX711_getWeight(void)
 { 
   float Weight = 0;
   uint32_t weight_raw = HX711_valueAve(16, Channel_A, 128);
   Weight = 2* ((pow(2,23) - weight_raw))/((pow(2, 23)/200));
   return Weight;
 }

 /***
  * @brief lấy giá trị huyết áp
  * @param NONE
  * @return gía trị huyết áp
  * */
 uint8_t HX711_getPressure(void)
 {
   uint8_t data = 0;
   uint32_t data_raw = HX711_valueAve(16, Channel_B, 32);
   data = 2* ((pow(2,23) - data_raw))/((pow(2, 23)/300));
 }

 void measurePress(void)
 {
   switch (currentState)
   {
   case START:
     /* code */
     break;
   case INFLATE:
   if(sysMax < pressure){
     currentState = DEFLATE;
   } 
   else currentState = INFLATE;

   case DEFLATE:
   if(diasMin > pressure){
     currentState = STOP;
   }
   else currentState = DEFLATE;
   
   }
   switch (currentState)
   {
   case START:
     //show UI_gLCD
     UImeas_pressure();
    //  measureState = SYS;

     break;
   case INFLATE:
   SYS_measure();
   //update value pressure
    break;
   case DEFLATE:
   DIAS_measure();
   //update value pressure
    break;
   case STOP:
   //show SYS, DIA, PULSE 
    break;
 }
 }
 
// void SYS_measure(void)
// {
//   HAL_GPIO_WritePin(Valve_GPIO_Port, Valve_Pin, ON);
//   HAL_GPIO_WritePin(Pump_GPIO_Port, Pump_Pin, ON);
//   HX711_getPressure();
// }
//
// void DIAS_measure(void)
// {
//
// }

unsigned long HX711_Read(void)
{
  unsigned long count;
  unsigned char i;

  HAL_GPIO_WritePin(Dout_GPIO_PORT, Dout_GPIO_PIN, RESET);
  count = 0;
  int ii = 0;
  while (1)
  {
    if(HAL_GPIO_ReadPin(Dout_GPIO_PORT, Dout_GPIO_PIN) == 0){
      delay_us(1);
      if(HAL_GPIO_ReadPin(Dout_GPIO_PORT, Dout_GPIO_PIN) == 0){
        break;
      }
    }
    ii++;
    if(ii++ >= 1000000){
      break;
    }
  }
  delay_us(1);
  for(i = 0; i < 24; i++){
    HAL_GPIO_WritePin(SCK_GPIO_PORT, SCK_GPIO_PIN, SET);
    delay_us(1);
    count = count << 1;
    HAL_GPIO_WritePin(SCK_GPIO_PORT, SCK_GPIO_PIN, RESET);
    if(HAL_GPIO_ReadPin(Dout_GPIO_PORT, Dout_GPIO_PIN) == 1){
      count++;
    }
  }
  HAL_GPIO_WritePin(SCK_GPIO_PORT, SCK_GPIO_PIN, SET);
  delay_us(2);
  count = count^0x800000;
  HAL_GPIO_WritePin(SCK_GPIO_PORT, SCK_GPIO_PIN, RESET);
  return(count);
}




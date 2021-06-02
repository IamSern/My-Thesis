#include "hx711.h"
#include "Config.h"
#include "Timer_Delay.h"
#include "math.h"

#if (_HX711_USE_FREERTOS == 1)
#include "cmsis_os.h"
#define HX711_delay(x)    osDelay(x)
#else
#define HX711_delay(x)    HAL_Delay(x)
#endif

//#############################################################################################
__STATIC_INLINE void HX711_delay_us(uint32_t microseconds)
{
  uint32_t clk_cycle_start = DWT->CYCCNT;
  microseconds *= (HAL_RCC_GetHCLKFreq() / 1000000);
  while ((DWT->CYCCNT - clk_cycle_start) < microseconds);
}
//#############################################################################################
void  HX711_init(void)
{
  GPIO_InitTypeDef  gpio;
  gpio.Mode = GPIO_MODE_OUTPUT_PP;
  gpio.Pull = GPIO_NOPULL;
  gpio.Speed = GPIO_SPEED_FREQ_HIGH;
  gpio.Pin = _HX711_SCK_PIN;
  HAL_GPIO_Init(_HX711_SCK_GPIO, &gpio);
  gpio.Mode = GPIO_MODE_INPUT;
  gpio.Pull = GPIO_NOPULL;
  gpio.Speed = GPIO_SPEED_FREQ_HIGH;
  gpio.Pin = _HX711_DI_PIN;
  HAL_GPIO_Init(_HX711_DI_GPIO, &gpio);
  HAL_GPIO_WritePin(_HX711_SCK_GPIO, _HX711_SCK_PIN, GPIO_PIN_SET);
  HX711_delay(10);
  HAL_GPIO_WritePin(_HX711_SCK_GPIO, _HX711_SCK_PIN, GPIO_PIN_RESET);
  HX711_delay(10);
  HX711_valueAve(8, Channel_A);
  HX711_delay(10);
  HX711_valueAve(8, Channel_B);
}
//#############################################################################################
uint32_t HX711_value(int Channel)
{
  uint32_t data = 0;
  uint32_t  startTime = HAL_GetTick();
  while(HAL_GPIO_ReadPin(_HX711_DI_GPIO, _HX711_DI_PIN) == GPIO_PIN_SET)
  {
    if(HAL_GetTick() - startTime > 150)
      return 0;
  }
  for(int8_t i=0; i < Channel ; i++)
  {
    HAL_GPIO_WritePin(_HX711_SCK_GPIO, _HX711_SCK_PIN, GPIO_PIN_SET);
    delay_us(1);
//    HX711_delay_us(1);
    data = data << 1;
    HAL_GPIO_WritePin(_HX711_SCK_GPIO, _HX711_SCK_PIN, GPIO_PIN_RESET);
    delay_us(1);
//    HX711_delay_us(1);
    if(HAL_GPIO_ReadPin(_HX711_DI_GPIO, _HX711_DI_PIN) == GPIO_PIN_SET)
      data ++;
  }
  data = data ^ 0x800000;
  HAL_GPIO_WritePin(_HX711_SCK_GPIO, _HX711_SCK_PIN, GPIO_PIN_SET);
  delay_us(1);
//  HX711_delay_us(1);
  HAL_GPIO_WritePin(_HX711_SCK_GPIO, _HX711_SCK_PIN, GPIO_PIN_RESET);
  delay_us(1);
//  HX711_delay_us(1);
  return data;
}
//#############################################################################################
uint32_t HX711_valueAve(uint16_t sample, int Channel)
{
  uint64_t  ave = 0;

  for(uint16_t i=0 ; i < sample ; i++)
    ave += HX711_value(Channel);
  return (int32_t)(ave / sample);
}
//#############################################################################################
 float HX711_getWeight(void)
 { 
   float Weight = 0;
   uint32_t weight_raw = HX711_valueAve(16, Channel_A);
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
   uint32_t data_raw = HX711_valueAve(16, Channel_B);
   data = 2* ((pow(2,23) - data_raw))/((pow(2, 23)/300));
 }



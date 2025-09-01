#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
#include "gd32f4xx.h"
#include "led.h"
#include "system_gd32f4xx.h"
#include "rtthread.h"

LED LED1 = {GPIOE, GPIO_PIN_4, SET, RESET};

/*这个函数会在main之前执行，在这里进行硬件初始化*/
void hardware_init(void)
{
	led_init_config(&LED1);
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / 1000);/*初始化systick，1ms中断一次*/
}

int main(void)
{
	while (1)
	{
		led_toggle(&LED1);
		rt_thread_delay(1000);
	}
}

void rt_hw_us_delay(uint32_t us)
{
	uint32_t start, now, delta, reload, us_tick;
	start	= SysTick->VAL;
	reload	= SysTick->LOAD;
	us_tick = SystemCoreClock / 1000000UL;

	do
	{
		now	  = SysTick->VAL;
		delta = start > now ? start - now : reload + start - now;
	} while (delta < us_tick * us);
}

void rt_hw_console_output(const char *str)
{
	extern void rt_enter_critical(void);
	rt_enter_critical();
	/*空实现*/
	extern void rt_exit_critical(void);
	rt_exit_critical();
}

char rt_hw_console_getchar(void)
{
	/* Note: the initial value of ch must < 0 */
	int ch = -1;
	/*空实现*/

	return ch;
}

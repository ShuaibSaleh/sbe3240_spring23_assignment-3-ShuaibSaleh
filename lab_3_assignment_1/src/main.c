/*
 * main.c
 *
 *  Created on: Apr 17, 2023
 *      Name: Shuaib Abdulsalam Ahmed Aklan Saleh
 *      Sec: 1
 *      B.N.: 48
 */


#define GPIOB_BASE_ADDR 0x40020400
#define GPIOB_MODER     (*(unsigned long *)(GPIOB_BASE_ADDR + 0x00))
#define GPIOB_OTYPER    (*(unsigned long *)(GPIOB_BASE_ADDR + 0x04))
#define GPIOx_ODR       (*(unsigned long *)(GPIOB_BASE_ADDR + 0x14))
#define RCC_AHB1ENR     (*(unsigned long *)(0x40023800 + 0x30))

int main(){

	RCC_AHB1ENR |= (1 << 1); /* enable clock on port B */

	unsigned char mode_pin_gpio_b = 1; /* pin 3 output mode */

	GPIOB_MODER &= ~(0x03 << 3*2); /* clear pin 3 */
	GPIOB_MODER |= mode_pin_gpio_b << (3*2); /* pin 3 output mode */


	GPIOB_OTYPER &= ~(1 << 3); /* pin 3 push pull */

	GPIOx_ODR |= (1 << 3);


	while(1){
		//set pin 3 to high
		GPIOx_ODR |= (1 << 3);

		//wait for 1 sec
		for (int i = 0; i < 1600000; i++); 
		

		// set pin 3 to low
		GPIOx_ODR &= ~(1 << 3);
		
		//wait for 1 sec
		for (int i = 0; i < 1600000; i++);

		

	}



	

	return 0;
}

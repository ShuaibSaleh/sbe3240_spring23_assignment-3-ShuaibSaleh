/*
 * main.c
 *
 *  Created on: Apr 17, 2023
 *      Name: Shuaib Abdulsalam Ahmed Aklan Saleh
 *      Sec: 1
 *      B.N.: 48
 */




#define GPIOB_BASE_ADDRESS 0x40020400
#define RCC_BASE_ADDRESS  0x40023800
#define RCC_AHB1ENR_PORT_B (*(unsigned long *)(RCC_BASE_ADDRESS + 0x30))

#define GPIOB_MODER (*(unsigned long *)(GPIOB_BASE_ADDRESS + 0x00))

#define GPIOB_OTYPER (*(unsigned long *)(GPIOB_BASE_ADDRESS + 0x04))
#define GPIOB_PUPDR    (*(unsigned long *)(GPIOB_BASE_ADDRESS + 0x0C))

#define GPIOB_ODR (*(unsigned long *)(GPIOB_BASE_ADDRESS + 0x14))
#define GPIOB_IDR (*(unsigned long *)(GPIOB_BASE_ADDRESS + 0x10))




void RGB_LED(char mixedcolor, char red,char green, char blue);




int main(){

    /* enable port */
    RCC_AHB1ENR_PORT_B |= 1<<1 ;

    /* set pin number 3 as input button  */
    GPIOB_MODER &= ~(1<<(3*2));

    /* set pin 5 6 7 as output */
    GPIOB_MODER |= 1<<(5*2);
    GPIOB_MODER |= 1<<(6*2);
    GPIOB_MODER |= 1<<(7*2);


    /* type of input button   Pull-up*/
    GPIOB_PUPDR |= 1<<(3*2);



    /* type of output pin of led */
    GPIOB_OTYPER &= ~(1<<5);
    GPIOB_OTYPER &= ~(1<<6);
    GPIOB_OTYPER &= ~(1<<7);





    // char counter=0;
     char flag=0;
    char mixedcolor = 0;
    char red = 1<<5;
    char green = 1<<6;
    char blue = 1<<7;

while (1)
     {

	/* check the input button then apply delay
	   then check again for the denouncing feature*/
     if (GPIOB_IDR&(1<<3)){
         flag=0;

    
        for (int i = 0; i < 1600000; i++)
        {
            
        }
     
        if (GPIOB_IDR&(1<<3)){
             flag=0;

        }



     }


    //  else{
    //     if (counter >= 8 && flag == 0){
    //     counter=0;
    //     }

    //     if (counter < 8 && flag == 0){
    //     counter++;
    //     flag = 1;
    //     }

    //  }

     else{
              if (mixedcolor >= 7 && flag == 0 ){
            	  mixedcolor=-1;
              }

              if (mixedcolor < 7 && flag == 0){
            	  mixedcolor++;
                  flag = 1;
              }

           }


     RGB_LED(mixedcolor,red,green,blue);


    /*switch (counter)
                {

            case 0:
                GPIOB_ODR &= ~(1<<5) ;
                GPIOB_ODR &= ~(1<<6) ;
                GPIOB_ODR &= ~(1<<7) ;
                break;

            case 1:
                GPIOB_ODR |= 1<<5 ;
                GPIOB_ODR &= ~(1<<6) ;
                GPIOB_ODR &= ~(1<<7) ;
                break;
            case 2:
                GPIOB_ODR &= ~(1<<5) ;
                GPIOB_ODR |= (1<<6)  ;
                GPIOB_ODR &= ~(1<<7) ;
                break;
            case 3:

                GPIOB_ODR &= ~(1<<5) ;
                GPIOB_ODR &= ~(1<<6) ;
                GPIOB_ODR |= (1<<7)  ;
                break;
            case 4:
                GPIOB_ODR |= (1<<5)  ;
                GPIOB_ODR |= (1<<6)  ;
                GPIOB_ODR &= ~(1<<7) ;
                break;
            case 5:
                GPIOB_ODR |= (1<<5)  ;
                GPIOB_ODR &= ~(1<<6) ;
                GPIOB_ODR |= (1<<7)  ;
                break;
            case 6:
                GPIOB_ODR &= ~(1<<5) ;
                GPIOB_ODR |= (1<<6)  ;
                GPIOB_ODR |= (1<<7)  ;
                break;
            case 7:
                GPIOB_ODR |= (1<<5)  ;
                GPIOB_ODR |= (1<<6)  ;
                GPIOB_ODR |= (1<<7)  ;
                break;

            case 8:
				GPIOB_ODR &= ~(1<<5) ;
				GPIOB_ODR &= ~(1<<6) ;
				GPIOB_ODR &= ~(1<<7) ;
				break;

            default:
			    counter=0;
			    flag=0;

    }*/


    ///////////////////////////////////////////////////////////////////////////////////////////////

}





    return 0 ;

}

void RGB_LED(char mixedcolor, char red,char green, char blue){

    if(mixedcolor == 0){
        GPIOB_ODR &= ~red ;
        GPIOB_ODR &= ~green ;
        GPIOB_ODR &= ~blue ;

    }

    else if(mixedcolor == 1){
        GPIOB_ODR |= red ;
        GPIOB_ODR &= ~(green) ;
        GPIOB_ODR &= ~blue ;
    }
    else if(mixedcolor == 2){
        GPIOB_ODR &= ~red ;
        GPIOB_ODR |= green  ;
        GPIOB_ODR &= ~blue ;
    }
    else if(mixedcolor == 3){

        GPIOB_ODR &= ~red ;
        GPIOB_ODR &= ~green ;
        GPIOB_ODR |= blue  ;
    }
    else if(mixedcolor == 4){
        GPIOB_ODR |= red  ;
        GPIOB_ODR |= green  ;
        GPIOB_ODR &= ~blue ;
    }
    else if(mixedcolor == 5){
        GPIOB_ODR |= red  ;
        GPIOB_ODR &= ~green ;
        GPIOB_ODR |= blue  ;
    }
    else if(mixedcolor == 6){
        GPIOB_ODR &= ~red ;
        GPIOB_ODR |= green  ;
        GPIOB_ODR |= blue  ;
    }
    else if(mixedcolor == 7){
        GPIOB_ODR |= red  ;
        GPIOB_ODR |= green  ;
        GPIOB_ODR |= blue  ;
    }

    else{
        mixedcolor = -1;
    }



}


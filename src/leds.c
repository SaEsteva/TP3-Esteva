#include "leds.h"

static uint16_t * puerto;

#define ALL_LEDS_ON 0x0000
#define ALL_LEDS_OFF 0xFFFF
#define LED_ON      1
#define LED_OFSET   1

uint16_t led_to_bit(uint8_t led){
    return (LED_ON << (led-LED_OFSET));
}

void Leds_Create(uint16_t * puntero){
    puerto = puntero;
    Led_TurnOffAll();
}

void Led_TurnOn(uint8_t led){
    *puerto |= led_to_bit(led);
}

void Led_TurnOff(uint8_t led){
    *puerto &= ~led_to_bit(led);
}

void Led_TurnOffAll(void){
    *puerto = ALL_LEDS_ON;
}

void Led_TurnOnAll(void){
    *puerto = ALL_LEDS_OFF;
}

void Led_Consult(uint8_t led,uint16_t * puntero){
    *puntero = (* puerto) & led_to_bit(led);
}
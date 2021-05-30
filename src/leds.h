#include <stdint.h>

void Leds_Create(uint16_t * puntero);
void Led_TurnOn(uint8_t led);
void Led_TurnOff(uint8_t led);
void Led_TurnOffAll(void);
void Led_TurnOnAll(void);
void Led_Consult(uint8_t led,uint16_t * puntero);
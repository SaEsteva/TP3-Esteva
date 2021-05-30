#include "unity.h"
#include "leds.h"

#define LED 5
uint16_t ledsVirtuales;


void setUp(void){
    ledsVirtuales = 0xFFFF;
    Leds_Create(&ledsVirtuales);
}

void tearDown(void){
}

// Despues de la inicializacion todos los LEDS deben quedar apagados
void test_LedsOffAfterCreate(void){
    TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales); //inyeccion de dependencias, compruebo que todos los leds esten apagados
}

// Se puede prender un LED individual
void test_TurnOnLedOne(void){
    Led_TurnOn(LED);
    TEST_ASSERT_EQUAL_HEX16(1 << (LED - 1), ledsVirtuales);
}

// Se puede apagar un LED individual
void test_TurnOffLedOne(void){
    Led_TurnOn(LED);
    Led_TurnOff(LED);
    TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
}

// Se pueden prender y apagar múltiples LEDs.
void test_TurnOnAndOffManyLeds(void){
    Led_TurnOn(3);
    Led_TurnOn(LED);
    Led_TurnOff(3);
    TEST_ASSERT_EQUAL_HEX16(1 <<(LED - 1), ledsVirtuales);
}

// Se pueden prender todos los LEDs de una vez.
void test_TurnOnAllLeds(void){
    Led_TurnOnAll();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, ledsVirtuales);
}

// Se pueden apagar todos los LEDs de una vez.
void test_TurnOffAllLeds(void){
    Led_TurnOnAll();
    Led_TurnOffAll();
    TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
}

// Se puede consultar el estado de un LED apagado.
void test_ConsultAnOffLed(void){
    uint16_t ledsVirtualesState = 0x0000;
    Led_TurnOn(LED);
    Led_TurnOff(LED);
    Led_Consult(LED,&ledsVirtualesState);
    TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtualesState);
}

// Se puede consultar el estado de un LED 
void test_ConsultALed(void){
    uint16_t ledsVirtualesState = 0x0000;
    Led_TurnOn(LED);
    Led_Consult(LED,&ledsVirtualesState);
    TEST_ASSERT_EQUAL_HEX16(1 <<(LED - 1), ledsVirtualesState);
}

// Revisar limites de los parametros.
void test_LimitParameters(void){
    uint16_t ledsVirtualesState = 0x0000;
    Led_TurnOn(18);
    TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
    Led_TurnOn(3);
    Led_Consult(0,&ledsVirtualesState);
    TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtualesState);    
}
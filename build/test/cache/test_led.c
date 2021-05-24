#include "src/leds.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.31.0/vendor/unity/src/unity.h"




uint16_t ledsVirtuales;





void setUp(void){



}



void tearDown(void){

}





void test_LedsOffAfterCreate(void){

    ledsVirtuales = 0xFFFF;

    Leds_Create(&ledsVirtuales);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(19), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOnLedOne(void){

    Led_TurnOn(5);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << (5 - 1))), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(25), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOffLedOne(void){

    Led_TurnOn(5);

    Led_TurnOff(5);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOnAndOffManyLeds(void){

    Led_TurnOn(3);

    Led_TurnOn(5);

    Led_TurnOff(3);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 <<(5 - 1))), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(40), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOnAllLeds(void){

    Led_TurnOffAll();

    Led_TurnOnAll();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(47), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOffAllLeds(void){

    Led_TurnOnAll();

    Led_TurnOffAll();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(54), UNITY_DISPLAY_STYLE_HEX16);

}





void test_ConsultAnOffLed(void){

    uint16_t ledsVirtualesState = 0x0000;

    Led_TurnOn(5);

    Led_TurnOff(5);

    Led_ConsutlOff(5,&ledsVirtualesState);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtualesState)), (

   ((void *)0)

   ), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_HEX16);

}





void test_ConsultALed(void){

    uint16_t ledsVirtualesState = 0x0000;

    Led_TurnOn(5);

    Led_ConsutlLed(5,&ledsVirtualesState);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 <<(5 - 1))), (UNITY_INT)(UNITY_INT16)((ledsVirtualesState)), (

   ((void *)0)

   ), (UNITY_UINT)(71), UNITY_DISPLAY_STYLE_HEX16);

}





void test_LimitParameters(void){

    uint16_t ledsVirtualesState = 0x0000;

    Led_TurnOffAll();

    Led_TurnOn(18);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_HEX16);

    Led_TurnOn(3);

    Led_ConsutlLed(0,&ledsVirtualesState);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtualesState)), (

   ((void *)0)

   ), (UNITY_UINT)(82), UNITY_DISPLAY_STYLE_HEX16);

}

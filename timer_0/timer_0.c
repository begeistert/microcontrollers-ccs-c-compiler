
#include <18F45K50.h>                      // Para PIC18F4550 cambiar por: #include <18F4550.h>
#use delay(internal=48MHz)                // Tipo de oscilador y frecuencia dependiendo del microcontrolador 
#build(reset=0x02000,interrupt=0x02008)  // Asigna los vectores de reset e interrupción para la versión con bootloader
#org 0x0000,0x1FFF {}                       // Reserva espacio en memoria para el bootloader

void SisInit()
{
    set_tris_b(0x00);                                 // C2 salida
    setup_timer_0(T0_INTERNAL|T0_DIV_2); //|T0_DIV_4
    set_timer0(0X1B);
    enable_interrupts(INT_TIMER0);
    enable_interrupts(GLOBAL);

}

#int_TIMER0
void TIMER0_isr() {
    output_toggle(PIN_B0);                              //Salida Pin_C2 50Hz
    set_timer0(0X1B);                                      // 20 miliSegundos
}

void main()
{
    SisInit();
    while(TRUE) {};
}




#include <18F45K50.h>                                        //Para PIC18F4550 cambiar por: #include <18F4550.h>
#use delay(internal=48Mhz)                                  //Tipo de oscilador y frecuencia dependiendo del microcontrolador 
#build(reset=0x02000,interrupt=0x02008)        //Asignación de los vectores de reset e interrupción
#org 0x0000,0x1FFF {}
#use standard_io(B)
int1 cont= 0;
#int_TIMER1 //interrupcion timer 1
void templs(void) //funcion
{
    if(cont==1) output_toggle(PIN_B1); //Cada 2 interrupciones de 0.5s
    set_timer1(3036); //recarga del timer1
    cont++;
}
void main()
{
    setup_timer_1(T1_INTERNAL | T1_DIV_BY_8);
    set_timer1(3036); //recarga del timer1
    enable_interrupts(INT_TIMER1); //Habilita interrupcion timer1
    enable_interrupts(global);
    while(true) {
    }
}


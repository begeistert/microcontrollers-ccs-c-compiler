#include <18F45K50.h>                                        //Para PIC18F4550 cambiar por: #include <18F4550.h>
#use delay(internal=48Mhz)                                  //Tipo de oscilador y frecuencia dependiendo del microcontrolador
#build(reset=0x02000,interrupt=0x02008)        //Asignación de los vectores de reset e interrupción
#org 0x0000,0x1FFF {}
#use standard_io(B)
void templs()
{
    int cont=0;
    output_toggle(PIN_B1);
    while(cont<2) //para contar 2 veces 0.5s
    {
        set_timer1(3036); //inicializa el TMR1
        while (get_timer1()>=3036); //espera a que se desborde (0.5s)
        cont++;
    }
}
void main ()
{
    setup_timer_1(T1_INTERNAL | T1_DIV_BY_8);
    while(true) {
        templs(); //llamada a la funcion de temporizacion
    }
}


#include <18F45K50.h>                                        //Para PIC18F4550 cambiar por: #include <18F4550.h>
#use delay(internal=48Mhz)                                  //Tipo de oscilador y frecuencia dependiendo del microcontrolador
#build(reset=0x02000,interrupt=0x02008)        //Asignación de los vectores de reset e interrupción
#org 0x0000,0x1FFF {}
#include <lcd.c>
int8 cuenta;
#int_timer0
void timer_0()
{
    set_timer0(0);
}
void main()
{
    setup_timer_0(rtcc_ext_l_to_h | rtcc_div_1);
    set_timer0(0);
    enable_interrupts(int_timer0);
    enable_interrupts(global);
    lcd_init();
    while(true)
    {
        cuenta= get_timer0();
        lcd_gotoxy(1,1);
        printf(lcd_putc," Cuenta= %3u ",cuenta);
    }
}


#include <18F45K50.h>
#use delay(internal=48Mhz)
#include <lcd.c>
#use fast_io(B)
//#build(reset=0x02000,interrupt=0x02008)
//#org 0x0000,0x1FFF {}
#int_ext
void ext_isr() {
    printf(lcd_putc,"\fFuncion\nInterrupcion");
    for(int i = 0; i < 10; i++) {
        output_high(PIN_B7);
        delay_ms(200);
        output_low(PIN_B7);
        delay_ms(100);
    }
}


void main() {
    lcd_init();
    printf(lcd_putc,"\fFucion\nPrincipal");
    set_tris_B(0x01);
    port_b_pullups(TRUE);
    output_high(PIN_B5);
    delay_ms(1000);
    output_low(PIN_B5);
    delay_ms(1000);
    enable_interrupts(int_ext);
    ext_int_edge(H_TO_L);
    enable_interrupts(GLOBAL);

    while(true) {
        printf(lcd_putc,"\fFuncion\nCiclada");
        output_high(PIN_B3);
        delay_ms(300);
        output_low(PIN_B3);
        delay_ms(200);
    }
}


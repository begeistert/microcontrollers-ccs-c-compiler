#include <18F45K50.h>       ///< Importación de librería para el PIC
#device ADC=10              ///<Conversor Analógico digital a 10 bits.
#use delay(internal = 4Mhz) ///< Declaración de la frec. del Oscilador
#include <lcd.c>
#include <stdio.h>
#include <stdint.h>
#build(reset = 0x02000,                                                        \
       interrupt =                                                             \
           0x02008)    ///< Asignación de los vectores de reset e interrupción
#org 0x0000, 0x1FFF {} ///< Reservación espacio en la memoría

float valor;
float voltaje;

void main(){
    setup_adc(ADC_CLOCK_INTERNAL);         //Seleccionamos el reloj interno RC para ADC 35kHz.
    set_adc_channel(0);                    //Seleccionamos el canal 0.
    lcd_init();
    set_tris_a(0xFF); // PORTA -> Entrada
    lcd_putc('\f');
    lcd_gotoxy(1, 1);
    while(true){
        delay_ms(100);
        valor = read_adc();
        voltaje = (valor*5.0)/1023;
        lcd_gotoxy(1,1);                    //Cursos en Fila 1, Columna 1.
        printf(lcd_putc, "ADC = %4.3f", valor); //Imprimir "valor" como 4 enteros 3 decimales.
        lcd_gotoxy(1,2);                    //Cursos en Fila 2, Comumna 1.
        printf(lcd_putc, "Voltaje = %4.3f", voltaje); //Imprimir "conversion" como 4 enteros 3 decimales.
        delay_ms(500);
    }
}





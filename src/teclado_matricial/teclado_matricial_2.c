#include <18F45K50.h> // Para PIC18F4550 cambiar por: #include <18F4550.h>
//#use delay(internal=48MHz)                          // Tipo de oscilador y
// frecuencia dependiendo del microcontrolador
#use delay(internal = 500kHz)
//#use standard_io(A)
#build(reset = 0x02000,                                                        \
       interrupt =                                                             \
           0x02008) // Asigna los vectores de reset e interrupción para
// la versión con bootloader
#org 0x0000, 0x1FFF {} // Reserva espacio en memoria para el bootloader

//#define LED PIN_A1                                       //Pin donde está
// conectado el LED de X-TRAINER char TECLA_PRESS;

////CONFIGURACION DE PINES TECLADO

#define row0 PIN_B0 // Filas del teclado colocar resistecia pullup
#define row1 PIN_B1 // Filas del teclado colocar resistecia pullup
#define row2 PIN_B2 // Filas del teclado colocar resistecia pullup
#define row3 PIN_B3 // Filas del teclado colocar resistecia pullup
#define col0 PIN_B4 // Columnas del teclado
#define col1 PIN_B5
#define col2 PIN_B6
//#define col3 PIN_B7

#include "Teclado4x3.h" //LIBRERIA DE TECLADO
#include <lcd.c>
#include <stdlib.h>
//#rom 0x2100={'7','2','3'}

void main() {
  char k;
  int x;
  lcd_init();
  kbd_init(); // inicialización del teclado.
  lcd_putc("\fListo.. . \n");
  while (true) {
    k = kbd_getc();
    x = k - 48;
    if (k != 0) {
      if (k == '*') {
        lcd_putc("\fListo.. . \n");
      } else {
        lcd_putc(k);
        // delay_ms(500);

        // printf(lcd_putc, "\f Car=%c",k);
        // delay_ms(500);

        // printf (lcd_putc,"\f Car=%u",k);
        // delay_ms(500);

        // printf (lcd_putc,"\f Num=%u",x) ;
        // delay_ms(500);
        // lcd_putc ("\fListo. . . \n") ;
      }
    }
  }
}

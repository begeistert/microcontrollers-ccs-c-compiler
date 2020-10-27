/**
  @file standard_io.c
  @brief Programa para apagar y encender un LED mediante un bot�n

  Mediante el puerto A0 conectado a un bot�n en pull-up se encendera un LED,
  si el pin A0 se encuentra en 0 el PIN B0 activara el LED de lo contrario lo
  apagar�
  
  ** Se configuraran los puertos mediante standard_io()

  @author Iv�n Montiel Cardona
  @date 10/2020

*/
#include <18F45K50.h>                  ///< Importaci�n de librer�a para el PIC
#use delay(internal=48Mhz)             ///< Declaraci�n de la frec. del oscilador
#use standard_io(B)                    ///< Configuracion E/S para el PORT A
#use standard_io(D)                    ///< Configuracion E/S para el PORT B
#build(reset=0x02000,interrupt=0x02008)///< Asignaci�n de los vectores de reset e interrupci�n
#org 0x0000,0x1FFF {}                  ///< Reservaci�n espacio en la memor�a
#include "lcd.c"
#include "kbd.c"

void main(){
   char k;
   int x;
   lcd_init();
   kbd_init(); 
   port_b_pullups(true);
   lcd_putc ("\fListo.. . \n");
   while(true){
      k = kbd_getc();
      x = k-48;
      if(k != 0){
         if(k == "*")
            lcd_putc("\f");
         else 
            lcd_putc(k);
            delay_ms (500) ;
            printf (lcd_putc, "\f Car=%c",k);
            delay_ms (500) ;
            printf (lcd_putc,"\f Car=%u",k) ; 
            delay_ms (500) ;
            printf (lcd_putc,"\f Num=%u",x) ;
            delay_ms (500) ;
            lcd_putc ("\fListo. . . \n") ;
      }
   }
}

/**
  @file display_0-99.c
  @brief Programa para realizar menú de contron mediante pulsador

  El programa debe mostrar un menú de 3 funciones. Mediante el pulsador se debe
  seleccionar uno de los 3 elementos y otro para ejecutar la función
  
  ** Se configuraran los puertos mediante standard_io()

  @author Iván Montiel Cardona
  @date 10/2020

*/
#include <18F45K50.h>                  ///< Importación de librería para el PIC
#use delay(internal=48Mhz)             ///< Declaración de la frec. del oscilador
#use fast_io(A)                    ///< Configuracion E/S para el PORT A
#use fast_io(C)                    ///< Configuracion E/S para el PORT B
#build(reset=0x02000,interrupt=0x02008)///< Asignación de los vectores de reset e interrupción
#org 0x0000,0x1FFF {}                  ///< Reservación espacio en la memoría
byte const display[10] = {
                           0x3f,
                           0x06,
                           0X5b,
                           0x4f,
                           0x66,
                           0x6d,
                           0x7d,
                           0x07,
                           0x7f,
                           0x6f
                          };

void SistInit(){
   set_tris_b(0x00);
   set_tris_a(0x00);
   output_b(0);
}

void main(){
   byte ud=0, dec=0;
   SistInit();
   for(;;) 
   {
      for (dec=0;dec<10;dec++) 
      {
         for (ud=0;ud<10;ud++) 
         {
            output_a(0x02);
            output_b(DISPLAY[ud]);
            delay_ms(50);
            if (dec==0) output_a(0x03);
            else output_a(0x01);
            output_b(DISPLAY[dec]);
            delay_ms(50);
         }
      }
   }
}


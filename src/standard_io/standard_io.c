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
#use standard_io(A)                    ///< Configuracion E/S para el PORT A
#use standard_io(B)                    ///< Configuracion E/S para el PORT B
#build(reset=0x02000,interrupt=0x02008)///< Asignaci�n de los vectores de reset e interrupci�n
#org 0x0000,0x1FFF {}                  ///< Reservaci�n espacio en la memor�a

/**
 * Funcion principal, realizarar� todas las operaciones cicladas que deseemos
 * @param None.
 */

void main() {

    while(true) {                ///< Inicio de bucle infinito

        if(input(PIN_A0) == 1) { ///< Condici�n: En tanto el pin A0 sea 1 o True

            output_LOW(PIN_B0); ///< El pin B0 se apagar� (LED)

        } else {               ///< Si el pin A0 no es 1 o True

            output_HIGH(PIN_B0);///< El pin B0 se encender�

        }

    }

}

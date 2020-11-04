/**
  @file fast_io.c
  @brief Programa para apagar y encender un LED mediante un bot�n

  Mediante el puerto A0 conectado a un bot�n en pull-up se encendera un LED,
  si el pin A0 se encuentra en 0 el PIN B0 activara el LED de lo contrario lo
  apagar�

  ** Se configuraran los puertos mediante fast_io()

  @author Iv�n Montiel Cardona
  @date 10/2020

*/
#include <18F45K50.h>        ///< Importaci�n de librer�a para el PIC
#use delay(internal = 48Mhz) ///< Declaraci�n de la frec. del Oscilador
#use fast_io(A)              ///< Configuracion E/S para el PORT A
#use fast_io(B)              ///< Configuracion E/S para el PORT B
#build(reset = 0x02000,                                                        \
       interrupt =                                                             \
           0x02008)    ///< Asignaci�n de los vectores de reset e interrupci�n
#org 0x0000, 0x1FFF {} ///< Reservaci�n espacio en la memor�a

/**
 * Inicializa los puertos A y B mediante la funci�n set_tris_x()
 * El puerto A se define como salida
 * El puerto B se define como entrada
 * @param None.
 */

void SisInit() {
  ///                  Pin Numero: 0|1|2|3|4|5|6|7
  ///                              ---------------
  set_tris_a(0XFF); ///< EL puerto A se define como (I|I|I|I|I|I|I|I)
  set_tris_b(0X00); ///< El puerto B se define como (O|O|O|O|O|O|O|O)
  output_a(0X00);   ///< La salida del puerto A es  (0|0|0|0|0|0|0|0)
                    ///  Donde I->Input y O->Output
}

/**
 * Funcion principal, realizarar� todas las operaciones cicladas que deseemos
 * @param None.
 */

void main() {

  SisInit(); ///< Configuraci�n de los puertos del PIC

  while (1) { ///< Inicio de bucle infinito

    if (input(PIN_A0) == 1) { ///< Condici�n: En tanto el pin A0 sea 1 o True

      output_LOW(PIN_B0); ///< El pin B0 se apagar� (LED)

    } else { ///< Si el pin A0 no es 1 o True

      output_HIGH(PIN_B0); ///< El pin B0 se encender�
    }
  }
}

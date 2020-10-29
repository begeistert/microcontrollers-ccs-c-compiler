# Programa 5 - Teclado Matricial
## Programa para habilitar un relay por medio de un código

### Descripción:

Mediante un _**LCD**_ conectado al `PORT D`, un teclado matricial 4x3 conectado al `PORT B` y un circuito con relay conectado al pin `A0`

## Circuito

<p align="center">
  <img src="https://github.com/begeistert/microcontrollers-ccs-c-compiler/blob/main/circuits/teclado_matricial.jpg">
</p>

### Instrucciones

Recuerda no olvidar las siguientes lineas de configuración, son fundamentales para el PIC `18F45K50`

```c
#include <18F45K50.h>                  ///< Importación de librería para el PIC
#use delay(internal=48Mhz)             ///< Declaración de la frec. del Oscilador
#build(reset=0x02000,interrupt=0x02008)///< Asignación de los vectores de reset e interrupción
#org 0x0000,0x1FFF {}                  ///< Reservación espacio en la memoría
```

* _Para este ejercicio se utilizo una version modificada de la librería `kbd.c` obtenida de [Microside](https://microside.com/portfolio-item/practica-10-ccs-as/), nuevamente adaptada a los requerimientos de este ejemplo (Vease [`Teclado4x3.h`](https://github.com/begeistert/microcontrollers-ccs-c-compiler/blob/main/teclado_matricial/Teclado4x3.h) para mas información). Debido a esto se declararon dentro del programa las filas y columnas a usar._

```c
#define row0 PIN_B0      //Fila A del teclado (colocar resistecia pullup)
#define row1 PIN_B1      //Fila B del teclado (colocar resistecia pullup)
#define row2 PIN_B2      //Fila C del teclado (colocar resistecia pullup)
#define row3 PIN_B3      //Fila D del teclado (colocar resistecia pullup)
#define col0 PIN_B4      //Columna 1 del teclado
#define col1 PIN_B5      //Columna 2 del teclado
#define col2 PIN_B6      //Columna 3 del teclado
```

Dentro del método [`main`](https://github.com/begeistert/microcontrollers-ccs-c-compiler/blob/955a77aec47d7b38fe45dcb9f0f0ef2d24f79b96/teclado_matricial/teclado-1-0.c#L28)
se ha declarado un bucle infinito, dentro del cual, mediante distintas variables de contro y el arreglo `data` se obtienen las teclas presionadas, posterior a ello 
una condicion `if` comprueba que todos los datos ingresados en el array `data` coincidan con la clave, de sera así se mostrará en el _**LCD**_ la frase _"Puerta Abierta"_, 
inmediatamente despues se habilitará el pin `A0`, lo que cambiara la posición del relay durante `500ms`, despues de eso, el relay regresará a su posicion original y se 
mostrará el mensaje _"Puerta Cerrada"_ en el **_LCD_**, por ultimo habra un delay de `1s` antes de volver a iniciar todo el ciclo.
existe una condición que comprueba si el boton conectado a `A0` ha sido presionado, de ser así, el contador `item`

** _Revisa el archivo [`teclado-1-0.c`](https://github.com/begeistert/microcontrollers-ccs-c-compiler/blob/main/teclado_matricial/teclado-1-0.c) para más información_
<br/>
*** _Para el ejemplo `5` revisa el archivo [`teclado_matricial_2.c`](https://github.com/begeistert/microcontrollers-ccs-c-compiler/blob/main/teclado_matricial/teclado_matricial_2.c)_

##### Iván Montiel Cardona

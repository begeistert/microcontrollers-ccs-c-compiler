# Programa 4 - Display _LCD_
## Programa para hacer un menú con un display _LCD_

### Descripción:

Mediante un _**LCD**_ conectado al `PORT D`, dos botones que serviran como los selectores en los pines `A0` y `A1` y 3 _**LEDs**_  conectadoas a los pines `C0`,
`C1` y `C2`.

La configuracion de los puertos se realiza usando `standard_io`
- Esta directiva afecta al código que el compilador genera para las instrucciones de entrada y salida. El método `standard_io` causará que el compilador genere
código para hacer que un pin de E/S sea entrada o salida cada vez que se utiliza.

## Circuito

<p align="center">
  <img src="https://github.com/begeistert/microcontrollers-ccs-c-compiler/blob/main/circuits/display_LCD.jpg">
</p>

### Instrucciones

Recuerda no olvidar las siguientes lineas de configuración, son fundamentales para el PIC `18F45K50`

```c
#include <18F45K50.h>                  ///< Importación de librería para el PIC
#use delay(internal=48Mhz)             ///< Declaración de la frec. del Oscilador
#use fast_io(A)                        ///< Configuracion E/S para el PORT A
#use fast_io(B)                        ///< Configuracion E/S para el PORT B
#build(reset=0x02000,interrupt=0x02008)///< Asignación de los vectores de reset e interrupción
#org 0x0000,0x1FFF {}                  ///< Reservación espacio en la memoría
```

Dentro del método [`main`](https://github.com/begeistert/microcontrollers-ccs-c-compiler/blob/2154e8924c1812ab68dd5153a6c4526c4dedde1f/display-LCD/display_LCD.c#L57)
se ha declarado un bucle infinito, dentro del cual, existe una condición que comprueba si el boton conectado a `A0` ha sido presionado, de ser así, el contador `item`
aumentara su valor, otra condición comprueba que el valor de `item` no sea mayor a `3`, de ser asi cambiara a `0`, segudo de estas instrucciones se encuentra un [`switch`](https://github.com/begeistert/microcontrollers-ccs-c-compiler/blob/2154e8924c1812ab68dd5153a6c4526c4dedde1f/display-LCD/display_LCD.c#L73)
el cual imprimira en el _**LCD**_ el mensaje correspondiente al elemento del menu seleccionado, por ultimo, existe una condición que determinará si el boton conectado
al pin `A1` ha sido presionado, de ser así, se hara una llamada al método [`run_func()`](https://github.com/begeistert/microcontrollers-ccs-c-compiler/blob/2154e8924c1812ab68dd5153a6c4526c4dedde1f/display-LCD/display_LCD.c#L38)
que a su vez posee un [`switch`](https://github.com/begeistert/microcontrollers-ccs-c-compiler/blob/2154e8924c1812ab68dd5153a6c4526c4dedde1f/display-LCD/display_LCD.c#L39) que ejecutara la acción correspondiente a la acción del elemento del menú seleccionado

** _Revisa el archivo [`display_LCD.c`](https://github.com/begeistert/microcontrollers-ccs-c-compiler/blob/2154e8924c1812ab68dd5153a6c4526c4dedde1f/display-LCD/display_LCD.c) para más información_

##### Iván Montiel Cardona

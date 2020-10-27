# Programa 2 - Puertos standard_io
## Programa para apagar y encender un LED mediante un botón

### Descripción:

Mediante el puerto `A0` conectado a un botón en _pull-up_ se encendera un _**LED**_, si el pin `A0` se encuentra en `0` el pin `B0` activara el _**LED**_ de lo contrario lo apagará

La configuracion de los puertos se realiza usando `standard_io`
- Esta directiva afecta al código que el compilador genera para las instrucciones de entrada y salida. El método `standard_io` causará que el compilador genere
código para hacer que un pin de E/S sea entrada o salida cada vez que se utiliza.

### Instrucciones

Recuerda no olvidar las siguientes lineas de configuración, son fundamentales para el PIC `18F45K50`

```c
#include <18F45K50.h>                  ///< Importación de librería para el PIC
#use delay(internal=48Mhz)             ///< Declaración de la frec. del Oscilador
#use standard_io(A)                    ///< Configuracion E/S para el PORT A
#use standard_io(B)                    ///< Configuracion E/S para el PORT B
#build(reset=0x02000,interrupt=0x02008)///< Asignación de los vectores de reset e interrupción
#org 0x0000,0x1FFF {}                  ///< Reservación espacio en la memoría
```
Dentro del método [`main`](https://github.com/begeistert/microcontrollers-ccs-c-compiler/blob/f4610e37ce9313f6c1a660e468bdaa2b84d419a9/standard_io/standard_io.c#L43) se han declarado condiciones que permiten una configuración _pull-up_ a la entrada, que sera el pin `A0`. La condición define que si
`A0`== `0` el  _**LED**_ en `B0` (que funge como salida) se encenderá, en caso de que `A0` == `1` ocurrira que, `B0` tendrá a la salida `0` o `false` y el _**LED**_ se apagará

** _Revisa el archivo [`standard_io.c`](https://github.com/begeistert/microcontrollers-ccs-c-compiler/blob/f4610e37ce9313f6c1a660e468bdaa2b84d419a9/standard_io/standard_io.c) para más información_

##### Iván Montiel Cardona

<!-- PROJECT LOGO -->
<br />
<p align="center">
  <a href="https://github.com/begeistert/microcontrollers-ccs-c-compiler/tree/main/fast_io#microcontroladores">
    <img src="https://github.com/begeistert/microcontrollers-ccs-c-compiler/blob/main/circuits/pic.png" alt="Logo" width="200" height="200">
  </a>

  <h3 align="center">Microcontroladores</h3>
  <h4 align="center">Programa 2 - Puertos standard_io</h4>
  <p align="center">
    Programa para apagar y encender un LED mediante un botón
    <br />
    <a href="https://github.com/begeistert/microcontrollers-ccs-c-compiler/blob/main/standard_io/standard_io.c"><strong>Ve el código fuente »</strong></a>
    <br />
  </p>
  </p>

### Descripción:

Mediante el puerto `A0` conectado a un botón en _pull-up_ se encendera un
_**LED**_, si el pin `A0` se encuentra en `0` el pin `B0` activara el _**LED**_
de lo contrario lo apagará

La configuracion de los puertos se realiza usando `standard_io`

> Esta directiva afecta al código que el compilador genera para las
> instrucciones de entrada y salida. El método `standard_io` causará que el
> compilador genere código para hacer que un pin de E/S sea entrada o salida
> cada vez que se utiliza.

## Circuito

<p align="center">
  <img src="https://github.com/begeistert/microcontrollers-ccs-c-compiler/blob/main/circuits/fast_io.jpg?raw=true">
</p>

### Instrucciones

Recuerda no olvidar las siguientes lineas de configuración, son fundamentales
para el PIC `18F45K50`

```c
#include <18F45K50.h>                  ///< Importación de librería para el PIC
#use delay(internal=48Mhz)             ///< Declaración de la frec. del Oscilador
#use standard_io(A)                    ///< Configuracion E/S para el PORT A
#use standard_io(B)                    ///< Configuracion E/S para el PORT B
#build(reset=0x02000,interrupt=0x02008)///< Asignación de los vectores de reset e interrupción
#org 0x0000,0x1FFF {}                  ///< Reservación espacio en la memoría
```

- Cuando se hace uso de `standard_io(x)` no es requerido declarar si el pin de
  determinado puerto es entrada o salida, por lo que para este caso se omitirá

Dentro del método
[`main`](https://github.com/begeistert/microcontrollers-ccs-c-compiler/blob/fcfacda5cac251dd9f4ae61bc9bedbb9a21a5040/fast_io/fast_io.c#L41)
se han declarado condiciones que permiten una configuración _pull-up_ a la
entrada, la cual será el pin `A0`.

```c
if(input(PIN_A0) == 1){
  ...
} else {
  ...
}
```

La condición define que si`A0`== `1` el _**LED**_ en `B0` (que funge como
salida) se apagará

```c
if(input(PIN_A0) == 1){
  output_LOW(PIN_B0);
}
```

En caso de que la condición `A0` == `0` se cumpla, `B0` tendrá a la salida `1` o
`true` y el _**LED**_ se encenderá

```c
else {
  output_HIGH(PIN_B0);
}
```

##### Iván Montiel Cardona

<!-- PROJECT LOGO -->
<br />
<p align="center">
  <a href="https://github.com/begeistert/microcontrollers-ccs-c-compiler/tree/main/fast_io#microcontroladores">
    <img src="https://github.com/begeistert/microcontrollers-ccs-c-compiler/blob/main/circuits/pic.png" alt="Logo" width="200" height="200">
  </a>

  <h2 align="center">Microcontroladores</h2>
  <h3 align="center">Programa 1 - Puertos fast_io</h3>
  <p align="center">
    Programa para apagar y encender un LED mediante un botón
    <br />
    <a href="https://github.com/begeistert/microcontrollers-ccs-c-compiler/blob/main/fast_io/fast_io.c"><strong>Ve el código fuente »</strong></a>
    <br />
  </p>
  </p>

---

### Descripción:

Mediante el puerto `A0` conectado a un botón en _pull-up_ se encendera un _**LED**_, si el pin `A0` se encuentra en `0` el pin `B0` activara el _**LED**_ de lo contrario lo apagará

La configuracion de los puertos se realiza usando `fast_io`
> Esta directiva afecta al código que el compilador generará para las instrucciones de entrada y salida. Este método rápido de hacer I/O ocasiona que el compilador   realice I/O sin programar el registro de dirección

---

## Circuito

<p align="center">
  <a href="https://github.com/begeistert/microcontrollers-ccs-c-compiler/tree/main/fast_io#circuito">
    <img src="https://github.com/begeistert/microcontrollers-ccs-c-compiler/blob/main/circuits/fast_io.jpg?raw=true">
  </a>
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

Para este programa se ha usado un metodo de configuración denominado [`SisInit()`](https://github.com/begeistert/microcontrollers-ccs-c-compiler/blob/fcfacda5cac251dd9f4ae61bc9bedbb9a21a5040/fast_io/fast_io.c#L27), esto es necesario debido a la impelentación `fast_io(x)`, para la cual es necesario definir entradas y salidas en el puerto seleccionado, el metodo de configuración se ha definido de la siguiente manera [^1]


```c
void SisInit(){
   set_tris_a(0XFF);  
   set_tris_b(0X00);  
   output_a(0X00);    
}
```

Sin embargo, esto no es estrictamente necesario, es posible cambiar el nombre de la función o incluso añadirlo directamente al metodo [`main`](https://github.com/begeistert/microcontrollers-ccs-c-compiler/blob/fcfacda5cac251dd9f4ae61bc9bedbb9a21a5040/fast_io/fast_io.c#L41) , por ejemplo
```c
void main(){
   set_tris_a(0XFF);  
   set_tris_b(0X00);  
   output_a(0X00); 
   ...
}
```

Con el codigo anterior, los puertos A y B quedarian configurados de la siguente manera:

| Puerto |  Pin 0  |  Pin 1  |  Pin 2  |  Pin 3  |  Pin 4  |  Pin 5  |  Pin 6  |  Pin 7  |
| :----: | :-----: | :-----: | :-----: | :-----: | :-----: | :-----: | :-----: | :-----: |
|   A    | Entrada | Entrada | Entrada | Entrada | Entrada | Entrada | Entrada | Entrada |
|   B    | Salida  | Salida  | Salida  | Salida  | Salida  | Salida  | Salida  | Salida  |


Dentro del método [`main`](https://github.com/begeistert/microcontrollers-ccs-c-compiler/blob/fcfacda5cac251dd9f4ae61bc9bedbb9a21a5040/fast_io/fast_io.c#L41) se han declarado condiciones que permiten una configuración _pull-up_ a la entrada, la cual será el pin `A0`.

```c
if(input(PIN_A0) == 1){
  ...
} else {
  ...
}
```

La condición define que si`A0`== `1` el  _**LED**_ en `B0` (que funge como salida) se apagará

```c
if(input(PIN_A0) == 1){
  output_LOW(PIN_B0);
}
```

En caso de que la condición `A0` == `0` se cumpla,  `B0` tendrá a la salida `1` o `true` y el _**LED**_ se encenderá

```c
else {
  output_HIGH(PIN_B0);
}
```
---

#### **_Revisa el archivo [`fast_io.c`](https://github.com/begeistert/microcontrollers-ccs-c-compiler/blob/main/fast_io/fast_io.c) para más información_

##### Iván Montiel Cardona

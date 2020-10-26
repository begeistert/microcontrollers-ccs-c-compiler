# Programa 1 - Puertos fast_io
## Programa para apagar y encender un LED mediante un botón

### Descripción:

Mediante el puerto `A0` conectado a un botón en _pull-up_ se encendera un _**LED**_, si el pin `A0` se encuentra en `0` el pin `B0` activara el _**LED**_ de lo contrario lo apagará

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

Para este programa se ha usado un metodo de configuración denominado `SisInit()`, definido de la siguiente manera


```c
void SisInit(){
   set_tris_a(0XFF);  
   set_tris_b(0X00);  
   output_a(0X00);    
}
```

Sin embargo, esto no es estrictamente necesario, es posible cambiar el nombre de la función o incluso añadirlo directamente al metodo `main`, por ejemplo
```c
void main(){
   set_tris_a(0XFF);  
   set_tris_b(0X00);  
   output_a(0X00); 
   ...
}
```
Dentro del método `main` se han declarado condiciones que permiten una configuración _pull-up_ a la entrada, que sera el pin `A0`. La condición define que si
`A0`== `0` el  _**LED**_ en `B0` (que funge como salida) se encenderá, en caso de que `A0` == `1` ocurrira que, `B0` tendrá a la salida `0` o `false` y el _**LED**_ se apagará

** _Revisa el archivo `puertos-fast_io.c` para más información_

##### Iván Montiel Cardona

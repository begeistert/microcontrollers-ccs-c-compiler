<!-- PROJECT LOGO -->
<br />
<p align="center">
  <a href="https://github.com/begeistert/microcontrollers-ccs-c-compiler/tree/main/fast_io#microcontroladores">
    <img src="https://github.com/begeistert/microcontrollers-ccs-c-compiler/blob/main/circuits/pic.png" alt="Logo" width="200" height="200">
  </a>

  <h3 align="center">Microcontroladores</h3>
  <h4 align="center">Programa 3 - Display de 7 segmentos de 0 a 99</h4>
  <p align="center">
    Programa para hacer un conteo de 0 a 99 en un display de 7 segmentos multiplexeado
    <br />
    <a href="https://github.com/begeistert/microcontrollers-ccs-c-compiler/blob/main/display_7_seg_0-99/display_0-99.c"><strong>Ve el código fuente »</strong></a>
    <br />
  </p>
  </p>

### Descripción:

Mediante un _**display de 7 segmentos doble**_, conectado al `PORT B` y sus habilitadores a los pines `A0` y `A1` se realizará un conteo de 0 a 99, esto se lograra
mediante un multiplexeo del display doble, logrando así mostrar unidades y decenas

La configuracion de los puertos se realiza usando `fast_io`
> Esta directiva afecta al código que el compilador generará para las instrucciones de entrada y salida. Este método rápido de hacer I/O ocasiona que el compilador   realice I/O sin programar el registro de dirección

## Circuito

<p align="center">
  <img src="https://github.com/begeistert/microcontrollers-ccs-c-compiler/blob/main/circuits/display_0-99.jpg?raw=true">
</p>

En caso de no disponer de un display doble, es posible realizar la sigiente configuración con dos displays independientes

<p align="center">
  <img src="http://www.redusers.com/noticias/wp-content/uploads/2016/01/Display_PinOut.jpg">
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

Para este programa se ha usado un metodo de configuración denominado [`SisInit()`](https://github.com/begeistert/microcontrollers-ccs-c-compiler/blob/e05545064d016ff100d04a41fce35f53ccc1ec49/display_7_seg_0-99/display_0-99.c#L33), 
esto es necesario debido a la impelentación `fast_io(x)`, para la cual es necesario definir entradas y salidas en el puerto seleccionado, 
el metodo de configuración se ha definido de la siguiente manera


```c
void SisInit(){
   set_tris_a(0X00);  
   set_tris_b(0X00);   
}
```

Sin embargo, esto no es estrictamente necesario, es posible cambiar el nombre de la función o incluso añadirlo directamente al 
metodo [`main`](https://github.com/begeistert/microcontrollers-ccs-c-compiler/blob/e05545064d016ff100d04a41fce35f53ccc1ec49/display_7_seg_0-99/display_0-99.c#L39),
por ejemplo
```c
void main(){
   set_tris_a(0X00);  
   set_tris_b(0X00);  
   ...
}
```

Con el codigo anterior, los puertos A y B quedarian configurados de la siguente manera:

| Puerto |  Pin 0  |  Pin 1  |  Pin 2  |  Pin 3  |  Pin 4  |  Pin 5  |  Pin 6  |  Pin 7  |
| :----: | :-----: | :-----: | :-----: | :-----: | :-----: | :-----: | :-----: | :-----: |
|   A    | Salida  | Salida  | Salida  | Salida  | Salida  | Salida  | Salida  | Salida  |
|   B    | Salida  | Salida  | Salida  | Salida  | Salida  | Salida  | Salida  | Salida  |

Para habilitar los segmentos correctos del display se hace uso de un array unidimensional de 10 elementos denominado display, donde cada elemento de este arreglo
representará los numeros de `0` a `9` en codificación para display de 7 segmentos
```c
byte const display[10] = { 0x3f,
                           0x06,
                           0X5b,
                           0x4f,
                           0x66,
                           0x6d,
                           0x7d,
                           0x07,
                           0x7f,
                           0x6f};

```
Las configuraciones se muestran (para **catodo común**)en la siguente tabla a modo de valores booleanos (`true` y `false`):

<br/>
<p align="center">
  <img src="http://www.redusers.com/noticias/wp-content/uploads/2016/01/Display_Letras.jpg" width="201.6" height="232">
  <br/>
  <sub><stroke>Segmentos del display de 7 segmentos</stroke></sub>
</p>
<br/>

| Numero |    a    |    b    |    c    |    d    |    e    |    f    |    g    |
| :----: | :-----: | :-----: | :-----: | :-----: | :-----: | :-----: | :-----: | 
|   0    | `true`  | `true`  | `true`  | `true`  | `true`  | `true`  | `false` |
|   1    | `false` | `true`  | `true`  | `false` | `false` | `false` | `false` |
|   2    | `true`  | `true`  | `false` | `true`  | `true`  | `false` | `true`  |
|   3    | `true`  | `true`  | `true`  | `true`  | `false` | `false` | `true`  |
|   4    | `false` | `true`  | `true`  | `false` | `false` | `true`  | `true`  |
|   5    | `true`  | `false` | `true`  | `true`  | `false` | `true`  | `true`  |
|   6    | `true`  | `false` | `true`  | `true`  | `true`  | `true`  | `true`  |
|   7    | `true`  | `true`  | `true`  | `false` | `false` | `false` | `false` |
|   8    | `true`  | `true`  | `true`  | `true`  | `true`  | `true`  | `true`  |
|   9    | `true`  | `true`  | `true`  | `true`  | `false` | `true`  | `true`  |

<sub>En caso de usar un display en **anodo común** simplemente se debe ontener el complemento de cada valor en la tabla</sub>

Dentro del método [`main`](https://github.com/begeistert/microcontrollers-ccs-c-compiler/blob/e05545064d016ff100d04a41fce35f53ccc1ec49/display_7_seg_0-99/display_0-99.c#L39) se han declarado un par de ciclos anidados que recorrerán el arreglo `display`.

```c
for (dec=0;dec<10;dec++){
  for (ud=0;ud<10;ud++){
    ...
  }
}
```

El ciclo mas anidado recorrera las unidades y las mostrara en el display de unidades.

```c
for (dec=0;dec<10;dec++){
  for (ud=0;ud<10;ud++){
    output_a(0x02);
    output_b(DISPLAY[ud]);
    delay_ms(50);
    ...
  }
}
```

Cuando este ciclo se haya concluido, el `for` superior aumentara en uno el contador de decenas y volverá a entrar al ciclo más "profundo", pero esta vez mostrara
el digito de las decenas multiplexeando el display

```c
for (dec=0;dec<10;dec++){
  for (ud=0;ud<10;ud++){
    ...
    if (dec==0) output_a(0x03);
    else output_a(0x01);
    output_b(DISPLAY[dec]);
    delay_ms(50);
  }
}
```

Esto continuará hasta llegar a 99, momento en el cual los ciclos se reiniciarán y el conteo volverá a comenzar.

** _Revisa el archivo [`display_0-99.c`](https://github.com/begeistert/microcontrollers-ccs-c-compiler/blob/main/display_7_seg_0-99/display_0-99.c) para más información_

##### Iván Montiel Cardona

/**
  @file display_LCD.c
  @brief Programa para realizar men� de contron mediante pulsador

  El programa debe mostrar un men� de 3 funciones. Mediante el pulsador se debe
  seleccionar uno de los 3 elementos y otro para ejecutar la funci�n

  ** Se configuraran los puertos mediante standard_io()

  @author Iv�n Montiel Cardona
  @date 10/2020

*/
#include <18F45K50.h>                  ///< Importaci�n de librer�a para el PIC
#use delay(internal=48Mhz)             ///< Declaraci�n de la frec. del Oscilador
#include <lcd.c>
#use standard_io(A)                    ///< Configuracion E/S para el PORT A
#use standard_io(C)                    ///< Configuracion E/S para el PORT B
#build(reset=0x02000,interrupt=0x02008)///< Asignaci�n de los vectores de reset e interrupci�n
#org 0x0000,0x1FFF {}                  ///< Reservaci�n espacio en la memor�a
enum funciones {med,cal,ini};

void medir() {
    //algoritmo correspondiente
    output_toggle(PIN_C0);
}

void calibrar() {
    //algoritmo correspondiente
    output_toggle (PIN_C1);
}

void inicializar () {
    //algoritmo correspondiente
    output_toggle (pin_C2) ;
}

void run_func (int numfunc) {
    switch (numfunc) {
    case med:
        medir ();
        break;
    case cal:
        calibrar ();
        break;
    case ini:
        inicializar ();
        break;
    }
}

/**
 * Funcion principal, realizarar� todas las operaciones cicladas que deseemos
 * @param None.
 */

void main() {

    char item;
    char n_menus = 3;

    lcd_init();

    while(true) {                ///< Inicio de bucle infinito

        if(input(PIN_A0)) { ///< Condici�n: En tanto el pin A0 sea 1 o True
            item++;
            delay_ms(300);
            lcd_putc('\f');
        }
        if (item > (n_menus-1)) {
            item = 0;
        }

        switch(item) {
        case 0:
            lcd_gotoxy(1, 1);
            printf(lcd_putc, "MEDIR");
            lcd_gotoxy(1, 1);
            break;
        case 1:
            printf(lcd_putc, "CALIBRAR");
            lcd_gotoxy(1, 1);
            break;
        case 2:
            printf(lcd_putc, "INICIALIZAR");
            lcd_gotoxy(1, 1);
            break;
        }

        if(input(PIN_A1)) {
            delay_ms(200);
            run_func(item);
        }
    }
}

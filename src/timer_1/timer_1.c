
#include <18F45K50.h> // Para PIC18F4550 cambiar por: #include <18F4550.h>
#use delay(internal = 48MHz) // Tipo de oscilador y frecuencia dependiendo del
// microcontrolador
#build(reset = 0x02000,                                                        \
       interrupt =                                                             \
           0x02008) // Asigna los vectores de reset e interrupción para
// la versión con bootloader
#org 0x0000, 0x1FFF {} // Reserva espacio en memoria para el bootloader
#use standard_io(B)

void SisInit() {                         // C2 salida
  setup_timer_1(T0_INTERNAL | T0_DIV_8); //|T0_DIV_4
}

void templs() {
  int cont = 0;

  output_toggle(PIN_B1);

  while (cont < 2) {
    set_timer1(3036);
    while (get_timer1() >= 3036)
      ;
    cont++;
  }
}

void main() {
  SisInit();
  while (TRUE) {
  };
}

#include <18F45K50.h>        //Para PIC18F4550 cambiar por: #include <18F4550.h>
#use delay(internal = 48Mhz) // Tipo de oscilador y frecuencia dependiendo del
                             // microcontrolador
#build(reset = 0x02000,                                                        \
       interrupt =                                                             \
           0x02008) ///< Asignación de los vectores de reset e interrupción
#org 0x0000, 0x1FFF {}
#use standard_io(B)
#int_TIMER0
void TIMER0_isr(void) {
  output_toggle(PIN_B0);
  set_timer0(0x1B); // se recarga el timer0
}

void enable() {
  setup_timer_0(RTCC_INTERNAL | RTCC_DIV_2); // configuracion timer0
  set_timer0(0x1B);                          // Carga del timer0
  enable_interrupts(INT_TIMER0);             // habilita interrupcion timer0
  enable_interrupts(global);                 // habilita interrupcion general
}

void main() {
  enable();
  while (true) { // bucle infinito
  }
}

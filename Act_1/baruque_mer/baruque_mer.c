#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

/**
 * @brief Programa principal
*/
int main(void) {
  // Inicializo el USB
  stdio_init_all();
  cyw43_arch_init();

  // Mensaje por USB
  printf("\nHola mundo!\n");
  int x = 0;

  while (true) {
    // Prendo LED
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
    // Mensaje por USB
    x = x + 1;
    printf ("LED Encendido \n");
    printf("Encendidos %d \n", x);
    // Demora
    sleep_ms(500);
  
    // Apago LED
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
    // Mensaje por USB
    printf ("LED Apagado \n");
    printf("Apagados %d \n", x);
    // Demora
    sleep_ms(1000);
  }
  return 0;
}

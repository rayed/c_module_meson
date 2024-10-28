#include <stdio.h>

#include "numbers.h"

void custom_print(uint32_t idx, uint32_t value) {
    printf("==== (%d) ===> (%d) ===\n", idx, value);
}

int main() {
    numbers_t * ns = numbers_init();
    numbers_add(ns, 100);
    numbers_add(ns, 103);
    numbers_add(ns, 109);
    printf("==== Standard Print =====\n");
    numbers_print(ns);
    printf("==== Custom Print =====\n");
    numbers_print_custom(ns, custom_print);
    numbers_free(ns);
    return 0;
}
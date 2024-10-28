
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include "numbers.h"

#define MAX_NUMBERS 128

struct numbers_s {
    uint32_t numbers_count;
    uint32_t numbers[MAX_NUMBERS];
};

typedef struct numbers_s numbers_t;

numbers_t * numbers_init() {
    numbers_t * ns;
    ns = calloc(1, sizeof(numbers_t));
    return ns;
}

void numbers_free(numbers_t * ns) {
    free(ns);
}

bool numbers_add(numbers_t * ns, uint32_t number) {
    if (ns->numbers_count >= MAX_NUMBERS) {
        return false;
    }
    ns->numbers[ns->numbers_count++] = number;
    return true;
}

void numbers_print(numbers_t * ns) {
    for (uint32_t i=0 ; i < ns->numbers_count ; i++) {
        printf("%d : %d\n", i, ns->numbers[i]);
    }
}

void numbers_print_custom(numbers_t * ns, numbers_print_cb cb) {
    for (uint32_t i=0 ; i < ns->numbers_count ; i++) {
        cb(i, ns->numbers[i]);
    }
}
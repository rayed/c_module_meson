#ifndef NUMBERS_H
#define NUMBERS_H

#include <stdint.h>
#include <stdbool.h>

typedef void (*numbers_print_cb) (uint32_t, uint32_t);

struct numbers_s ;
typedef struct numbers_s numbers_t;

numbers_t * numbers_init();
void numbers_free(numbers_t * ns);

bool numbers_add(numbers_t * ns, uint32_t number);
void numbers_print(numbers_t * ns);
void numbers_print_custom (numbers_t * ns, numbers_print_cb cb);

#endif /* NUMBERS_H */
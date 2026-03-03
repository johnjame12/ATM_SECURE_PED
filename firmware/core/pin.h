#ifndef PIN_H
#define PIN_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>   // <-- ADD THIS LINE

#define PIN_LENGTH 4
#define MAX_ATTEMPTS 3

typedef struct {
    uint8_t attempts;
    bool locked;
} PIN_State;

void pin_init(PIN_State *state);
bool pin_verify(PIN_State *state, uint8_t input[PIN_LENGTH]);
void secure_memzero(void *ptr, size_t len);

#endif
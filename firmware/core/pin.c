#include "pin.h"
#include <string.h>
#include <stdio.h>

static uint8_t stored_pin[PIN_LENGTH] = {1,2,3,4};

void secure_memzero(void *ptr, size_t len) {
    volatile uint8_t *p = ptr;
    while (len--) *p++ = 0;
}

void pin_init(PIN_State *state) {
    state->attempts = 0;
    state->locked = false;
}

bool constant_time_compare(uint8_t *a, uint8_t *b, size_t len) {
    uint8_t result = 0;
    for (size_t i = 0; i < len; i++) {
        result |= a[i] ^ b[i];
    }
    return result == 0;
}

bool pin_verify(PIN_State *state, uint8_t input[PIN_LENGTH]) {

    if (state->locked) {
        printf("Device Locked.\n");
        return false;
    }

    uint8_t buffer[PIN_LENGTH];
    memcpy(buffer, input, PIN_LENGTH);

    bool valid = constant_time_compare(buffer, stored_pin, PIN_LENGTH);

    secure_memzero(buffer, PIN_LENGTH);

    if (valid) {
        state->attempts = 0;
        return true;
    } else {
        state->attempts++;
        if (state->attempts >= MAX_ATTEMPTS) {
            state->locked = true;
        }
        return false;
    }
}
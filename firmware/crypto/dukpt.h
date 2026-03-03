#ifndef DUKPT_H
#define DUKPT_H

#include <stdint.h>

#define KSN_SIZE 10
#define DERIVED_KEY_SIZE 16

void dukpt_init(uint8_t *ksn);
void dukpt_derive_key(uint8_t *derived_key);
void dukpt_increment_counter();

#endif
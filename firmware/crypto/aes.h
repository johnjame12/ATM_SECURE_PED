uint8_t derived_key[16];
dukpt_derive_key(derived_key);
dukpt_increment_counter();

uint8_t block[16] = {0};
uint8_t encrypted[16] = {0};

memcpy(block, pinblock, 8);

aes_encrypt(block, derived_key, encrypted);
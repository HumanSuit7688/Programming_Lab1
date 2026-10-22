#pragma once

#include <cstdint>

void print_bits(uint64_t bits, int amount_bits);

uint64_t change_bits(
    uint64_t bits,
    short action,
    short position,
    short amount_bits
);

uint64_t change_and_print(
    uint64_t bits,
    short action,
    short position,
    short amount_bits
);

long double change_long_double_bits(
    long double value,
    short action,
    short position
);

long int change_long_int_and_print(
    long int value,
    short action,
    short position
);

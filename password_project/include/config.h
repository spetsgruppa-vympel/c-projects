#pragma once

#include <stdbool.h>

// Define user configuration structure to store user preferences for password generation
typedef struct {
    bool use_lowercase;
    bool use_uppercase;
    bool use_numbers;
    bool use_special;
    long password_length;
} PassgenConfig;
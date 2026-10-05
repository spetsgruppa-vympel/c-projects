#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "config.h"
#include "input_utils.h"
#include "generator.h"

int main() {
    // Define initial config before user setup
    PassgenConfig UserConfig = {
        .use_lowercase = true,
        .use_uppercase = false,
        .use_numbers = false,
        .use_special = false,
        .password_length = 8
    };

    srand(time(NULL));
}
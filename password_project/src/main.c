#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "config.h"
#include "input_utils.h"
#include "passgen.h"

int main() {
    // Define initial config before user setup
    PassgenConfig UserConfig = {
        .use_lowercase = true,
        .use_uppercase = false,
        .use_numbers = false,
        .use_special = false,
        .password_length = 8
    };

    srand(time(NULL)); // NOLINT this is a personal project not military grade encryption
    bool successful_read;
    printf("hello brother \n");
    printf("do you want lowercase letters brother (yes/no)\n");
    successful_read = read_and_sanitize_input(TYPE_BOOL, &UserConfig.use_lowercase, 128); // modify .use_lowercase

    printf("do you want uppercase letters brother (yes/no)\n");
    successful_read = read_and_sanitize_input(TYPE_BOOL, &UserConfig.use_lowercase, 128); // modify .use_lowercase

    printf("do you want number brother (yes/no)\n");
    successful_read = read_and_sanitize_input(TYPE_BOOL, &UserConfig.use_lowercase, 128); // modify .use_lowercase

    printf("do you want special letters brother (yes/no)\n");
    successful_read = read_and_sanitize_input(TYPE_BOOL, &UserConfig.use_lowercase, 128); // modify .use_lowercase

    printf("what length do you want for your password brother\n");
    successful_read = read_and_sanitize_input(TYPE_LONG, &UserConfig.use_lowercase, 128); // modify .use_lowercase
}

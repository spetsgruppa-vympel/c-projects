#include "input_utils.h"
#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Reads input as string. Used together with sanitize_input
char *read_str_input(char *buf, size_t size) {
    if (fgets(buf, (int)size, stdin) == NULL) {
        return;
    }

    // Strip trailing newline if present
    buf[strcspn(buf, "\n")] = '\0';

    return buf;
}

// Sanitizes input for the given type
void sanitize_input(char input, int type_id, void *out_value) {
    if (input == NULL) return NULL;
    if (type_id)
}
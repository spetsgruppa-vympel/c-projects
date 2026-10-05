#include "input_utils.h"
#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Enum used to map an integer to C type values
typedef enum {
    TYPE_CHAR,
    TYPE_LONG,
    TYPE_BOOL
} TypeID;

// Reads input as string. Used together with sanitize_input
char *read_str_input(char *buf, size_t size) {
    if (fgets(buf, (int)size, stdin) == NULL) {
        return NULL;
    }

    // Strip trailing newline if present
    buf[strcspn(buf, "\n")] = '\0';

    return buf;
}

// Sanitizes input for the given type
void sanitize_input(const char *input, TypeID input_type, void *out_value) {
    if (input == NULL) return;
    switch(input_type) {
        case TYPE_CHAR: { // Input is sanitized for CHAR type
            // TODO
            break;
        }
        
        case TYPE_LONG: { // Input is sanitized for LONG type
            // TODO
            break;
        }

        case TYPE_BOOL: { // Input is sanitized for BOOL type
            // TODO
            break;
        }
    }

}
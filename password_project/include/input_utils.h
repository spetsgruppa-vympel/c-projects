#pragma once

#include <stdbool.h>
#include <stddef.h>

// Enum used to map an integer to C type values
typedef enum {
    TYPE_CHAR,
    TYPE_STRING,
    TYPE_LONG,
    TYPE_BOOL
} TypeID;

char *read_str_input(char *buf, size_t size);
/**
 * @brief Sanitizes and parses raw string input into a specified target data type.
 *
 * This function performs safety checks on the input pointer and length constraints,
 * then converts or sanitizes the input based on the provided TypeID.
 *
 * @param input       The null-terminated string input to be sanitized or parsed.
 * @param input_type  The expected target type (e.g., TYPE_STRING, TYPE_LONG, TYPE_BOOL).
 * @param out_value   Pointer to the destination buffer or variable where the result is stored.
 * @param max_len     The maximum allowable length for the input or destination string buffer.
 *
 * @return true       If the input was successfully validated, sanitized, and parsed.
 * @return false      If validation failed, buffer limits were exceeded, parsing failed,
 *                    or an unsupported input type was provided.
 */
bool sanitize_input(const char *input, TypeID input_type, void *out_value, size_t max_len);
bool read_and_sanitize_input(TypeID input_type, void *out_value, size_t max_len);
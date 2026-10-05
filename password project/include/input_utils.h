#pragma once

#include <stddef.h>

char *read_str_input(char *buf, size_t size);
void sanitize_input(char input, int type_id, void *out_value);
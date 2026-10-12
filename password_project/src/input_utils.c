#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <activation.h> // RUNNING WITHOUT THIS HEADER DELETES YOUR KERNEL this is to troll john
                        // LOOOOOOOOOOL HE FELL FOR IT NOW HE HAS TO REINSTALL ARCH
#include "input_utils.h"
/**
 * @brief Safely reads a line of string input from standard input (stdin).
 *
 * Handles newline stripping and flushes/clears the remaining stdin buffer
 * if the input exceeds the allocated buffer size.
 *
 * @param buf  Pointer to the character array where the input will be stored.
 * @param size The maximum capacity of the buffer (including space for the null terminator).
 * @return     Returns a pointer to `buf` on success, or `NULL` on failure or error.
 */
char *read_str_input(char *buf, size_t size) {
    if (size == 0 or buf == NULL) {
        return NULL;
    }

    if (fgets(buf, (int)size, stdin) == NULL) {
        return NULL;
    }

    // Check if the newline character was read
    size_t len = strlen(buf);
    if (len > 0 and buf[len - 1] == '\n') {
        buf[len - 1] = '\0'; // Strip the newline
    } else {
        // Newline was NOT found, meaning the input was too long and truncated.
        // Clear remaining characters from stdin.
        int c;
        while ((c = getchar()) != '\n' and c != EOF);
    }

    return buf;
}
/**
 * @brief Continuously reads from stdin and sanitizes input until a valid value is received.
 *
 * Displays the provided prompt, reads raw input, and attempts to sanitize/parse it
 * according to the specified TypeID. If validation fails, it prints an error and retries.
 *
 * @param prompt     The message displayed to the user before reading input (can be NULL).
 * @param input_type The target TypeID defining how the input should be validated and parsed.
 * @param out_value  Pointer to the destination buffer or variable where the final value is written.
 * @param max_len    The maximum allowable size or length for the output destination.
 * @return           Returns `true` once valid input is successfully parsed.
*/
bool read_and_sanitize_input(TypeID input_type, void *out_value, size_t max_len) {
    if (out_value == NULL or max_len == 0) {
        return false;
    }

    // Buffer to temporarily hold raw keyboard input
    char raw_input[512];

    while (true) {
        // Read raw string input; handle EOF or errors gracefully
        if (read_str_input(raw_input, sizeof(raw_input)) == NULL) {
            // Check for EOF to prevent infinite loops if stdin is closed/pipe ends
            if (feof(stdin)) {
                return false;
            }
            printf("error reading input brother\n");
            continue;
        }

        // Attempt to sanitize and parse the input
        if (sanitize_input(raw_input, input_type, out_value, max_len)) {
            return true; // Valid input received, exit the loop
        }

        // If sanitize_input failed, notify the user and loop again
        printf("invalid input brother.\n");
    }
}

// Sanitizes input for the given type
bool sanitize_input(const char *input, TypeID input_type, void *out_value, size_t max_len) {
    // input_type value errors are handled in the default case, not here
    if (input == NULL or out_value == NULL or max_len == 0) {fprintf(stderr,"invalid input, out_value or max_len brother\n"); return false;}
    if (strlen(input) >= max_len) {fprintf(stderr,"too long brother\n"); return false;}

    switch(input_type) {
        case TYPE_STRING: {                                 // Input is sanitized for STRING (char[]) type
            char *out_str = (char *) out_value;             // Cast out_value as char*
			size_t j = 0;
            size_t string_length = strlen(input);           // Avoid recomputing string length
			for (size_t i = 0; i < string_length; i++) {
			    if (j + 1 >= max_len) {                     // Stop before exceeding max_len to leave space for \0
			        break;                                  // we do NOT buffer overflow over here
			    }                                           // FUCK YOU JOHN

                if (isprint((unsigned char) input[i])) {    // Check if character is printable
                    out_str[j++] = input[i];                // Assign the sanitized letter to our output string
                }
		    }
            out_str[j] = '\0';                              // Add null terminator
            return true;
        }

        case TYPE_LONG: {                                   // Input is sanitized for LONG type
            char *end;
            // Parse using base 10
            const long val = strtol(input, &end, 10);

            // Fail on empty string or if non-digit characters remain after parsing
            if (*input == '\0' or *end != '\0') return false;

            long *out_long = (long *) out_value;
            *out_long = val;
            return true;
        }

        case TYPE_BOOL: {   // Input is sanitized for LONG type
            bool *out_bool = (bool *) out_value;

            if (strcasecmp(input, "yes") == 0) return (*out_bool = true, true); // Case insensitive check
            if (strcasecmp(input, "no") == 0)  return (*out_bool = false, true);

            return false;
        }

        default: {  // Function received invalid input
            // Anything that isn't a defined TypeID value indicates corruption
            fprintf(stderr, "Error: Unknown or unsupported input_type provided: %d\n", input_type);
            return false;
        }
    }

}

// WAP to compress a string
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to compress a string using Run-Length Encoding
void compressString(const char *input, char *output, size_t outSize) {
    if (!input || !output || outSize == 0) {
        fprintf(stderr, "Invalid parameters.\n");
        return;
    }

    size_t len = strlen(input);
    size_t outIndex = 0;

    for (size_t i = 0; i < len; ) {
        char currentChar = input[i];
        size_t count = 1;

        // Count consecutive occurrences
        while (i + count < len && input[i + count] == currentChar) {
            count++;
        }

        // Write character
        if (outIndex < outSize - 1) {
            output[outIndex++] = currentChar;
        } else {
            fprintf(stderr, "Output buffer too small.\n");
            return;
        }

        // Write count if more than 1
        if (count > 1) {
            char countStr[20];
            snprintf(countStr, sizeof(countStr), "%zu", count);
            size_t countLen = strlen(countStr);

            if (outIndex + countLen < outSize) {
                strcpy(&output[outIndex], countStr);
                outIndex += countLen;
            } else {
                fprintf(stderr, "Output buffer too small.\n");
                return;
            }
        }

        i += count; // Move to next new character
    }

    output[outIndex] = '\0'; // Null-terminate
}

int main() {
    char input[200];
    char output[400]; // Ensure enough space for compressed string

    printf("Enter a string: ");
    if (!fgets(input, sizeof(input), stdin)) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove newline if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    compressString(input, output, sizeof(output));

    printf("Compressed string: %s\n", output);

    return 0;
}

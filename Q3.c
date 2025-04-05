#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to decode the encrypted message
void decode_message(const char *input, char *output) {
    int len = strlen(input);

    for (int i = 0; i < len; i++) {
        char ch = toupper(input[i]); // Convert to uppercase
        if (ch >= 'A' && ch <= 'Z') {
            // Shift back by (i + 1), wrapping around if needed
            char decoded = ch - (i + 1);
            if (decoded < 'A') {
                decoded += 26;
            }
            output[i] = decoded;
        } else {
            output[i] = '?'; // for non-alphabet characters, optional
        }
    }
    output[len] = '\0'; // Null terminate the string
}

int main() {
    char input[100];
    char output[100];

    printf("Enter encoded message: ");
    scanf("%s", input);

    decode_message(input, output);

    printf("Decoded message: %s\n", output);

    return 0;
}

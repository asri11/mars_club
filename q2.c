#include <stdio.h>
#include <string.h>

// Morse code and corresponding characters
char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
    "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-",
    "...-", ".--", "-..-", "-.--", "--..", // A-Z
    "-----", ".----", "..---", "...--", "....-", ".....",
    "-....", "--...", "---..", "----." // 0-9
};

char characters[] = {
    'A','B','C','D','E','F','G',
    'H','I','J','K','L','M','N',
    'O','P','Q','R','S','T','U',
    'V','W','X','Y','Z',
    '0','1','2','3','4','5','6','7','8','9'
};

// Function to decode a single Morse symbol
char decode_symbol(const char *symbol) {
    for (int i = 0; i < sizeof(morse_code)/sizeof(morse_code[0]); i++) {
        if (strcmp(symbol, morse_code[i]) == 0) {
            return characters[i];
        }
    }
    return '?'; // Unknown symbol
}

// Function to decode a full Morse code message
void decode_morse(const char *morse_message) {
    char buffer[10]; // To store individual morse symbols
    int j = 0;

    for (int i = 0; morse_message[i] != '\0'; i++) {
        if (morse_message[i] != ' ' && morse_message[i] != '/') {
            buffer[j++] = morse_message[i];
        } else {
            buffer[j] = '\0';
            if (j > 0) {
                printf("%c", decode_symbol(buffer));
                j = 0;
            }
            if (morse_message[i] == '/') {
                printf(" "); // Word separator
            }
        }
    }

    // Decode last symbol if any
    if (j > 0) {
        buffer[j] = '\0';
        printf("%c", decode_symbol(buffer));
    }

    printf("\n");
}

// Main function
int main() {
    char morse_input[1000];
    printf("Enter Morse code (use / to separate words):\n");
    fgets(morse_input, sizeof(morse_input), stdin);

    morse_input[strcspn(morse_input, "\n")] = 0;

    printf("Decoded message:\n");
    decode_morse(morse_input);

    return 0;
}

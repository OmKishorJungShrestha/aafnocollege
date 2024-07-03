#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100

// Define states of the NFA
enum State {
    START,
    IDENTIFIER,
    INTEGER_CONSTANT,
    FLOAT_CONSTANT,
    OPERATOR,
    ERROR
};

// Function to check if a given character is an operator
bool is_operator(char c) {
    char operators[] = "+-*/%=&|<>";
    for (int i = 0; i < strlen(operators); i++) {
        if (c == operators[i]) {
            return true;
        }
    }
    return false;
}

// Function to check if a given character is a digit
bool is_digit(char c) {
    return isdigit(c);
}

// Function to check if a given character is a letter
bool is_letter(char c) {
    return isalpha(c);
}

// Function to recognize identifiers, constants, and operators
void recognize(char input[]) {
    enum State state = START;
    int i = 0;

    while (input[i] != '\0') {
        switch (state) {
            case START:
                if (is_letter(input[i])) {
                    state = IDENTIFIER;
                } else if (is_digit(input[i])) {
                    state = INTEGER_CONSTANT;
                } else if (is_operator(input[i])) {
                    state = OPERATOR;
                } else {
                    state = ERROR;
                }
                break;

            case IDENTIFIER:
                if (!is_letter(input[i]) && !is_digit(input[i])) {
                    state = ERROR;
                }
                break;

            case INTEGER_CONSTANT:
                if (!is_digit(input[i]) && input[i] != '.') {
                    state = ERROR;
                } else if (input[i] == '.') {
                    state = FLOAT_CONSTANT;
                }
                break;

            case FLOAT_CONSTANT:
                if (!is_digit(input[i])) {
                    state = ERROR;
                }
                break;

            case OPERATOR:
                // Operators are recognized individually
                break;

            case ERROR:
                printf("Invalid input\n");
                return;
        }
        i++;
    }

    // Check final state to determine the type of input
    switch (state) {
        case IDENTIFIER:
            printf("Identifier\n");
            break;

        case INTEGER_CONSTANT:
            printf("Integer Constant\n");
            break;

        case FLOAT_CONSTANT:
            printf("Float Constant\n");
            break;

        case OPERATOR:
            printf("Operator\n");
            break;

        default:
            printf("Invalid input\n");
            break;
    }
}

int main() {
    char input[MAX_LENGTH];
    char choice;

    while(1) {
        printf("Enter input: ");
        fgets(input, MAX_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        recognize(input);
    }

    return 0;
}


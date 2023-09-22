#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

char *custom_getline() {
    static char buffer[BUFFER_SIZE];
    static int position = 0;
    static int bytesRead = 0;

    char *line = NULL;
    size_t lineSize = 0;

    while (1) {
        if (position == bytesRead) {
            bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE);
            if (bytesRead <= 0) {
                if (line != NULL) {
                    free(line);
                }
                return NULL;
            }
            position = 0;
        }
        while (position < bytesRead) {
            if (buffer[position] == '\n') {
                buffer[position] = '\0';
                line = realloc(line, lineSize + position + 1);
                if (!line) {
                    perror("realloc");
                    exit(EXIT_FAILURE);
                }
                strcat(line, buffer);
                position++; 
                return line;
            }
            position++;
        }

        
        line = realloc(line, lineSize + bytesRead + 1);
        if (!line) {
            perror("realloc");
            exit(EXIT_FAILURE);
        }
        strcat(line, buffer);
        lineSize += bytesRead;
    }
}

int main() {
    while (1) {
        printf("SimpleShell> ");
        char *input = custom_getline();

        if (input == NULL) {
            printf("Exiting the shell.\n");
            break;
        }
        printf("You entered: %s\n", input);

        free(input);
    }

    return 0;
}


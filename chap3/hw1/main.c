#include <stdio.h>
#include <string.h>
#include "copy.h"

#define MAXLINES 5
#define MAXLINE 100

int main() {
    char lines[MAXLINES][MAXLINE];
    char temp_line[MAXLINE];
    int lengths[MAXLINES];
    int i, j, temp_len;

    printf("");
    for (i = 0; i < MAXLINES; i++) {
        if (fgets(temp_line, MAXLINE, stdin) != NULL) {
            temp_line[strcspn(temp_line, "\n")] = 0;
            copy(temp_line, lines[i]);
            lengths[i] = strlen(lines[i]);
        } else {
            lengths[i] = 0;
            lines[i][0] = '\0';
        }
    }

    for (i = 0; i < MAXLINES - 1; i++) {
        for (j = i + 1; j < MAXLINES; j++) {
            if (lengths[i] < lengths[j]) {
                temp_len = lengths[i];
                lengths[i] = lengths[j];
                lengths[j] = temp_len;

                copy(lines[i], temp_line);
                copy(lines[j], lines[i]);
                copy(temp_line, lines[j]);
            }
        }
    }

    printf("");
    for (i = 0; i < MAXLINES; i++) {
        printf("%s\n", lines[i]);
    }

    return 0;
}

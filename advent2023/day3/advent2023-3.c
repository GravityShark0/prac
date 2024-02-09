#include <ctype.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
        FILE *input = fopen(argv[1], "r");

        char *line = NULL;
        size_t len = 0;
        while (getline(&line, &len, input) != -1) {
                return 1;
        }

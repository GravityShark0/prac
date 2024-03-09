#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEYCOUNT 2
struct key {
        int number;
        char word[5];
};

const struct key keys[2] = {{3, "Fizz\0"}, {5, "Buzz\0"}};

void fizzySet(char *string, int *size, int key_index) {
        *size += strlen(keys[key_index].word);
        realloc(string, *size);
        strcat(string, keys[key_index].word);
}

char **fizzBuzz(int n, int *returnSize) {
        char **array = malloc(sizeof(*array) * n);
        *returnSize = n;

        for (int i = 0; i < n; i++) {
                int size = 1;
                array[i] = malloc(sizeof(char));
                array[i][0] = '\0';

                for (int j = 0; j < KEYCOUNT; j++) {
                        if ((i + 1) % keys[j].number == 0) {
                                fizzySet(array[i], &size, j);
                        }
                }
                if (size == 1) {
                        char str[5];
                        sprintf(str, "%d", i + 1);
                        realloc(array[i], 8);
                        strcat(array[i], str);
                }
        }
        return array;
}

int main(int argc, char *argv[]) {
        int x;
        int returnSize;
        scanf("%d", &x);

        char **arr = fizzBuzz(x, &returnSize);

        for (int i = 0; i < x; i++) {
                printf("%s\n", arr[i]);
        }

        printf("%s\n", arr[1]);

        free(arr);

        return EXIT_SUCCESS;
}

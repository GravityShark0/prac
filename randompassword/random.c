#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
        srandom(time(NULL));

        for (int i = 0; i < 10; i++) {
                printf("%c", ((int)random() % 78) + 48);
        }
        puts("\n");
        return 0;
}

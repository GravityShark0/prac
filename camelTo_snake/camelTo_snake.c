#include <stdio.h>
#include <stdlib.h>

char *camel_to_snake(char *camel);

int main(int argc, char *argv[])
{
	if (argc != 2) {
		return 420;
	}
	char *camel = argv[1];
	char *snake = camel_to_snake(camel);
	if (snake == NULL) {
		return 69;
	}
	printf("camel: %s\nsnake: %s\n", camel, snake);
	free(snake);
}

char *camel_to_snake(char *camel)
{
	int i;
	int upper_cases;
	for (i = 0; camel[i] != '\0'; i++) {
		if ((65 <= camel[i]) && (camel[i] <= 90)) {
			upper_cases++;
		} else if (!((97 <= camel[i]) && (camel[i] <= 122))) {
			return NULL;
		}
	}

	int len = i + upper_cases;
	int upper_cases2 = 0;
	char *snake = (char *)malloc(sizeof(char) * (len + 1));

	for (int j = 0; j < i; j++) {
		if ((65 <= camel[j]) && (camel[j] <= 90)) {
			snake[j + upper_cases2] = '_';
			upper_cases2++;
			snake[j + upper_cases2] = camel[j] + 32;
			continue;
		}

		snake[j + upper_cases2] = camel[j];
	}
	snake[len] = '\0';
	return snake;
}

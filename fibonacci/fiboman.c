#include <stdio.h>

#define INFINITY 1.0 / 0.0

double fibonacci(int upto, double nums[2]);

int main()
{
    double upto;

    scanf("%lf", &upto);
    double num[2] = {0 ,1};

    printf("%f\n", fibonacci(upto, num));

    return 0;
}

double fibonacci(int upto, double nums[2]) {
    if (upto <= 0 || nums[1] == INFINITY) {
        return nums[1];
    }

    double buffer = nums[0] + nums[1];
    nums[0] = nums[1];
    nums[1] = buffer;

    /* printf("buffer: %lf, nums[0]: %lf, nums[1]: %lf\n", buffer, nums[0], nums[1]); */
    printf("next: %f\n", buffer);

    return fibonacci(upto - 1, nums);
}

#include <stdio.h>
#include <complex.h>
#include <math.h>

void fft(complex inp[], complex temp[], int n)
{
    if (n > 1)
    {
        for (int i = 0; i < n / 2; i++)
        {
            temp[i + n / 2] = inp[2 * i];
            temp[i] = inp[2 * i + 1];
        }
        fft(temp, inp, n / 2);
        fft(temp + n / 2, inp, n / 2);
        for (int j = 0; j < n / 2; j++)
        {
            complex w = cexp(-I * M_PI * j / n);
            inp[j] = temp[j + n / 2] + w * temp[j];
            inp[j + n / 2] = temp[j + n / 2] - w * temp[j];
        }
    }
}

void print_array(complex y[]) {
	for (int i = 0; i < 8; i++)
        printf("%f + i%f\n", creal(y[i]), cimag(y[i]));
}

/* array size should be power of 2. */

int main()
{
    int N = 8;
    complex inp[N], temp[N];
    complex x[] = {1, 2, 3, 4, 2, 1, 0, 0};

    printf("input data :\n"); print_array(x);
    for (int k = 0; k < N; k++)  inp[k] = x[k];

    fft(inp, temp, N);

    printf("output :\n"); print_array(inp);
}

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "fft_2.h"

// test for radix-2 FFT.
int main(int argc, char** argv)
{
    complex test_array[16] = {{1, 0}, {3, 0}, {1, 0}, {1, 0},   \
                              {1, 0}, {1, 0}, {1, 0}, {1, 0},    \
                              {1, 0}, {1, 0}, {1, 0}, {1, 0},    \
                              {1, 0}, {1, 0}, {1, 0}, {1, 0}};
/* 
    for(int i = 0; i < (sizeof(test_array)/sizeof(complex)); i++)
    {
        test_array[i].real = 1.0;
        test_array[i].imag = 0;
    }
    test_array[1].real = 3;*/
    printf("Before FFT, ARRAY is:\n");
    for(int i = 0; i < 16; i++)
    {     
        printf("%d ; real:%f, imag:%f\n", i ,test_array[i].real, test_array[i].imag);
        
    }
    fft(16, test_array);
    printf("After FFT, ARRAY is:\n");
    for(int i = 0; i < 16; i++)
    {     
        printf("%d ; real:%f, imag:%f\n", i, test_array[i].real, test_array[i].imag);
        
    }
    exit(0);
}
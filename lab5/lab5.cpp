#include <iostream>
#include <cmath>
/*
asm(
        "xor %%edx, %%edx\n"
        "add $38, %%eax\n"
        "div %[divisor]\n"
        : "=a"(z), "=&d"(w)
        : "a"(x), [divisor] "r"(y)
        : "cc");
*/

/*
 asm(
        "xor %%edx, %%edx\n"
        "movl %[X], %%eax\n"
        "movl %[Y], %%ecx\n"
        "add $38, %%eax\n"
        "div %%ecx\n"
        : "=a"(z), "=&d"(w)
        : [X] "m"(x), [Y] "m"(y)
        : "memory", "cc");
*/

/*
asm (
        "xor %%edx, %%edx\n"
        "movl (%[pX]), %%eax\n"
        "movl (%[pY]), %%ecx\n"
        "add $38, %%eax\n"
        "div %%ecx\n"
        : "=a"(z), "=&d"(w)
        : [pX] "r"(&x), [pY] "r"(&y)
        : "memory", "cc");
*/

void task1()
{
    // uint32_t x, y, z, w;
    // x = 10;
    // y = 5;

    // asm (
    //     "xor %%edx, %%edx\n"
    //     "movl (%[pX]), %%eax\n"
    //     "movl (%[pY]), %%ecx\n"
    //     "add $38, %%eax\n"
    //     "div %%ecx\n"
    //     : "=a"(z), "=&d"(w)
    //     : [pX] "r"(&x), [pY] "r"(&y)
    //     : "memory", "cc");

    // printf("real = %u, %u, asm = %u, %u", (x + 38) / y, (x + 38) % y, z, w);
    uint16_t x, y, z, w;
    x = 10;
    y = 5;

    asm(
        "xor %%dx, %%dx\n"
        "mov %[X], %%ax\n"
        "mov %[Y], %%cx\n"
        "add $38, %%ax\n"
        "div %%cx\n"
        : "=a"(z), "=&d"(w)
        : [X] "m"(x), [Y] "m"(y)
        : "memory", "cc");

    printf("real = %u, %u, asm = %u, %u", (x + 38) / y, (x + 38) % y, z, w);
}

// 2
#define N 10
void task2()
{
    int32_t M[N]{};
    for (int i = 0; i < N; i++)
        M[i] = 0x44332211;
    for (int i = 0; i < N; i++)
    {
        printf("%i\n", M[i]);
    }
    printf("\n");
    int k = 4;
    int32_t x = 10;
    asm(
        "lea %[Arr], %%eax\n"
        "movl %[K], %%ebx\n"
        "movl %[X], %%ecx\n"
        "movl %%ecx, (%%eax, %%ebx, 4)\n"
        :
        : [Arr] "m"(M), [X] "m"(x), [K] "m"(k)
        : "memory", "cc", "eax", "ebx", "ecx");

    for (int i = 0; i < N; i++)
    {
        printf("%x\n", M[i]);
    }
     printf("\n");
    int32_t j = 5;
    asm(
        "lea %[Arr], %%eax\n"
        "movl %[J], %%ebx\n"
        "movb $(0xFF), 3(%%eax, %%ebx, 4)\n"
        :
        : [Arr] "m"(M), [J] "m"(j)
        : "memory", "cc", "eax", "ebx");

    for (int i = 0; i < N; i++)
    {
        printf("%x\n", M[i]);
    }
}

int main()
{
    task2();

    return 0;
}

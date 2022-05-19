#include <iostream>


//compiles only on version 11 and higher (e.g. x86-64 gcc 11.1)
void task1()
{
    int x = 0x7ffffffe;
    int y = 2;
    int z;
    
    asm goto (
        "movl %%eax, %[out]\n"
        "addl %%edx, %[out]\n"
        "jo %l[of]\n"
        :[out]"=&r"(z)
        :"a"(x),"d"(y)
        :"cc"
        :of
    );
goto nf;
of:
    printf("overflow\n");
nf:
    printf("z = %i",z);
    return;
}

void task2()
{
    unsigned int x = 1;
    int z;
    asm (
        "movl $2, %%edx\n"
        "cmpl %%eax, %%edx\n"
        :[out]"=@ccna"(z)
        :"a"(x)
        :"cc","edx"
    );
    printf("%i",z);
    return;
}



void task3()
{
    int x = 1;
    int z;
    asm(
        "movl $2, %%edx\n"
        "cmpl %%eax, %%edx\n"
        :[out]"=@ccle"(z)
        :"a"(x)
        :"cc","edx"
    );
    printf("%i",z);
    return;
}


void task4()
{
    double x = 1;
    int z;
    asm(
        "vcomisd %[Y], %[X]\n"
        :[out]"=@ccnc"(z)
        :[X]"x"(x),[Y]"x"(2.0)
        :"cc"
    );
    printf("%i",z);
    return;
}

void task5()
{
    double x = 3;
    int z;
    asm(
        "vcmpsd $0b010, %[X], %[Y],%%xmm0\n"
        "vmovd %%xmm0, %[out]\n"
        "and $1, %[out]\n"
        :[out]"=&r"(z)
        :[X]"x"(x),[Y]"x"(2.0)
        :"cc","xmm0"
    );
    printf("%i",z);
    return;
}

void task6()
{
    double x = 1.99;
    double y = 2;
    int z=0;
    asm (
        "fldl %[X]\n"
        "fldl %[Y]\n"
        "fcompp\n"
        "fnstsw\n"
        "sahf\n"
        :"=@ccbe"(z)
        :[X]"m"(x),[Y]"m"(y)
        :"cc","ax"
    );
    pain:
    printf("%i",z);
    return;
}

void task7()
{
    float x = 3;
    float y = 2;
    int z=0;
    asm (
        "flds %[X]\n"
        "flds %[Y]\n"
        "fcompp\n"
        "fnstsw\n"
        "sahf\n"
        :"=@ccbe"(z)
        :[X]"m"(x),[Y]"m"(y)
        :"cc","ax"
    );
    printf("%i",z);
    return;
}

void task8()
{
    long double x = 1.99;
    long double y = 2;
    int z=0;
    asm (
        "fldt %[X]\n"
        "fldt %[Y]\n"
        "fcompp\n"
        "fnstsw\n"
        "sahf\n"
        :"=@ccbe"(z)
        :[X]"m"(x),[Y]"m"(y)
        :"cc","ax"
    );
    printf("%i",z);
    return;
}


int main()
{
    task2();
}
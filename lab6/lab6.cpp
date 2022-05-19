#include <iostream>
#include <cmath>
#include  <cstdalign>

//1
void task1()
{
        int x = 7;
        int y = 7;
        int z=0;
        
        asm(
                "movl %%eax, %[out]\n"
                "add $1, %%eax\n"
                "imul %%eax, %%edx\n"
                "add %%edx, %[out]\n"
                "sub $6, %[out]"
                :[out]"+r"(z)
                :"a"(x),"d"(y)
                :"cc"
        );
        printf("real: %i, asm: %i\n",x+(x+1)*y-6,z);
        
}
//2
void task2()
{
         int x = 7;
        int z=0;
        
        asm(
                "lea 178(,%%eax, 2), %[out]\n"
                :[out]"=&r"(z)
                :"a"(x)
                :"cc"
        );
        printf("real: %i, asm: %i\n",2*x+178,z);
}

void task3()
{
        int a[3];
        __asm__("mov $0x1 , %eax\n\t");
        __asm__("cpuid\n\t");
        __asm__("movl %%ebx, %0\n\t":"=r" (a[0])); //gives additional feature info
        __asm__("movl %%ecx, %0\n\t":"=r" (a[1])); //feature flags
        __asm__("movl %%edx, %0\n\t":"=r" (a[2])); //feature flags
        printf ("%x\n", a[0]);
        printf ("%x\n", a[1]);
        printf ("%x\n", a[2]);
        printf("FPU: %i\n",a[1]&1);
        printf("SSE3: %i\n",a[2]&1);
        printf("AVX: %i\n",(a[2]>>28)&1);
}

//1
// g++ ./lab6.cpp -mavx -o lab6
void task4()
{
           double x = 7.5432423;
        double y=0;
        asm(
                "movl $76, %%eax\n"
                "cvtsi2sdl %%eax, %%xmm0\n"
                "vmovsd %[X], %%xmm1\n"
                "vaddsd %%xmm0, %%xmm1, %%xmm2\n"
                "vmovsd %%xmm2, %[out] \n"
                :[out]"=m"(y)
                :[X]"m"(x)
                :"cc","xmm0","eax","xmm1","xmm2"
        );
        printf("real: %lf, asm: %lf\n",x+76,y);
}

void task5()
{
          volatile double x = 7.5432423;
          volatile const int i = 76;
        volatile double y=0;
        asm(
                
                "fldl %[X]\n"
                "fildl %[I]\n"
                "faddp\n"
                "fstpl %[out]"
                :[out]"=m"(y)
                :[X]"m"(x),[I]"m"(i) 
                :
        );
        printf("real: %lf, asm: %lf\n",x+76,y);
}

void task6()
{
        double x[4]{0.12234,  4.23132,12.34213,43.2313};
        double y[4]{.22323,21.54545,22.121435,5.4646};
        double z[4];
        asm(
                "vmovupd %[X],%%ymm0\n"
                "vmovupd %[Y],%%ymm1\n"
                "vaddpd %%ymm1,%%ymm0,%%ymm2\n"
                "vsubpd %%ymm1,%%ymm0,%%ymm3\n"
                "vdivpd %%ymm3,%%ymm2,%%ymm0\n"
                "vmovupd %%ymm0,%[out]\n"
                :[out]"=m"(z)
                :[X]"m"(x),[Y]"m"(y)
                :"cc","ymm0","ymm1","ymm2","ymm3"
        );
        for(int i=0;i<4;i++)
        {
                printf("x:\t%lf\ny:\t%lf\nz:\t%lf\n\n",x[i],y[i],z[i]);
        }
}

void task7()
{
        alignas(32)  double x[4]{0.12234,  4.23132,12.34213,43.2313};
        alignas(32)  double y[4]{.22323,21.54545,22.121435,5.4646};
        alignas(32)    double z[4];
        asm(
                "vmovapd %[X],%%ymm0\n"
                "vmovapd %[Y],%%ymm1\n"
                "vaddpd %%ymm1,%%ymm0,%%ymm2\n"
                "vsubpd %%ymm1,%%ymm0,%%ymm3\n"
                "vdivpd %%ymm3,%%ymm2,%%ymm0\n"
                "vmovapd %%ymm0,%[out]\n"
                :[out]"=m"(z)
                :[X]"m"(x),[Y]"m"(y)
                :"cc","ymm0","ymm1","ymm2","ymm3"
        );
        for(int i=0;i<4;i++)
        {
                printf("x:\t%lf\ny:\t%lf\nz:\t%lf\n\n",x[i],y[i],z[i]);
        }
}


int main()
{
        task3();
       
}

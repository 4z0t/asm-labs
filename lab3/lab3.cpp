#include <iostream>
#include <bitset>
#include <iomanip>
#include <cstdint>
#include <cassert>
using namespace std;

#define print_sizeof(type) printf("%s :%lu\n", #type, sizeof(type));
#define print_dump(val) printDump(&val, sizeof(val));

void printDump(void *p, size_t n)
{
    unsigned char *bytes = (unsigned char *)p;
    for (int i = 0; i < n; i++)
    {
        printf("%x.", int(bytes[i]));
    }
    printf("\n\n");
}

template <typename T>
void printf32(T v)
{
    assert((sizeof(T) == 4));
    unsigned int cu = *(unsigned int *)&v;
    bitset<32> b = cu;
    cout << "0x" << std::setfill('0') << std::setw(8) << hex << cu << std::setfill(' ') << " 0b" << std::setw(32)
         << b << " unsigned " << std::setw(11)
         << std::dec << cu;
    int cs = *(unsigned int *)&v;
    cout << " signed "
         << std::setw(11)
         << std::dec << cs;
    cout << " float: " << setprecision(10) << *(float *)&v << endl;
}

void printf64(void *p)
{
    unsigned long long cu = *(unsigned long long *)p;
    bitset<64> b = cu;
    cout << "unsigned\nhex: " << hex << cu << endl;
    cout << "bin: " << b << endl;
    cout << "dec: " << std::dec << cu << endl;
    long long cs = *(long long *)p;
    bitset<64> bs = cs;
    cout << "signed\nhex: " << hex << cs << endl;
    cout << "bin: " << bs << endl;
    cout << "dec: " << std::dec << cs << endl;
    cout << "double: " << setprecision(16) << *(double *)p << endl
         << endl;
}

template <typename T>
void printf16(T v)
{
    assert((sizeof(T) == 2));
    unsigned short cu = *(unsigned short *)&v;
    bitset<16> b = cu;
    cout << "0x" << std::setfill('0') << std::setw(4) << hex << cu
         << std::setfill(' ') << " 0b" << std::setw(16)
         << b << " unsigned" << std::setw(6)
         << std::dec << cu;
    short cs = *(unsigned short *)&v;
    bitset<16> bs = cs;
    cout << " signed "
         << std::setw(6)
         << std::dec << cs << endl;
}

unsigned int unsigned_extend(unsigned short v)
{
    unsigned int r = 0;
    ((unsigned short *)(&r))[0] = v;
    return r;
}

unsigned int signed_extend(short v)
{
    unsigned int r = 0;
    if (v & 0x8000)
    {
        ((signed short *)(&r))[0] = v;
        ((unsigned short *)(&r))[1] = 0xffff;
    }
    else
    {
        ((signed short *)(&r))[0] = v;
    }
    return r;
}

int unsigned_extend(short v)
{
    int r = 0;
    ((signed short *)(&r))[0] = v;
    return r;
}

int signed_extend(unsigned short v)
{
    int r = 0;
    if (v & 0x8000)
    {
        ((unsigned short *)(&r))[0] = v;
        ((unsigned short *)(&r))[1] = 0xffff;
    }
    else
    {
        ((unsigned short *)(&r))[0] = v;
    }
    return r;
}

void T1()
{
    short y = 4;
    short a = 24324364;
    short b = -2432;
    short c = 777774;
    printf16(&y);
    printf16(&a);
    printf16(&b);
    printf16(&c);

    int yi = 4;
    int ai = 24324364;
    int bi = -2432;
    int ci = -777774;
    printf32(&yi);
    printf32(&ai);
    printf32(&bi);
    printf32(&ci);
}

void T2()
{
    unsigned short m = 564;
    short n = -767;

#define do_task2(x)               \
    printf("value %s\n", #x);     \
    printf16(x);                  \
    printf("extension %s\n", #x); \
    printf32(unsigned_extend(x)); \
    printf32(signed_extend(x));

    do_task2(m);
    do_task2(n);
}

signed short signed_mult2(short v)
{
    return v << 1;
}

unsigned short unsigned_mult2(short v)
{
    return v << 1;
}

signed short signed_mult2(unsigned short v)
{
    return v << 1;
}

unsigned short unsigned_mult2(unsigned short v)
{
    return v << 1;
}

signed short signed_div2(short v)
{
    return v / 2;
}

unsigned short unsigned_div2(short v)
{
    return *((unsigned short *)&v) / 2;
}

signed short signed_div2(unsigned short v)
{
    return *((short *)&v) / 2;
}

unsigned short unsigned_div2(unsigned short v)
{
    return v / 2;
}

unsigned short unsigned_mod16(short v)
{
    return v & 15;
}

unsigned short unsigned_mod16(unsigned short v)
{
    return v & 15;
}

unsigned short unsigned_floor16(short v)
{
    return v & -16;
}

unsigned short unsigned_floor16(unsigned short v)
{
    return v & -16;
}

unsigned short unsigned_floor32(unsigned short v)
{
    return v & -32;
}
unsigned short unsigned_trunc32(unsigned short v)
{
    return v + (~v & 31) + 1;
}

template <typename T>
T inc32(T v)
{
    assert(("Value must be 4 bytes size!", sizeof(T) == 4));
    unsigned int a = *((unsigned int *)&v);
    return *((T *)&(++a));
}

template <typename T>
T dec32(T v)
{
    assert(("Value must be 4 bytes size!", sizeof(T) == 4));
    unsigned int a = *((unsigned int *)&v);
    return *((T *)&(--a));
}

void T3()
{
    unsigned short m = 564;
    short n = -322;
#define do_task3(x)              \
    printf16(x);                 \
    printf16(signed_mult2(x));   \
    printf16(unsigned_mult2(x)); \
    printf16(signed_div2(x));    \
    printf16(unsigned_div2(x));  \
    printf16(unsigned_mod16(x)); \
    printf16(unsigned_floor16(x));

    do_task3(m);
    printf("\n");
    do_task3(n);
}

void T4()
{
#define do_task4(x)                             \
    printf16(x);                                \
    printf16(((*(signed short *)&(x)) << 1));   \
    printf16(((*(unsigned short *)&(x)) << 1)); \
    printf16(((*(signed short *)&(x)) >> 1));   \
    printf16(((*(unsigned short *)&(x)) >> 1)); \
    printf16((x) & (signed short)15);           \
    printf16((x) & (signed short)-16);

    unsigned short m = 564;
    short n = -322;
    do_task4(m);
    printf("\n");
    do_task4(n);
}

void T5()
{
    unsigned short m = 564;
    short n = -322;
#define do_task5(x)                \
    printf16(x);                   \
    printf16(unsigned_trunc32(x)); \
    printf16(unsigned_floor32(x));
    do_task5(n);
    printf("\n");
    do_task5(m);
}

void T6()
{
#define do_task6(x)   \
    printf32(x);      \
    printf32(inc32(x)); \
    printf32(dec32(x)); \
    printf("\n");


    float a = 0;
    float b = 1;
    float c = 12345678;
    float d = 123456789;
    unsigned int z = 0;
    unsigned int umax = UINT32_MAX;
    int smin = INT32_MIN;
    int smax = INT32_MAX;


    do_task6(a);
    do_task6(b);
    do_task6(c);
    do_task6(d);
    do_task6(z);
    do_task6(umax);
    do_task6(smin);
    do_task6(smax);
}

int main()
{
    T6();
    
    return 0;
}
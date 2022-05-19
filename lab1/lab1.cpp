#include <iostream>
#include <bitset>
#include <iomanip>
#include <cstdint>
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

void printf32(void *p)
{
    unsigned int cu = *(unsigned int *)p;
    bitset<32> b = cu;
    cout << "unsigned\nhex: " << hex << cu << endl;
    cout << "bin: " << b << endl;
    cout << "dec: " << dec << cu << endl;
    int cs = *(unsigned int *)p;
    bitset<32> bs = cs;
    cout << "signed\nhex: " << hex << cs << endl;
    cout << "bin: " << bs << endl;
    cout << "dec: " << dec << cs << endl;
    cout << "float: " << setprecision(8) << *(float *)p << endl
         << endl;
}

void printf64(void *p)
{
    unsigned long long cu = *(unsigned long long *)p;
    bitset<64> b = cu;
    cout << "unsigned\nhex: " << hex << cu << endl;
    cout << "bin: " << b << endl;
    cout << "dec: " << dec << cu << endl;
    long long cs = *(long long *)p;
    bitset<64> bs = cs;
    cout << "signed\nhex: " << hex << cs << endl;
    cout << "bin: " << bs << endl;
    cout << "dec: " << dec << cs << endl;
    cout << "double: " << setprecision(16) << *(double *)p << endl
         << endl;
}

void printf16(void *p)
{
    unsigned short cu = *(unsigned short *)p;
    bitset<16> b = cu;
    cout << "unsigned\nhex: " << hex << cu << endl;
    cout << "bin: " << b << endl;
    cout << "dec: " << dec << cu << endl;
    short cs = *(unsigned short *)p;
    bitset<16> bs = cs;
    cout << "signed\nhex: " << hex << cs << endl;
    cout << "bin: " << bs << endl;
    cout << "dec: " << dec << cs << endl
         << endl;
}

void t2()
{
    print_sizeof(char);
    print_sizeof(signed char);
    print_sizeof(unsigned char);
    print_sizeof(wchar_t);
    print_sizeof(short);
    print_sizeof(unsigned short);
    print_sizeof(int);
    print_sizeof(unsigned int);
    print_sizeof(long);
    print_sizeof(unsigned long);
    print_sizeof(long long);
    print_sizeof(unsigned long long);
    print_sizeof(float);
    print_sizeof(double);
    print_sizeof(long double);
    print_sizeof(size_t);
    print_sizeof(ptrdiff_t);
    print_sizeof(void *);
    print_sizeof(char *);
    print_sizeof(int *);
    print_sizeof(unsigned int *);
}

void t3()
{
    unsigned short max_ushort = UINT16_MAX;
    unsigned short min_ushort = 0;
    short min_short = INT16_MIN;
    short max_short = INT16_MAX;
    short y = 4;
    short z = -7;
    printf16(&max_ushort);
    printf16(&min_ushort);
    printf16(&min_short);
    printf16(&max_short);
    printf16(&y);
    printf16(&z);
}

void t4()
{
    unsigned long long max_ulong_long = UINT64_MAX;
    unsigned int min_uint = 0;
    long long min_long_long = INT64_MIN;
    short max_short = INT16_MAX;

    printf("max signed short:\n");
    printf16(&max_short);
    printf("min signed long long:\n");
    printf64(&min_long_long);
    printf("min unsigned int:\n");
    printf32(&min_uint);
    printf("max unsigned long long:\n");
    printf64(&max_ulong_long);
    long long x = 0xF1F2F3F4;
    int y = 4;
    short z = -7;
    printf16(&z);
    printf32(&y);
    printf64(&x);
}

void t5()
{
    unsigned int x = 0xF1F2F3F4;
    print_dump(x);
    long long arr[] = {0xF1F2F3F4, 4, -7};
    print_dump(arr);
    double f = 4;
    print_dump(f);
    printf64(&f);
}

void strings()
{
    char s1[] = "abczklmn";
    char s2[] = "абвёклмн";
    wchar_t s3[] = L"abczklmn";
    wchar_t s4[] = L"абвёклмн";
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;
    std::cout << s4 << std::endl;
    wprintf(L"%s",s4);
    print_dump(s1);
    print_dump(s2);
    print_dump(s3);
    print_dump(s4);
}

#define T5

int main()
{
    std::cout << "task2" << std::endl;
    t2();
    std::cout << "task3" << std::endl;
    t3();
    std::cout << "task4" << std::endl;
    t4();
    std::cout << "task5" << std::endl;
    t5();
    std::cout << "strings:" << std::endl;
    strings();

    return 0;
}
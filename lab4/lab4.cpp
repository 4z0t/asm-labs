#define _USE_MATH_DEFINES

#include <math.h>
#include <cstdio>
#include <cstring>
#include <typeinfo>

#define _wrap_scanf(args, ...)             \
    int flag;                              \
    do                                     \
    {                                      \
        flag = scanf(args, ##__VA_ARGS__); 		\
        fflush(stdin);                     \
        if (flag != 0)                     \
            break;                         \
        printf("type correct value!\n");   \
    } while (true);


void T1()
{
	puts("PIN-23\nBiriukov & Grebennikov\n#11");
}

template <typename T>
void print_arr(const T* arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d \t %llx\n", arr[i], arr[i]);
	printf("\n");
}

void print_arr(float arr[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%.18f\n", arr[i]);
	printf("\n");
}

void print_arr(double arr[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%.18lf\n", arr[i]);
	printf("\n");
}

void change_arr(int* arr)
{
	printf("Enter int -> ");
	_wrap_scanf("%d", arr + 1);
}

void change_arr(short* arr)
{
	printf("Enter short -> ");
	_wrap_scanf("%hd", arr + 1);
}

void change_arr(float* arr)
{
	printf("Enter float -> ");
	_wrap_scanf("%f", arr + 1);
}

void change_arr(double* arr)
{
	printf("Enter double -> ");
	_wrap_scanf("%lf", arr + 1);
}

void change_arr(long long* arr)
{
	printf("Enter long -> ");
	_wrap_scanf("%lli", arr + 1);
}

void T23()
{
	short s = 0xC0DE;
	int l = 0xDEADBEEF;
	long long q = 0xBECACA01FFEDC0CA;
	float fs = (float)M_PI;
	double fl = (double)M_PI;

	short Ms[5] = { s, s, s, s, s };
	int Ml[5] = { l, l, l, l, l };
	long long Mq[5] = { q, q, q, q, q };
	float Mfs[5] = { fs, fs, fs, fs, fs };
	double Mfl[5] = { fl, fl, fl, fl, fl };

	print_arr(Ms, 5);
	print_arr(Ml, 5);
	print_arr(Mq, 5);
	print_arr(Mfs, 5);
	print_arr(Mfl, 5);

	change_arr(Ms);
	print_arr(Ms, 5);
	change_arr(Ml);
	print_arr(Ml, 5);
	change_arr(Mq);
	print_arr(Mq, 5);
	change_arr(Mfs);
	print_arr(Mfs, 5);
	change_arr(Mfl);
	print_arr(Mfl, 5);


}

void T4()
{
	short s = 0xC0DE;
	short Ms[5] = { s, s, s, s, s };
	printf("Enter short numbers:\n");
	int c = 0;
	while (true)
	{
		c = scanf("%hd%hd%hd%hd%hd", &Ms[0], &Ms[1], &Ms[2], &Ms[3], &Ms[4]);
		if (c != 5)
		{
			printf("Incorrect input\nThere must be 5 numbers, you typed %d\n", c);
			fflush(stdin);
		}
		else
			break;
	}



	print_arr(Ms, 5);
}

void T5()
{
	const int size = 256;
	char buff[size]{};
	char* s1 = NULL, * s2 = NULL, * s3 = NULL;
	printf("Enter string without spaces -> ");
	scanf("%s", buff);
	int len = strlen(buff) + 1;
	s1 = new char[len] {};
	strcpy(s1, buff);
	printf("%s\n", s1);

	fflush(stdin);
	memset(buff, 0, size);
	printf("Enter string with spaces -> ");
	gets(buff);
	len = strlen(buff) + 1;
	s2 = new char[len] {};
	strcpy(s2, buff);

	printf("%s\n", s2);

	printf("Enter string with spaces -> ");
	fgets(buff, sizeof(buff), stdin);
	len = strlen(buff) + 1;
	s3 = new char[len] {};
	strcpy(s3, buff);
	printf("\n\n%s\n%d", s3, len);

	delete[]s1;
	delete[]s2;
	delete[]s3;
}

void T6()
{
	short s = 0xC0DE;
	int l = 0xDEADBEEF;
	long long q = 0xBECACA01FFEDC0CA;
	float fs = (float)M_PI;
	double fl = (double)M_PI;

	short Ms[5] = { s, s, s, s, s };
	int Ml[5] = { l, l, l, l, l };
	long long Mq[5] = { q, q, q, q, q };
	float Mfs[5] = { fs, fs, fs, fs, fs };
	double Mfl[5] = { fl, fl, fl, fl, fl };
	for (int i = 0; i < 5; i++)
		printf("%24.d\t", Ms[i]);
	printf("\n");
	for (int i = 0; i < 5; i++)
		printf("%24.d\t", Ml[i]);
	printf("\n");
	for (int i = 0; i < 5; i++)
		printf("%24.lli\t", Mq[i]);
	printf("\n");
	for (int i = 0; i < 5; i++)
		printf("%27.2f\t", Mfs[i]);
	printf("\n");
	for (int i = 0; i < 5; i++)
		printf("%27.2lf\t", Mfl[i]);
	printf("\n");


}

int main()
{
	T6();

	return 0;
}
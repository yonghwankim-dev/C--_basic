#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
	char str1[] = "Result";
	char str2[30];

	strcpy_s(str2, 10, str1);

	printf("%s: %f\n", str1, sin(0.14));
	printf("%s: %f\n", str2, abs(-1.25));

	system("pause");
	return 0;
}
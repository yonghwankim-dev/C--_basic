#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;


int main(void)
{
	char ch1[100] = "result";
	char ch2[100] = "1234";
	char ch3[100] = "";

	cout << "strlen : " << strlen(ch1) << endl;

	strcat_s(ch1,sizeof(ch1), ch2);
	cout << "strcat : " <<ch1 << endl;

	strcpy_s(ch3, sizeof(ch3), ch1);
	cout << "strcpy_s : " << ch3 << endl;


	cout << "strcmp : " << strcmp(ch1, ch3) << endl;

	system("pause");
	return 0;

}
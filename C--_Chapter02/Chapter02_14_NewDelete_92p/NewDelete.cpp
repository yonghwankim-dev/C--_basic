#include <iostream>
#include <string.h>
#include <stdlib.h>

using std::cout;
using std::endl;

char* MakeStrAdr(int len)
{
	//char* str = (char*)malloc(sizeof(char)*len);
	char* str = new char[len];
	return str;
}

int main(void)
{
	char* str = MakeStrAdr(20);
	strcpy_s(str, 20, "I am so happy~");
	cout << str << endl;
	//free(str);
	delete []str;


	system("pause");
	return 0;
}
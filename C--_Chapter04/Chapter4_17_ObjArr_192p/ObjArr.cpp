#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

class Person
{
private:
	char * name;
	int age;
public:
	Person(const char * myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy_s(name, len, myname);
		age = myage;
	}
	Person()
	{
		name = NULL;
		age = 0;
		cout << "called Person()" << endl;
	}
	void SetPersonInfo(char * myname, int myage)
	{
		name = myname;
		age = myage;
	}
	void ShowPersonInfo() const
	{
		cout << "이름: " << name << ", ";
		cout << "나이: " << age << endl;
	}
	~Person()
	{
		delete []name;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person parr[3];
	char namestr[100];
	char * strptr;
	int age;
	int len;

	for (int i = 0;i < 3;i++)
	{
		cout << "이름: ";
		cin >> namestr;
		cout << "나이: ";
		cin >> age;
		len = strlen(namestr) + 1;
		strptr = new char[len];
		strcpy_s(strptr, len, namestr);
		parr[i].SetPersonInfo(strptr, age);
	}
	
	for (int i = 0;i < 3;i++)
	{
		parr[i].ShowPersonInfo();
	}

	system("pause");
	return 0;
}
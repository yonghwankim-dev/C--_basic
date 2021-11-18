#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
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
		cout << "�̸�: " << name << ", ";
		cout << "����: " << age << endl;
	}
	~Person()
	{
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person * parr[3];
	char namestr[100];
	int age;

	for (int i = 0;i < 3;i++)
	{
		cout << "�̸�: ";
		cin >> namestr;
		cout << "����: ";
		cin >> age;
		parr[i] = new Person(namestr, age);
	}

	for (int i = 0;i < 3;i++)
	{
		parr[i]->ShowPersonInfo();
	}

	for (int i = 0;i < 3;i++)
	{
		delete parr[i];
	}

	system("pause");
	return 0;
}
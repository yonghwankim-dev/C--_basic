#include <iostream>
#include <cstring>

using std::endl;
using std::cout;

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
	void ShowPersonInfo() const
	{
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}
	Person& operator=(const Person& ref)
	{
		delete[]name;	// �޸� ������ �������� �޸� ���� ����
		int len = strlen(ref.name) + 1;
		name = new char[len];
		strcpy_s(name, len, ref.name);
		age = ref.age;
		return *this;
	}
	~Person()
	{
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person man1("Lee dong woo", 29);
	Person man2("Yoon ji yul", 22);
	man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	system("pause");
	return 0;
}
#include <iostream>
#include <cstring>

using std::endl;
using std::cout;

class Person
{
private:
	char * name;
public:
	Person(const char * myname)
	{
		int len = strlen(myname)+1;
		name = new char[len];
		strcpy_s(name, len, myname);
	}
	~Person()
	{
		delete[]name;
	}
	void WhatYourName() const
	{
		cout << "My name is " << name << endl;
	}
};

class UnivStudent : public Person
{
private:
	char * major;
public:
	UnivStudent(const char * myname, const char * mymajor) : Person(myname)
	{
		int len = strlen(mymajor) + 1;
		major = new char[len];
		strcpy_s(major, len, mymajor);
	}
	~UnivStudent()
	{
		delete[]major;
	}
	void WhoAreYou() const
	{
		WhatYourName();
		cout << "My major is " << major << endl << endl;
	}
};

int main(void)
{
	UnivStudent st1("Kim", "Mathematics");
	st1.WhoAreYou();
	UnivStudent st2("Hong", "Physics");
	st2.WhoAreYou();

	system("pause");
	return 0;
}
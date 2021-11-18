#include <iostream>
#include <cstring>

using std::endl;
using std::cout;

class MyFriendInfo
{
private:
	char * name;
	int age;
public:
	MyFriendInfo(const char * myname, int myage) :age(myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy_s(name, len, myname);
	}
	~MyFriendInfo()
	{
		delete[]name;
	}
	void ShowMyFriendInfo()
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl << endl;;
	}
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
	char * addr;
	char * phone;
public:
	MyFriendDetailInfo(const char * myname, int myage, const char * myaddr, const char * myphone)
		: MyFriendInfo(myname, myage)
	{
		int len = strlen(myaddr) + 1;
		addr = new char[len];
		strcpy_s(addr, len, myaddr);

		len = strlen(myphone) + 1;
		phone = new char[len];
		strcpy_s(phone, len, myphone);
	}
	~MyFriendDetailInfo()
	{
		delete[]addr;
		delete[]phone;
	}
	void ShowMyFriendDetailInfo()
	{
		ShowMyFriendInfo();
		cout << "주소: " << addr << endl;
		cout << "phone: " << phone << endl << endl;;
	}
};

int main(void)
{
	MyFriendDetailInfo f("kim", 24, "okchen", "010-4963-4496");
	f.ShowMyFriendInfo();
	f.ShowMyFriendDetailInfo();

	system("pause");
	return 0;
}
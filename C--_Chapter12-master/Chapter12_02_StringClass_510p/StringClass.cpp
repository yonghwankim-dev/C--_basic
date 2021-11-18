#include <iostream>
#include <string>

using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::ostream;
using std::istream;

class String
{
private:
	int len;
	char * str;
public:
	String();
	String(const char * s);	// ������
	String(const String& s);	// ���� ������
	~String();	// �Ҹ���
	String& operator=(const String& s);	// ���� ������
	String operator+(const String& s);	// +�������� �����ε�
	String& operator+=(const String& s);	// +=�������� �����ε�
	bool operator==(const String& s);	// ==�������� �����ε�
	friend ostream& operator<<(ostream& os, const String& s);	//<<������
	friend istream& operator>>(istream& is, String& s);	//>> ������
};

String::String()
{
	len = 0;
	str = NULL;
}

String::String(const char * s)
{
	len = strlen(s) + 1;
	str = new char[len];	// �����Ҵ�
	strcpy_s(str, len, s);
}

String::String(const String& s)
{
	len = s.len;
	str = new char[len];	// �����Ҵ�
	strcpy_s(str, len, s.str);
}

String::~String()
{
	if (str != NULL)
	{
		delete[]str;
	}
	
}

String& String::operator=(const String& s)
{
	if (str != NULL)
	{
		delete[]str;
	}
	len = s.len;
	str = new char[len];
	strcpy_s(str, len, s.str);
	return *this;
}

String& String::operator+=(const String& s)
{
	len += (s.len - 1);
	char * tempstr = new char[len];
	strcpy_s(tempstr,len, str);
	strcat_s(tempstr,len, s.str);

	if (str != NULL)
	{
		delete[]str;
	}
	str = tempstr;
	return *this;
}

bool String::operator==(const String& s)
{

	if (strcmp(str, s.str) == 0)
	{
		return true;
	}
	else {
		return false;
	}
}

String String::operator+(const String& s)
{
	int templen = len + s.len - 1;
	char * tempstr = new char[templen];	// len�� s.len���� +1 +1�� ���ؼ� -1�� �����ָ� 1ĭ �� ��������.
	strcpy_s(tempstr, templen, s.str);
	strcat_s(tempstr,templen, s.str);

	String temp(tempstr);
	delete[]tempstr;
	return temp;
}



ostream& operator<<(ostream& os, const String& s)
{
	os << s.str;
	return os;
}

istream& operator>>(istream& is, String& s)
{
	char str[100];
	is >> str;
	s = String(str);
	return is;
}

int main(void)
{
	string str1 = "I like";
	string str2 = "string class";
	string str3 = str1 + str2;

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;
	if (str1 == str3)
	{
		cout << "���� ���ڿ�!" << endl;
	}
	else {
		cout << "�������� ���� ���ڿ�!" << endl;
	}

	string str4;
	cout << "���ڿ� �Է�: ";
	cin >> str4;
	cout << "�Է��� ���ڿ�: " << str4 << endl;

	system("pause");
	return 0;
}
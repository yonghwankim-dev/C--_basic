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
	String(const char * s);	// 생성자
	String(const String& s);	// 복사 생성자
	~String();	// 소멸자
	String& operator=(const String& s);	// 대입 연산자
	String operator+(const String& s);	// +연산자의 오버로딩
	String& operator+=(const String& s);	// +=연산자의 오버로딩
	bool operator==(const String& s);	// ==연산자의 오버로딩
	friend ostream& operator<<(ostream& os, const String& s);	//<<연산자
	friend istream& operator>>(istream& is, String& s);	//>> 연산자
};

String::String()
{
	len = 0;
	str = NULL;
}

String::String(const char * s)
{
	len = strlen(s) + 1;
	str = new char[len];	// 동적할당
	strcpy_s(str, len, s);
}

String::String(const String& s)
{
	len = s.len;
	str = new char[len];	// 동적할당
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
	char * tempstr = new char[templen];	// len과 s.len에서 +1 +1로 인해서 -1을 안해주면 1칸 더 많아진다.
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
		cout << "동일 문자열!" << endl;
	}
	else {
		cout << "동일하지 않은 문자열!" << endl;
	}

	string str4;
	cout << "문자열 입력: ";
	cin >> str4;
	cout << "입력한 문자열: " << str4 << endl;

	system("pause");
	return 0;
}
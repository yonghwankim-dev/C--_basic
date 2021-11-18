#ifndef __STRING_H__
#define __STRING_H__

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::cin;
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

#endif

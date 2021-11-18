#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class Book
{
private:
	char * title;	// å ����
	char * isbn;	// ���� ǥ�� ���� ��ȣ
	int price;		// å ����
public:
	Book(const char* mytitle, const char* myisbn, int myprice) :price(myprice)
	{
		int len = strlen(mytitle)+1;
		title = new char[len];
		strcpy_s(title, len, mytitle);

		len = strlen(myisbn) + 1;
		isbn = new char[len];
		strcpy_s(isbn, len, myisbn);
	}
	~Book()
	{
		delete title;
		delete isbn;
	}

	void ShowBookInfo()
	{
		cout << "���� : " << title << endl;
		cout << "ISBN : " << isbn << endl;
		cout << "���� : " << price << endl;
	}
};

class EBook : public Book
{
private:
	char * DRMKey; //���Ȱ��� Ű
public:
	EBook(const char* mytitle,const char* myisbn, int myprice,const char* myDRMKey) : Book(mytitle, myisbn, myprice)
	{
		int len = strlen(myDRMKey) + 1;
		DRMKey = new char[len];
		strcpy_s(DRMKey, len, myDRMKey);
	}
	~EBook()
	{
		delete DRMKey;
	}
	void ShowBookInfo()
	{
		Book::ShowBookInfo();
		cout << "����Ű : " << DRMKey << endl;
	}
};

int main(void)
{
	Book book("���� C++","555-12345-890-0",20000);
	book.ShowBookInfo();
	cout << endl;

	EBook ebook("���� C++ ebook","555-12345-890-1",10000,"fdx9w0i8kiw");
	ebook.ShowBookInfo();

	system("pause");
	return 0;

}
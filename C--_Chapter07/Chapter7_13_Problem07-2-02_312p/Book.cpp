#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class Book
{
private:
	char * title;	// 책 제목
	char * isbn;	// 국제 표준 도서 번호
	int price;		// 책 정가
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
		cout << "제목 : " << title << endl;
		cout << "ISBN : " << isbn << endl;
		cout << "가격 : " << price << endl;
	}
};

class EBook : public Book
{
private:
	char * DRMKey; //보안관련 키
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
		cout << "인증키 : " << DRMKey << endl;
	}
};

int main(void)
{
	Book book("좋은 C++","555-12345-890-0",20000);
	book.ShowBookInfo();
	cout << endl;

	EBook ebook("좋은 C++ ebook","555-12345-890-1",10000,"fdx9w0i8kiw");
	ebook.ShowBookInfo();

	system("pause");
	return 0;

}
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
		int len = strlen(mytitle) + 1;
		title = new char[len];
		strcpy_s(title, len, mytitle);

		len = strlen(myisbn) + 1;
		isbn = new char[len];
		strcpy_s(isbn, len, myisbn);
	}
	Book(const Book& ref)
	{
		int len = strlen(ref.title) + 1;
		title = new char[len];
		strcpy_s(title, len, ref.title);

		len = strlen(ref.isbn) + 1;
		isbn = new char[len];
		strcpy_s(isbn, len, ref.isbn);

		price = ref.price;
	}
	Book& operator=(const Book& ref)
	{
		delete []title;
		delete []isbn;

		int len = strlen(ref.title) + 1;
		title = new char[len];
		strcpy_s(title, len, ref.title);

		len = strlen(ref.isbn) + 1;
		isbn = new char[len];
		strcpy_s(isbn, len, ref.isbn);

		price = ref.price;

		return *this;
	}

	~Book()
	{
		delete title;
		delete isbn;
		cout << "called Book title, isbn destructor" << endl;
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
	EBook(const char* mytitle, const char* myisbn, int myprice, const char* myDRMKey) : Book(mytitle, myisbn, myprice)
	{
		int len = strlen(myDRMKey) + 1;
		DRMKey = new char[len];
		strcpy_s(DRMKey, len, myDRMKey);
	}
	EBook(const EBook& ref) : Book(ref)
	{
		int len = strlen(ref.DRMKey) + 1;
		DRMKey = new char[len];
		strcpy_s(DRMKey, len, ref.DRMKey);
	}
	EBook& operator=(const EBook& ref)
	{
		Book::operator=(ref);
		
		delete []DRMKey;

		int len = strlen(ref.DRMKey) + 1;
		DRMKey = new char[len];
		strcpy_s(DRMKey, len, ref.DRMKey);

		return *this;
	}
	~EBook()
	{
		delete DRMKey;
		cout << "called EBook DRMKey destructor" << endl;
	}
	void ShowBookInfo()
	{
		Book::ShowBookInfo();
		cout << "인증키 : " << DRMKey << endl;
	}
};

int main(void)
{
	EBook ebook1("좋은 C++", "555-12345-890-0", 20000,"qwer1234qwer");
	EBook ebook2 = ebook1;	// 복사 생성자 호출

	ebook2.ShowBookInfo();

	cout << endl;

	EBook ebook3("dumy","dumy",0,"dumy");
	ebook3 = ebook2;		// 대입 연산자 호출

	ebook3.ShowBookInfo();
	system("pause");
	return 0;

}
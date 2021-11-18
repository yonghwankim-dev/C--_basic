#include <iostream>
#include <cstring>

using std::endl;
using std::cout;

class Gun
{
private:
	int bullet;
public:
	Gun(int bnum) :bullet(bnum)
	{

	}
	void Shot()
	{
		cout << "BBANG!" << endl;
		bullet--;
	}
};

class Police
{
private:
	int handcuffs;
	Gun * pistol;
public:
	Police(int bnum, int bcuff) : handcuffs(bcuff)
	{
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}
	void PutHandcuff()
	{
		cout << "SNAP!" << endl;
		handcuffs--;
	}
	void Shot()
	{
		if (pistol == NULL)
		{
			cout << "Hut BBANG!" << endl;
		}
		else {
			pistol->Shot();
		}
	}
	~Police()
	{
		if (pistol != NULL)
		{
			delete pistol;
			cout << "called destructor" << endl;
		}
	}

	// 대입연산자
	Police& operator=(const Police& ref)
	{
		if (pistol != NULL)	// 메모리 누수를 막기위한 조건문 연산
							// 기존에 존재하는 피스톨 객체가 있으면 삭제한다.
		{
			delete pistol;
		}

		if (ref.pistol != NULL)
		{
			pistol = new Gun(*(ref.pistol));
		}
		else {
			pistol = NULL;
		}
		handcuffs = ref.handcuffs;
		return *this;
	}
	// 복사생성자
	Police(const Police& copy)
	{
		if (copy.pistol != NULL)
		{
			pistol = new Gun(*(copy.pistol));	// Gun의 복사 생성자 호출
		}
		else {
			pistol = NULL;
		}

		handcuffs = copy.handcuffs;
	}
};

int main(void)
{
	Police pman1(5, 3);
	Police pman2 = pman1;	// 복사 생성자의 호출
	pman2.PutHandcuff();
	pman2.Shot();
	

	Police pman3(2, 4);
	pman3 = pman1;		// 대입 연산자의 호출
	pman3.PutHandcuff();
	pman3.Shot();
	
	system("pause");
	return 0;
}
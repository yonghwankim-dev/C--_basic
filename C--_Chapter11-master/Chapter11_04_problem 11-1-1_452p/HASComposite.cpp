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

	// ���Կ�����
	Police& operator=(const Police& ref)
	{
		if (pistol != NULL)	// �޸� ������ �������� ���ǹ� ����
							// ������ �����ϴ� �ǽ��� ��ü�� ������ �����Ѵ�.
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
	// ���������
	Police(const Police& copy)
	{
		if (copy.pistol != NULL)
		{
			pistol = new Gun(*(copy.pistol));	// Gun�� ���� ������ ȣ��
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
	Police pman2 = pman1;	// ���� �������� ȣ��
	pman2.PutHandcuff();
	pman2.Shot();
	

	Police pman3(2, 4);
	pman3 = pman1;		// ���� �������� ȣ��
	pman3.PutHandcuff();
	pman3.Shot();
	
	system("pause");
	return 0;
}
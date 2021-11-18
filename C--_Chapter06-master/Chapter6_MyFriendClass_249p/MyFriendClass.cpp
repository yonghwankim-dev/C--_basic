#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class Gril;

class Boy
{
private:
	int height;
	friend class Gril;

public:
	Boy(int len) :height(len)
	{
		
	}
	void ShowYourFriendInfo(Gril &frn);
};

class Gril
{
private:
	char phNum[20];
public:
	Gril(const char * num)
	{
		strcpy_s(phNum, 20, num);
	}
	void ShowYourFriendInfo(Boy &frn);
	friend class Boy;
};

void Boy::ShowYourFriendInfo(Gril &frn)
{
	cout << "Her phone number: " << frn.phNum << endl;
}

void Gril::ShowYourFriendInfo(Boy &frn)
{
	cout << "His height: " << frn.height << endl;
}

int main(void)
{
	Boy boy(170);
	Gril gril("010-1234-5678");
	boy.ShowYourFriendInfo(gril);
	gril.ShowYourFriendInfo(boy);

	system("pause");
	return 0;
}
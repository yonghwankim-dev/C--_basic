#include <iostream>

using std::endl;
using std::cout;

class SoBase
{
private:
	int baseNum;
public:
	SoBase(int n) :baseNum(n)
	{
		cout << "SoBase(int n) : " << baseNum << endl;
	}
	~SoBase()
	{
		cout << "~SoBase() : " << baseNum << endl;
	}
};

class SoDerived :public SoBase
{
private:
	int derivNum;
public:
	SoDerived(int n) :SoBase(n), derivNum(n)
	{
		cout << "SoDerived() : " << derivNum << endl;
	}
	~SoDerived()
	{
		cout << "~SoDerived() : " << derivNum << endl;
	}
};

int main(void)
{
	SoDerived sr1(15);
	SoDerived sr2(27);
	system("pause");
	return 0;
}
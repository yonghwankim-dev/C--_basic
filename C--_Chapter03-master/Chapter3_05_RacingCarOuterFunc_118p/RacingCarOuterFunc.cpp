#include <iostream>

using std::cout;
using std::endl;

namespace CAR_CONST
{
	enum
	{
		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP = 10
	};
}

struct Car
{
	char gamerID[CAR_CONST::ID_LEN];	// ������ID
	int fuelGauge;						// ���ᷮ
	int curSpeed;						// ����ӵ�

	void showCarState(void);
	void Accel(void);
	void Break(void);

};

inline void Car::showCarState(void)
{
	cout << "������ID:" << gamerID << endl;
	cout << "���ᷮ:" << fuelGauge << "%" << endl;
	cout << "����ӵ�:" << curSpeed << "km/s" << endl << endl;
}

inline void Car::Accel(void)
{
	if (fuelGauge <= 0)
	{
		return;
	}
	else {
		fuelGauge -= CAR_CONST::FUEL_STEP;
	}

	curSpeed += CAR_CONST::ACC_STEP;
}

inline void Car::Break(void)
{
	if (curSpeed < CAR_CONST::BRK_STEP)
	{
		curSpeed = 0;
		return;
	}

	curSpeed -= CAR_CONST::BRK_STEP;
}

int main(void)
{
	Car run99 = { "run99",100,0 };
	run99.Accel();
	run99.Accel();
	run99.showCarState();
	run99.Break();
	run99.showCarState();

	Car run77 = { "sped77",100,0 };
	run77.Accel();
	run77.Break();
	run77.showCarState();

	system("pause");
	return 0;


}
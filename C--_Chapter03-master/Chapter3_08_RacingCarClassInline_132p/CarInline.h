#pragma once
#ifndef __CAR_H__
#define __CAR_H__

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

class Car
{
private:
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;
public:
	void InitMembers(const char *ID, int fuel);
	void ShowCarState();
	void Accel();
	void Break();
};

inline void Car::ShowCarState()
{
	cout << "������ID:" << gamerID << endl;
	cout << "���ᷮ:" << fuelGauge << "%" << endl;
	cout << "����ӵ�:" << curSpeed << "km/s" << endl << endl;
}

inline void Car::Break()
{
	if (curSpeed < CAR_CONST::BRK_STEP)
	{
		curSpeed = 0;
		return;
	}
	curSpeed -= CAR_CONST::BRK_STEP;
}

#endif // !__CAR_H__

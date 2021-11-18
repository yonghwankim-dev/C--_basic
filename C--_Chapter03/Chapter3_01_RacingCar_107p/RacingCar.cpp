#include <iostream>

using std::cout;
using std::endl;

#define ID_LEN		20
#define MAX_SPD		200
#define FUEL_STEP	2
#define ACC_STEP	10
#define BRK_STEP	10

struct Car
{
	char gamerID[ID_LEN];	// ������ID
	int fuelGauge;			// ���ᷮ
	int curSpeed;			// ����ӵ�

	
};

void showCarState(const Car &car)
{
	cout << "������ID:" << car.gamerID << endl;
	cout << "���ᷮ:" << car.fuelGauge << "%" << endl;
	cout << "����ӵ�:" << car.curSpeed << "km/s" << endl << endl;
}

void Accel(Car &car)
{
	if (car.fuelGauge <= 0)
	{
		return;
	}
	else {
		car.fuelGauge -= FUEL_STEP;
	}

	car.curSpeed += ACC_STEP;
}

void Break(Car &car)
{
	if (car.curSpeed < BRK_STEP)
	{
		car.curSpeed = 0;
		return;
	}

	car.curSpeed -= BRK_STEP;
}

int main(void)
{
	Car run99 = { "run99",100,0 };
	Accel(run99);
	Accel(run99);
	showCarState(run99);
	Break(run99);
	showCarState(run99);

	Car run77 = { "sped77",100,0 };
	Accel(run77);
	Break(run77);
	showCarState(run77);

	system("pause");
	return 0;

	
}
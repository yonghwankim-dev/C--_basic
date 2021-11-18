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
	char gamerID[ID_LEN];	// 소유자ID
	int fuelGauge;			// 연료량
	int curSpeed;			// 현재속도

	void showCarState(void)
	{
		cout << "소유자ID:" << gamerID << endl;
		cout << "연료량:" << fuelGauge << "%" << endl;
		cout << "현재속도:" << curSpeed << "km/s" << endl << endl;
	}

	void Accel(void)
	{
		if (fuelGauge <= 0)
		{
			return;
		}
		else {
			fuelGauge -= FUEL_STEP;
		}

		curSpeed += ACC_STEP;
	}

	void Break(void)
	{
		if (curSpeed < BRK_STEP)
		{
			curSpeed = 0;
			return;
		}

		curSpeed -= BRK_STEP;
	}
};



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
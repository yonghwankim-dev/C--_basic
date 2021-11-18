#include <iostream>

using std::endl;
using std::cout;

class Car
{
private:
	int gasolineGauge;
public:
	Car(int n) :gasolineGauge(n)
	{
		cout << "Car() : " << endl;
	}
	int GetGasGauge()
	{
		return gasolineGauge;
	}
};

class HybridCar : public Car
{
private:
	int electricGauge;
public:
	HybridCar(int n1, int n2) :Car(n1), electricGauge(n2)
	{
		cout << "HybridCar()" << endl;
	}
	int GetElecGauge()
	{
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar
{
private:
	int waterGauge;
public:
	HybridWaterCar(int n1, int n2, int n3) :HybridCar(n1, n2), waterGauge(n3)
	{
		cout << "HybridWaterCar()" << endl;
	}
	void ShowCurrentGauge()
	{
		cout << "ÀÜ¿© °¡¼Ö¸°: " << GetGasGauge() << endl;
		cout << "ÀÜ¿© Àü±â·®: " << GetElecGauge() << endl;
		cout << "ÀÜ¿© ¿öÅÍ·®: " << waterGauge << endl;
	}
};

int main(void)
{
	HybridWaterCar hwc(10, 20, 30);
	hwc.ShowCurrentGauge();

	system("pause");
	return 0;
}
#include <iostream>
#include <cstring>

using std::endl;
using std::cout;

class Computer
{
private:
	char owner[50];
public:
	Computer(const char * name)
	{
		int len = strlen(name)+1;
		strcpy_s(owner, len, name);
	}
	void Calculate()
	{
		cout << "��û ������ ����մϴ�." << endl;
	}
};

class NotebookComp : public Computer
{
private:
	int Battery;
public:
	NotebookComp(const char * name, int initChag) : Computer(name), Battery(initChag)
	{
	}
	void Charging() {
		Battery += 5;
	}
	void UseBattery() {
		Battery -= 1;
	}
	void MovingCal()
	{
		if (GetBatteryInfo() < 1)
		{
			cout << "������ �ʿ��մϴ�." << endl;
			return;
		}
		cout << "�̵��ϸ鼭 ";
		Calculate();
		UseBattery();
	}
	int GetBatteryInfo()
	{
		return Battery;
	}
};

class TabletNotebook : public NotebookComp
{
private:
	char regstPenModel[50];
public:
	TabletNotebook(const char * name, int initChag, const char * pen):NotebookComp(name,initChag)
	{
		int len = strlen(pen)+1;
		strcpy_s(regstPenModel, len, pen);
	}
	void Write(const char * penInfo)
	{
		if (GetBatteryInfo() < 1)
		{
			cout << "������ �ʿ��մϴ�." << endl;
			return;
		}
		if (strcmp(regstPenModel, penInfo) != 0)
		{
			cout << "��ϵ� ���� �ƴմϴ�.";
			return;
		}
		cout << "�ʱ� ������ ó���մϴ�." << endl;
		UseBattery();
	}
};

int main(void)
{
	NotebookComp nc("�̼���", 5);
	TabletNotebook tn("������", 5, "ISE-241-242");
	nc.MovingCal();
	tn.Write("ISE-241-242");
	
	system("pause");
	return 0;
}
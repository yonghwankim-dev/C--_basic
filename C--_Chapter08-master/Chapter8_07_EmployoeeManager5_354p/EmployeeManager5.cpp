#include <iostream>
#include <cstring>

using std::endl;
using std::cout;

enum RISK_LEVEL{RISK_A=1,RISK_B,RISK_C};

class Employee
{
private:
	char name[100];
public:
	Employee(const char * name)
	{
		int len = strlen(name) + 1;
		strcpy_s(this->name, len, name);
	}
	void ShowYourName() const
	{
		cout << "name: " << name << endl;
	}

	virtual int GetPay() const = 0;
	virtual void ShowSalaryInfo() const = 0;
};

class PermanentWorker : public Employee
{
private:
	int salary;
public:
	PermanentWorker(const char * name, int money) : Employee(name), salary(money)
	{

	}
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class TemporaryWorker : public Employee
{
private:
	int workTime; // ���� �ð� �հ�
	int payPerHour;	// �ð��� �޿�
public:
	TemporaryWorker(const char * name, int pay) :Employee(name), workTime(0), payPerHour(pay)
	{

	}
	void AddWorkTime(int time)	// ���� �ð� �߰�
	{
		workTime += time;
	}
	int GetPay() const // �� ���� �޿�
	{
		return workTime * payPerHour;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class SalesWorker : public PermanentWorker
{
private:
	int salesResult;	// �� �ǸŽ���
	double bonusRatio;	// �󿩱� ����
public:
	SalesWorker(const char * name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{

	}
	void AddSalesResult(int value)
	{
		salesResult += value;
	}
	int GetPay() const
	{
		return PermanentWorker::GetPay() +	// PermanentWorker�� GetPay �Լ� ȣ��
			(int)(salesResult*bonusRatio);
	}

	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl;
	}
};

class ForeignSalesWorker : public SalesWorker
{
private:
	double level;
	double RiskPay;
public:
	ForeignSalesWorker(const char * name, int money, double ratio, int RiskLevle)
		:SalesWorker(name, money, ratio)
	{
		if (RiskLevle == RISK_LEVEL::RISK_A)
			level = 0.3;
		else if (RiskLevle == RISK_LEVEL::RISK_B)
			level = 0.2;
		else if (RiskLevle == RISK_LEVEL::RISK_C)
			level = 0.1;
	}
	void AddSalesResult(int value)
	{
		SalesWorker::AddSalesResult(value);
		RiskPay = SalesWorker::GetPay()*level;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << SalesWorker::GetPay() << endl;
		cout << "risk pay: " << RiskPay << endl;
		cout << "sum:" << SalesWorker::GetPay() + RiskPay << endl << endl;
	}
};

class EmployeeHandler
{
private:
	Employee * empList[50];
	int empNum;
public:
	EmployeeHandler() :empNum(0)
	{

	}
	void AddEmployee(Employee* emp)
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const
	{

		for (int i = 0;i<empNum;i++)
		{
			empList[i]->ShowSalaryInfo();
		}

	}
	void ShowTotalSalary() const
	{
		int sum = 0;

		for (int i = 0;i < empNum;i++)
			sum += empList[i]->GetPay();

		cout << "salary sum : " << sum << endl;

	}
	~EmployeeHandler()
	{
		for (int i = 0;i < empNum;i++)
			delete empList[i];
	}
};

int main(void)
{
	//���� ������ �������� ���Ե� ��Ʈ�� Ŭ������ ��ü����
	EmployeeHandler handler;

	// �ؿ� ������ ���
	ForeignSalesWorker * fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1);

	ForeignSalesWorker * fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	ForeignSalesWorker * fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);

	//�̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowAllSalaryInfo();

	system("pause");
	return 0;
}
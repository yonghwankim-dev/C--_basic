#include <iostream>
#include <cstring>

using std::endl;
using std::cout;

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
		cout << "salary: " << GetPay() << endl << endl;
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
		
		for(int i=0;i<empNum;i++)
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

	//������ ���
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));

	//�ӽ��� ���
	TemporaryWorker * alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	//������ ���
	SalesWorker * seller = new SalesWorker("Hong", 100, 0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);

	//�̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowAllSalaryInfo();

	// �̹� �޿� �����ؾ��� �޿��� ����
	handler.ShowTotalSalary();

	system("pause");
	return 0;
}
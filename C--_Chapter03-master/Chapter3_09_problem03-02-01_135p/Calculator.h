#pragma once
#ifndef __CARCULATOR_H__
#define __CARCULATOR_H__

namespace CALCULATOR_OPERATOR
{
	enum {
		PLUS = 0, MINUS = 1, MULTIPLY = 2, DIVIDE = 3
	};
}

class Calculator
{
private:
	int count[4];
public:
	double Add(double num1, double num2);
	double Min(double num1, double num2);
	double Mul(double num1, double num2);
	double Div(double num1, double num2);
	void SmallPoint_fixed();
	void ShowOpCount();
	void Init();
};
#endif // !__CARCULATOR_H__

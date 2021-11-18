#include "Calculator.h"
#include <iostream>

using std::cout;
using std::endl;
using std::fixed;

double Calculator::Add(double num1, double num2)
{
	count[CALCULATOR_OPERATOR::PLUS]++;
	return num1 + num2;
}

double Calculator::Min(double num1, double num2)
{
	count[CALCULATOR_OPERATOR::MINUS]++;
	return num1 - num2;
}

double Calculator::Mul(double num1, double num2)
{
	count[CALCULATOR_OPERATOR::MULTIPLY]++;
	return num1 * num2;
}

double Calculator::Div(double num1, double num2)
{
	count[CALCULATOR_OPERATOR::DIVIDE]++;
	return num1 / num2;
}

void Calculator::ShowOpCount()
{
	cout << "µ¡¼À: " << count[CALCULATOR_OPERATOR::PLUS] << " ";
	cout << "»¬¼À: " << count[CALCULATOR_OPERATOR::MINUS] << " ";
	cout << "°ö¼À: " << count[CALCULATOR_OPERATOR::MULTIPLY] << " ";
	cout << "³ª´°¼À: " << count[CALCULATOR_OPERATOR::DIVIDE] << endl;
	return;
}

void Calculator::Init()
{
	count[CALCULATOR_OPERATOR::PLUS] = 0;
	count[CALCULATOR_OPERATOR::MINUS] = 0;
	count[CALCULATOR_OPERATOR::MULTIPLY] = 0;
	count[CALCULATOR_OPERATOR::DIVIDE] = 0;
	SmallPoint_fixed();
	return;
}

void Calculator::SmallPoint_fixed()
{
	cout << fixed;
	cout.precision(2);
	return;
}
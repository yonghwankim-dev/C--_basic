#pragma once
#ifndef __NAMECARD_H_
#define __NAMECARD_H_

namespace COM_POS
{
	enum {
		CLERK, SENIOR, ASSIST, MANAGER
	};

	void ShowPositionInfo(int position);
}

class NameCard
{
private:
	char *name;
	char *company;
	char *phone;
	int position;
public:
	NameCard(const char * _name, const char * _company, const char * _phone, int pos);
	NameCard(const NameCard &copy);
	void ShowNameCardInfo() const;
	~NameCard();
};
#endif // !__NAMECARD_H_

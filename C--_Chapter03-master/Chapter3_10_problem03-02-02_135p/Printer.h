#pragma once
#ifndef __PRINTER_H__
#define __PRINTER_H__

namespace PRINTER_ENUM
{
	enum {
		STR_LEN = 20
	};
}

class Printer
{
private:
	char ch[PRINTER_ENUM::STR_LEN];
public:
	void SetString(const char * str);
	void ShowString();
};

#endif // !__PRINTER_H__

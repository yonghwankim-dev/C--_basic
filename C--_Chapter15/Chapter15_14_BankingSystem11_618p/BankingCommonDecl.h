/*
�����̸�: BankingCommonDecl.h
�ۼ��� : ���ȯ
������Ʈ ���� : 2018-11-09 ���� ���� 07
*/

#ifndef __BANKING_COMMON_H__
#define __BANKING_COMMON_H__

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::cin;

const int NAME_LEN = 20;	// �̸� ����

							/* 1:���»��� 2:�Ա� 3:��� 4:�������� ��ü ��� 5:���α׷� ���� */
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

/* �ſ��� A,B,C */
enum CREDIT { A = 1, B, C };

#endif // !__BANKING_COMMON_H__

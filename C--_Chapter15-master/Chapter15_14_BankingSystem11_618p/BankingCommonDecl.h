/*
파일이름: BankingCommonDecl.h
작성자 : 김용환
업데이트 정보 : 2018-11-09 파일 버전 07
*/

#ifndef __BANKING_COMMON_H__
#define __BANKING_COMMON_H__

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::cin;

const int NAME_LEN = 20;	// 이름 길이

							/* 1:계좌생성 2:입금 3:출금 4:개인정보 전체 출력 5:프로그램 종료 */
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

/* 신용등급 A,B,C */
enum CREDIT { A = 1, B, C };

#endif // !__BANKING_COMMON_H__

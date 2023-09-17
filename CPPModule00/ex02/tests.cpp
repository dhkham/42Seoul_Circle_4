// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"


int		main( void ) {

	typedef std::vector<Account::t>							  accounts_t;		//std::vector<Account::t> (Account 객체들의 동적 배열) 대신 accounts_t 사용
	typedef std::vector<int>								  ints_t;			//std::vector<int> 대신 ints_t 사용
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;		//두 가지 반복자 타입을 포함하는 std::pair의 별칭을 acc_int_t

	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 }; // 계좌 잔고 배열
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );		//amounts 배열의 크기를 계산

	accounts_t				accounts( amounts, amounts + amounts_size );		//accounts_t(std::vector<Account::t>) 타입의 accounts 객체 생성: amounts는 배열 시작 주소, amounts + amounts_size는 배열 마지막 다음 주소를 가리키는 포인터
																				//amounts는 배열 시작 주소, amounts + amounts_size는 배열 마지막 다음 주소를 가리키는 포인터
	accounts_t::iterator	acc_begin	= accounts.begin();						//accounts의 첫 번째 객체를 가리키는 반복자
	accounts_t::iterator	acc_end		= accounts.end();						//accounts의 마지막 객체 다음을 가리키는 반복자

	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };		// 입금액 배열
	size_t const		d_size( sizeof(d) / sizeof(int) );						//d 배열의 크기를 계산

	ints_t				deposits( d, d + d_size );								//ints_t (std::vector<int>)타입의 deposits 객체 생성
	
	ints_t::iterator	dep_begin	= deposits.begin();							
	ints_t::iterator	dep_end		= deposits.end();							

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };	// 출금액 배열
	size_t const		w_size( sizeof(w) / sizeof(int) );						//w 배열의 크기를 계산

	ints_t				withdrawals( w, w + w_size );							//ints_t (std::vector<int>)타입의 withdrawals 객체 생성

	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();

	Account::displayAccountsInfos();											//Account 클래스의 static 멤버 함수 displayAccountsInfos 호출
																				//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
	
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) ); //accounts의 각 원소에 대해 Account::displayStatus 호출
																				//[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
	
	//accounts의 각 원소에 대해 Account::makeDeposit 호출
	for ( acc_int_t it( acc_begin, dep_begin );									//acc_int_t 타입의 it 객체를 생성: it.first는 accounts의 첫 번째 Account 객체를 가리키며, it.second는 deposits의 첫 번째 입금액을 가리킴
		  it.first != acc_end && it.second != dep_end;							//it.first와 it.second가 각각 acc_end와 dep_end가 아닐 때까지 반복
		  ++(it.first), ++(it.second) ) {										//it.first와 it.second를 각각 증가시킴

		(*(it.first)).makeDeposit( *(it.second) );								//it.first가 가리키는 Account 객체에 it.second가 가리키는 값을 입금
																				//[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
	}

	Account::displayAccountsInfos();											//Account 클래스의 static 멤버 함수 displayAccountsInfos 호출
																				//[19920104_091532] accounts:8;total:21524;deposits:8;withdrawals:0
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );	//accounts의 각 원소에 대해 Account::displayStatus 호출
																				//[19920104_091532] index:0;amount:47;deposits:1;withdrawals:0

	//accounts의 각 원소에 대해 Account::makeWithdrawal 호출
	for ( acc_int_t it( acc_begin, wit_begin );									//acc_int_t 타입의 it 객체를 생성하고 acc_begin과 wit_begin을 초기화
		  it.first != acc_end && it.second != wit_end;							//it.first와 it.second가 각각 acc_end와 wit_end가 아닐 때까지 반복
		  ++(it.first), ++(it.second) ) {										//it.first와 it.second를 각각 증가시킴 (it.first는 accounts의 원소를 가리키고 it.second는 withdrawals의 원소를 가리킴)

		(*(it.first)).makeWithdrawal( *(it.second) );							//it.first가 가리키는 Account 객체(계좌)에 it.second가 가리키는 값(출금액)을 출금
																				//[19920104_091532] index:0;p_amount:47;withdrawal:refused
	}

	Account::displayAccountsInfos();											//Account 클래스의 static 멤버 함수 displayAccountsInfos 호출
																				//[19920104_091532] accounts:8;total:12442;deposits:8;withdrawals:6
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );	//accounts의 각 원소에 대해 Account::displayStatus 호출
																				//[19920104_091532] index:0;amount:47;deposits:1;withdrawals:0

	return 0;																	//소멸자 호출
																				//[19920104_091532] index:0;amount:47;closed
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //

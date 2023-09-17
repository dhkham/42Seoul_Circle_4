#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) :	// 생성자
	_accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)	// 초기화 리스트: 멤버 변수 초기화
{
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account( void )	// 소멸자
{
	_displayTimestamp();	// 현재 시간 출력
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;	// 계좌 정보 출력
}

void Account::makeDeposit( int deposit )	// 예금
{
	_totalAmount += deposit;	// 총 예금액에 예금액 추가
	_amount += deposit;			// 계좌 예금액에 예금액 추가
	_nbDeposits++;				// 예금 횟수 증가
	_totalNbDeposits++;			// 총 예금 횟수 증가

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << (_amount - deposit) << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal )	// 인출
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";";

	if(withdrawal > _amount) // 인출액이 예금액보다 크면
	{
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
	else 
	{
		_amount -= withdrawal; // 계좌 예금액에서 인출액 차감
		_totalAmount -= withdrawal; // 총 예금액에서 인출액 차감
		_nbWithdrawals++; // 인출 횟수 증가
		_totalNbWithdrawals++; // 총 인출 횟수 증가

		std::cout << "withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return true;
	}
}

int Account::checkAmount( void ) const 
{
	return _amount;
}

void Account::displayStatus( void ) const 
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos( void ) 
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp( void )
{
	std::time_t t = std::time(0);									// 현재 시간을 초 단위로 얻기
	std::tm tm = *std::localtime(&t);								// std::localtime은 주어진 시간 (t)을 로컬 시간대의 tm 구조체로 변환함. tm 구조체는 시간을 나타내기 위한 다양한 필드 (예: 년, 월, 일, 시, 분, 초)를 가지고 있음
	std::cout << "[" << (tm.tm_year + 1900)							// tm.tm_year는 1900년부터의 년도를 나타내므로 년도는 1900년을 더해야 함
		<< std::setfill('0') << std::setw(2) << (tm.tm_mon + 1)		// 월은 0부터 시작하므로 1을 더해야 함
		<< std::setfill('0') << std::setw(2) << tm.tm_mday << "_"	// 일
		<< std::setfill('0') << std::setw(2) << tm.tm_hour			// 시
		<< std::setfill('0') << std::setw(2) << tm.tm_min			// 분
		<< std::setfill('0') << std::setw(2) << tm.tm_sec << "] ";	// 초
}

int Account::getNbAccounts( void )
{
    return _nbAccounts;
}

int Account::getTotalAmount( void )
{
    return _totalAmount;
}

int Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}

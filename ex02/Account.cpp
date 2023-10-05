/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:20:32 by axcallet          #+#    #+#             */
/*   Updated: 2023/09/11 18:23:34 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	this->_displayTimestamp();
	std::cout << "index:" << this->_nbAccounts 
			<< ";amount:" << initial_deposit 
			<< ";created" << std::endl;
	this->_accountIndex  = this->_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_nbAccounts++;
	this->_totalAmount += initial_deposit;
	return ;
}

Account::~Account(void) {
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";closed" << std::endl;
	this->_nbAccounts--;
	return ;
}

void	Account::_displayTimestamp(void) {
	std::time_t currentTime;
	std::time(&currentTime);
	std::tm* localTime;
	localTime = std::localtime(&currentTime);

	std::cout << "[" << std::setw(4) << std::setfill('0') << (localTime->tm_year + 1900)
			<< std::setw(2) << std::setfill('0') << (localTime->tm_mon + 1)
			<< std::setw(2) << std::setfill('0') << localTime->tm_mday
			<< "_"
			<< std::setw(2) << std::setfill('0') << localTime->tm_hour
			<< std::setw(2) << std::setfill('0') << localTime->tm_min
			<< std::setw(2) << std::setfill('0') << localTime->tm_sec
			<< "] " << std::flush;
	return 	;
}

void	Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";total:"
			<< Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits
			<< ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
	return ;
}

void	Account::displayStatus(void) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			 << ";amount:" << this->_amount
			 << ";deposits:" << this->_nbDeposits
			 << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit) {
	int	p_amount = this->_amount;

	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			 << ";p_amount:" << p_amount
			 << ";deposit:" << deposit
			 << ";amount:" << this->_amount
			 << ";nb_deposits:" << this->_nbDeposits << std::endl;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal) {
	int	p_amount = this->_amount;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			 << ";p_amount:" << p_amount << ";withdrawal:";
	if (this->_amount - withdrawal < 0) {
		std::cout << "refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	std::cout << withdrawal
				<< ";amount:" << this->_amount
				<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return (true);
}

int		Account::checkAmount(void) const {
	return (this->_amount);
}

int	Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return (_totalAmount);
}

int	Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}
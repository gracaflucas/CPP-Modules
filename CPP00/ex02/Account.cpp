/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:32:26 by marvin            #+#    #+#             */
/*   Updated: 2025/05/02 13:32:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int     Account::_nbAccounts = 0;
int     Account::_totalAmount = 0;
int     Account::_totalNbDeposits = 0;
int     Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) {
    this->_accountIndex = _nbAccounts;
    _nbAccounts += 1;
    this->_amount = initial_deposit;
    _totalAmount += this->_amount;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::~Account( void ) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

void	Account::makeDeposit( int deposit ) {
    _displayTimestamp();
    int p_amount = _amount;
    _amount += deposit;
    _nbDeposits += 1;
    _totalNbDeposits += 1;
    _totalAmount += deposit;
    std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount
              << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:"
              << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
    _displayTimestamp();
    int p_amount = _amount;
    std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";withdrawal:";
    if (withdrawal > _amount) {
        std::cout << "refused\n";
        return false;
    }    
    _amount -= withdrawal;
    _nbWithdrawals += 1;
    _totalNbWithdrawals += 1;
    _totalAmount -= withdrawal;
    std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

void    Account::displayAccountsInfos( void ) {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:"
              << _totalAmount << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus( void ) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:"
              << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void    Account::_displayTimestamp( void ) {
    std::time_t now = std::time(NULL);
    std::tm *ltm = std::localtime(&now);
    std::cout << "[" << (ltm->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << ltm->tm_mon + 1
              << std::setw(2) << std::setfill('0') << ltm->tm_mday
              << "_"
              << std::setw(2) << std::setfill('0') << ltm->tm_hour
              << std::setw(2) << std::setfill('0') << ltm->tm_min
              << std::setw(2) << std::setfill('0') << ltm->tm_sec
              << "] ";
}

int     Account::getNbAccounts( void ) {
    return _nbAccounts;
}

int     Account::getTotalAmount( void ) {
    return _totalAmount;
}

int     Account::getNbDeposits( void ) {
    return _totalNbDeposits;
}

int     Account::getNbWithdrawals( void ) {
    return _totalNbWithdrawals;
}

int		Account::checkAmount( void ) const {
    return _amount;
}

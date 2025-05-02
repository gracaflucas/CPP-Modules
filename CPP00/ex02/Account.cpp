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

int     Account::getNbAccounts( void ) {
    return _nbAccounts;
}

int     Account::getTotalAmount( void ) {
    return _totalAmount;
}

int     Account::getNbDeposits( void ) {
    return _nbDeposits;
}

int     Account::getNbWithdrawals( void ) {
    return _nbWithdrawals;
}

void    Account::displayAccountsInfos( void ) {

}

Account::Account( int initial_deposit ) {

}
Account::~Account( void ) {

}

void	Account::makeDeposit( int deposit ) {

}

bool	Account::makeWithdrawal( int withdrawal ) {

}

int		Account::checkAmount( void ) const {

}

void	Account::displayStatus( void ) const {

}
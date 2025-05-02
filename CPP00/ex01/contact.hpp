/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:52:48 by marvin            #+#    #+#             */
/*   Updated: 2025/04/30 16:52:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <cctype>
# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>

class Contact {

    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string number;
        std::string darkestSecret;
    
    public:
        Contact();
        ~Contact();
        void        setContact();
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickname() const;
        std::string getNumber() const;
        std::string getDarkestSecret() const;
};

bool        getNonEmptyInput(const std::string prompt, std::string& input);
bool        isNumeric(const std::string number);
std::string formatField(const std::string& field);

#endif

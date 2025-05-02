/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:45:26 by lufiguei          #+#    #+#             */
/*   Updated: 2025/05/02 12:52:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "contact.hpp"

class   PhoneBook {

    private:
        Contact contacts[8];
        int     totalContacts;
        int     index;

    public:
        PhoneBook();
        ~PhoneBook();
        void    addContact();
        int     getTotalContacts() const;
        void    displayContact() const;
        void    displayContactDetails(int index) const;
};

#endif

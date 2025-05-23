/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:45:26 by lufiguei          #+#    #+#             */
/*   Updated: 2025/04/30 12:45:27 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"

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

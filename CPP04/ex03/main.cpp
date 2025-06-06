/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:40:05 by marvin            #+#    #+#             */
/*   Updated: 2025/05/26 14:40:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

int main() {
   IMateriaSource* src = new MateriaSource();
   src->learnMateria(new Ice());
   src->learnMateria(new Cure());
   ICharacter* me = new Character("me");
   AMateria* tmp;
   tmp = src->createMateria("ice");
   me->equip(tmp);
   tmp = src->createMateria("cure");
   me->equip(tmp);
   ICharacter* bob = new Character("bob");
   me->use(0, *bob);
   me->use(1, *bob);
   delete bob;
   delete me;
   delete src;
   return 0;
}
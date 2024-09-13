/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:58:09 by tsurma            #+#    #+#             */
/*   Updated: 2024/09/13 16:02:14 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern( void ) {
  std::cout << "\033[34mIntern created\033[0m" << std::endl;
}

Intern::Intern( Intern& other ) {
	*this = other;
}

Intern& Intern::operator=(Intern& other) {
	if (this == &other) { return(*this); }
	return (*this);
}

Intern::~Intern() { std::cout << "\033[34mIntern destructed\033[0m" << std::endl; }

AForm* Intern::makeFormShrub(std::string target) {
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeFormRobo(std::string target) {
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makeFormPresi(std::string target) {
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string name, std::string target) {

	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*ptrs[3])(std::string) = {&Intern::makeFormShrub, &Intern::makeFormRobo, &Intern::makeFormPresi};
	for (int i = 0; i < 3; ++i)
		if (name == forms[i]) {
			std::cout << "Intern created " << forms[i] << " form" << std::endl;
			return (this->*ptrs[i])(target);
		}
	std::cout << name << " isn't a valid form." << std::endl;
	return (NULL);
}

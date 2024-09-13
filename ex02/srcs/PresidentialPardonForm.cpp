/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:32:03 by tsurma            #+#    #+#             */
/*   Updated: 2024/09/13 14:46:27 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

// PresidentialPardonForm::PresidentialPardonForm() {}

void PresidentialPardonForm::process( void ) const {
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", 25, 5) {
	this->_target = target;
	std::cout << "\033[34m" << this->getName() << "\twas created.\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& other)
	: AForm(other) {}

PresidentialPardonForm& PresidentialPardonForm::operator=( PresidentialPardonForm& other ) {
	if (this == &other) {return(*this);}
	this->setName(other.getName());
	this->setSigned(other.isSigned());
	this->setReqGradeSign(other.getRequiredGradeSign());
	this->setReqGradeExec(other.getRequiredGradeExec());
	this->_target = other._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << "\033[34mPardon\t" << this->getName() << "\twas destructed.\033[0m" << std::endl;
}

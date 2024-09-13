/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:01:42 by tsurma            #+#    #+#             */
/*   Updated: 2024/09/13 14:46:51 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

// RobotomyRequestForm::RobotomyRequestForm() {}

void RobotomyRequestForm::process( void ) const {
	static bool rng;
	rng ? (std::cout << "DRRRR BRRR CHONK CHONK " << this->_target << " has been robotomized" << std::endl) : (std::cout << "DRRR BRRR ... oh no, the robotomy on " << this->_target << " failed!" << std::endl);
	rng = !rng;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45) {
	this->_target = target;
	std::cout << "\033[34m" << this->getName() << "\twas created.\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& other)
	: AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=( RobotomyRequestForm& other ) {
	if (this == &other) {return(*this);}
	this->setName(other.getName());
	this->setSigned(other.isSigned());
	this->setReqGradeSign(other.getRequiredGradeSign());
	this->setReqGradeExec(other.getRequiredGradeExec());
	this->_target = other._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << "\033[34mRobot\t" << this->getName() << "\twas destructed.\033[0m" << std::endl;
}

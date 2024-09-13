/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:27:03 by tsurma            #+#    #+#             */
/*   Updated: 2024/09/13 14:47:22 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

// ShrubberyCreationForm::ShrubberyCreationForm() {}

void ShrubberyCreationForm::process( void ) const {
	std::string name;
	name = this->_target + "_shrubbery";
	std::ofstream outfile (name.c_str());
	outfile <<
"      ccee88oo\n"
"  C8O8O8Q8PoOb o8oo\n"
" dOB69QO8PdUOpugoO9bD\n"
"CgggbU8OU qOp qOdoUOdcb\n"
"    6OuU  /p u gcoUodpP\n"
"      \\\\//  /douUP\n"
"        \\\\////\n"
"         |||/\\\n"
"         |||\\/\n"
"         |||||\n"
"   .....//||||\\...." << std::endl;
	outfile.close();
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137) {
	this->_target = target;
	std::cout << "\033[34m" << this->getName() << "\twas created.\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other)
	: AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( ShrubberyCreationForm& other ) {
	if (this == &other) {return(*this);}
	this->setName(other.getName());
	this->setSigned(other.isSigned());
	this->setReqGradeSign(other.getRequiredGradeSign());
	this->setReqGradeExec(other.getRequiredGradeExec());
	this->_target = other._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
  std::cout << "\033[34mShrub\t" << this->getName() << "\twas destructed.\033[0m" << std::endl;
}

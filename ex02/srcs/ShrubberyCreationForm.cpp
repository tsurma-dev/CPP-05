/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:27:03 by tsurma            #+#    #+#             */
/*   Updated: 2024/09/11 18:33:11 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

// ShrubberyCreationForm::ShrubberyCreationForm() {}

void ShrubberyCreationForm::process( void ) const {

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137) {
	this->_target = target;
	std::cout << "ShrubberyCreationForm\t" << this->getName() << "\twas created."
            << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other)
	: AForm(other) {
		this->_target = other._target;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm\t" << this->getName() << "\twas destructed." << std::endl;
}


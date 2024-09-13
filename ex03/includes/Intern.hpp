/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:52:55 by tsurma            #+#    #+#             */
/*   Updated: 2024/09/13 15:59:48 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP_
#define INTERN_HPP_

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern {
private:
	AForm *makeFormShrub(std::string target);
	AForm *makeFormRobo(std::string target);
	AForm *makeFormPresi(std::string target);
public:
	Intern( void );
	Intern( Intern& other );
	Intern& operator=( Intern& other );
	~Intern();

	AForm* makeForm( std::string name, std::string target );
};

#endif

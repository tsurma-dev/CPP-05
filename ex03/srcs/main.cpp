/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:15:55 by tsurma            #+#    #+#             */
/*   Updated: 2024/09/13 15:56:45 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main(void) {
	Intern a;
	Intern b(a);
	Intern c = a;
	Bureaucrat vip("VIP", 5);

	AForm *array[3];

	array[0] = a.makeForm("shrubbery creation", "Home");
	array[1] = b.makeForm("robotomy request", "Bender");
	array[2] = c.makeForm("garglblargl", "NOPE");
	vip.signForm(*(array[1]));
	vip.excecuteForm(*(array[1]));
	delete array[0];
	delete array[1];
	delete array[2];
}

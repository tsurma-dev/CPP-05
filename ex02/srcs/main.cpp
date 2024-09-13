/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:15:55 by tsurma            #+#    #+#             */
/*   Updated: 2024/09/13 14:38:46 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main(void) {
	Bureaucrat	hermes("Hermes", 20);
	Bureaucrat	vip("VIP", 5);
	ShrubberyCreationForm shrub("Home");
	RobotomyRequestForm robb("Subject");
	PresidentialPardonForm pres("Person");

	hermes.signForm(shrub);
	hermes.excecuteForm(shrub);
	hermes.signForm(robb);
	hermes.excecuteForm(robb);
	hermes.excecuteForm(robb);
	hermes.excecuteForm(robb);
	hermes.signForm(pres);
	vip.excecuteForm(pres);
}

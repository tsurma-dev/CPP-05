/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:15:55 by tsurma            #+#    #+#             */
/*   Updated: 2024/09/11 18:22:12 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Bureaucrat.hpp"

int main(void) {
	Bureaucrat	hermes("Hermes", 30);
	ShrubberyCreationForm help("nothing");
	hermes.signForm(help);
	ShrubberyCreationForm aah(help);
	std::cout << help << std::endl;
	std::cout << aah << std::endl;

}

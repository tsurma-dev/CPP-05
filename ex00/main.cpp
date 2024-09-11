/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:15:55 by tsurma            #+#    #+#             */
/*   Updated: 2024/09/11 13:23:35 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
	Bureaucrat a("Hermes", 1);
	Bureaucrat b("Else", 100);

	try {
		std::cout << b;
		a.incrGrade();
	}
	catch (std::exception & e) {
		std::cout << "Unscheduled Screaming from wrong Forms" << std::endl;
	}
	std::cout << a;
}

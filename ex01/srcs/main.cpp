/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:15:55 by tsurma            #+#    #+#             */
/*   Updated: 2024/09/11 17:01:59 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

int main(void) {
	Bureaucrat	hermes("Hermes", 30);
	Form		a38("A38", 29, 29);

	hermes.signForm(a38);
	std::cout << a38 << std::endl;
	hermes.incrGrade();
	hermes.signForm(a38);
	std::cout << a38 << std::endl;

}

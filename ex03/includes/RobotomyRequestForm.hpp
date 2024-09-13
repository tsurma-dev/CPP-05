/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:00:02 by tsurma            #+#    #+#             */
/*   Updated: 2024/09/13 15:58:29 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_HPP_
#define ROBOTOMY_HPP_

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	RobotomyRequestForm();
	//Executing
	void process( void ) const;
public:
	//orthodox canonical form
	RobotomyRequestForm( std::string target );
	RobotomyRequestForm( RobotomyRequestForm& other );
	RobotomyRequestForm& operator=(RobotomyRequestForm& other);
	~RobotomyRequestForm();
};

#endif

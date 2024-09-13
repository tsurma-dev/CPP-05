/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:21:17 by tsurma            #+#    #+#             */
/*   Updated: 2024/09/13 15:58:32 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_HPP_
#define SHRUBBERY_HPP_

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
	ShrubberyCreationForm();
	//Executing
	void process( void ) const;
public:
	//orthodox canonical form
	ShrubberyCreationForm( std::string target );
	ShrubberyCreationForm( ShrubberyCreationForm& other );
	ShrubberyCreationForm& operator=(ShrubberyCreationForm& other);
	~ShrubberyCreationForm();
};

#endif

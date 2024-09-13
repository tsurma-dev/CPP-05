/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:31:05 by tsurma            #+#    #+#             */
/*   Updated: 2024/09/13 14:31:44 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARDON_HPP_
#define PARDON_HPP_

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	PresidentialPardonForm();
	//Executing
	void process( void ) const;
public:
	//orthodox canonical form
	PresidentialPardonForm( std::string target );
	PresidentialPardonForm( PresidentialPardonForm& other );
	PresidentialPardonForm& operator=(PresidentialPardonForm& other);
	~PresidentialPardonForm();
};

#endif

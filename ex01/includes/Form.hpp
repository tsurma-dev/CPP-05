/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:32:56 by tsurma            #+#    #+#             */
/*   Updated: 2024/09/11 16:48:02 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP_
#define FORM_HPP_

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string	_name;
	bool				_signed;
	const int			_reqGradeSign;
	const int			_reqGradeExec;
	Form();
public:
	//orthodox canonical Form
	Form( std::string name, int sign, int exec );
	Form( const Form& other );
	Form& operator=( const Form& other );
	~Form();

	//Getter Functions
	std::string getName( void ) const;
	bool isSigned( void ) const;
	int getRequiredGradeSign( void ) const;
	int getRequiredGradeExec( void ) const;

	//Signing
	void beSigned( Bureaucrat& signer);

	//Exceptions
  class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

  class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

	std::ostream& operator<<(std::ostream& os, Form& other);


#endif

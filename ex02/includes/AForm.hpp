/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:32:56 by tsurma            #+#    #+#             */
/*   Updated: 2024/09/11 18:34:17 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP_
#define AFORM_HPP_

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string	_name;
	bool				_signed;
	const int			_reqGradeSign;
	const int			_reqGradeExec;
	AForm();
	virtual void process() const = 0;
protected:
	std::string	_target;
public:
	//orthodox canonical Form
	AForm( std::string name, int sign, int exec );
	AForm( const AForm& other );
	AForm& operator=( const AForm& other );
	virtual ~AForm();

	//Getter Functions
	std::string getName( void ) const;
	bool isSigned( void ) const;
	int getRequiredGradeSign( void ) const;
	int getRequiredGradeExec( void ) const;

	//Signing
	void beSigned( Bureaucrat& signer);
	void execute(Bureaucrat const & executor) const;

	//Exceptions
  class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

  class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class NotSignedException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

	std::ostream& operator<<(std::ostream& os, AForm& other);


#endif

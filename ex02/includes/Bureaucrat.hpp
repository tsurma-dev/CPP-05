/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:24:48 by tsurma            #+#    #+#             */
/*   Updated: 2024/09/13 12:49:05 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
private:
	const std::string	_name;
	int					_grade;
	Bureaucrat();

public:
	// orthodox canonical form
	Bureaucrat( std::string name, int grade );
	Bureaucrat( const Bureaucrat& other );
	Bureaucrat& operator=( const Bureaucrat& other );
	~Bureaucrat();

	// getter functions
	std::string getName( void ) const;
	int getGrade( void ) const;

	// grade incr and decr functions
	void incrGrade( void );
	void decrGrade( void );

	//Actions
	void signForm( AForm& form );
	void excecuteForm( AForm const & form);

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
	std::ostream& operator<<(std::ostream& os, Bureaucrat& other);

#endif

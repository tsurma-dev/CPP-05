/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:33:08 by tsurma            #+#    #+#             */
/*   Updated: 2024/09/11 17:03:35 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include <exception>

// Form::Form( void ) {}

Form::Form( std::string name, int sign, int exec ) : _name(name), _signed(false), _reqGradeSign(sign), _reqGradeExec(exec) {
	if (_reqGradeExec < 1 || _reqGradeSign < 1)
		throw Form::GradeTooHighException();
	if (_reqGradeExec > 155 || _reqGradeSign > 155)
		throw Form::GradeTooLowException();
	std::cout << "Form\t" << _name << "\twas created." << std::endl;
}

Form::Form(const Form& other) : _name(other.getName()),  _signed(other.isSigned()), _reqGradeSign(other.getRequiredGradeSign()), _reqGradeExec(other.getRequiredGradeExec()) {
}

Form& Form::operator=(const Form& other) {
	if (this == &other) {return(*this);}
	(std::string)this->_name = other._name;
	this->_signed = other.isSigned();
	const_cast<int&>(_reqGradeSign) = other.getRequiredGradeSign();
	const_cast<int&>(_reqGradeExec) = other.getRequiredGradeExec();
	return (*this);
}

Form::~Form() {
	std::cout << "Form\t" << _name << "\twas destructed." << std::endl;
}

std::string Form::getName(void) const {
	return (this->_name);
}

bool Form::isSigned(void) const {
  return (_signed);
}

int Form::getRequiredGradeSign(void) const {
	return (_reqGradeSign);
}

int Form::getRequiredGradeExec(void) const {
	return (_reqGradeExec);
}

void Form::beSigned(Bureaucrat& signer) {
	if (signer.getGrade() > this->_reqGradeSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

std::ostream& operator<<(std::ostream& os, Form& other) {
  return (os << "Form: " << other.getName() << "\nSigned:" << (other.isSigned() ? "true" : "false") << "\nRequired Grade to sign: " << other.getRequiredGradeSign() << "\nRequired Grade to execute: " << other.getRequiredGradeExec());
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}

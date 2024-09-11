/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:33:08 by tsurma            #+#    #+#             */
/*   Updated: 2024/09/11 18:20:45 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include <exception>

// Form::Form( void ) {}

AForm::AForm( std::string name, int sign, int exec ) : _name(name), _signed(false), _reqGradeSign(sign), _reqGradeExec(exec) {
	if (_reqGradeExec < 1 || _reqGradeSign < 1)
		throw AForm::GradeTooHighException();
	if (_reqGradeExec > 155 || _reqGradeSign > 155)
		throw AForm::GradeTooLowException();
	std::cout << "Form\t" << _name << "\twas created." << std::endl;
}

AForm::AForm(const AForm& other) : _name(other.getName()),  _signed(other.isSigned()), _reqGradeSign(other.getRequiredGradeSign()), _reqGradeExec(other.getRequiredGradeExec()) {
}

AForm& AForm::operator=(const AForm& other) {
	if (this == &other) {return(*this);}
	(std::string)this->_name = other._name;
	this->_signed = other.isSigned();
	const_cast<int&>(_reqGradeSign) = other.getRequiredGradeSign();
	const_cast<int&>(_reqGradeExec) = other.getRequiredGradeExec();
	return (*this);
}

AForm::~AForm() {
	std::cout << "Form\t" << _name << "\twas destructed." << std::endl;
}

std::string AForm::getName(void) const {
	return (this->_name);
}

bool AForm::isSigned(void) const {
  return (_signed);
}

int AForm::getRequiredGradeSign(void) const {
	return (_reqGradeSign);
}

int AForm::getRequiredGradeExec(void) const {
	return (_reqGradeExec);
}

void AForm::beSigned(Bureaucrat& signer) {
	if (signer.getGrade() > this->_reqGradeSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

void AForm::execute(Bureaucrat const& executor) const {
	if (this->_signed == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->_reqGradeExec)
		throw AForm::GradeTooLowException();
	this->process();
}

std::ostream& operator<<(std::ostream& os, AForm& other) {
  return (os << "Form: " << other.getName() << "\nSigned:" << (other.isSigned() ? "true" : "false") << "\nRequired Grade to sign: " << other.getRequiredGradeSign() << "\nRequired Grade to execute: " << other.getRequiredGradeExec());
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}

const char* AForm::NotSignedException::what() const throw() {
	return ("Form is not signed!");
}

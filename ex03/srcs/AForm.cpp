/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:33:08 by tsurma            #+#    #+#             */
/*   Updated: 2024/09/13 14:45:02 by tsurma           ###   ########.fr       */
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
  std::cout << "\033[34mForm\t" << _name << "\twas created.\033[0m" << std::endl;
}

AForm::AForm(const AForm& other) : _name(other.getName()),  _signed(other.isSigned()),
	_reqGradeSign(other.getRequiredGradeSign()), _reqGradeExec(other.getRequiredGradeExec()), _target(other._target) {
}

AForm& AForm::operator=(const AForm& other) {
	if (this == &other) {return(*this);}
	this->setName(other.getName());
	this->setSigned(other.isSigned());
	this->setReqGradeSign(other.getRequiredGradeSign());
	this->setReqGradeExec(other.getRequiredGradeExec());
	this->_target = other._target;
	return (*this);
}

AForm::~AForm() {
	std::cout << "\033[34mForm\t" << _name << "\twas destructed.\033[0m" << std::endl;
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

void AForm::setName(const std::string name) {
	const_cast<std::string&>(_name) = name;
}

void AForm::setSigned(const bool sign) {
	_signed = sign;
}

void AForm::setReqGradeSign(const int grade) {
	const_cast<int&>(_reqGradeSign) = grade;
}

void AForm::setReqGradeExec(const int grade) {
	const_cast<int&>(_reqGradeExec) = grade;
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

//Exceptions
const char* AForm::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}

const char* AForm::NotSignedException::what() const throw() {
	return ("Form is not signed!");
}

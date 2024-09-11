/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:36:22 by tsurma            #+#    #+#             */
/*   Updated: 2024/09/11 13:22:41 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	std::cout << "Bereaucrat\t" << _name << "\twith grade\t" << _grade << " created" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this == &other) return(*this);
	(std::string)this->_name = other.getName();
	this->_grade = other.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat\t" << _name << " destructed" << std::endl;
}

const std::string& Bureaucrat::getName(void) const {
	return (this->_name);
}

const int& Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void Bureaucrat::incrGrade(void) {
	if (this->_grade <= 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	this->_grade--;
}

void Bureaucrat::decrGrade(void) {
	if (this->_grade >= 155) {
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade++;
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& other) {
	return (os << other.getName() << ", bureaucrat grade " << other.getGrade() << "." << std::endl);
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Grade too High!\n");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Grade too Low!\n");
}


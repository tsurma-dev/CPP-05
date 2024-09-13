/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:36:22 by tsurma            #+#    #+#             */
/*   Updated: 2024/09/13 15:03:43 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include <exception>

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (_grade > 155)
		throw Bureaucrat::GradeTooLowException();
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	std::cout << "\033[34mBureaucrat\t" << _name << "\twith grade\t" << _grade << " created\033[0m" << std::endl;
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
	std::cout << "\033[34mBureaucrat\t" << _name << " destructed\033[0m" << std::endl;
}

std::string Bureaucrat::getName(void) const {
	return (this->_name);
}

int Bureaucrat::getGrade(void) const {
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

void Bureaucrat::signForm( AForm& form ) {
	try {
		form.beSigned(*this);
	} catch (std::exception& e) {
		std::cout << this->_name << "\tcouldn't sign " << form.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << this->_name << "\tsigned " << form.getName() << std::endl;
}

void Bureaucrat::excecuteForm(AForm const& form) {
	try {
		form.execute(*this);
	} catch (std::exception& e) {
		std::cout << this->_name << "\tcouldn't execute " << form.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << this->_name << "\texecuted " << form.getName() << std::endl;
}


std::ostream& operator<<(std::ostream& os, Bureaucrat& other) {
  return (os << other.getName() << ", bureaucrat grade " << other.getGrade()
             << ".");
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Grade too High!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Grade too Low!");
}


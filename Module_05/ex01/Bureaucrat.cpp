/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:36:09 by kfaustin          #+#    #+#             */
/*   Updated: 2023/09/02 15:44:19 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const std::string Bureaucrat::type = "Bureaucrat";

Bureaucrat::Bureaucrat(void) : _name("Generic"), _grade(150) {
	std::cout << this->type << " " << this->_name << " default constructor called\n";
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << this->type << " " << this->_name << " destructor called\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	this->setGrade(grade);
	std::cout << this->type << " " << this->_name << " constructor overload called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade) {
	std::cout << this->type << " " << this->_name << " copy constructor called\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& src) {
	if (this != &src) {
		const_cast<std::string&>(this->_name) = src._name; // You should not use const_cast to modify a const object unless you are certain that the original object was not originally declared as const.
		this->_grade = src._grade;
	}
	std::cout << this->type << " " << this->_name << " copy assignment called\n";
	return (*this);
}

const std::string Bureaucrat::getName(void) const {
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void	Bureaucrat::setGrade(int grade) {
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

void	Bureaucrat::incrementGrade(void) {
	if (this->_grade > 1)
		this->_grade -= 1;
	else
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade(void) {
	if (this->_grade < 150)
		this->_grade += 1;
	else
		throw Bureaucrat::GradeTooLowException();
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Bureaucrat EXCEPTION: Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Bureaucrat EXCEPTION> Grade too low");
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& src) {
	os << src.getName() << ", " << src.type << " grade " << src.getGrade() << std::endl;
	return (os);
}

void	Bureaucrat::signForm(Bureaucrat& bureaucrat, bool sign) const {
	if (sign)
		std::cout << bureaucrat._name << " signed " << "a form" << std::endl;
	else
		std::cout << bureaucrat._name << " couldn't sign " << "a form because of his grade" << std::endl;
}

void	Bureaucrat::signForm(Bureaucrat& bureaucrat, Form& form) const {
	if (form.getSign())
		std::cout << bureaucrat._name << " signed " << form.getName() << std::endl;
	else
		std::cout << bureaucrat._name << " couldn't sign " << form.getName() << " because of his grade" << std::endl;
}
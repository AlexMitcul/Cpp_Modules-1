/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:32:16 by kfaustin          #+#    #+#             */
/*   Updated: 2023/09/02 20:32:16 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:20:25 by kfaustin          #+#    #+#             */
/*   Updated: 2023/09/02 19:51:22 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const std::string	AForm::type = "AForm";

int	AForm::checkGradeRange(int value) {
	if (value < 1)
		throw (AForm::GradeTooHighException());
	else if (value > 150)
		throw (AForm::GradeTooLowException());
	return (value);
}

AForm::AForm(void) : _name("Generic"), _isSigned(false), _gradeToSign(150), _gradeToexecute(150) {
	std::cout << type << " " << this->_name << " default constructor called" << std::endl;
}

AForm::~AForm(void) {
	std::cout << type << " " << this->_name << " destructor called" << std::endl;
}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_execute) : _name(name), _isSigned(false), _gradeToSign(grade_to_sign), _gradeToexecute(grade_to_execute) {
	//this->_gradeToSign = checkGradeRange(grade_to_sign); // This constructor must be called with a try catch to avoid grade out of range
	//this->_gradeToexecute = checkGradeRange(grade_to_execute);
	std::cout << type << " " << this->_name << " constructor overload called" << std::endl;
}

AForm::AForm(const AForm& src) : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToexecute(src._gradeToexecute) {
	// const data member must be initialized on the list initializer.
	std::cout << type << " " << this->_name << " copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &src) {
	/*if (this != &src) { // copy assignment doing nothing, because const data members.
		const_cast<std::string&>(this->_name) = src._name;
		this->_isSigned = src._isSigned;
		this->_gradeToSign = src._gradeToSign;
		this->_gradeToexecute = src._gradeToexecute;
	}*/
	std::cout << type << " " << this->_name << " copy constructor called" << std::endl;
	return (*this);
}

const std::string	AForm::getName(void) const {
	return (this->_name);
}

bool	AForm::getSign(void) const {
	return (this->_isSigned);
}

const int	AForm::getGradeTosign(void) const {
	return (this->_gradeToSign);
}

const int	AForm::getGradeToExecute(void) const {
	return (this->_gradeToexecute);
}

void	AForm::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->getGradeTosign())
		this->_isSigned = true;
	else
		throw (AForm::GradeTooLowException());
	bureaucrat.signForm(bureaucrat, this->_isSigned);
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("AForm EXCEPTION> Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("AForm EXCEPTION> Grade is too low");
}

const char* AForm::FormNotSignedException::what() const throw() {
	return ("AForm EXCEPTION> AForm was not sign");
}

std::ostream& operator<<(std::ostream& os, AForm& src) {
	os << src.getName() << ", " << src.type << " grade " << src.getGradeTosign() << ", " << src.getGradeToExecute() << std::endl;
	return (os);
}
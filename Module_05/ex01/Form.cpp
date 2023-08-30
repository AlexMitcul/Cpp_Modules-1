/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:20:25 by kfaustin          #+#    #+#             */
/*   Updated: 2023/08/30 12:48:00 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const std::string	Form::type = "Form";

int	Form::checkGradeRange(int value) {
	if (value < 1)
		throw (Form::GradeTooHighException());
	else if (value > 150)
		throw (Form::GradeTooLowException());
	return (value);

}

Form::Form(void) : _name("Generic Form"), _isSigned(false), _gradeToSign(150), _gradeToexecute(150) {
	std::cout << type << " " << this->_name << " default constructor called" << std::endl;
}

Form::~Form(void) {
	std::cout << type << " " << this->_name << " destructor called" << std::endl;
}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute) : _name(name), _isSigned(false), _gradeToSign(grade_to_sign), _gradeToexecute(grade_to_execute) {
	//this->_gradeToSign = checkGradeRange(grade_to_sign);
	//this->_gradeToexecute = checkGradeRange(grade_to_execute);
	std::cout << type << " " << this->_name << " constructor overload called" << std::endl;
}

Form::Form(const Form& src) : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToexecute(src._gradeToexecute) {
	/*if (this != &src) {
		// *this = src;
		this->_name = src._name;
		this->_isSigned = src._isSigned;
		this->_gradeToSign = src._gradeToSign;
		this->_gradeToexecute = src._gradeToexecute;
	}*/
	std::cout << type << " " << this->_name << " copy constructor called" << std::endl;
}

/*Form &Form::operator=(const Form &src) {
	if (this != &src) {
		// *this = src;
		const_cast<std::string&>(this->_name) = src._name;
		this->_isSigned = src._isSigned;
		this->_gradeToSign = src._gradeToSign;
		this->_gradeToexecute = src._gradeToexecute;
	}
	std::cout << type << " " << this->_name << " copy constructor called" << std::endl;
	return (*this);
}*/

const std::string	Form::getName(void) const {
	return (this->_name);
}

bool	Form::getSign(void) const {
	return (this->_isSigned);
}

const int	Form::getGradeTosign(void) const {
	return (this->_gradeToSign);
}

const int	Form::getGradeToExecute(void) const {
	return (this->_gradeToexecute);
}

void	Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->getGradeTosign())
		this->_isSigned = true;
	else
		throw (Form::GradeTooLowException());
	bureaucrat.signForm(bureaucrat, this->_isSigned);
}

/*void	Form::setGradeToSign(int grade_to_sign) {
	if (grade_to_sign < 1) {
		throw(Form::GradeTooHighException());
		this->_gradeToSign = 150;
	}
	else if (grade_to_sign > 150) {
		throw(Form::GradeTooLowException());
		this->_gradeToSign = 150;
	}
	this->_gradeToSign = grade_to_sign;
}*/

const char* Form::GradeTooHighException::what() const throw() {
	return ("Form EXCEPTION> Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Form EXCEPTION> Grade is too low");
}

std::ostream& operator<<(std::ostream& os, Form& src) {
	os << src.getName() << ", " << src.type << " grade " << src.getGradeTosign() << ", " << src.getGradeToExecute() << std::endl;
	return (os);
}
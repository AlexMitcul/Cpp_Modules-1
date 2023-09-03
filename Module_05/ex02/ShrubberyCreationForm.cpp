/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:38:51 by kfaustin          #+#    #+#             */
/*   Updated: 2023/09/03 12:27:14 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

const std::string	ShrubberyCreationForm::type = "ShrubberyCreationForm";

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm(type, 145, 137), _target("Generic") {
	std::cout << this->type << " " << this->_target << " default constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << this->type << " " << this->_target << " destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm(type, 145, 137), _target(target) {
	std::cout << this->type << " " << this->_target << " constructor overload called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(type, 145, 137), _target(src._target) {
	std::cout << this->type << " " << this->_target << " copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
	if (this != &src)
		const_cast<std::string&>(this->_target) = src._target; // It isn't recommended
	std::cout << this->type << " " << this->_target << " copy assignment called" << std::endl;
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget(void) const {
	return (this->_target);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (executor.getGrade() > this->getGradeToExecute())
		throw Bureaucrat::GradeTooLowException();
	else if (!this->getSign())
		throw AForm::FormNotSignedException();
	else {
		std::ofstream outfile (this->getTarget().append("_shrubbery").c_str());
		outfile << "BIG ASCII TREE\n";
		outfile.close();
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& os, ShrubberyCreationForm& src) {
	os << src.type << " target: " << src.getTarget() << std::endl;
	return (os);
}

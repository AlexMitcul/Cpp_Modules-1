/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:07:54 by kfaustin          #+#    #+#             */
/*   Updated: 2023/09/03 18:54:21 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

const std::string	PresidentialPardonForm::type = "PresidentialPardonForm";

PresidentialPardonForm::PresidentialPardonForm(void) : AForm(type, 25, 5), _target("Generic") {
	std::cout << this->type << " " << this->_target << " default constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << this->type << " " << this->_target << " destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm(type, 25, 5), _target(target) {
	std::cout << this->type << " " << this->_target << " constructor overload called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(type, 25, 5), _target(src._target) {
	std::cout << this->type << " " << this->_target << " copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
	if (this != &src)
		const_cast<std::string&>(this->_target) = src._target; // It isn't recommended
	std::cout << this->type << " " << this->_target << " copy assignment called" << std::endl;
	return (*this);
}

std::string PresidentialPardonForm::getTarget(void) const {
	return (this->_target);
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (executor.getGrade() > this->getGradeToExecute())
		throw (Bureaucrat::GradeTooLowException());
	else if (!this->getSign())
		throw (AForm::FormNotSignedException());
	else {
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& os, PresidentialPardonForm& src) {
	os << src.type << " target: " << src.getTarget() << std::endl;
	return (os);
}
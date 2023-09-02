/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   robotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 22:03:13 by kfaustin          #+#    #+#             */
/*   Updated: 2023/09/02 22:15:47 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "robotomyRequestForm.hpp"

const std::string	RobotomyRequestForm::type = "RobotomyRequestForm";

RobotomyRequestForm::RobotomyRequestForm(void) : AForm(type, 72, 45), _target("Generic") {
	std::cout << this->type << " " << this->_target << " default constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << this->type << " " << this->_target << " destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm(type, 72, 45), _target(target) {
	std::cout << this->type << " " << this->_target << " constructor overload called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(type, 72, 45), _target(src._target) {
	std::cout << this->type << " " << this->_target << " copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
	if (this != &src)
		const_cast<std::string&>(this->_target) = src._target; // It isn't recommended
	std::cout << this->type << " " << this->_target << " copy assignment called" << std::endl;
	return (*this);
}

std::string RobotomyRequestForm::getTarget(void) const {
	return (this->_target);
}

static int	chance;

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (executor.getGrade() > this->getGradeToExecute())
		throw (Bureaucrat::GradeTooLowException());
	else if (!this->getSign())
		throw (AForm::FormNotSignedException());
	else {
		std::cout << "Drilling noise" << std::endl;
		if ((++chance)%2 == 0)
			std::cout << this->_target << " has been robotomized successfully" << std::endl;
		else
			std::cout << this->_target << " robotomy failed" << std::endl;
	}
}

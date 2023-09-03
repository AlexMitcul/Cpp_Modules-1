/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:01:46 by kfaustin          #+#    #+#             */
/*   Updated: 2023/09/03 22:22:19 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const std::string	Intern::type = "Intern";

Intern::Intern(void) {
	std::cout << this->type << " default constructor called" << std::endl;
}

Intern::~Intern(void) {
	std::cout << this->type << " destructor called" << std::endl;
}

Intern::Intern(const Intern& src) : Intern() {
	std::cout << this->type << " copy constructor called" << std::endl;
}

Intern&	Intern::operator=(const Intern &src) {
	std::cout << this->type << " copy assignment called" << std::endl;
	return (*this);
}

static AForm* doShrubbery(const std::string target) {
	return (new ShrubberyCreationForm{target});
}

static AForm* doRobot(const std::string target) {
	return (new RobotomyRequestForm{target});
}

static AForm* doPresident(const std::string target) {
	return (new PresidentialPardonForm{target});
}

AForm*	Intern::makeForm(const std::string form, const std::string target)
{
	AForm*				(*formFunc[])(const std::string target) = {&doShrubbery, &doRobot, &doPresident};
	const std::string	formForm[] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};

	for (int i = 0; i < 3; i++)
	{
		if (form == formForm[i]) {
			AForm* formCreated = formFunc[i](target);
			std::cout << "Intern creates " << form << std::endl;
			return (formCreated);
		}
	}
	std::cout << "Intern can't create " << form << std::endl;
	return (NULL);
}
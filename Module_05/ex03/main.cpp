/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:42:40 by kfaustin          #+#    #+#             */
/*   Updated: 2023/09/03 22:37:14 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main(void) {
	{ //Inter test
		{
			std::cout << "----- Intern Test (start)----" << std::endl;
			Bureaucrat				bur("Chopin", 1);
			Bureaucrat				noob;
			Intern 					var;
			AForm					*form;
			AForm					*form1;
			AForm					*form2;

			std::cout << std::endl;
			std::cout << std::endl;
			form = var.makeForm("Presidential Pardon","Generic");
			form1 = var.makeForm("Robotomy Request","Generic");
			form2 = var.makeForm("Shrubbery Creation","Generic");
			std::cout << std::endl;
			std::cout << *form;
			std::cout << *form1;
			std::cout << *form2;
			std::cout << std::endl;
			std::cout << std::endl;

			form->beSigned(bur);
			bur.executeForm(*form);
			form1->beSigned(bur);
			bur.executeForm(*form1);
			form2->beSigned(bur);
			bur.executeForm(*form2);
			try {
				form->beSigned(noob);
			}
			catch (std::exception& excp) {
				std::cout << excp.what() << std::endl;
			}
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "DEFAULT CONSTRUCTOR (end)-----" << std::endl;
			delete form;
			delete form1;
			delete form2;
		}
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:42:40 by kfaustin          #+#    #+#             */
/*   Updated: 2023/09/03 14:52:18 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "presidentialPardonForm.hpp"
#include "robotomyRequestForm.hpp"

int	main(void) {
	{ //Constructor test
		{
			std::cout << "----- DEFAULT CONSTRUCTOR (start)----" << std::endl;
			Bureaucrat 				bur;
			PresidentialPardonForm	pre;
			RobotomyRequestForm		rob;
			ShrubberyCreationForm	shr;

			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << bur;
			std::cout << pre;
			std::cout << rob;
			std::cout << shr;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "DEFAULT CONSTRUCTOR (end)-----" << std::endl;
		}
		{
			std::cout << "\n\n----- OVERLOAD CONSTRUCTOR (start)----" << std::endl;
			Bureaucrat 				bur("Chopin", 1);
			PresidentialPardonForm	pre("Target_1");
			RobotomyRequestForm		rob("Target_2");
			ShrubberyCreationForm	shr("Target_3");

			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << bur;
			std::cout << pre;
			std::cout << rob;
			std::cout << shr;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "OVERLOAD CONSTRUCTOR (end)-----" << std::endl;
		}
		{
			std::cout << "\n\n----- COPY CONSTRUCTOR (start)----" << std::endl;
			Bureaucrat 				bur("Chopin", 1);
			Bureaucrat 				bur1(bur);
			PresidentialPardonForm	pre("Target_1");
			PresidentialPardonForm	pre1(pre);
			RobotomyRequestForm		rob("Target_2");
			RobotomyRequestForm		rob1(rob);
			ShrubberyCreationForm	shr("Target_3");
			ShrubberyCreationForm	shr1(shr);

			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << bur << "copy: " << bur1;
			std::cout << pre << "copy: " << pre1;
			std::cout << rob << "copy: " << rob1;
			std::cout << shr << "copy: " << shr1;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "COPY CONSTRUCTOR (end)-----" << std::endl;
		}
		{
			std::cout << "\n\n----- COPY ASSIGNMENT (start)----" << std::endl;
			Bureaucrat 				bur("Chopin", 1);
			Bureaucrat 				bur1;
			PresidentialPardonForm	pre("Target_1");
			PresidentialPardonForm	pre1;
			RobotomyRequestForm		rob("Target_2");
			RobotomyRequestForm		rob1;
			ShrubberyCreationForm	shr("Target_3");
			ShrubberyCreationForm	shr1;

			std::cout << std::endl;
			bur1 = bur;
			pre1 = pre;
			rob1 = rob;
			shr1 = shr;
			std::cout << std::endl;
			std::cout << bur << "copy: " << bur1;
			std::cout << pre << "copy: " << pre1;
			std::cout << rob << "copy: " << rob1;
			std::cout << shr << "copy: " << shr1;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "COPY ASSIGNMENT (end)-----" << std::endl;
		}
	}
	std::cout << "\n\nCLASSES TEST (start)----" << std::endl;
	{
		{ // No exception
			std::cout << "\nNo Exception (start)----" << std::endl;

			try {
				Bureaucrat 				bur("Burocrata", 2);
				PresidentialPardonForm	pre("Marcelo form");
				RobotomyRequestForm		rob("Robozao");
				ShrubberyCreationForm	shr("Franz Schubert");

				std::cout << std::endl;
				std::cout << bur;
				std::cout << pre;
				pre.beSigned(bur);
				rob.beSigned(bur);
				shr.beSigned(bur);
				bur.executeForm(pre);
				bur.executeForm(rob);
				bur.executeForm(rob);
				bur.executeForm(shr);
				std::cout << std::endl;
				std::cout << std::endl;
			}
			catch (std::exception& except) {
				std::cerr << except.what() << std::endl;
			}
			std::cout << std::endl;
			std::cout << std::endl;


			std::cout << "No Exception (end)-----" << std::endl;
		}
		{ // No exception
			std::cout << "\nNot enough grade (start)----" << std::endl;

			Bureaucrat 				bur("Burocrata", 30);
			PresidentialPardonForm	pre("Marcelo form");
			RobotomyRequestForm		rob("Robozao");
			ShrubberyCreationForm	shr("Franz Schubert");
			try {

				std::cout << std::endl;
				rob.beSigned(bur);
				shr.beSigned(bur);
				bur.executeForm(rob);
				bur.executeForm(shr);
				pre.beSigned(bur);
				bur.executeForm(pre);
				std::cout << std::endl;
				std::cout << std::endl;
			}
			catch (std::exception& except) {
				std::cerr << except.what() << std::endl;
			}
			std::cout << std::endl;
			std::cout << std::endl;


			std::cout << "Not enough grade (end)-----" << std::endl;
		}
	}
	return (0);
}
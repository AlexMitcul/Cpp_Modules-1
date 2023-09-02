/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:50:46 by kfaustin          #+#    #+#             */
/*   Updated: 2023/09/02 17:58:58 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	{
		Bureaucrat bur1;
		Bureaucrat bur2("Mozart", 1);
		Bureaucrat bur3(bur1);
		Bureaucrat bur4;
		bur4 = bur2; // This doesn't lead segfault because og the <const_cast> on the copy assignment

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "bur1> " << bur1;
		std::cout << "bur2> " << bur2;
		std::cout << "bur3> " << bur3;
		std::cout << "bur4> " << bur4;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{ // Case GradeTooHigh
		std::cout << "- Exception <Grade to High>" << std::endl;
		try {
			Bureaucrat obj("Bot", 0);
		}
		catch (std::exception& execpt) {
			std::cerr << execpt.what() << std::endl;
			//std::cout << "Bot_1>" << obj; obj; OBJ doesn't exist in this scope
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{ // Case GradeTooLow
		std::cout << "- Exception <Grade to Low>" << std::endl;
		try {
			Bureaucrat obj("Bot", 151);
		}
		catch (std::exception& execpt) {
			std::cerr << execpt.what() << std::endl;
			// std::cout << "Bot_2>" << obj; OBJ doesn't exist in this scope
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{ // Case Operation over the limits
		std::cout << "- Exception <Grade to high/low>" << std::endl;
		try {
			Bureaucrat obj("Bot", 1);
			obj.incrementGrade();
			std::cout << "Obj>" << obj;
		}
		catch (std::exception& execpt) {
			std::cerr << execpt.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{ // Case Operation over the limits
		std::cout << "- Exception <Grade to high/low>" << std::endl;
		try {
			Bureaucrat obj("Bot", 150);
			obj.decrementGrade();
			std::cout << "Obj>" << obj;
		}
		catch (std::exception& execpt) {
			std::cerr << execpt.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{ // Case Operation over the limits
		std::cout << "- No Exception" << std::endl;
		try {
			Bureaucrat obj("Bot", 90);
			obj.incrementGrade();
			std::cout << obj;
			obj.incrementGrade();
			std::cout << obj;
			obj.decrementGrade();
			std::cout << obj;
			obj.decrementGrade();
			std::cout << obj;
			obj.decrementGrade();
			std::cout << obj;
		}
		catch (std::exception& execpt) {
			std::cerr << execpt.what() << std::endl;
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:42:40 by kfaustin          #+#    #+#             */
/*   Updated: 2023/08/30 14:40:04 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int	main(void) {
	{ //Default constructor
		Bureaucrat bur;
		Form form;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << bur;
		std::cout << form;
		std::cout << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{ // Constructor overload
		Bureaucrat bur{"Lord", 1};
		Form form{"Chopin", 1, 1}; //Different way to define from(name, grade, grade);
		std::cout << form;
		form.beSigned(bur);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{ // Exception Bur doesn't have enough grade
		Bureaucrat bur{"Lord", 50};
		Form form{"Chopin", 10, 1}; //Different way to define from(name, grade, grade);
		try {
			form.beSigned(bur);
		}
		catch (std::exception& except) {
			std::cerr << except.what() << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{ // Incrementing Bur before assigning
		Bureaucrat bur{"Lord", 52};
		Form form{"Chopin", 50, 52}; //Different way to define from(name, grade, grade);
		try {
			form.beSigned(bur);
		}
		catch (std::exception& except) {
			std::cerr << except.what() << std::endl;
		}
		std::cout << std::endl;
		std::cout << bur;
		bur.incrementGrade();
		std::cout << bur;
		bur.incrementGrade();
		std::cout << bur;
		std::cout << std::endl;
		try {
			form.beSigned(bur);
		}
		catch (std::exception& except) {
			std::cerr << except.what() << std::endl;
		}
	}
	return (0);
}
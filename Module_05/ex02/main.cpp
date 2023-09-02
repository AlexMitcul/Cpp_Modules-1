/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:42:40 by kfaustin          #+#    #+#             */
/*   Updated: 2023/09/02 20:40:20 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void) {
	{ //Default constructor
		Bureaucrat bur;
		//AForm form;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << bur;
		//std::cout << form;
		std::cout << std::endl;
		std::cout << std::endl;
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:00:42 by kfaustin          #+#    #+#             */
/*   Updated: 2023/09/05 16:08:53 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Input by args" << std::endl;
		return (0);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
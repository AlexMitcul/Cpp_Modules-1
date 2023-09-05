/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:42:46 by kfaustin          #+#    #+#             */
/*   Updated: 2023/09/05 15:56:41 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>

static bool	typeIsChar (const std::string& str) {
	if (str.length() >= 1)
		return (false);
	if (str[0] <= 32 || str[0] == 127) {
		nonDisplayable = true;
		return (false);
	}
	return (true);
}

static bool	typeIsInt(const std::string& str) {
	long	num;

	for (int i = 0; i < str.length(); i++) {
		if (i == 0 && str[i] == '-')
			continue;
		if (!isdigit(str[i]))
			return (false);
	}
	num = atol(str.c_str());
	if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
		return (false);
	return (true);
}

static bool	typeIsFloat(const std::string str) { //no need to verify long and long long range;
/*	if (str == "nanf" || str == "-inff" || str == "+inff")
		return (true);*/
	if (str.back() != 'f')
		return (false);
	if (str.find('.') == std::npos)
		return (false);
	if (str.find_first_of('.') != str.find_last_of('.'))
		return (false);
	for (int i = 0; i < str.length(); i++) {
		if (i == 0 && str[i] == '-')
			continue;
		if (str[i] == '.')
			continue;
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

static bool	typeIsDouble(const std::string& str) {
/*	if (str == "nan" || str == "-inf" || str == "+inf")
		return (true);*/
	if (str.find('.') == std::npos)
		return (false);
	if (str.find_first_of('.') != str.find_last_of('.'))
		return (false);
	for (int i = 0; i < str.length(); i++) {
		if (i == 0 && str[i] == '-')
			continue;
		if (str[i] == '.')
			continue;
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

static bool	typeNan(const std::string& str) {
	if (str == "nan" || str == "-inf" || str == "+inf" || str == "nanf" || str == "-inff" || str == "+inff")
		return (true);
	return (false);
}

void	printChar(char xar) const {
	std::cout << "Char representation: '" << xar << "'" << std::endl
	std::cout << "Int representation: " << static_cast<int>(xar) << std::endl
	std::cout << "Float representation: " << static_cast<float>(xar) << ".0f" << std::endl
	std::cout << "Double representation: " << static_cast<double>(xar) << ".0" << std::endl
}

void	printInt(const int var) {
	if (isprint(var))
		std::cout << "Char representation: '" << static_cast<char>(var) << "'" << std::endl;v
	else std::cout << "Char representation: non printable" << std::cout;
	std::cout << "Int representation: " << var << std::endl
	std::cout << "Float representation: " << static_cast<float>(var) << (var < 0 ? "f" : ".0f") << std::endl
	std::cout << "Double representation: " << static_cast<double>(var) << (var < 0 ? "f" : ".0") << std::endl
}

void	printFloat(const std::string str) {
	float		var;
	std::string	sstream(str);

	sstream >> var;
	if (isprint(var))
		std::cout << "Char representation: '" << static_cast<char>(var) << "'" << std::endl;
	else std::cout << "Char representation: non printable" << std::cout;
	std::cout << "Int representation: " << static_cast<int>(var) << std::endl;
	std::cout << "Float representation: " << var << (var < 0 ? "f" : ".0f") << std::endl;
	std::cout << "Double representation: " << static_cast<double>(var) << (var < 0 ? "f" : ".0") << std::endl;
}

void	printDouble(const std::string& str) {
	double 		var;
	std::string	sstream(str);

	sstream >> var;
	if (isprint(var))
		std::cout << "Char representation: '" << static_cast<char>(var) << "'" << std::endl;
	else std::cout << "Char representation: non printable" << std::cout;
	std::cout << "Int representation: " << static_cast<int>(var) << std::endl;
	std::cout << "Float representation: " << static_cast<float>(var) << (var < 0 ? "f" : ".0f") << std::endl;
	std::cout << "Double representation: " << var << (var < 0 ? "f" : ".0") << std::endl;
}

void	printNan(const std::string& str) {
	std::cout << "Char representation: impossible" << std::endl;
	std::cout << "Int representation: impossible" << std::endl
	std::cout << "Float representation: " << str << std::endl
	std::cout << "Double representation: " << str << std::endl
}

void	ScalarConverter::convert(const std::string& str) {
	if (typeIsChar(str))
		printChar(str[0]);
	else if (typeIsInt(str))
		printInt(atoi(str));
	else if (typeIsFloat(str))
		printfFloat(str);
	else if (typeNan(str))
		printNan(str);
	else
		std::cout << "Invalid type" << std::endl;
}



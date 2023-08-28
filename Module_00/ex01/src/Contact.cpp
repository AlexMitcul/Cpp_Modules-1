/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:33:07 by kfaustin          #+#    #+#             */
/*   Updated: 2023/05/29 15:37:57 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

std::string	Contact::get_first_name(void) {
	return (this->_first_name);
}

std::string	Contact::get_last_name(void) {
	return (this->_last_name);
}

std::string	Contact::get_nick_name(void) {
	return (this->_nick_name);
}

std::string	Contact::get_phone_number(void) {
	return (this->_phone_number);
}

std::string	Contact::get_darkest_secret(void) {
	return (this->_darkest_secret);
}

void	Contact::get_full_xnfo(void) {
std::cout << "\n******-<CONTACT>-******" << std::endl;
std::cout << "* First Name: " << this->get_first_name() << std::endl;
std::cout << "* Last Name: " << this->get_last_name() <<std::endl;
std::cout << "* Nickname: " << this->get_nick_name() << std::endl;
std::cout << "* Phone Number: " << this->get_phone_number() << std::endl;
std::cout << "* Darkest Secret: " << this->get_darkest_secret() << std::endl;
std::cout << "*********************\n" << std::endl;
}

void	Contact::set_full_xnfo(void) {
	this->_first_name = get_check_xnput("First Name: ");
	this->_last_name = get_check_xnput("Last Name: ");
	this->_nick_name = get_check_xnput("Nickname: ");
	this->_phone_number = get_check_xnput("Phone Number: ");
	this->_darkest_secret = get_check_xnput("Darkest Secret: ");
}

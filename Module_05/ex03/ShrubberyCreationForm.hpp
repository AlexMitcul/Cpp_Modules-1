/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:39:19 by kfaustin          #+#    #+#             */
/*   Updated: 2023/09/02 20:44:37 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat; // forward declaration

class Form; //forward declaration

class ShrubberyCreationForm : public AForm {
	private:
		const std::string	_target;

	public:
		static const std::string	type;

		ShrubberyCreationForm(void);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& src);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);

		std::string	getTarget(void) const;

		virtual void	execute(const Bureaucrat& executor) const;
};

std::ostream&	operator<<(std::ostream& os, ShrubberyCreationForm& src);

#endif //SHRUBBERYCREATIONFORM_HPP

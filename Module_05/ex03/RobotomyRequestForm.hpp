/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   robotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 22:02:58 by kfaustin          #+#    #+#             */
/*   Updated: 2023/09/03 12:22:35 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class AForm;

class Bureaucrat;

class RobotomyRequestForm : public AForm {
	private:
		const std::string	_target;

	public:
		static const std::string	type;

		RobotomyRequestForm(void);
		~RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& src);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& src);

		std::string	getTarget(void) const;

		virtual void	execute(const Bureaucrat& executor) const;
};

std::ostream&	operator<<(std::ostream& os, RobotomyRequestForm& src);

#endif //ROBOTOMYREQUESTFORM_HPP

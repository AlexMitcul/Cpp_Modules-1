/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:02:22 by kfaustin          #+#    #+#             */
/*   Updated: 2023/09/03 12:11:05 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class AForm;

class Bureaucrat;

class PresidentialPardonForm  : public AForm {
	private:
		const std::string	_target;

	public:
		static const std::string	type;

	PresidentialPardonForm(void);
	~PresidentialPardonForm(void);
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& src);
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& src);

	std::string	getTarget(void) const;

	virtual void	execute(const Bureaucrat& executor) const;
};

std::ostream&	operator<<(std::ostream& os, PresidentialPardonForm& src);

#endif //PRESIDENTIALPARDONFORM_HPP

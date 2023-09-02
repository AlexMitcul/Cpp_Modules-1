/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:27:45 by kfaustin          #+#    #+#             */
/*   Updated: 2023/09/02 15:43:45 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once // Prevents multiple includes.

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"

class Form; //Forward declaration

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;

	public:
		// friend std::ostream& operator<<(std::ostream& os, Bureaucrat& src);
		void	signForm(Bureaucrat& bureaucrat, bool sign) const; // Old version
		void	signForm(Bureaucrat& bureaucrat, Form& form) const; // This func overload is better, It works directly with the obj

		static const std::string type;
		Bureaucrat(void);
		~Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat &operator=(const Bureaucrat& src);

		const std::string	getName(void) const;
		int getGrade(void) const;

		void	setGrade(int grade);

		void	incrementGrade(void);
		void	decrementGrade(void);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
	};

std::ostream& operator<<(std::ostream& os, Bureaucrat& src);

#endif //BUREAUCRAT_HPP

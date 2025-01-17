/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:20:25 by kfaustin          #+#    #+#             */
/*   Updated: 2023/09/02 20:30:29 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include <fstream>
# include "Bureaucrat.hpp"

class Bureaucrat; //Forward declaration

class AForm {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToexecute;

	public:
		static const std::string	type;
		static int	checkGradeRange(int value);

		AForm(void);
		~AForm(void);
		AForm(std::string name, int grade_to_sign, int grade_to_execute);
		AForm(const AForm& src);
		AForm& operator=(const AForm& src); // Getting a lot of problems while const int.

		const std::string	getName(void) const;
		bool				getSign(void) const;
		const int			getGradeTosign(void) const;
		const int			getGradeToExecute(void) const;

		void				beSigned(Bureaucrat& bureaucrat);
		virtual void		execute(const Bureaucrat& executor) const = 0; //Pure virtual function > The class know is abstract (base) class. It cant be instantiated.

		void				setGradeToSign(int grade_to_sign);
		void				setGradeToExecute(int grade_to_execute);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, AForm& src);

#endif //AForm_HPP

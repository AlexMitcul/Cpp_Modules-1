/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:20:25 by kfaustin          #+#    #+#             */
/*   Updated: 2023/08/30 12:23:46 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Form {
	private:
		const std::string	_name;
		bool	_isSigned;
		const int	_gradeToSign;
		const int	_gradeToexecute;

	public:
		static const std::string	type;
		static int	checkGradeRange(int value);

		Form(void);
		~Form(void);
		Form(std::string name, int grade_to_sign, int grade_to_execute);
		Form(const Form& src);
		//Form& operator=(const Form& src);

		const std::string	getName(void) const;
		bool	getSign(void) const;
		const int	getGradeTosign(void) const;
		const int	getGradeToExecute(void) const;

		void	beSigned(Bureaucrat& bureaucrat);

		void	setGradeToSign(int grade_to_sign);
		void	setGradeToExecute(int grade_to_execute);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
		class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, Form& src);

#endif //FORM_HPP

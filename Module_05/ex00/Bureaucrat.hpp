/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:27:45 by kfaustin          #+#    #+#             */
/*   Updated: 2023/08/29 12:52:04 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat {
	private:
		const std::string	_name;
		int	_grade;

	public:
		// friend std::ostream& operator<<(std::ostream& os, Bureaucrat& src);
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

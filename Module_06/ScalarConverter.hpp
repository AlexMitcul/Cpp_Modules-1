/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:34:27 by kfaustin          #+#    #+#             */
/*   Updated: 2023/09/05 16:00:18 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

/*
In C++, there is no concept of a "static class" in the same way that someother
programming languages have a static class concept, like in C# or Java.
In C++, classes can have static members,
but the class itself is not declared as static.
Question:
Do we need to implement this class in canonical form?
If answer if yes, can I set all methods as private?
*/
class ScalarConverter {
	public:
		static void	convert(const std::string& str);
};

#endif //SCALARCONVERTER_HPP

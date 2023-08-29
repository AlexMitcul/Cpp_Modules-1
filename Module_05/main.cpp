/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:50:46 by kfaustin          #+#    #+#             */
/*   Updated: 2023/08/29 13:43:09 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	{
		Bureaucrat bur1;
		Bureaucrat bur2("Mozart", 1);
		Bureaucrat bur3(bur1);
		Bureaucrat bur4;
		bur4 = bur2;
	}
	return (0);
}

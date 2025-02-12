/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:17:04 by sbelomet          #+#    #+#             */
/*   Updated: 2025/02/12 10:47:13 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int main(int ac, char** av)
{
	int	toup;
	
	if (ac != 2)
	{
		ft_putstr_fd("Only one argument\n", 2);
		exit(1);
	}
	ft_putstr_fd("look i touppered your entry: ", 1);
	toup = ft_toupper(*(av[1]));
	ft_putnbr_fd(toup, 1);
	ft_putchar_fd('\n', 1);
	if (ft_isdigit(*(av[1])))
		ft_putstr_fd("your thing is a digit btw\n", 1);
}

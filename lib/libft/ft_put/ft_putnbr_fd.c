/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:41:10 by sbelomet          #+#    #+#             */
/*   Updated: 2025/02/11 14:12:55 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putnbr_fd((n % 10), fd);
	}
	else
	{
		ft_putchar_fd((n + '0'), fd);
	}
}

/* 
int	main(void)
{
	ft_putnbr_fd(-2147483648, 1);
	puts("");
	ft_putnbr_fd(0, 1);
	puts("");
	ft_putnbr_fd(123, 1);
	puts("");
	ft_putnbr_fd(-456, 1);
	puts("");
	ft_putnbr_fd(2147483647, 1);
	puts("");
} */

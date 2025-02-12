/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:13:19 by sbelomet          #+#    #+#             */
/*   Updated: 2025/02/12 09:44:09 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)s = '\0';
		s++;
		i++;
	}
}

/*
int	main(void)
{
	char	str[50] = "This is string.h library function";

	printf("%s\n", str);
	ft_bzero((str + 9), 7);
	printf("%s\n", str);
}*/
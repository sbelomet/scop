/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:13:50 by sbelomet          #+#    #+#             */
/*   Updated: 2025/02/11 13:37:40 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	char	str[] = "huntlow & lumity";
	char	to_find1 = 'u';
	char	to_find2 = '\0';
	char	to_find3 = 'z';
	char	to_find4 = '&';

	printf("to_find1 : %p\n", ft_memchr(str, to_find1, 2));
	printf("to_find2 : %p\n", ft_memchr(str, to_find2, 5));
	printf("to_find3 : %p\n", ft_memchr(str, to_find3, 12));
	printf("to_find4 : %p\n", ft_memchr(str, to_find4, 14));
}*/
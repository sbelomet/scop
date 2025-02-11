/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:29:49 by sbelomet          #+#    #+#             */
/*   Updated: 2025/02/11 13:57:56 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dst);
}

/* 
int	main(void)
{
	char str[] = "ABCDEF";
	char *one, *two;

	one = str;
	two = one + 1;

	puts(str);
	puts(one);
	puts(two);

	char *result = ft_memcpy(one, two, 3);
	printf("returned memcpy: %s\n", result);
	puts(str);
	write(1, one, 6);
	puts("");
	write(1, two, 5);
	puts("");
} */
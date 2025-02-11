/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:52:28 by sbelomet          #+#    #+#             */
/*   Updated: 2025/02/11 15:09:25 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (len + 1 > 0)
	{
		if (s[len] == (char)c)
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}

/*
int	main(void)
{
	char	str[] = "huntlow & lumity";
	int		to_find1 = 'u';
	int		to_find2 = '\0';
	int		to_find3 = 'z';
	int		to_find4 = '&';

	printf("to_find1 : %p\n", ft_strrchr(str, to_find1));
	printf("to_find2 : %p\n", ft_strrchr(str, to_find2));
	printf("to_find3 : %p\n", ft_strrchr(str, to_find3));
	printf("to_find4 : %p\n", ft_strrchr(str, to_find4));
}*/
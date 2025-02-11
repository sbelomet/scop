/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:01:15 by sbelomet          #+#    #+#             */
/*   Updated: 2025/02/11 15:07:44 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 1;
			while (i + j < len && needle[j] && haystack[i + j] == needle[j])
				j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	char	str[] = "huntlow & lumity";
	char	to_find1[] = "huntlow";
	char	to_find2[] = "luzura";
	char	to_find3[] = "untloww";

	printf("to_find1 : %p\n", ft_strnstr(str, to_find1, 7));
	printf("to_find2 : %p\n", ft_strnstr(str, to_find2, 6));
	printf("to_find3 : %p\n", ft_strnstr(str, to_find3, 6));
	printf("to_find4 : %s\n", ft_strnstr("lorem ipsum dolor sit amet", "", 10));
}*/
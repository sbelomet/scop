/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:35:48 by sbelomet          #+#    #+#             */
/*   Updated: 2025/02/11 15:04:13 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*res;
	unsigned int		i;

	res = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*
char add_one(unsigned int i, char c) {
    return c + i;
}

int main() {
    char str[] = "hello";
    char* result = ft_strmapi(str, add_one);
    printf("%s\n", result);
    free(result);
    return 0;
}*/
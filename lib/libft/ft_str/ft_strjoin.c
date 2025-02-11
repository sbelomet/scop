/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:38:39 by lgosselk          #+#    #+#             */
/*   Updated: 2025/02/11 14:54:29 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len_s1;
	int		i;
	char	*res;

	len_s1 = ft_strlen(s1);
	res = (char *)malloc((len_s1 + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2 && s2[i])
	{
		res[len_s1 + i] = s2[i];
		i++;
	}
	res[len_s1 + i] = '\0';
	return (res);
}

char	*ft_strjoin_alloc(char const *s1, char const *s2,
	t_alloc **alloc)
{
	int		len_s1;
	int		i;
	char	*res;

	len_s1 = ft_strlen(s1);
	res = (char *)ft_malloc((len_s1 + ft_strlen(s2) + 1) * sizeof(char), alloc);
	if (!res)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2 && s2[i])
	{
		res[len_s1 + i] = s2[i];
		i++;
	}
	res[len_s1 + i] = '\0';
	return (res);
}

/* 
int	main(void)
{
	printf("result: |%s|\n", ft_strjoin("simon ", "petrikov"));
	printf("result: |%s|\n", ft_strjoin("Finn ", ""));
	printf("result: |%s|\n", ft_strjoin("", "the Dog"));
	printf("result: |%s|\n", ft_strjoin("Princess ", NULL));
	printf("result: |%s|\n", ft_strjoin(NULL, "the Vampire Queen"));
	printf("result: |%s|\n", ft_strjoin("Ice ", "King"));
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:56:21 by lgosselk          #+#    #+#             */
/*   Updated: 2025/02/11 14:26:44 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = ft_strlen(s1);
	s2 = (char *)malloc(i * sizeof(char) + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strdup_allocated(const char *s1, t_alloc **alloc)
{
	char	*s2;
	int		i;

	i = ft_strlen(s1);
	s2 = (char *)ft_malloc((i * sizeof(char) + 1), alloc);
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

/*
int	main(void)
{
	char str[] = "test-test";
	char *p;

	p = ft_strdup(str);
	printf("dup str: %s\n", p);
}*/
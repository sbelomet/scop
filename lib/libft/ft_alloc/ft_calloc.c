/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:16:25 by sbelomet          #+#    #+#             */
/*   Updated: 2025/02/11 13:32:56 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, (count * size));
	return (p);
}

/*
int	main(void)
{
	int	*p;
	int	i;

	p = (int *)ft_calloc(5, sizeof(int));
	i = 0;
	while (p[i])
	{
		write(1, p[i], 8);
		i++;
	}
}*/
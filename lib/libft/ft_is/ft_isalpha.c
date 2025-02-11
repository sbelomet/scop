/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:03:08 by sbelomet          #+#    #+#             */
/*   Updated: 2025/02/11 13:35:20 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c > 64 && c < 91) || (c > 96 && c < 123));
}

/*
#include <stdio.h>
int	main(void)
{
	int	i = 0;
	while (i < 128)
	{
		printf("%d: %d\n", i, ft_isalpha(i));
		i++;
	}
}*/
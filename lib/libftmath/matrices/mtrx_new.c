/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtrx_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:56:26 by sbelomet          #+#    #+#             */
/*   Updated: 2025/10/22 15:51:39 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_mat4	ft_mat4(void)
{
	t_mat4	m;
	int		i;

	i = 0;
	while (i < 16)
	{
		if (i % 5 == 0)
			m.m[i] = 1;
		else
			m.m[i] = 0;
		i++;
	}
	return (m);
}

t_mat4	ft_mat4_null(void)
{
	t_mat4	m;
	int		i;

	i = -1;
	while (++i < 16)
		m.m[i] = 0;
	return (m);
}

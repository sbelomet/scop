/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtrx_mul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:54:07 by sbelomet          #+#    #+#             */
/*   Updated: 2025/10/15 15:37:42 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_mat4	ft_mat4_mul(const t_mat4 m1, const t_mat4 m2)
{
	int		i;
	int		j;
	int		k;
	t_mat4	m;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			m.m[i * 4 + j] = 0;
			while (++k < 4)
				m.m[i * 4 + j] += m1.m[i * 4 + k] * m2.m[k * 4 + j];
		}
	}
	return (m);
}

t_vec4	ft_mat4_vec4_mul(const t_mat4 m, const t_vec4 v)
{
	t_vec4	result;
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		result.v[i] = 0;
		j = -1;
		while (++j < 4)
			result.v[i] += m.m[i * 4 + j] * v.v[j];
	}
	return (result);
}

t_mat4	ft_mat4_smul(t_mat4 m1, const float n)
{
	int	i;

	i = -1;
	while (++i < 16)
		m1.m[i] *= n;
	return (m1);
}

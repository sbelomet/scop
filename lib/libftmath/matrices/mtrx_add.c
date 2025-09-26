/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtrx_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:09:54 by sbelomet          #+#    #+#             */
/*   Updated: 2025/02/18 14:17:35 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_mat4	ft_mat4_add(t_mat4 m1, const t_mat4 m2)
{
	int	i;

	i = -1;
	while (++i < 16)
		m1.m[i] += m2.m[i];
	return (m1);
}

t_mat4	ft_mat4_sadd(t_mat4 m1, const float n)
{
	int	i;

	i = -1;
	while (++i < 16)
		m1.m[i] += n;
	return (m1);
}

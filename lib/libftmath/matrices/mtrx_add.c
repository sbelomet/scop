/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtrx_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:09:54 by sbelomet          #+#    #+#             */
/*   Updated: 2025/10/22 15:57:29 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_mat4	ft_mat4_add(const t_mat4 m1, const t_mat4 m2)
{
	t_mat4	m_res;
	int	i;

	m_res = ft_mat4_null();
	i = -1;
	while (++i < 16)
		m_res.m[i] = m1.m[i] + m2.m[i];
	return (m_res);
}

t_mat4	ft_mat4_sadd(const t_mat4 m1, const float n)
{
	t_mat4	m_res;
	int	i;

	m_res = ft_mat4_null();
	i = -1;
	while (++i < 16)
		m_res.m[i] = m1.m[i] + n;
	return (m_res);
}

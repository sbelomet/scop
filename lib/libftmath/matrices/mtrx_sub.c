/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtrx_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:16:23 by sbelomet          #+#    #+#             */
/*   Updated: 2025/10/22 15:59:41 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_mat4	ft_mat4_sub(const t_mat4 m1, const t_mat4 m2)
{
	t_mat4	m_res;
	int	i;

	m_res = ft_mat4_null();
	i = -1;
	while (++i < 16)
		m_res.m[i] = m1.m[i] - m2.m[i];
	return (m_res);
}

t_mat4	ft_mat4_ssub(const t_mat4 m1, const float n)
{
	t_mat4	m_res;
	int	i;

	m_res = ft_mat4_null();
	i = -1;
	while (++i < 16)
		m_res.m[i] = m1.m[i] - n;
	return (m_res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctr_div.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:24:05 by sbelomet          #+#    #+#             */
/*   Updated: 2025/10/22 16:09:23 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_vec3	ft_vec3_div(const t_vec3 v1, const t_vec3 v2)
{
	t_vec3	v_res;
	int		i;

	v_res = ft_vec3_null();
	i = -1;
	while (++i < 3)
	{
		if (v2.v[i])
			v_res.v[i] = v1.v[i] / v2.v[i];
		else
			v_res.v[i] = 0;
	}
	return (v_res);
}

t_vec3	ft_vec3_sdiv(const t_vec3 v1, const float n)
{
	t_vec3	v_res;

	v_res = ft_vec3_null();
	if (n == 0)
		return (v_res);
	v_res.v[0] = v1.v[0] / n;
	v_res.v[1] = v1.v[1] / n;
	v_res.v[2] = v1.v[2] / n;
	return (v_res);
}

t_vec4	ft_vec4_div(const t_vec4 v1, const t_vec4 v2)
{
	t_vec4	v_res;
	int		i;

	v_res = ft_vec4_null();
	i = -1;
	while (++i < 4)
	{
		if (v2.v[i])
			v_res.v[i] = v1.v[i] / v2.v[i];
		else
			v_res.v[i] = 0;
	}
	return (v_res);
}

t_vec4	ft_vec4_sdiv(const t_vec4 v1, const float n)
{
	t_vec4	v_res;

	v_res = ft_vec4_null();
	if (n == 0)
		return (v_res);
	v_res.v[0] = v1.v[0] / n;
	v_res.v[1] = v1.v[1] / n;
	v_res.v[2] = v1.v[2] / n;
	v_res.v[3] = v1.v[3] / n;
	return (v_res);
}

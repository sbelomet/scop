/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctr_div.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:24:05 by sbelomet          #+#    #+#             */
/*   Updated: 2025/02/18 14:19:36 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_vec3	ft_vec3_div(t_vec3 v1, const t_vec3 v2)
{
	int i;

	i = -1;
	while (++i < 3)
	{
		if (v2.v[i])
			v1.v[i] /= v2.v[i];
		else
			v1.v[i] = 0;
	}
	return (v1);
}

t_vec3	ft_vec3_sdiv(t_vec3 v1, const float n)
{
	if (n == 0)
		return (ft_vec3(0, 0, 0));
	v1.v[0] /= n;
	v1.v[1] /= n;
	v1.v[2] /= n;
	return (v1);
}

t_vec4	ft_vec4_div(t_vec4 v1, const t_vec4 v2)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (v2.v[i])
			v1.v[i] /= v2.v[i];
		else
			v1.v[i] = 0;
	}
	return (v1);
}

t_vec4	ft_vec4_sdiv(t_vec4 v1, const float n)
{
	if (n == 0)
		return (ft_vec4(0, 0, 0, 0));
	v1.v[0] /= n;
	v1.v[1] /= n;
	v1.v[2] /= n;
	v1.v[3] /= n;
	return (v1);
}

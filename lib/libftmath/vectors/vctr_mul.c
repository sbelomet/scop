/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctr_mul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:07:52 by sbelomet          #+#    #+#             */
/*   Updated: 2025/02/18 16:12:12 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_vec3	ft_vec3_mul(t_vec3 v1, const t_vec3 v2)
{
	v1.v[0] *= v2.v[0];
	v1.v[1] *= v2.v[1];
	v1.v[2] *= v2.v[2];
	return (v1);
}

t_vec3	ft_vec3_smul(t_vec3 v1, const float n)
{
	v1.v[0] *= n;
	v1.v[1] *= n;
	v1.v[2] *= n;
	return (v1);
}

t_vec4	ft_vec4_mul(t_vec4 v1, const t_vec4 v2)
{
	v1.v[0] *= v2.v[0];
	v1.v[1] *= v2.v[1];
	v1.v[2] *= v2.v[2];
	v1.v[3] *= v2.v[3];
	return (v1);
}

t_vec4	ft_vec4_smul(t_vec4 v1, const float n)
{
	v1.v[0] *= n;
	v1.v[1] *= n;
	v1.v[2] *= n;
	v1.v[3] *= n;
	return (v1);
}

t_vec4	ft_vec4_mmul(const t_vec4 v, const t_mat4 m)
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

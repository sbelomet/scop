/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctr_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:02:30 by sbelomet          #+#    #+#             */
/*   Updated: 2025/02/18 13:19:49 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_vec3	ft_vec3_sub(t_vec3 v1, const t_vec3 v2)
{
	v1.v[0] -= v2.v[0];
	v1.v[1] -= v2.v[1];
	v1.v[2] -= v2.v[2];
	return (v1);
}

t_vec3	ft_vec3_ssub(t_vec3 v1, const float n)
{
	v1.v[0] -= n;
	v1.v[1] -= n;
	v1.v[2] -= n;
	return (v1);
}

t_vec4	ft_vec4_sub(t_vec4 v1, const t_vec4 v2)
{
	v1.v[0] -= v2.v[0];
	v1.v[1] -= v2.v[1];
	v1.v[2] -= v2.v[2];
	v1.v[3] -= v2.v[3];
	return (v1);
}

t_vec4	ft_vec4_ssub(t_vec4 v1, const float n)
{
	v1.v[0] -= n;
	v1.v[1] -= n;
	v1.v[2] -= n;
	v1.v[3] -= n;
	return (v1);
}

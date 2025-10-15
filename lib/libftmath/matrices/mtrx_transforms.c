/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtrx_transforms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:16:23 by sbelomet          #+#    #+#             */
/*   Updated: 2025/10/15 16:17:01 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_mat4	ft_mat4_trans(const t_vec4 trans)
{
	t_mat4	table;

	table = ft_mat4();
	table.m[3] = trans.v[0];
	table.m[7] = trans.v[1];
	table.m[11] = trans.v[2];
	return (table);
}

t_mat4	rotation_matrix(t_vec3 rot_axis, const float angle)
{
	t_mat4	full_rotation;
	t_vec3	axis;
	double	c;
	double	s;
	double	t;

	rot_axis = ft_vec3_normalize(rot_axis);
	c = cos(angle);
	s = sin(angle);
	t = 1 - c;
	full_rotation = ft_mat4();
	full_rotation.m[0] = c + pow(rot_axis.v[0], 2) * t;
	full_rotation.m[1] = rot_axis.v[0] * rot_axis.v[1] * t - rot_axis.v[2] * s;
	full_rotation.m[2] = rot_axis.v[0] * rot_axis.v[2] * t + rot_axis.v[1] * s;
	full_rotation.m[4] = rot_axis.v[1] * rot_axis.v[0] * t + rot_axis.v[2] * s;
	full_rotation.m[5] = c + pow(rot_axis.v[1], 2) * t;
	full_rotation.m[6] = rot_axis.v[1] * rot_axis.v[2] * t - rot_axis.v[0] * s;
	full_rotation.m[8] = rot_axis.v[2] * rot_axis.v[0] * t - rot_axis.v[1] * s;
	full_rotation.m[9] = rot_axis.v[2] * rot_axis.v[1] * t + rot_axis.v[0] * s;
	full_rotation.m[10] = c + pow(rot_axis.v[2], 2) * t;
	return (full_rotation);
}

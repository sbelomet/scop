/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtrx_projections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:09:54 by sbelomet          #+#    #+#             */
/*   Updated: 2025/10/21 16:13:13 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_mat4	ft_mat4_persp(const float fov, const float asp_ratio, const float near, const float far)
{
	t_mat4	table;
	float	s_factor;

	table = ft_mat4();
	s_factor = 1.0f / tan(fov * 0.5f);
	table.m[0] = s_factor / asp_ratio;
	table.m[5] = s_factor;
	table.m[10] = -(far + near) / (far - near);
	table.m[11] = -(2.0f * far * near) / (far - near);
	table.m[14] = -1.0f;
	table.m[15] = 0.0f;
	return (table);
}

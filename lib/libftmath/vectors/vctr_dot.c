/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctr_dot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:46:39 by sbelomet          #+#    #+#             */
/*   Updated: 2025/02/18 13:56:28 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

float	ft_vec3_dot(const t_vec3 v1, const t_vec3 v2)
{
	return (v1.v[0] * v2.v[0] + v1.v[1] * v2.v[1] + v1.v[2] * v2.v[2]);
}

float	ft_vec4_dot(const t_vec3 v1, const t_vec3 v2)
{
	return (v1.v[0] * v2.v[0] + v1.v[1] * v2.v[1]
		+ v1.v[2] * v2.v[2] + v1.v[3] * v2.v[3]);
}

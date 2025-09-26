/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctr_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:40:01 by sbelomet          #+#    #+#             */
/*   Updated: 2025/02/18 13:43:24 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

float	ft_vec3_len(const t_vec3 v)
{
	return (sqrt(v.v[0] * v.v[0] + v.v[1] * v.v[1] + v.v[2] * v.v[2]));
}

float	ft_vec4_len(const t_vec4 v)
{
	return (sqrt(v.v[0] * v.v[0] + v.v[1] * v.v[1]
			+ v.v[2] * v.v[2] + v.v[3] * v.v[3]));
}

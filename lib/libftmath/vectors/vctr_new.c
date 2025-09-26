/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctr_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:03:06 by sbelomet          #+#    #+#             */
/*   Updated: 2025/02/18 12:06:26 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_vec3	ft_vec3(const float x, const float y, const float z)
{
	t_vec3	v;

	v.v[0] = x;
	v.v[1] = y;
	v.v[2] = z;
	return (v);
}

t_vec4	ft_vec4(const float x, const float y, const float z, const float w)
{
	t_vec4	v;

	v.v[0] = x;
	v.v[1] = y;
	v.v[2] = z;
	v.v[3] = w;
	return (v);
}

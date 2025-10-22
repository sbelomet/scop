/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctr_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:03:06 by sbelomet          #+#    #+#             */
/*   Updated: 2025/10/22 15:49:04 by sbelomet         ###   ########.fr       */
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

t_vec3	ft_vec3_null(void)
{
	t_vec3	v;

	v.v[0] = 0;
	v.v[1] = 0;
	v.v[2] = 0;
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

t_vec4	ft_vec4_null(void)
{
	t_vec4	v;

	v.v[0] = 0;
	v.v[1] = 0;
	v.v[2] = 0;
	v.v[3] = 0;
	return (v);
}

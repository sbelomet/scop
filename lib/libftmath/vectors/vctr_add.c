/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctr_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:43:21 by sbelomet          #+#    #+#             */
/*   Updated: 2025/10/22 16:03:49 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_vec3	ft_vec3_add(const t_vec3 v1, const t_vec3 v2)
{
	t_vec3	v_res;
	
	v_res = ft_vec3_null();
	v_res.v[0] = v1.v[0] + v2.v[0];
	v_res.v[1] = v1.v[1] + v2.v[1];
	v_res.v[2] = v1.v[2] + v2.v[2];
	return (v_res);
}

t_vec3	ft_vec3_sadd(const t_vec3 v1, const float n)
{
	t_vec3	v_res;
	
	v_res = ft_vec3_null();
	v_res.v[0] = v1.v[0] + n;
	v_res.v[1] = v1.v[1] + n;
	v_res.v[2] = v1.v[2] + n;
	return (v_res);
}

t_vec4	ft_vec4_add(const t_vec4 v1, const t_vec4 v2)
{
	t_vec4	v_res;
	
	v_res = ft_vec4_null();
	v_res.v[0] = v1.v[0] + v2.v[0];
	v_res.v[1] = v1.v[1] + v2.v[1];
	v_res.v[2] = v1.v[2] + v2.v[2];
	v_res.v[3] = v1.v[3] + v2.v[3];
	return (v_res);
}

t_vec4	ft_vec4_sadd(const t_vec4 v1, const float n)
{
	t_vec4	v_res;
	
	v_res = ft_vec4_null();
	v_res.v[0] = v1.v[0] + n;
	v_res.v[1] = v1.v[1] + n;
	v_res.v[2] = v1.v[2] + n;
	v_res.v[3] = v1.v[3] + n;
	return (v_res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctr_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:24:30 by sbelomet          #+#    #+#             */
/*   Updated: 2025/02/18 12:27:54 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

void	ft_print_vec3(const t_vec3 v, const char *name)
{
	printf("Vector3 %s(x:%f, y:%f, z:%f)\n", name, v.v[0], v.v[1], v.v[2]);
}

void	ft_print_vec4(const t_vec4 v, const char *name)
{
	printf("Vector4 %s(x:%f, y:%f, z:%f, w:%f)\n",
		name, v.v[0], v.v[1], v.v[2], v.v[3]);
}

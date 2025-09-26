/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctr_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:00:50 by sbelomet          #+#    #+#             */
/*   Updated: 2025/02/18 15:05:00 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_vec3	ft_vec3_normalize(const t_vec3 v)
{
	return (ft_vec3_sdiv(v, ft_vec3_len(v)));
}

t_vec4	ft_vec4_normalize(const t_vec4 v)
{
	return (ft_vec4_sdiv(v, ft_vec4_len(v)));
}

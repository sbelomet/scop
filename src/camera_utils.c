/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:23:01 by sbelomet          #+#    #+#             */
/*   Updated: 2025/10/22 16:16:54 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_mat4	ft_lookat(const t_vec3 camPos, const t_vec3 targetPos, const t_vec3 worldUp)
{
	t_vec3	cam_dir = ft_vec3_normalize(ft_vec3_sub(camPos, targetPos));
	t_vec3	cam_right = ft_vec3_normalize(ft_vec3_cross(worldUp, cam_dir));
	t_vec3	cam_up = ft_vec3_cross(cam_dir, cam_right);

	
}

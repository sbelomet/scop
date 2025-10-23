/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:23:01 by sbelomet          #+#    #+#             */
/*   Updated: 2025/10/23 13:02:39 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_mat4	ft_lookat(const t_vec3 camPos, const t_vec3 targetPos, const t_vec3 worldUp)
{
	t_vec3	cam_dir = ft_vec3_normalize(ft_vec3_sub(camPos, targetPos));
	t_vec3	cam_right = ft_vec3_normalize(ft_vec3_cross(worldUp, cam_dir));
	t_vec3	cam_up = ft_vec3_cross(cam_dir, cam_right);

	t_mat4	lookat_rot = ft_mat4();
	lookat_rot.m[0] = cam_right.v[0];
	lookat_rot.m[1] = cam_right.v[1];
	lookat_rot.m[2] = cam_right.v[2];
	lookat_rot.m[4] = cam_up.v[0];
	lookat_rot.m[5] = cam_up.v[1];
	lookat_rot.m[6] = cam_up.v[2];
	lookat_rot.m[8] = cam_dir.v[0];
	lookat_rot.m[9] = cam_dir.v[1];
	lookat_rot.m[10] = cam_dir.v[2];

	return (ft_mat4_mul(lookat_rot, ft_mat4_transl(ft_vec3_smul(camPos, -1.0f))));
}

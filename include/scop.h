/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:59:43 by sbelomet          #+#    #+#             */
/*   Updated: 2025/10/25 13:32:04 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

/* C libraries */
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

/* Custom libraries */
# include "libft.h"
# include "libftmath.h"

/* External libraries */
# include <glad/glad.h>
# include <GLFW/glfw3.h>
# include <stb_image.h>

# define WIDTH 1280
# define HEIGHT 1000

/* Structures */
typedef struct	s_camera
{
	t_vec3	pos;
	t_vec3	front;
	t_vec3	up;
	float	yaw;
	float	pitch;
	float	fov;
}				t_camera;

/* Function prototypes */
char			*readFile(const char* filePath);
unsigned int	ft_load_texture(const char *path);

unsigned int	ft_newShader(const char *vertexPath, const char *fragmentPath);

t_mat4			ft_lookat(const t_vec3 camPos, const t_vec3 targetPos, const t_vec3 worldUp);

#endif
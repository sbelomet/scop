/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:59:43 by sbelomet          #+#    #+#             */
/*   Updated: 2025/10/28 16:22:36 by sbelomet         ###   ########.fr       */
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

/* Enums */
enum e_tex_type
{
	TEX_DIFF,
	TEX_SPEC
};

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

typedef struct	s_vertex
{
	t_vec3	position;
	t_vec3	normal;
	t_vec2	tex_coords;
}				t_vertex;

typedef struct	s_texture
{
	unsigned int	id;
	unsigned int	type;
}				t_texture;

typedef struct	s_mesh
{
	t_vertex		*vertices;
	unsigned int	*indices;
	t_texture		*textures;

	unsigned int	vert_count;
	unsigned int	index_count;
	unsigned int	tex_count;

	unsigned int	VAO;
	unsigned int	VBO;
	unsigned int	EBO;
}				t_mesh;

typedef struct	s_model
{
	t_mesh			*meshes;
	unsigned int	mesh_count;
	char			*dir;
}				t_model;


/* Function prototypes */
int				startswithmtllib(char *line);
int				startswithusemtl(char *line);

int				ft_parse_mtllib(line);
int				ft_parse_mesh(line);
int				ft_parse_vertex(line);
int				ft_parse_texcoord(line);
int				ft_parse_normal(line);
int				ft_parse_usemtl(line);
int				ft_parse_smooth(line);
int				ft_parse_face(line);

char			*readFile(const char* filePath);
unsigned int	ft_load_texture(const char *path);

unsigned int	ft_newShader(const char *vertexPath, const char *fragmentPath);

void			ft_mesh_setup(t_mesh *mesh);
void			ft_mesh_draw(t_mesh *mesh, unsigned int shader);

t_mat4			ft_lookat(const t_vec3 camPos, const t_vec3 targetPos, const t_vec3 worldUp);

#endif
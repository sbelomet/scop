/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:20:33 by sbelomet          #+#    #+#             */
/*   Updated: 2025/10/30 15:55:55 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static t_vec2 cutout2coord(char *line, int start_offset)
{
	t_vec2 res;
	int end = 0;
	int start = 0;

	if (!line)
		return (ft_vec2(0, 0));

	for (size_t i = 0; i < 1; i++)
	{
		start = start_offset + end;
		end = start;
		while (line[end] && line[end] != ' ')
			end++;
		char *coord = ft_substr(line, start, end - start);
		end++;
		if (coord)
		{
			res.v[i] = atof(coord);
			free(coord);
		}
		else
			res.v[i] = 0;
	}
	return (res);
}

static t_vec3 cutout3coord(char *line, int start_offset)
{
	t_vec3 res;
	int end = 0;
	int start = 0;

	if (!line)
		return (ft_vec3_null());

	for (size_t i = 0; i < 2; i++)
	{
		start = start_offset + end;
		end = start;
		while (line[end] && line[end] != ' ')
			end++;
		char *coord = ft_substr(line, start, end - start);
		end++;
		if (coord)
		{
			res.v[i] = atof(coord);
			free(coord);
		}
		else
			res.v[i] = 0;
	}
	return (res);
}

int	ft_parse_mtllib(char *)
{
	return (GL_TRUE);
}

int	ft_parse_mesh(t_base *base, char *line)
{
	t_mesh new_mesh;

	new_mesh.vertices = NULL;
	new_mesh.indices = NULL;
	new_mesh.textures = NULL;
	new_mesh.vert_count = 0;
	new_mesh.vert_capacity = 0;
	new_mesh.index_count = 0;
	new_mesh.index_capacity = 0;
	new_mesh.tex_count = 0;
	new_mesh.tex_capacity = 0;
	new_mesh.VAO = 0;
	new_mesh.VBO = 0;
	new_mesh.EBO = 0;

	if (ft_mesh_push(&(base->model), base->model.meshes, &new_mesh))
		return (GL_FALSE);
	return (GL_TRUE);
}

int	ft_parse_vertex(t_base *base, char *line, int i)
{
	t_vertex new_vert;

	new_vert.position = cutout3coord(line, 2);
	new_vert.normal = ft_vec3_null();
	new_vert.tex_coords = ft_vec2(0, 0);

	if (!(base->model.meshes) || (base->model.mesh_count < i + 1))
		return (GL_FALSE);

	if (ft_vertex_push(&(base->model.meshes[i]), base->model.meshes[i].vertices, &new_vert))
		return (GL_FALSE);
	return (GL_TRUE);
}

int	ft_parse_texcoord(t_base *base, char *line, int mesh_i, int vert_i)
{	
	if (!(base->model.meshes) || (base->model.mesh_count < mesh_i + 1))
		return (GL_FALSE);
	
	if (!(base->model.meshes[mesh_i].vertices) || (base->model.meshes[mesh_i].vert_count < vert_i + 1))
		return (GL_FALSE);
	
	base->model.meshes->vertices[vert_i].tex_coords = cutout2coord(line, 3);

	return (GL_TRUE);
}

int	ft_parse_normal(t_base *base, char *line, int mesh_i, int vert_i)
{	
	if (!(base->model.meshes) || (base->model.mesh_count < mesh_i + 1))
		return (GL_FALSE);
	
	if (!(base->model.meshes[mesh_i].vertices) || (base->model.meshes[mesh_i].vert_count < vert_i + 1))
		return (GL_FALSE);
	
	base->model.meshes->vertices[vert_i].normal = ft_vec3_normalize(cutout3coord(line, 3));

	return (GL_TRUE);
}

int	ft_parse_usemtl(char *)
{
	return (GL_TRUE);
}

int	ft_parse_smooth(char *)
{
	return (GL_TRUE);
}

int	ft_parse_face(t_base *base, char *line, int i)
{
	if (!(base->model.meshes) || (base->model.mesh_count < i + 1))
		return (GL_FALSE);
	
	if (ft_index_push(&(base->model.meshes[i]), base->model.meshes[i].indices, new_index))
		return (GL_FALSE);
	return (GL_TRUE);
}
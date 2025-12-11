/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:20:33 by sbelomet          #+#    #+#             */
/*   Updated: 2025/12/11 13:05:43 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int	ft_parse_mtllib(char *)
{
	return (GL_TRUE);
}

int	ft_parse_mesh(t_base *base, char *)
{
	t_mesh new_mesh;
	new_mesh.vertices = malloc(sizeof(t_vertex));
	new_mesh.indices = malloc(sizeof(unsigned int));
	new_mesh.textures = malloc(sizeof(t_texture));
	new_mesh.vert_count = 0;
	new_mesh.vert_capacity = 1;
	new_mesh.index_count = 0;
	new_mesh.index_capacity = 1;
	new_mesh.tex_count = 0;
	new_mesh.tex_capacity = 1;
	new_mesh.VAO = 0;
	new_mesh.VBO = 0;
	new_mesh.EBO = 0;

	if (!ft_mesh_push(&(base->model), &new_mesh))
		return (GL_FALSE);
	printf("base->model.mesh_count: %i\n", base->model.mesh_count);
	return (GL_TRUE);
}

int	ft_parse_vertex(t_base *base, char *line, int i)
{
	printf("start of parse vert %i\n", base->model.meshes[i].vert_count);
	t_vertex new_vert;

	new_vert.position = cutout3coord(line, 2);
	new_vert.normal = ft_vec3_null();
	new_vert.tex_coords = ft_vec2(0, 0);

	if (!(base->model.meshes) || (base->model.mesh_count < (unsigned int)(i + 1)))
		return (GL_FALSE);

	if (!ft_vertex_push(&(base->model.meshes[i]), &new_vert))
		return (GL_FALSE);
	return (GL_TRUE);
}

int	ft_parse_texcoord(t_base *base, char *line, int mesh_i, int vert_i)
{
	printf("mesh_i : %i, vert_i: %i\n", mesh_i, vert_i);
	if (!(base->model.meshes) || (base->model.mesh_count < (unsigned int)(mesh_i + 1)))
		return (GL_FALSE);
	
	if (!(base->model.meshes[mesh_i].vertices))
		return (GL_FALSE);
	if (base->model.meshes[mesh_i].vert_count >= (unsigned int)(vert_i + 1))
	{
		printf("adding tex coord\n");
		base->model.meshes[mesh_i].vertices[vert_i].tex_coords = cutout2coord(line, 3);
		printf("added\n");
		return (GL_TRUE);
	}
	
	t_vertex new_vert;

	new_vert.position = ft_vec3_null();
	new_vert.normal = ft_vec3_null();
	new_vert.tex_coords = cutout2coord(line, 3);

	if (!ft_vertex_push(&(base->model.meshes[mesh_i]), &new_vert))
		return (GL_FALSE);
	return (GL_TRUE);
}

int	ft_parse_normal(t_base *base, char *line, int mesh_i, int vert_i)
{
	printf("start of parse normal\n");
	if (!(base->model.meshes) || (base->model.mesh_count < (unsigned int)(mesh_i + 1)))
		return (GL_FALSE);
	
	if (!(base->model.meshes[mesh_i].vertices))
		return (GL_FALSE);
	if (base->model.meshes[mesh_i].vert_count >= (unsigned int)(vert_i + 1))
	{
		printf("adding normal coord\n");
		base->model.meshes[mesh_i].vertices[vert_i].normal = ft_vec3_normalize(cutout3coord(line, 3));
		printf("added\n");
		return (GL_TRUE);
	}
	
	t_vertex new_vert;

	new_vert.position = ft_vec3_null();
	new_vert.normal = ft_vec3_normalize(cutout3coord(line, 3));
	new_vert.tex_coords = ft_vec2(0, 0);

	if (!ft_vertex_push(&(base->model.meshes[mesh_i]), &new_vert))
		return (GL_FALSE);
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

int	ft_parse_face(t_base *base, char *line, int mesh_i)
{
	printf("start f face\n");
	if (!valid_line(line + 2))
		return (GL_FALSE);
		
	if (!(base->model.meshes) || (base->model.mesh_count < (unsigned int)(mesh_i + 1)))
		return (GL_FALSE);
		
	unsigned int *indices = cutout_indices(line);
	if (!indices)
		return (GL_FALSE);

	for (size_t i = 0; i < 9; i++)
	{
		if (indices[i] == 0)
		{
			free(indices);
			return (GL_FALSE);
		}
		if (!ft_index_push(&(base->model.meshes[mesh_i]), &(indices[i])))
		{
			free(indices);
			return (GL_FALSE);
		}
	}

	free(indices);

	return (GL_TRUE);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:33:47 by sbelomet          #+#    #+#             */
/*   Updated: 2025/11/05 12:07:10 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static int safe_mul_overflow_size(size_t count, size_t size)
{
    if (size != 0 && count > SIZE_MAX / size)
        return 1; /* overflow */
    return 0;
}

int ft_mesh_reserve(t_model *model, t_mesh *meshes, size_t new_capacity)
{
    if (!meshes) return 0;
    if (new_capacity <= model->mesh_capacity) return 1;
    if (safe_mul_overflow_size(new_capacity, sizeof(t_mesh))) return 0;
    t_mesh *tmp = realloc(meshes, new_capacity * sizeof(t_mesh));
    if (!tmp) return 0;
    meshes = tmp;
    model->mesh_capacity = new_capacity;
    return 1;
}

int	ft_mesh_push(t_model *model, t_mesh *meshes, const t_mesh *new)
{
	if (!meshes || !new) return 0;
    if (model->mesh_count == model->mesh_capacity)
	{
        size_t newc = model->mesh_capacity ? model->mesh_capacity * 2 : 8;
        if (newc < model->mesh_capacity) return 0; /* overflow */
        if (!ft_mesh_reserve(model, meshes, newc)) return 0;
    }
    meshes[model->mesh_count++] = *new;
    return 1;
}

int ft_vertex_reserve(t_mesh *mesh, t_vertex *vertices, size_t new_capacity)
{
    if (!vertices) return 0;
    if (new_capacity <= mesh->vert_capacity) return 1;
    if (safe_mul_overflow_size(new_capacity, sizeof(t_vertex))) return 0;
    t_vertex *tmp = realloc(vertices, new_capacity * sizeof(t_vertex));
    if (!tmp) return 0;
    vertices = tmp;
    mesh->vert_capacity = new_capacity;
    return 1;
}

int	ft_vertex_push(t_mesh *mesh, t_vertex *vertices, const t_vertex *new)
{
	if (!vertices || !new) return 0;
    if (mesh->vert_count == mesh->vert_capacity)
	{
        size_t newc = mesh->vert_capacity ? mesh->vert_capacity * 2 : 8;
        if (newc < mesh->vert_capacity) return 0; /* overflow */
        if (!ft_vertex_reserve(mesh, vertices, newc)) return 0;
    }
    vertices[mesh->vert_count++] = *new;
    return 1;
}

int ft_index_reserve(t_mesh *mesh, unsigned int *vertices, size_t new_capacity)
{
    if (!vertices) return 0;
    if (new_capacity <= mesh->vert_capacity) return 1;
    if (safe_mul_overflow_size(new_capacity, sizeof(unsigned int))) return 0;
    unsigned int *tmp = realloc(vertices, new_capacity * sizeof(unsigned int));
    if (!tmp) return 0;
    vertices = tmp;
    mesh->vert_capacity = new_capacity;
    return 1;
}

int	ft_index_push(t_mesh *mesh, unsigned int *indices, const unsigned int *new)
{
	if (!indices || !new) return 0;
    if (mesh->index_count == mesh->index_capacity)
	{
        size_t newc = mesh->index_capacity ? mesh->index_capacity * 2 : 8;
        if (newc < mesh->index_capacity) return 0; /* overflow */
        if (!ft_index_reserve(mesh, indices, newc)) return 0;
    }
    indices[mesh->index_count++] = *new;
    return 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:33:47 by sbelomet          #+#    #+#             */
/*   Updated: 2025/11/05 15:01:18 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static int safe_mul_overflow_size(size_t count, size_t size)
{
    if (size != 0 && count > SIZE_MAX / size)
        return 1; /* overflow */
    return 0;
}

int ft_mesh_reserve(t_model *model, size_t new_capacity)
{
    if (!model) return 0;
    if (new_capacity <= model->mesh_capacity) return 1;
    if (safe_mul_overflow_size(new_capacity, sizeof(t_mesh))) return 0;
    if (!model->meshes)
    {
        t_mesh *tmp = malloc(new_capacity * sizeof(t_mesh));
        if (!tmp) return 0;
        memset(tmp, 0, new_capacity * sizeof(t_mesh));
        model->meshes = tmp;
        model->mesh_capacity = new_capacity;
        return 1;
    }
    t_mesh *tmp = realloc(model->meshes, new_capacity * sizeof(t_mesh));
    if (!tmp) return 0;
    /* zero the newly allocated area to avoid uninitialized counts */
    if (new_capacity > model->mesh_capacity)
        memset((char*)tmp + model->mesh_capacity * sizeof(t_mesh), 0,
               (new_capacity - model->mesh_capacity) * sizeof(t_mesh));
    model->meshes = tmp;
    model->mesh_capacity = new_capacity;
    return 1;
}

int	ft_mesh_push(t_model *model, const t_mesh *new)
{
	printf("startof mesh push\n");
	if (!new) return 0;
	printf("1\n");
    if (model->mesh_count == model->mesh_capacity)
	{
        size_t newc = model->mesh_capacity ? model->mesh_capacity * 2 : 8;
		printf("newc: %li\n", newc);
        if (newc < model->mesh_capacity) return 0; /* overflow */
        if (!ft_mesh_reserve(model, newc)) return 0;
    }
	printf("4\n");
	printf("model.mesh_count: %i\n", model->mesh_count);
	printf("model.mesh_cap: %i\n", model->mesh_capacity);
    model->meshes[model->mesh_count++] = *new;
	printf("model.mesh_count: %i\n", model->mesh_count);
    return 1;
}

int ft_vertex_reserve(t_mesh *mesh, size_t new_capacity)
{
    if (!mesh) return 0;
    if (new_capacity <= mesh->vert_capacity) return 1;
    if (safe_mul_overflow_size(new_capacity, sizeof(t_vertex))) return 0;
    if (!mesh->vertices)
    {
        t_vertex *tmp = malloc(new_capacity * sizeof(t_vertex));
        if (!tmp) return 0;
        memset(tmp, 0, new_capacity * sizeof(t_vertex));
        mesh->vertices = tmp;
        mesh->vert_capacity = new_capacity;
        return 1;
    }
    t_vertex *tmp = realloc(mesh->vertices, new_capacity * sizeof(t_vertex));
    if (!tmp) return 0;
    mesh->vertices = tmp;
    mesh->vert_capacity = new_capacity;
    return 1;
}

int	ft_vertex_push(t_mesh *mesh, const t_vertex *new)
{
	if (!new) return 0;
    if (mesh->vert_count == mesh->vert_capacity)
	{
        size_t newc = mesh->vert_capacity ? mesh->vert_capacity * 2 : 8;
        if (newc < mesh->vert_capacity) return 0; /* overflow */
        if (!ft_vertex_reserve(mesh, newc)) return 0;
    }
    mesh->vertices[mesh->vert_count++] = *new;
    return 1;
}

int ft_index_reserve(t_mesh *mesh, size_t new_capacity)
{
    if (!mesh) return 0;
    if (new_capacity <= mesh->index_capacity) return 1;
    if (safe_mul_overflow_size(new_capacity, sizeof(unsigned int))) return 0;
    if (!mesh->indices)
    {
        unsigned int *tmp = malloc(new_capacity * sizeof(unsigned int));
        if (!tmp) return 0;
        memset(tmp, 0, new_capacity * sizeof(unsigned int));
        mesh->indices = tmp;
        mesh->index_capacity = new_capacity;
        return 1;
    }
    unsigned int *tmp = realloc(mesh->indices, new_capacity * sizeof(unsigned int));
    if (!tmp) return 0;
    mesh->indices = tmp;
    mesh->index_capacity = new_capacity;
    return 1;
}

int	ft_index_push(t_mesh *mesh, const unsigned int *new)
{
	if (!new) return 0;
    if (mesh->index_count == mesh->index_capacity)
	{
        size_t newc = mesh->index_capacity ? mesh->index_capacity * 2 : 8;
        if (newc < mesh->index_capacity) return 0; /* overflow */
        if (!ft_index_reserve(mesh, newc)) return 0;
    }
    mesh->indices[mesh->index_count++] = *new;
    return 1;
}

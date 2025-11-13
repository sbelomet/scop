/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:48:54 by sbelomet          #+#    #+#             */
/*   Updated: 2025/11/13 11:01:22 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int ft_model_dump_debug(const t_model *model, const char *path)
{
    if (!model || !path) return 0;
    FILE *f = fopen(path, "w");
    if (!f) return 0;

    fprintf(f, "model.mesh_count = %u\n", model->mesh_count);
    for (unsigned int m = 0; m < model->mesh_count; ++m)
    {
        const t_mesh *mesh = &model->meshes[m];
        fprintf(f, "\n# --- mesh %u ---\n", m);
        fprintf(f, "vert_count=%u vert_capacity=%u\n", mesh->vert_count, mesh->vert_capacity);
        fprintf(f, "index_count=%u index_capacity=%u\n", mesh->index_count, mesh->index_capacity);
        fprintf(f, "tex_count=%u tex_capacity=%u\n", mesh->tex_count, mesh->tex_capacity);

        fprintf(f, "\n# vertices (position.x position.y position.z)\n");
        for (unsigned int i = 0; i < mesh->vert_count; ++i)
        {
            t_vec3 p = mesh->vertices[i].position;
            fprintf(f, "v % .6f % .6f % .6f\n", p.v[0], p.v[1], p.v[2]);
        }

        fprintf(f, "\n# texcoords (u v)\n");
        for (unsigned int i = 0; i < mesh->vert_count; ++i)
        {
            t_vec2 uv = mesh->vertices[i].tex_coords;
            fprintf(f, "vt % .6f % .6f\n", uv.v[0], uv.v[1]);
        }

        fprintf(f, "\n# normals (x y z)\n");
        for (unsigned int i = 0; i < mesh->vert_count; ++i)
        {
            t_vec3 n = mesh->vertices[i].normal;
            fprintf(f, "vn % .6f % .6f % .6f\n", n.v[0], n.v[1], n.v[2]);
        }

        fprintf(f, "\n# indices (triples)\n");
        for (unsigned int i = 0; i + 2 < mesh->index_count; i += 3)
        {
			fprintf(f, "tri %u %u %u\n", mesh->indices[i], mesh->indices[i+1], mesh->indices[i+2]);
        }
    }

    fclose(f);
    return 1;
}
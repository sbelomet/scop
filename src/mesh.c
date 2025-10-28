/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:58:57 by sbelomet          #+#    #+#             */
/*   Updated: 2025/10/28 13:22:27 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	ft_mesh_setup(t_mesh *mesh)
{
	// Generate the Vertex Array Object, the Vertex Buffer Object and the Element Buffer Object
	glGenVertexArrays(1, &mesh->VAO);
	glGenBuffers(1, &mesh->VBO);
	glGenBuffers(1, &mesh->EBO);

	// Bind VAO
	glBindVertexArray(mesh->VAO);

	// Bind and fill VBO
	glBindBuffer(GL_ARRAY_BUFFER, mesh->VBO);
	glBufferData(GL_ARRAY_BUFFER, mesh->vert_count * sizeof(t_vertex), mesh->vertices, GL_STATIC_DRAW);

	// Bind and fill EBO if indices exist
	if (mesh->indices && mesh->index_count > 0)
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->index_count * sizeof(unsigned int), mesh->indices, GL_STATIC_DRAW);
	}

	// Fill the VAO
	// position (location = 0)
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(t_vertex), (void*)offsetof(t_vertex, position));
	// normal (location = 1)
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(t_vertex), (void*)offsetof(t_vertex, normal));
	// tex coords (location = 2)
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(t_vertex), (void*)offsetof(t_vertex, tex_coords));

	// unbind VAO
	glBindVertexArray(0);
}

void	ft_mesh_draw(t_mesh *mesh, unsigned int shader)
{
	unsigned int diffuse_nbr = 1;
	unsigned int specular_nbr = 1;

	// Make texture names (expected syntax: texture_[type][number])
	for (unsigned int i = 0; i < mesh->tex_count; i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);
		char *str;
		char *temp;
		unsigned int type = mesh->textures[i].type;
		if (type == TEX_DIFF)
		{
			temp = ft_itoa(diffuse_nbr++);
			str = ft_strjoin("texture_diffuse", temp);
			if (temp) free(temp);
		}
		else if (type == TEX_SPEC)
		{
			temp = ft_itoa(specular_nbr++);
			str = ft_strjoin("texture_specular", temp);
			if (temp) free(temp);
		}
		else
		{
			printf("bad texture\n");
			return ;
		}

		temp = ft_strjoin("material.", str);
		if (str) free(str);
		// Set name in shader
		glUniform1i(glGetUniformLocation(shader, temp), i);
		if (temp) free(temp);
		glBindTexture(GL_TEXTURE_2D, mesh->textures[i].id);
	}
	glActiveTexture(GL_TEXTURE0);

	// Draw the mesh
	glBindVertexArray(mesh->VAO);
	glDrawElements(GL_TRIANGLES, mesh->index_count, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

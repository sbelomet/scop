/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:34:43 by sbelomet          #+#    #+#             */
/*   Updated: 2025/11/05 11:52:32 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	ft_model_setup(t_model *model)
{
	for (unsigned int i = 0; i < model->mesh_count; i++)
		ft_mesh_setup(&(model->meshes[i]));
}

void	ft_model_draw(t_model *model, unsigned int shader)
{
	for (unsigned int i = 0; i < model->mesh_count; i++)
		ft_mesh_draw(&(model->meshes[i]), shader);
}

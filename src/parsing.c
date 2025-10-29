/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:20:33 by sbelomet          #+#    #+#             */
/*   Updated: 2025/10/29 16:04:18 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int	ft_parse_mtllib(char *)
{
	return (GL_TRUE);
}

int	ft_parse_mesh(t_base *base, char *line)
{
	t_mesh new_mesh;
	ft_mesh_push(base, base->model.meshes, &new_mesh);
}

int	ft_parse_vertex(t_base *base, char *line)
{

}

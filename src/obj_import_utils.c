/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_import_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:50:43 by sbelomet          #+#    #+#             */
/*   Updated: 2025/10/28 16:16:18 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int	startswithmtllib(char *line)
{
	if (!line)
		return (GL_FALSE);
	if (line[0] == 'm'
		&& line[1] == 't'
		&& line[2] == 'l'
		&& line[3] == 'l'
		&& line[4] == 'i'
		&& line[5] == 'b'
		&& line[6] == ' ') return (GL_TRUE);
	return (GL_FALSE);
}

int	startswithusemtl(char *line)
{
	if (!line)
		return (GL_FALSE);
	if (line[0] == 'u'
		&& line[1] == 's'
		&& line[2] == 'e'
		&& line[3] == 'm'
		&& line[4] == 't'
		&& line[5] == 'l'
		&& line[6] == ' ') return (GL_TRUE);
	return (GL_FALSE);
}

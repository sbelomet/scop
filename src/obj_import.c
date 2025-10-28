/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_import.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:30:10 by sbelomet          #+#    #+#             */
/*   Updated: 2025/10/28 16:18:23 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	ft_load_obj(char *path)
{
	int fd = open(path, O_RDONLY);
	if (fd < 0)
		return (printf("Failed to open file: %s\n", path));

	int fail = 0;
	char *line;
	while (GL_TRUE)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			fail = 1;
			break;
		}
		if (line[0] == '#')
		{
			if (line) free(line);
			continue;
		}
		else if (startswithmtllib(line))
		{
			if (ft_parse_mtllib(line))
			{
				fail = 1;
				ft_putstr_fd("bad mtllib\n", 1);
				if (line) free(line);
				break ;
			}
		}
		else if (line[0] == 'o' && line[1] == ' ')
		{
			if (ft_parse_mesh(line))
			{
				fail = 1;
				ft_putstr_fd("bad mesh name\n", 1);
				if (line) free(line);
				break ;
			}
		}
		else if (line[0] == 'v' && line[1] == ' ')
		{
			if (ft_parse_vertex(line))
			{
				fail = 1;
				ft_putstr_fd("bad vertex coord\n", 1);
				if (line) free(line);
				break ;
			}
		}
		else if (line[0] == 'v' && line[1] == 't' && line[2] == ' ')
		{
			if (ft_parse_texcoord(line))
			{
				fail = 1;
				ft_putstr_fd("bad texture coord\n", 1);
				if (line) free(line);
				break ;
			}
		}
		else if (line[0] == 'v' && line[1] == 'n' && line[2] == ' ')
		{
			if (ft_parse_normal(line))
			{
				fail = 1;
				ft_putstr_fd("bad normal\n", 1);
				if (line) free(line);
				break ;
			}
		}
		else if (startswithusemtl(line))
		{
			if (ft_parse_usemtl(line))
			{
				fail = 1;
				ft_putstr_fd("bad usemtl\n", 1);
				if (line) free(line);
				break ;
			}
		}
		else if (line[0] == 's' && line[1] == ' ')
		{
			if (ft_parse_smooth(line))
			{
				fail = 1;
				ft_putstr_fd("bad smooth\n", 1);
				if (line) free(line);
				break ;
			}
		}
		else if (line[0] == 'f' && line[1] == ' ')
		{
			if (ft_parse_face(line))
			{
				fail = 1;
				ft_putstr_fd("bad face\n", 1);
				if (line) free(line);
				break ;
			}
		}
		if (line)
			free(line);
	};
}

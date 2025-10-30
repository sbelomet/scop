/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_import.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:30:10 by sbelomet          #+#    #+#             */
/*   Updated: 2025/10/30 15:31:54 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	ft_load_obj(t_base *base, char *path)
{
	int fd = open(path, O_RDONLY);
	if (fd < 0)
		return (printf("Failed to open file: %s\n", path));

	int mesh_i = -1;
	int vert_i = 0;
	int fail = 0;
	int last = -1;
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
			if (last != -1)
			{
				fail = 1;
				ft_putstr_fd("bad mtllib placement\n", 1);
				if (line) free(line);
				break ;
			}
			if (ft_parse_mtllib(line))
			{
				fail = 1;
				ft_putstr_fd("bad mtllib\n", 1);
				if (line) free(line);
				break ;
			}
			last = OBJ_ML;
		}
		else if (line[0] == 'o' && line[1] == ' ')
		{
			if (last != -1 && last != OBJ_ML && last != OBJ_F)
			{
				fail = 1;
				ft_putstr_fd("bad mesh placement\n", 1);
				if (line) free(line);
				break ;
			}
			if (ft_parse_mesh(base, line))
			{
				fail = 1;
				ft_putstr_fd("bad mesh name\n", 1);
				if (line) free(line);
				break ;
			}
			last = OBJ_O;
			mesh_i++;
		}
		else if (line[0] == 'v' && line[1] == ' ')
		{
			if (last != OBJ_O && last != OBJ_V)
			{
				fail = 1;
				ft_putstr_fd("bad vertex coord placement\n", 1);
				if (line) free(line);
				break ;
			}
			if (ft_parse_vertex(base, line, mesh_i))
			{
				fail = 1;
				ft_putstr_fd("bad vertex coord\n", 1);
				if (line) free(line);
				break ;
			}
			last = OBJ_V;
		}
		else if (line[0] == 'v' && line[1] == 't' && line[2] == ' ')
		{
			if (last != OBJ_V && last != OBJ_VT)
			{
				fail = 1;
				ft_putstr_fd("bad texture coord placement\n", 1);
				if (line) free(line);
				break ;
			}
			if (last == OBJ_V)
				vert_i = 0;
			if (ft_parse_texcoord(base, line, mesh_i, vert_i))
			{
				fail = 1;
				ft_putstr_fd("bad texture coord\n", 1);
				if (line) free(line);
				break ;
			}
			last = OBJ_VT;
			vert_i++;
		}
		else if (line[0] == 'v' && line[1] == 'n' && line[2] == ' ')
		{
			if (last != OBJ_VT && last != OBJ_VN)
			{
				fail = 1;
				ft_putstr_fd("bad normal placement\n", 1);
				if (line) free(line);
				break ;
			}
			if (last == OBJ_VT)
				vert_i = 0;
			if (ft_parse_normal(base, line, mesh_i, vert_i))
			{
				fail = 1;
				ft_putstr_fd("bad normal\n", 1);
				if (line) free(line);
				break ;
			}
			last = OBJ_VN;
			vert_i++;
		}
		else if (startswithusemtl(line))
		{
			if (last != OBJ_VN)
			{
				fail = 1;
				ft_putstr_fd("bad usemtl placement\n", 1);
				if (line) free(line);
				break ;
			}
			if (ft_parse_usemtl(line))
			{
				fail = 1;
				ft_putstr_fd("bad usemtl\n", 1);
				if (line) free(line);
				break ;
			}
			last = OBJ_UM;
		}
		else if (line[0] == 's' && line[1] == ' ')
		{
			if (last != OBJ_UM && last != OBJ_F)
			{
				fail = 1;
				ft_putstr_fd("bad smooth placement\n", 1);
				if (line) free(line);
				break ;
			}
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
			if (last != OBJ_UM && last != OBJ_F)
			{
				fail = 1;
				ft_putstr_fd("bad face placement\n", 1);
				if (line) free(line);
				break ;
			}
			if (ft_parse_face(base, line))
			{
				fail = 1;
				ft_putstr_fd("bad face\n", 1);
				if (line) free(line);
				break ;
			}
			last = OBJ_F;
		}
		if (line)
			free(line);
	};
}

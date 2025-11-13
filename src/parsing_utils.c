/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:06:30 by sbelomet          #+#    #+#             */
/*   Updated: 2025/11/13 13:15:58 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int	valid_line(char *arg)
{
	while (*arg)
	{
		if (!ft_isdigit(*arg) && !(*arg == '/')  && !(*arg == ' '))
			return (0);
		arg++;
	}
	return (1);
}

t_vec2 cutout2coord(char *line, int start_offset)
{
	t_vec2 res;
	int end = start_offset;
	int start = start_offset;

	if (!line)
		return (ft_vec2(0, 0));

	for (size_t i = 0; i < 2; i++)
	{
		start = end;
		while (line[end] && line[end] != ' ')
			end++;
		char *coord = ft_substr(line, start, end - start);
		end++;
		if (coord)
		{
			res.v[i] = atof(coord);
			free(coord);
		}
		else
			res.v[i] = 0;
	}
	return (res);
}

t_vec3 cutout3coord(char *line, int start_offset)
{
	t_vec3 res;
	int end = start_offset;
	int start = start_offset;

	if (!line)
		return (ft_vec3_null());

	for (size_t i = 0; i < 3; i++)
	{
		start = end;
		while (line[end] && line[end] != ' ')
			end++;

		char *coord = ft_substr(line, start, end - start);
		end++;
		if (coord)
		{
			res.v[i] = atof(coord);
			free(coord);
		}
		else
			res.v[i] = 0;
	}
	return (res);
}

unsigned int *cutout_indices(char *line)
{
	unsigned int *res = malloc(sizeof(unsigned int) * 9);
	if (!res) return NULL;
	int end = 2;
	int start = 2;

	for (size_t i = 0; i < 9; i++)
	{
		start = end;
		while (line[end] && line[end] != '/' && line[end] != ' ')
			end++;
		printf("start: %i\n", start);
		printf("end: %i\n", end);
		if (line[start]) printf("line[start]: %c\n", line[start]);
		if (line[end]) printf("line[end]: %c\n", line[end]);
		char *index = ft_substr(line, start, end - start);
		printf("index: %s\n", index);
		end++;
		if (index)
		{
			res[i] = atoi(index);
			free(index);
		}
		else
			res[i] = 0;
	}
	return (res);
}

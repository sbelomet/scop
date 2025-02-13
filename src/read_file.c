/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:23:01 by sbelomet          #+#    #+#             */
/*   Updated: 2025/02/13 13:57:20 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

char	*readFile(const char* filePath)
{
	int	fd;
	char *line;
	char *content;
	char *temp;

	fd = open(filePath, O_RDONLY);
	if (fd < 0)
		return (printf("Failed to open file: %s\n", filePath), NULL);
	content = ft_strdup("");
	line = ft_strdup("");
	while (line != NULL)
	{
		line = get_next_line(fd);
		temp = content;
		content = ft_strjoin(content, line);
		if (temp)
			free(temp);
		temp = content;
		content = ft_strjoin(content, "\n");
		if (temp)
			free(temp);
		if (line)
			free(line);
	}
	return (close(fd), content);
}

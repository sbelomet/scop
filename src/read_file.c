/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:23:01 by sbelomet          #+#    #+#             */
/*   Updated: 2025/10/02 11:43:04 by sbelomet         ###   ########.fr       */
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
	do	
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
	} while (line != NULL);
	return (close(fd), content);
}

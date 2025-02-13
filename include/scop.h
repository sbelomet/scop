/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:59:43 by sbelomet          #+#    #+#             */
/*   Updated: 2025/02/13 17:23:36 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

/* Custom libraries */
# include "libft.h"

/* External libraries */
# include <glad/glad.h>
# include <GLFW/glfw3.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <stb_image.h>

/* Function prototypes */
char			*readFile(const char* filePath);

unsigned int	ft_newShader(const char *vertexPath, const char *fragmentPath);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:59:43 by sbelomet          #+#    #+#             */
/*   Updated: 2025/10/21 15:17:36 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

/* C libraries */
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

/* Custom libraries */
# include "libft.h"
# include "libftmath.h"

/* External libraries */
# include <glad/glad.h>
# include <GLFW/glfw3.h>
# include <stb_image.h>

# define WIDTH 1280
# define HEIGHT 1000

/* Function prototypes */
char			*readFile(const char* filePath);

unsigned int	ft_newShader(const char *vertexPath, const char *fragmentPath);

#endif
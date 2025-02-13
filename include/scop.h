/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:59:43 by sbelomet          #+#    #+#             */
/*   Updated: 2025/02/13 14:14:39 by sbelomet         ###   ########.fr       */
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

/* Function prototypes */
char	*readFile(const char* filePath);

#endif
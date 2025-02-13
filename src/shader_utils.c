/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:55:00 by sbelomet          #+#    #+#             */
/*   Updated: 2025/02/13 15:19:55 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

unsigned int	ft_newShader(const char *vertexPath, const char *fragmentPath)
{
	char	*vertexShaderSource = readFile(vertexPath);
	char	*fragmentShaderSource = readFile(fragmentPath);
	if (!vertexShaderSource || !fragmentShaderSource)
		printf("Shader files not successfully read\n");
	
	unsigned int vertex, fragment;
	int success;
	char infoLog[512];

	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, (const GLchar * const *)&vertexShaderSource, NULL);
	glCompileShader(vertex);
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		printf("Vertex shader compilation error: %s\n", infoLog);
	}

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, (const GLchar * const *)&fragmentShaderSource, NULL);
	glCompileShader(fragment);
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment, 512, NULL, infoLog);
		printf("Fragment shader compilation error: %s\n", infoLog);
	}

	unsigned int ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);
	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		printf("Shader program linking error: %s\n", infoLog);
	}

	glDeleteShader(vertex);
	glDeleteShader(fragment);
	if (vertexShaderSource)
		free(vertexShaderSource);
	if (fragmentShaderSource)
		free(fragmentShaderSource);
	
	return (ID);
}

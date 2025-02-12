/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:17:04 by sbelomet          #+#    #+#             */
/*   Updated: 2025/02/12 15:10:22 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

void framebuffer_size_callback(GLFWwindow*, int width, int height)
{
	glViewport(0, 0, width, height);
}

int main(int, char**)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(1280, 1000, "hihi", NULL, NULL);
	if (window == NULL)
	{
		printf("Failed to create window\n");
		glfwTerminate();
		exit(-1);
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		printf("Failed to initialize GLAD\n");
		exit(-1);
	}
	while (!glfwWindowShouldClose(window))
    {
		processInput(window);

		glClearColor(.9f, .4f, .1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:17:04 by sbelomet          #+#    #+#             */
/*   Updated: 2025/02/13 15:52:24 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void processInput(GLFWwindow *window)
{
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

void framebuffer_size_callback(GLFWwindow *, int width, int height)
{
	glViewport(0, 0, width, height);
}

int main(int, char**)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow	*window = glfwCreateWindow(1280, 1000, "hihi", NULL, NULL);
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

	int nbrAttributes;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nbrAttributes);
	printf("max nbr attributes: %d\n", nbrAttributes);

	unsigned int myShader = ft_newShader("shaders/vertex_shader.glsl", "shaders/fragment_shader1.glsl");
	unsigned int myShader2 = ft_newShader("shaders/vertex_shader.glsl", "shaders/fragment_shader2.glsl");

	float vertices1[] = {
		// positions        // colors
		0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom right
		-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom left
		0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f // top
	};
	float vertices2[] = {
		0.5f, -0.5f, 0.0f,
		1.0f, -0.5f, 0.0f, 
		0.5f,  0.5f, 0.0f 
	};
	unsigned int VBOs[2], VAOs[2];
	glGenVertexArrays(2, VAOs);
	glGenBuffers(2, VBOs);
	// first triangle
	glBindVertexArray(VAOs[0]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0); //pos
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float))); //color
    glEnableVertexAttribArray(1);
	// second triangle
	glBindVertexArray(VAOs[1]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(.7f, .3f, .1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// first triangle
		glUseProgram(myShader);
		double timeValue = glfwGetTime();
		float offset = (float)(sin(timeValue) / 2.0);
		glUniform1f(glGetUniformLocation(myShader, "horiOffset"), offset);
		glUniform1f(glGetUniformLocation(myShader, "vertiOffset"), offset);
/* 		double timeValue = glfwGetTime();
		float greenValue = (float)(sin(timeValue) / 2.0 + 0.5);
		int vertexColorLocation = glGetUniformLocation(shaderPrograms[0], "ourColor");
		glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f); */

		glBindVertexArray(VAOs[0]);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		// sencond triangle
		/* glUseProgram(myShader2);
		glBindVertexArray(VAOs[1]);
		glDrawArrays(GL_TRIANGLES, 0, 3); */

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteVertexArrays(2, VAOs);
	glDeleteBuffers(2, VBOs);
	glDeleteProgram(myShader);
	glDeleteProgram(myShader2);

	glfwTerminate();
	return 0;
}

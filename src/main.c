/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:17:04 by sbelomet          #+#    #+#             */
/*   Updated: 2025/10/02 16:09:26 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

//Checks for inputs and does what need to be done
void processInput(GLFWwindow *window)
{
	// Close on ESC press
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

//Resets viewport on window resize
void framebuffer_size_callback(GLFWwindow *, int width, int height)
{
	glViewport(0, 0, width, height);
}

int main(int, char**)
{
	// Init GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create window
	GLFWwindow	*window = glfwCreateWindow(1280, 1000, "Scop yupyup", NULL, NULL);
	if (window == NULL)
	{
		ft_putstr_fd("Failed to create window\n", 1);
		glfwTerminate();
		exit(-1);
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// Init GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		ft_putstr_fd("Failed to initialize GLAD\n", 1);
		exit(-1);
	}

	int nbrAttributes;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nbrAttributes);
	printf("max nbr attributes: %d\n", nbrAttributes);

	// Create shader program
	unsigned int shaderPrograms[2]; 
	shaderPrograms[0] = ft_newShader("shaders/vertex_shader.glsl", "shaders/fragment_shader1.glsl");
	shaderPrograms[1] = ft_newShader("shaders/vertex_shader.glsl", "shaders/fragment_shader2.glsl");

	// Vertices for triangles
	float vertices1[] = {
	//	 0.5f,  0.5f,  0.0f,
	//	 0.5f, -0.5f,  0.0f,
	//	-0.5f, -0.5f,  0.0f,
	//	-0.5f,  0.5f,  0.0f
		// positions       // colors
		-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
		-0.25f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f
		
	};
	float vertices2[] = {
		// positions       // colors
		0.0f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.25f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
		0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f
	};
	unsigned int indices[] = {
		0, 1, 3,
		1, 2, 3
	};

	// Generate the Vertex Array Object, the Vertex Buffer Object and the Element Buffer Object
	unsigned int VAOs[2], VBOs[2], EBO;
	glGenVertexArrays(2, VAOs);
	glGenBuffers(2, VBOs);
	glGenBuffers(1, &EBO);

	// Bind the VAO to set it up
	glBindVertexArray(VAOs[0]);

	// Bind the VBO and add the vertices to it
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);

	// Bind the EBO and add the indices to it
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Add the attributes to the VAO
	// position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
	// color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

	// Unbind the VBO
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Unbind the VAO
	glBindVertexArray(0);

	glBindVertexArray(VAOs[1]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	// Wireframe: GL_LINE
	// Filled: GL_FILL
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	
	float offset = 0.0f;
	// Main loop
	while(!glfwWindowShouldClose(window))
	{
		// Input
		processInput(window);

		// Background color
		glClearColor(0.7f, 0.3f, 0.1f, 1.0f);
   		glClear(GL_COLOR_BUFFER_BIT);

		//float timeValue = glfwGetTime();
		offset+= 0.001f;
		
		// Draw triangles
		glUseProgram(shaderPrograms[0]);
		int vertexColorLocation = glGetUniformLocation(shaderPrograms[0], "horizontalOffset");
		glUniform1f(vertexColorLocation, offset); 
        glBindVertexArray(VAOs[0]);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glUseProgram(shaderPrograms[1]);
		vertexColorLocation = glGetUniformLocation(shaderPrograms[1], "horizontalOffset");
		glUniform1f(vertexColorLocation, offset); 
		/* float timeValue = glfwGetTime();
		float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
		int vertexColorLocation = glGetUniformLocation(shaderPrograms[1], "ourColor");
		glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f); */
        glBindVertexArray(VAOs[1]);
		glDrawArrays(GL_TRIANGLES, 0, 3);
        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		// glBindVertexArray(0); // no need to unbind it every time

		// Swap the buffers and check and call events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	// Cleaning
	glDeleteVertexArrays(2, VAOs);
    glDeleteBuffers(2, VBOs);
    glDeleteProgram(shaderPrograms[0]);
    glDeleteProgram(shaderPrograms[1]);
	
	// Stop GLFW
	glfwTerminate(); 
	return 0;
}

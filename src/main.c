/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:17:04 by sbelomet          #+#    #+#             */
/*   Updated: 2025/10/21 12:04:07 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

float mixValue = 0.2f;

//Checks for inputs and does what need to be done
void processInput(GLFWwindow *window)
{
	// Close on ESC press
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	{
		mixValue += 0.05f;
		if(mixValue >= 1.0f)
			mixValue = 1.0f;
	}
	if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		mixValue -= 0.05f;
		if(mixValue <= 0.0f)
			mixValue = 0.0f;
	}
}

//Resets viewport on window resize
void framebuffer_size_callback(GLFWwindow *, int width, int height)
{
	glViewport(0, 0, width, height);
}

int main(int, char**)
{
	// ---- INITIATIONS ----

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

	// ---- SHADERS ----
	
	// Enable the use of alpha
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Create shader program
	unsigned int shaderProgram; 
	shaderProgram = ft_newShader("shaders/vertex_shader.glsl", "shaders/fragment_shader1.glsl");

	// ---- COORDS ----

	// Vertices for triangles
	float vertices[] = {
		 // positions         // colors            // tex coords
		 0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
		 0.5f, -0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
		-0.5f, -0.5f,  0.0f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
		-0.5f,  0.5f,  0.0f,  1.0f,  1.0f,  0.0f,  0.0f,  0.0f
		
	};
	unsigned int indices[] = {
		0, 1, 3,
		1, 2, 3
	};

	// ---- VAO, VBO, EBO ----

	// Generate the Vertex Array Object, the Vertex Buffer Object and the Element Buffer Object
	unsigned int VAO, VBO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// Bind the VAO to set it up
	glBindVertexArray(VAO);

	// Bind the VBO and add the vertices to it
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Bind the EBO and add the indices to it
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Add the attributes to the VAO
	// position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
	// color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
	// texture attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

	// Unbind the VBO
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Unbind the VAO
	glBindVertexArray(0);

	// Wireframe: GL_LINE
	// Filled: GL_FILL
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// ---- TEXTURES ----

	// Generate texture
	unsigned int textures[2];
	glGenTextures(2, textures);

	// Bind the texture and set its options
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	// Load image and apply it to the texture
	int width, height, nrChannels;
	unsigned char *data = stbi_load("textures/texture2.jpg", &width, &height, &nrChannels, 0);
	if (!data)
		ft_putstr_fd("Failed to load image", 1);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	stbi_image_free(data);

	glBindTexture(GL_TEXTURE_2D, textures[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	data = stbi_load("textures/yugiohcard.png", &width, &height, &nrChannels, 0);
	if (!data)
		ft_putstr_fd("Failed to load image", 1);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	if (nrChannels == 4)
    	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	else if (nrChannels == 3)
    	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	stbi_image_free(data);

	glUseProgram(shaderProgram);
	glUniform1i(glGetUniformLocation(shaderProgram, "texture1"), 0);
	glUniform1i(glGetUniformLocation(shaderProgram, "texture2"), 1);

	t_mat4 transl = ft_mat4_transl(ft_vec4(0.5f, -0.5f, 0.0f, 0.0f));
	t_mat4 rot = ft_mat4_rot(ft_vec3(0.0f, 0.0f, 1.0f), ft_deg_to_rad(90.0f));
	//t_mat4 scale = ft_mat4_scale(ft_vec3(0.5, 0.5, 0.5));
	t_mat4 trans = ft_mat4_mul(transl, rot);
	

	unsigned int transformLoc = glGetUniformLocation(shaderProgram,"transform");
	glUniformMatrix4fv(transformLoc, 1, GL_TRUE, trans.m);

	// ---- MAIN LOOP ----
	while(!glfwWindowShouldClose(window))
	{
		// Input
		processInput(window);

		// Background color
		glClearColor(0.7f, 0.3f, 0.1f, 1.0f);
   		glClear(GL_COLOR_BUFFER_BIT);

		// Transform matrix
		t_mat4 transl = ft_mat4_transl(ft_vec4(0.5f, -0.5f, 0.0f, 0.0f));
		t_mat4 rot = ft_mat4_rot(ft_vec3(0.0f, 0.0f, 1.0f), (float)glfwGetTime());
		t_mat4 trans = ft_mat4_mul(transl, rot);
		unsigned int transformLoc = glGetUniformLocation(shaderProgram,"transform");
		glUniformMatrix4fv(transformLoc, 1, GL_TRUE, trans.m);
		
		// Draw triangles
		glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, textures[0]);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, textures[1]);
		glUseProgram(shaderProgram);
		glUniform1f(glGetUniformLocation(shaderProgram, "mixValue"), mixValue);
        glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		transl = ft_mat4_transl(ft_vec4(-0.5f, 0.5f, 0.0f, 0.0f));
		t_mat4 scale = ft_mat4_scale(ft_vec3(sin(glfwGetTime()), sin(glfwGetTime()), sin(glfwGetTime())));
		trans = ft_mat4_mul(transl, scale);
		transformLoc = glGetUniformLocation(shaderProgram,"transform");
		glUniformMatrix4fv(transformLoc, 1, GL_TRUE, trans.m);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		// Swap the buffers and check and call events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	// Cleaning
	glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);
	
	// Stop GLFW
	glfwTerminate(); 
	return 0;
}

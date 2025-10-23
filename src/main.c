/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:17:04 by sbelomet          #+#    #+#             */
/*   Updated: 2025/10/23 17:04:27 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

float	mixValue = 0.2f;

t_vec3	cameraPos, cameraFront, cameraUp;

int		firstMouse = GL_TRUE;
float	yaw = -90.0f;
float	pitch = 0.0f;
float	lastX = WIDTH / 2;
float	lastY = HEIGHT / 2;
float	fov = 45.0f;

float	deltaTime = 0.0f;
float	lastFrame = 0.0f;

//Checks for keyboard inputs and does what need to be done
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
	float cameraSpeed = 2.5f * deltaTime;
	float temp = cameraPos.v[1];
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		cameraPos = ft_vec3_add(cameraPos, ft_vec3_smul(cameraFront, cameraSpeed));
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		cameraPos = ft_vec3_sub(cameraPos, ft_vec3_smul(cameraFront, cameraSpeed));
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		cameraPos = ft_vec3_sub(cameraPos, ft_vec3_smul(ft_vec3_normalize(ft_vec3_cross(cameraFront, cameraUp)), cameraSpeed));
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		cameraPos = ft_vec3_add(cameraPos, ft_vec3_smul(ft_vec3_normalize(ft_vec3_cross(cameraFront, cameraUp)), cameraSpeed));
	cameraPos.v[1] = temp;
}

//Checks for mouse inputs and does what need to be done
void	mouse_callback(GLFWwindow *, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = GL_FALSE;
	}

	float	xoffset = xpos - lastX;
	float	yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	float	sensitivity = 0.1f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;
	
	t_vec3	direction;
	direction.v[0] = cos(ft_deg_to_rad(yaw)) * cos(ft_deg_to_rad(pitch));
	direction.v[1] = sin(ft_deg_to_rad(pitch));
	direction.v[2] = sin(ft_deg_to_rad(yaw)) * cos(ft_deg_to_rad(pitch));
	cameraFront = ft_vec3_normalize(direction);
}

void	scroll_callback(GLFWwindow *, double, double yoffset)
{
	fov -= (float)yoffset;
	if (fov < 1.0f)
		fov = 1.0f;
	if (fov > 45.0f)
		fov = 45.0f;
}

//Resets viewport on window resize
void framebuffer_size_callback(GLFWwindow *, int width, int height)
{
	glViewport(0, 0, width, height);
}

int main(int, char**)
{
	// ---- INITIATIONS ----
	cameraPos = ft_vec3(0.0f, 0.0f, 3.0f);
	cameraFront = ft_vec3(0.0f, 0.0f, -1.0f);
	cameraUp = ft_vec3(0.0f, 1.0f, 0.0f);

	// Init GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create window
	GLFWwindow	*window = glfwCreateWindow(WIDTH, HEIGHT, "Scop yupyup", NULL, NULL);
	if (window == NULL)
	{
		ft_putstr_fd("Failed to create window\n", 1);
		glfwTerminate();
		exit(-1);
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetInputMode(window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);

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

	glEnable(GL_DEPTH_TEST);

	// Create shader program
	unsigned int shaderProgram; 
	shaderProgram = ft_newShader("shaders/vertex_shader.glsl", "shaders/fragment_shader1.glsl");

	// ---- COORDS ----

	// Vertices for cube
	float vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };

	t_vec3 cubPos[] = {
		ft_vec3( 0.0f, 0.0f, 0.0f),
		ft_vec3( 2.0f, 5.0f, -15.0f),
		ft_vec3(-1.5f, -2.2f, -2.5f),
		ft_vec3(-3.8f, -2.0f, -12.3f),
		ft_vec3( 2.4f, -0.4f, -3.5f),
		ft_vec3(-1.7f, 3.0f, -7.5f),
		ft_vec3( 1.3f, -2.0f, -2.5f),
		ft_vec3( 1.5f, 2.0f, -2.5f),
		ft_vec3( 1.5f, 0.2f, -1.5f),
		ft_vec3(-1.3f, 1.0f, -1.5f)
	};


	// ---- VAO, VBO, EBO ----

	// Generate the Vertex Array Object, the Vertex Buffer Object and the Element Buffer Object
	unsigned int VAO, VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	//glGenBuffers(1, &EBO);

	// Bind the VAO to set it up
	glBindVertexArray(VAO);

	// Bind the VBO and add the vertices to it
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Bind the EBO and add the indices to it
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Add the attributes to the VAO
	// position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
	// color attribute
    //glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    //glEnableVertexAttribArray(1);
	// texture attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

	// Wireframe: GL_LINE
	// Filled: GL_FILL
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// ---- TEXTURES ----

	// Generate texture
	unsigned int textures[2];
	glGenTextures(2, textures);

	// Bind the texture and set its options
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	// Load image and apply it to the texture
	stbi_set_flip_vertically_on_load(GL_TRUE); // tell stb_image.h to flip loaded texture's on the y-axis.
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


	// ---- MAIN LOOP ----
	while(!glfwWindowShouldClose(window))
	{
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		// Input
		processInput(window);

		// Background color
		glClearColor(0.7f, 0.3f, 0.1f, 1.0f);
   		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
		
		// Draw triangles
		glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, textures[0]);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, textures[1]);
		glUseProgram(shaderProgram);
		glUniform1f(glGetUniformLocation(shaderProgram, "mixValue"), mixValue);

		t_mat4 view = ft_lookat(cameraPos, ft_vec3_add(cameraPos, cameraFront), cameraUp);
		t_mat4 projection = ft_mat4_persp(ft_deg_to_rad(fov), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);

		unsigned int modelLoc = glGetUniformLocation(shaderProgram,"model");
		unsigned int viewLoc = glGetUniformLocation(shaderProgram,"view");
		glUniformMatrix4fv(viewLoc, 1, GL_TRUE, view.m);
		unsigned int projectionLoc = glGetUniformLocation(shaderProgram,"projection");
		glUniformMatrix4fv(projectionLoc, 1, GL_TRUE, projection.m);

        glBindVertexArray(VAO);
		for (unsigned int i = 0; i < 10; i++)
		{
			t_mat4 model = ft_mat4_transl(cubPos[i]);
			float angle;
			if (i % 3 == 0)
				angle = glfwGetTime() * 10 + i;
			else
				angle = 20.f * i;
			model = ft_mat4_mul(model, ft_mat4_rot(ft_vec3(1.0f, 0.3f, 0.5f), ft_deg_to_rad(angle)));
			glUniformMatrix4fv(modelLoc, 1, GL_TRUE, model.m);
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}

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

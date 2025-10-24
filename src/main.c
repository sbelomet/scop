/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:17:04 by sbelomet          #+#    #+#             */
/*   Updated: 2025/10/24 17:21:25 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

float	mixValue = 0.2f;

t_camera camera;

int		firstMouse = GL_TRUE;
float	lastX = WIDTH / 2;
float	lastY = HEIGHT / 2;

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
	float temp = camera.pos.v[1];
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.pos = ft_vec3_add(camera.pos, ft_vec3_smul(camera.front, cameraSpeed));
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.pos = ft_vec3_sub(camera.pos, ft_vec3_smul(camera.front, cameraSpeed));
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.pos = ft_vec3_sub(camera.pos, ft_vec3_smul(ft_vec3_normalize(ft_vec3_cross(camera.front, camera.up)), cameraSpeed));
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.pos = ft_vec3_add(camera.pos, ft_vec3_smul(ft_vec3_normalize(ft_vec3_cross(camera.front, camera.up)), cameraSpeed));
	camera.pos.v[1] = temp;
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

	camera.yaw += xoffset;
	camera.pitch += yoffset;

	if (camera.pitch > 89.0f)
		camera.pitch = 89.0f;
	if (camera.pitch < -89.0f)
		camera.pitch = -89.0f;
	
	t_vec3	direction;
	direction.v[0] = cos(ft_deg_to_rad(camera.yaw)) * cos(ft_deg_to_rad(camera.pitch));
	direction.v[1] = sin(ft_deg_to_rad(camera.pitch));
	direction.v[2] = sin(ft_deg_to_rad(camera.yaw)) * cos(ft_deg_to_rad(camera.pitch));
	camera.front = ft_vec3_normalize(direction);
}

void	scroll_callback(GLFWwindow *, double, double yoffset)
{
	camera.fov -= (float)yoffset;
	if (camera.fov < 1.0f)
		camera.fov = 1.0f;
	if (camera.fov > 45.0f)
		camera.fov = 45.0f;
}

//Resets viewport on window resize
void framebuffer_size_callback(GLFWwindow *, int width, int height)
{
	glViewport(0, 0, width, height);
}

int main(int, char**)
{
	// ---- INITIATIONS ----
	camera.pos = ft_vec3(0.0f, 0.0f, 3.0f);
	camera.front = ft_vec3(0.0f, 0.0f, -1.0f);
	camera.up = ft_vec3(0.0f, 1.0f, 0.0f);
	camera.yaw = -90.0f;
	camera.pitch = 0.0f;
	camera.fov = 45.0f;

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
	unsigned int objShader = ft_newShader("shaders/obj_vs.glsl", "shaders/obj_fs.glsl");
	unsigned int lightCubeShader = ft_newShader("shaders/light_vs.glsl", "shaders/light_fs.glsl");

	// ---- COORDS ----

	// Vertices for cube
	float vertices[] = {
		-0.5f, -0.5f, -0.5f, 
         0.5f, -0.5f, -0.5f,  
         0.5f,  0.5f, -0.5f,  
         0.5f,  0.5f, -0.5f,  
        -0.5f,  0.5f, -0.5f, 
        -0.5f, -0.5f, -0.5f, 

        -0.5f, -0.5f,  0.5f, 
         0.5f, -0.5f,  0.5f,  
         0.5f,  0.5f,  0.5f,  
         0.5f,  0.5f,  0.5f,  
        -0.5f,  0.5f,  0.5f, 
        -0.5f, -0.5f,  0.5f, 

        -0.5f,  0.5f,  0.5f, 
        -0.5f,  0.5f, -0.5f, 
        -0.5f, -0.5f, -0.5f, 
        -0.5f, -0.5f, -0.5f, 
        -0.5f, -0.5f,  0.5f, 
        -0.5f,  0.5f,  0.5f, 

         0.5f,  0.5f,  0.5f,  
         0.5f,  0.5f, -0.5f,  
         0.5f, -0.5f, -0.5f,  
         0.5f, -0.5f, -0.5f,  
         0.5f, -0.5f,  0.5f,  
         0.5f,  0.5f,  0.5f,  

        -0.5f, -0.5f, -0.5f, 
         0.5f, -0.5f, -0.5f,  
         0.5f, -0.5f,  0.5f,  
         0.5f, -0.5f,  0.5f,  
        -0.5f, -0.5f,  0.5f, 
        -0.5f, -0.5f, -0.5f, 

        -0.5f,  0.5f, -0.5f, 
         0.5f,  0.5f, -0.5f,  
         0.5f,  0.5f,  0.5f,  
         0.5f,  0.5f,  0.5f,  
        -0.5f,  0.5f,  0.5f, 
        -0.5f,  0.5f, -0.5f,
	};

	// ---- VAO, VBO, EBO ----

	// Generate the Vertex Array Object, the Vertex Buffer Object and the Element Buffer Object
	unsigned int cubeVAO, VBO;
	glGenVertexArrays(1, &cubeVAO);
	glGenBuffers(1, &VBO);

	// Bind the VBO and add the vertices to it
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Bind the VAO to set it up
	glBindVertexArray(cubeVAO);

	// Add the attributes to the VAO
	// position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

	unsigned int lightVAO;
	glGenVertexArrays(1, &lightVAO);
	glBindVertexArray(lightVAO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

	// ---- MAIN LOOP ----
	while(!glfwWindowShouldClose(window))
	{
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		// Input
		processInput(window);

		// Background color
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
   		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
		
		// Set cube uniforms
		glUseProgram(objShader);
		glUniform3f(glGetUniformLocation(objShader, "objectColor"), 1.0f, 0.5f, 0.31f);
		glUniform3f(glGetUniformLocation(objShader, "lightColor"), 1.0f, 1.0f, 1.0f);		
		t_mat4 projection = ft_mat4_persp(ft_deg_to_rad(camera.fov), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
		glUniformMatrix4fv(glGetUniformLocation(objShader, "projection"), 1, GL_TRUE, projection.m);
		t_mat4 view = ft_lookat(camera.pos, ft_vec3_add(camera.pos, camera.front), camera.up);
		glUniformMatrix4fv(glGetUniformLocation(objShader,"view"), 1, GL_TRUE, view.m);
		t_mat4 model = ft_mat4();
		glUniformMatrix4fv(glGetUniformLocation(objShader,"model"), 1, GL_TRUE, model.m);

		// Draw cube
		glBindVertexArray(cubeVAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		// Same for light cube
		glUseProgram(lightCubeShader);
		glUniformMatrix4fv(glGetUniformLocation(lightCubeShader, "projection"), 1, GL_TRUE, projection.m);
		glUniformMatrix4fv(glGetUniformLocation(lightCubeShader,"view"), 1, GL_TRUE, view.m);
		t_mat4 transl = ft_mat4_transl(ft_vec3(1.2f, 1.0f, 2.0f));
		t_mat4 scale = ft_mat4_scale(ft_vec3(0.2f, 0.2f, 0.2f));
		model = ft_mat4_mul(transl, scale);
		glUniformMatrix4fv(glGetUniformLocation(objShader,"model"), 1, GL_TRUE, model.m);

		glBindVertexArray(lightVAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		// Swap the buffers and check and call events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	// Cleaning
	glDeleteVertexArrays(1, &cubeVAO);
	glDeleteVertexArrays(1, &lightVAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(objShader);
	glDeleteProgram(lightCubeShader);
	
	// Stop GLFW
	glfwTerminate(); 
	return 0;
}

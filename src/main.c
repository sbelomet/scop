/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:17:04 by sbelomet          #+#    #+#             */
/*   Updated: 2025/10/26 16:56:17 by sbelomet         ###   ########.fr       */
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
	//float temp = camera.pos.v[1];
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.pos = ft_vec3_add(camera.pos, ft_vec3_smul(camera.front, cameraSpeed));
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.pos = ft_vec3_sub(camera.pos, ft_vec3_smul(camera.front, cameraSpeed));
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.pos = ft_vec3_sub(camera.pos, ft_vec3_smul(ft_vec3_normalize(ft_vec3_cross(camera.front, camera.up)), cameraSpeed));
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.pos = ft_vec3_add(camera.pos, ft_vec3_smul(ft_vec3_normalize(ft_vec3_cross(camera.front, camera.up)), cameraSpeed));
	//camera.pos.v[1] = temp;
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
        // positions          // normals           // texture coords
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
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

	t_vec3 pointLightPos[] = {
		ft_vec3( 0.7f,  0.2f,  2.0f),
        ft_vec3( 2.3f, -3.3f, -4.0f),
        ft_vec3(-4.0f,  2.0f, -12.0f),
        ft_vec3( 0.0f,  0.0f, -3.0f)
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
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
	//normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
	//texture attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

	unsigned int lightVAO;
	glGenVertexArrays(1, &lightVAO);
	glBindVertexArray(lightVAO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

	// ---- TEXTURES ----
	unsigned int diffuseMap = ft_load_texture("textures/container.png");
	unsigned int specularMap = ft_load_texture("textures/container_specular.png");
	glUseProgram(objShader);
	glUniform1i(glGetUniformLocation(objShader, "material.diffuse"), 0);
	glUniform1i(glGetUniformLocation(objShader, "material.specular"), 1);

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
		
		// Set uniforms
		glUseProgram(objShader);
		glUniform3f(glGetUniformLocation(objShader, "viewPos"), camera.pos.v[0], camera.pos.v[1], camera.pos.v[2]);
		glUniform1f(glGetUniformLocation(objShader, "material.shininess"), 32.0f);

		// directional light
		glUniform3f(glGetUniformLocation(objShader, "dirLight.direction"), -0.2f, -1.0f, -0.3f);
		glUniform3f(glGetUniformLocation(objShader, "dirLight.ambient"), 0.05f, 0.05f, 0.05f);
		glUniform3f(glGetUniformLocation(objShader, "dirLight.diffuse"), 0.4f, 0.4f, 0.4f);
		glUniform3f(glGetUniformLocation(objShader, "dirLight.specular"), 0.5f, 0.5f, 0.5f);
		// point light 1
		glUniform3f(glGetUniformLocation(objShader, "pointLights[0].position"), pointLightPos[0].v[0], pointLightPos[0].v[1], pointLightPos[0].v[2]);
		glUniform3f(glGetUniformLocation(objShader, "pointLights[0].ambient"), 0.05f, 0.05f, 0.05f);
		glUniform3f(glGetUniformLocation(objShader, "pointLights[0].diffuse"), 0.8f, 0.8f, 0.8f);
		glUniform3f(glGetUniformLocation(objShader, "pointLights[0].specular"), 1.0f, 1.0f, 1.0f);
		glUniform1f(glGetUniformLocation(objShader, "pointLights[0].constant"), 1.0f);
		glUniform1f(glGetUniformLocation(objShader, "pointLights[0].linear"), 0.09f);
		glUniform1f(glGetUniformLocation(objShader, "pointLights[0].quadratic"), 0.032f);
		// point light 2
		glUniform3f(glGetUniformLocation(objShader, "pointLights[1].position"), pointLightPos[1].v[0], pointLightPos[1].v[1], pointLightPos[1].v[2]);
		glUniform3f(glGetUniformLocation(objShader, "pointLights[1].ambient"), 0.05f, 0.05f, 0.05f);
		glUniform3f(glGetUniformLocation(objShader, "pointLights[1].diffuse"), 0.8f, 0.8f, 0.8f);
		glUniform3f(glGetUniformLocation(objShader, "pointLights[1].specular"), 1.0f, 1.0f, 1.0f);
		glUniform1f(glGetUniformLocation(objShader, "pointLights[1].constant"), 1.0f);
		glUniform1f(glGetUniformLocation(objShader, "pointLights[1].linear"), 0.09f);
		glUniform1f(glGetUniformLocation(objShader, "pointLights[1].quadratic"), 0.032f);
		// point light 3
		glUniform3f(glGetUniformLocation(objShader, "pointLights[2].position"), pointLightPos[2].v[0], pointLightPos[2].v[1], pointLightPos[2].v[2]);
		glUniform3f(glGetUniformLocation(objShader, "pointLights[2].ambient"), 0.05f, 0.05f, 0.05f);
		glUniform3f(glGetUniformLocation(objShader, "pointLights[2].diffuse"), 0.8f, 0.8f, 0.8f);
		glUniform3f(glGetUniformLocation(objShader, "pointLights[2].specular"), 1.0f, 1.0f, 1.0f);
		glUniform1f(glGetUniformLocation(objShader, "pointLights[2].constant"), 1.0f);
		glUniform1f(glGetUniformLocation(objShader, "pointLights[2].linear"), 0.09f);
		glUniform1f(glGetUniformLocation(objShader, "pointLights[2].quadratic"), 0.032f);
		// point light 4
		glUniform3f(glGetUniformLocation(objShader, "pointLights[3].position"), pointLightPos[3].v[0], pointLightPos[3].v[1], pointLightPos[3].v[2]);
		glUniform3f(glGetUniformLocation(objShader, "pointLights[3].ambient"), 0.05f, 0.05f, 0.05f);
		glUniform3f(glGetUniformLocation(objShader, "pointLights[3].diffuse"), 0.8f, 0.8f, 0.8f);
		glUniform3f(glGetUniformLocation(objShader, "pointLights[3].specular"), 1.0f, 1.0f, 1.0f);
		glUniform1f(glGetUniformLocation(objShader, "pointLights[3].constant"), 1.0f);
		glUniform1f(glGetUniformLocation(objShader, "pointLights[3].linear"), 0.09f);
		glUniform1f(glGetUniformLocation(objShader, "pointLights[3].quadratic"), 0.032f);
		// spotlight
		glUniform3f(glGetUniformLocation(objShader, "spotLight.position"), camera.pos.v[0], camera.pos.v[1], camera.pos.v[2]);
		glUniform3f(glGetUniformLocation(objShader, "spotLight.direction"), camera.front.v[0], camera.front.v[1], camera.front.v[2]);
		glUniform3f(glGetUniformLocation(objShader, "spotLight.ambient"), 0.0f, 0.0f, 0.0f);
		glUniform3f(glGetUniformLocation(objShader, "spotLight.diffuse"), 1.0f, 1.0f, 1.0f);
		glUniform3f(glGetUniformLocation(objShader, "spotLight.specular"), 1.0f, 1.0f, 1.0f);
		glUniform1f(glGetUniformLocation(objShader, "spotLight.constant"), 1.0f);
		glUniform1f(glGetUniformLocation(objShader, "spotLight.linear"), 0.09f);
		glUniform1f(glGetUniformLocation(objShader, "spotLight.quadratic"), 0.032f);
		glUniform1f(glGetUniformLocation(objShader, "spotLight.cutOff"), cos(ft_deg_to_rad(12.5f)));
		glUniform1f(glGetUniformLocation(objShader, "spotLight.outerCutOff"), cos(ft_deg_to_rad(15.0f)));

		t_mat4 projection = ft_mat4_persp(ft_deg_to_rad(camera.fov), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
		glUniformMatrix4fv(glGetUniformLocation(objShader, "projection"), 1, GL_TRUE, projection.m);
		t_mat4 view = ft_lookat(camera.pos, ft_vec3_add(camera.pos, camera.front), camera.up);
		glUniformMatrix4fv(glGetUniformLocation(objShader,"view"), 1, GL_TRUE, view.m);
		unsigned int modelLoc = glGetUniformLocation(objShader,"model");

		// Draw cube
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, diffuseMap);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, specularMap);
		glBindVertexArray(cubeVAO);
		for (unsigned int i = 0; i < 10; i++)
		{
			t_mat4 model = ft_mat4_transl(cubPos[i]);
			float angle = 20.0f * i;
			model = ft_mat4_mul(model, ft_mat4_rot(ft_vec3(1.0f, 0.3f, 0.5f), ft_deg_to_rad(angle)));
			glUniformMatrix4fv(modelLoc, 1, GL_TRUE, model.m);
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}

		// Same for light cube
		glUseProgram(lightCubeShader);
		glUniform3f(glGetUniformLocation(lightCubeShader, "lightColor"), 1.0f, 1.0f, 1.0f);
		glUniformMatrix4fv(glGetUniformLocation(lightCubeShader, "projection"), 1, GL_TRUE, projection.m);
		glUniformMatrix4fv(glGetUniformLocation(lightCubeShader,"view"), 1, GL_TRUE, view.m);
		modelLoc = glGetUniformLocation(lightCubeShader,"model");

		glBindVertexArray(lightVAO);
		for (unsigned int i = 0; i < 4; i++)
		{
			t_mat4 model = ft_mat4_transl(pointLightPos[i]);
			model = ft_mat4_mul(model, ft_mat4_scale(ft_vec3(0.2f, 0.2f, 0.2f)));
			glUniformMatrix4fv(modelLoc, 1, GL_TRUE, model.m);
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}

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

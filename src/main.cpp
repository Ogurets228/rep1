#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

GLfloat point[] = {
	 0.0f,  0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f
};
GLfloat colors[] = {
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f
};

const char* vertex_shader_src =
"#version 460\n"
"layout(location = 0) in vec3 vertex_position;"
"layout(location = 1) in vec3 vertex_color;"
"out vec3 color;"
"void main() {"
"   color = vertex_color;"
"   gl_Position = vec4(vertex_position, 1.0);"
"}";

const char* fragment_shader_src =
"#version 460\n"
"in vec3 color;"
"out vec4 frag_color;"
"void main() {"
"	frag_color = vec4(color, 1.0);"
"}";

void glfwWindowSizeCallback(GLFWwindow* pWindow, int width, int height)
{
	glViewport(0, 0, width, height);
	cout << "Hi there\n";
}

void glfwKeyCallback(GLFWwindow* pWindow, int key, int scancode, int act, int mode)
{
	if (key == GLFW_KEY_ESCAPE && act == GLFW_RELEASE)
	{
		glfwSetWindowShouldClose(pWindow, GL_TRUE);
	}
}

int main()
{
	if (!glfwInit())
	{
		return -1;
	}
	GLFWwindow* pWindow = glfwCreateWindow(640, 480, "Test", nullptr, nullptr);
	if (!pWindow)
	{
		return -1;
		glfwTerminate();
	}

	glfwMakeContextCurrent(pWindow);

	glfwSetWindowSizeCallback(pWindow, glfwWindowSizeCallback);
	glfwSetKeyCallback(pWindow, glfwKeyCallback);


	if (!gladLoadGL())
	{
		return -1;
	}
	cout << GLVersion.major << "." << GLVersion.minor << endl;
	glClearColor(.7f, 0, 1, 1);



	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader_src, nullptr);
	glCompileShader(vs);

	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader_src, nullptr);
	glCompileShader(fs);



	GLuint shader_program = glCreateProgram();
	glAttachShader(shader_program, vs);
	glAttachShader(shader_program, fs);
	glLinkProgram(shader_program);

	glDeleteShader(vs);
	glDeleteShader(fs);



	GLuint vbo_p = 0;
	glGenBuffers(1, &vbo_p);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_p);
	glBufferData(GL_ARRAY_BUFFER, sizeof(point), point, GL_STATIC_DRAW);

	GLuint vbo_c = 0;
	glGenBuffers(1, &vbo_c);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_c);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);



	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_p);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_c);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

	while (!glfwWindowShouldClose(pWindow))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shader_program);
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(pWindow);

		glfwPollEvents();
	}


	glfwTerminate();
	return 0;
}
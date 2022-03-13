#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

float points[] = {
    -.5f, -.5f, 1,
    .5f, -.5f, 1,
    0, .5f, 1
};

float colors[] = {
    1, 0, 0,
    0, 1, 0,
    0, 0, 1
};

float points2[] = {
    .5f, .5f, 1,
    .75f, .75f, 1,
    .8, 0, 1
};

float colors2[] = {
    1, 0, 1,
    1, 1, 0,
    .5f, .5f, .5f
};

const char* vertex_shader_src =
"#version 460\n"
"layout(location=0) in vec3 vertex_pos;"
"layout(location=1) in vec3 vertex_color;"
"out vec3 color;"
"void main() {"
"   color = vertex_color;"
"   gl_Position = vec4(vertex_pos, 1);"
"}";

const char* fragment_shader_src =
"#version 460\n"
"in vec3 color;"
"out vec4 fragment_color;"
"void main() {"
"   fragment_color = vec4(color, 1);"
"}";

void glfwWindowSizeCallback(GLFWwindow* pWindow, int width, int height)
{
    glViewport(0, 0, width, height);
}

void glfwKeyCallback(GLFWwindow* pWindow, int key, int mode, int act, int scancode)
{
    if (key == GLFW_KEY_ESCAPE && act == GLFW_RELEASE)
    {
        glfwSetWindowShouldClose(pWindow, GL_TRUE);
    }
}

int main()
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
	
	if (!gladLoadGL())
	{
		cout << "Can't load GLAD." << endl;
		return -1;
	}
	cout << "OpenGL version:" << GLVersion.major << "." << GLVersion.minor << endl;
	
    glfwSetWindowSizeCallback(window, glfwWindowSizeCallback);
    glfwSetKeyCallback(window, glfwKeyCallback);

	glClearColor(.4f, 0, 1, 1);
	

    unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vertex_shader_src, nullptr);
    glCompileShader(vs);

    unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fragment_shader_src, nullptr);
    glCompileShader(fs);

    unsigned int shader_program = glCreateProgram();
    glAttachShader(shader_program, vs);
    glAttachShader(shader_program, fs);
    glLinkProgram(shader_program);

    glDeleteShader(vs);
    glDeleteShader(fs);


    unsigned int vbo_points = 0;
    glGenBuffers(1, &vbo_points);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_points);
    glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

    unsigned int vbo_colors = 0;
    glGenBuffers(1, &vbo_colors);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_colors);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_points);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_colors);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);



    unsigned int vbo_points2 = 0;
    glGenBuffers(1, &vbo_points2);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_points2);
    glBufferData(GL_ARRAY_BUFFER, sizeof(points2), points2, GL_STATIC_DRAW);

    unsigned int vbo_colors2 = 0;
    glGenBuffers(1, &vbo_colors2);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_colors2);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors2), colors2, GL_STATIC_DRAW);

    unsigned int vao2;
    glGenVertexArrays(1, &vao2);
    glBindVertexArray(vao2);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_points2);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_colors2);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);


    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader_program);

        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glBindVertexArray(vao2);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
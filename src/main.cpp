#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

void glfwWindowSizeCallback(GLFWwindow *pWindow, int width, int height)
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
	glClearColor(1, 0, 1, 1);

	while (!glfwWindowShouldClose(pWindow))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		
		glfwSwapBuffers(pWindow);

		glfwPollEvents();
	}


	glfwTerminate();
	return 0;
}
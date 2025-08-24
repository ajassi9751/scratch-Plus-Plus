#include<iostream>
#include<thread>
#include<GLFW/glfw3.h>

// This file is used for testing

void drawtest () {
	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3f(1.0f,0.0f,0.0f);
	glVertex2f(-0.5f,0.0f);
	glVertex2f(0.5f,0.0f);
	glEnd();
}

void windowRenderer (GLFWwindow* window) {
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	glViewport(0, 0, 800, 600);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0f,1.0f,1.0f,1.0f);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		
		drawtest();
		
		glFlush();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void framebuffer_size_callback (GLFWwindow* window, int width, int height) {
	glViewport(0,0,width,height);
}

int main () {
	//Initialization
	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW" << std::endl;
		return -1;
	}
	GLFWwindow* window = glfwCreateWindow(800, 600, "Scratch", nullptr, nullptr);
	if (!window) {
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	unsigned int threadsnum = std::thread::hardware_concurrency();
	unsigned int threadAvail = std::thread::hardware_concurrency();

	std::thread threads[threadsnum];

	threads[0] = std::thread(windowRenderer, window); //The render thread
	threadAvail--;
	
	//The main loop should end with this
	while (!glfwWindowShouldClose(window)) {
		//Wait idk
	}
	threads[0].join();

	glfwTerminate();
	return 0;
}

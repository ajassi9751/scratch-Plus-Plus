#include<iostream>
#include<thread>
#include<GLFW/glfw3.h>

// This file is used for testing

void thrdinit () {
	//A placeholder function to initialize threads
	std::cout << "created a thread\n";
}

void windowRenderer (GLFWwindow* window) {
	glfwMakeContextCurrent(window);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
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
	
	//for (unsigned int i = 1; i < threadsnum; i++) {
		//threads[i] = std::thread(thrdinit);
	//}
	//for (unsigned int i = 1; i < threadsnum; i++) {
		//if (threads[i].joinable())
			//threads[i].join();
	//}
	//std::cout << "Initialized " << threadsnum << " threads";
	//while (true) {
		//if (threads[0].joinable())
			//threads[0].join();
	//}
	while (!glfwWindowShouldClose(window)) {
		//Wait idk
	}
	if (threads[0].joinable())
		threads[0].join();

	glfwTerminate();
	return 0;
}

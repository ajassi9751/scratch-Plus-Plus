#include<iostream>
#include<thread>
#include<vector>
#include<GLFW/glfw3.h>
#include<mutex>

// This file is used for testing
std::mutex renderLock;

typedef struct {
	std::vector<float> lnwidth = {2.0f};
	std::vector<float> lncolor1 = {1.0f};
	std::vector<float> lncolor2 = {0.0f};
	std::vector<float> lncolor3 = {0.0f};
	std::vector<float> lnposx1 = {1.0f};
	std::vector<float> lnposy1 = {1.0f};
	std::vector<float> lnposx2 = {-1.0f};
	std::vector<float> lnposy2 = {-1.0f};
} renderStruct;

void draw (float width, float color1, float color2, float color3, float x1, float y1, float x2, float y2) {
	glLineWidth(width);
	glBegin(GL_LINES);
	glColor3f(color1,color2,color3);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glEnd();
}

void windowDisplayer (GLFWwindow* window, renderStruct* renderQue) {
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); // Vsync

	glViewport(0, 0, 800, 600);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0f,1.0f,1.0f,1.0f);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		// Drawings

		//draw(2,1.0f,0.0f,0.0f,-0.5f,0.25f,0.5f,-0.25f);
		
			for (int i = 0;i<renderQue->lnwidth.size();++i) {
				draw(renderQue->lnwidth[i],renderQue->lncolor1[i],renderQue->lncolor2[i],renderQue->lncolor3[i],renderQue->lnposx1[i],renderQue->lnposy1[i],renderQue->lnposx2[i],renderQue->lnposy2[i]);
			}
		
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

	renderStruct renderQue;
	unsigned int threadsnum = std::thread::hardware_concurrency();
	unsigned int threadAvail = std::thread::hardware_concurrency();

	std::thread threads[threadsnum];

	threads[0] = std::thread(windowDisplayer, window, &renderQue); //The render thread
	threadAvail--;
	
	//The main loop should end with this
	while (!glfwWindowShouldClose(window)) {
		//Wait idk
	}
	threads[0].join();

	glfwTerminate();
	return 0;
}

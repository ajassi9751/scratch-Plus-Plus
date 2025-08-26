#include<iostream>
#include<thread>
#include<vector>
#include<GLFW/glfw3.h>

// This file is used for testing

class Renderer {
	private:
		std::vector<float> lnposx1;
		std::vector<float> lnposy1;
		std::vector<float> lnposx2;
		std::vector<float> lnposy2;
		std::vector<float> lncolor1;
		std::vector<float> lncolor2;
		std::vector<float> lncolor3;
		std::vector<float> lnwidth;
	public:
		float getwidth (int index) {
			return lnwidth.at(index);
		}
		float getc1 (int index) {
			return lncolor1.at(index);
		}
		float getc2 (int index) {
			return lncolor2.at(index);
		}
		float getc3 (int index) {
			return lncolor3.at(index);
		}
		float getx1 (int index) {
			return lnposx1.at(index);
		}
		float gety1 (int index) {
			return lnposy1.at(index);
		}
		float getx2 (int index) {
			return lnposx2.at(index);
		}
		float gety2 (int index) {
			return lnposy2.at(index);
		}
		int isize () {
			return lnwidth.size();
		}
};

void draw (float width, float color1, float color2, float color3, float x1, float y1, float x2, float y2) {
	glLineWidth(width);
	glBegin(GL_LINES);
	glColor3f(color1,color2,color3);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glEnd();
}

void windowDisplayer (GLFWwindow* window, Renderer* renderer) {
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

		draw(2,1.0f,0.0f,0.0f,-0.5f,0.25f,0.5f,-0.25f);
		
		for (int i = 0;i<renderer->isize();++i) {
			draw(renderer->getwidth(i),renderer->getc1(i),renderer->getc2(i),renderer->getc3(i),renderer->getx1(i),renderer->gety1(i),renderer->getx2(i),renderer->gety2(i));
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
	Renderer renderer;
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

	threads[0] = std::thread(windowDisplayer, window, &renderer); //The render thread
	threadAvail--;
	
	//The main loop should end with this
	while (!glfwWindowShouldClose(window)) {
		//Wait idk
	}
	threads[0].join();

	glfwTerminate();
	return 0;
}

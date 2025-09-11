#include<iostream>
#include<cstring>
#include<thread>
#include<vector>
#include<chrono>
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

void windowDisplayer (GLFWwindow* window, renderStruct* renderQue, const int refreshRate) {
	// Delay setup
	auto time_current = std::chrono::steady_clock::now();
	auto time_last = time_current;
	const auto update_interval = std::chrono::milliseconds{1000/refreshRate};
	time_current = std::chrono::steady_clock::now();
	auto time_d = time_current - time_last;

	// Copyer setup
	renderStruct cpyQue;

	// glfw setup
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); // Vsync

	// Might remove
	glViewport(0, 0, 800, 600);

	// gl setup
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0f,1.0f,1.0f,1.0f);

	// Make sure one frame is rendered
	glClear(GL_COLOR_BUFFER_BIT);
	// Mutex locking to prevent data races
	renderLock.lock();
	for (int i = 0;i<renderQue->lnwidth.size();++i) {
		draw(renderQue->lnwidth[i],renderQue->lncolor1[i],renderQue->lncolor2[i],renderQue->lncolor3[i],renderQue->lnposx1[i],renderQue->lnposy1[i],renderQue->lnposx2[i],renderQue->lnposy2[i]);
	}
	renderLock.unlock();
	glFlush();
	glfwSwapBuffers(window);
	glfwPollEvents();
	// Main loop
	while (!glfwWindowShouldClose(window)) {
		renderLock.lock();
		//std::cout << std::memcmp(renderQue,&cpyQue,sizeof(*renderQue)) << "\n";
		if (cpyQue.lnwidth==renderQue->lnwidth && cpyQue.lncolor1==renderQue->lncolor1 && cpyQue.lncolor2==renderQue->lncolor2 && cpyQue.lncolor3==renderQue->lncolor3 && cpyQue.lnposx1==renderQue->lnposx1 && cpyQue.lnposy1==renderQue->lnposy1 && cpyQue.lnposx2==renderQue->lnposx2 && cpyQue.lnposy2==renderQue->lnposy2) {
			//std::cout << "true";
			glfwPollEvents();
			renderLock.unlock();
			continue;
		}
		else {
			//std::memcpy(&cpyQue,renderQue,sizeof(*renderQue));
			cpyQue.lnwidth = renderQue->lnwidth;
			cpyQue.lncolor1 = renderQue->lncolor1;
			cpyQue.lncolor2 = renderQue->lncolor2;
			cpyQue.lncolor3 = renderQue->lncolor3;
			cpyQue.lnposx1 = renderQue->lnposx1;
			cpyQue.lnposy1 = renderQue->lnposy1;
			cpyQue.lnposx2 = renderQue->lnposx2;
			cpyQue.lnposy2 = renderQue->lnposy2;
			renderLock.unlock();
		}

		glClear(GL_COLOR_BUFFER_BIT);

		// Delay for rendering, doesnt seem to work :(
		while (time_d >= update_interval) {
			time_d -= update_interval;
			time_last += update_interval;
		}
		// Drawings
		//draw(2,1.0f,0.0f,0.0f,-0.5f,0.25f,0.5f,-0.25f);
		// Mutex locking to prevent data races
		renderLock.lock();
		for (int i = 0;i<renderQue->lnwidth.size();++i) {
			draw(renderQue->lnwidth[i],renderQue->lncolor1[i],renderQue->lncolor2[i],renderQue->lncolor3[i],renderQue->lnposx1[i],renderQue->lnposy1[i],renderQue->lnposx2[i],renderQue->lnposy2[i]);
		}
		renderLock.unlock();
		
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
	// For the refresh rate stuff
	GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
	if (!window) {
		std::cerr << "No primary monitor found" << std::endl;
		glfwTerminate();
		return -1;
	}
	const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);
	const int refreshRate = mode->refreshRate;

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	renderStruct renderQue;
	unsigned int threadsnum = std::thread::hardware_concurrency();
	unsigned int threadAvail = std::thread::hardware_concurrency();

	std::thread threads[threadsnum];

	threads[0] = std::thread(windowDisplayer, window, &renderQue, refreshRate); //The render thread
	threadAvail--;
	
	//The main loop should end with this
	while (!glfwWindowShouldClose(window)) {
		//Wait idk
	}
	threads[0].join();

	glfwTerminate();
	return 0;
}

#include <iostream>
#include <thread>

// This file is used for testing

void thrdinit () {
	//A placeholder function to initialize threads
	std::cout << "created a thread\n";
}

int main () {
	unsigned int threadsnum = std::thread::hardware_concurrency();
	std::thread threads[threadsnum];
	for (unsigned int i = 0; i < threadsnum; i++) {
		threads[i] = std::thread(thrdinit);
	}
	for (unsigned int i = 0; i < threadsnum; i++) {
		threads[i].join();
	}
	for (unsigned int i = 0; i < threadsnum; i++) {
		threads[i] = std::thread(thrdinit);
	}
	for (unsigned int i = 0; i < threadsnum; i++) {
		threads[i].join();
	}

	std::cout << "Initialized " << threadsnum << " threads";
	return 0;
}

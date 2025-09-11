#ifndef SCRATCHTDLIB
#define SCRATCHTDLIB
#include<string>
#endif

namespace Scratch {
    // Globals
    std::string getInput();
    // Somehow do the time function
    bool isMouseDown();
    double getMouseX();
    double getMouseY();
    bool isButtonPressed(const char* button);
}
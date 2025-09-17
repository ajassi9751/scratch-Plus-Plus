#ifndef STDSTRING
#define STDSTRING
#include <string>
#endif

#ifndef SCRATCHTDLIB
#define SCRATCHTDLIB

#define RANDOM_POS 0
#define MOUSE_POINTER 1
#define LEFT_RIGHT 0
#define DONT_ROTATE 1
#define ALL_AROUND 2

namespace Scratch {
    // Objects
    class sprite {
       public:
        #ifdef SCRATCHPEN
            pen sPen;
        #endif
        // Motion
        void moveSteps(double steps);
        void turnClockwise(double degrees);
        void turnCounterClockwise(double degrees);
        void goTo(int selection);
        void goToPos(double x, double y);
        void glide(double time, int selection);
        void glidePos(double time, double x, double y);
        void point(int selection);
        void pointDirection(double degrees);
        void changeXBy(double x);
        void setXTo(double x);
        void changeYBy(double y);
        void setYTo(double y);
        void ifOnEdgeBounce();
        void setRotStyle(int selection);
        // Has a return value
        double getXPos();
        double getYPos();
        double getDir();
        // Looks
    };
    typedef struct {
        int r, g, b;
    } rgb;
    // Global funcs
    std::string getInput();
    // Somehow do the time function
    bool isMouseDown();
    double getMouseX();
    double getMouseY();
    bool isButtonPressed(const char* button); // Might need to be a string or array for things like "any"
}
#endif
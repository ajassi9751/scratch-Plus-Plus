#ifndef STDSTRING
#define STDSTRING
#include <string>
#endif

#ifndef SCRATCHTDLIB
#define SCRATCHTDLIB

// Macros for selection values (dropdown lists)
#define RANDOM_POS 0
#define MOUSE_POINTER 1

#define LEFT_RIGHT 0
#define DONT_ROTATE 1
#define ALL_AROUND 2

#define COLOR_EFFECT 0
#define FISHEYE_EFFECT 1
#define WHIRL_EFFECT 2
#define PIXELATE_EFFECT 3
#define MOSAIC_EFFECT 4
#define BRIGHTNESS_EFFECT 5
#define GHOST_EFFECT 6

#define FRONT_LAYER 0
#define BACK_LAYER 1

#define FORWARD_LAYER 0
#define BACKWARDS_LAYER 1

namespace Scratch {
    // Objects
    class sprite {
       public:
        #ifdef SCRATCHPEN
            pen sPen; // Change name, the preprocessor statment makes sure that this is only included if pen.hpp is included. This will tie the pen to a sprite and make it easily accesable
        #endif
        // Motion
        void moveSteps(const double steps);
        void turnClockwise(const double degrees);
        void turnCounterClockwise(const double degrees);
        void goTo(const int selection);
        void goToPos(const double x, const double y);
        void glide(const double time, const int selection);
        void glidePos(const double time, const double x, const double y);
        void point(const int selection);
        void pointDirection(const double degrees);
        void changeXBy(const double x);
        void setXTo(const double x);
        void changeYBy(const double y);
        void setYTo(const double y);
        void ifOnEdgeBounce();
        void setRotStyle(const int selection);
        // Has a return value
        double getXPos();
        double getYPos();
        double getDir();
        // Looks
        void sayFor(const std::string text, const double seconds);
        void say(const std::string text);
        void thinkFor(const std::string text, const double seconds);
        void think(const std::string text);
        void switchCostume(const int costume);
        void nextCostume();
        void switchBackdrop(const int background);
        void nextBackdrop();
        void changeSizeBy(const double percent);
        void setSizeTo(const double percent);
        void changeEffectBy(const int selection, const double percent);
        void setEffectTo(const int selection, const double percent);
        void clearEffects();
        void show();
        void hide();
        void goToLayer(const int selection);
        void changeLayer(const int selection, const int layers);
        // Has return value
        int getCostume();
        int getBackdrop();
        double getSize();
        // Sound
        void playUntilDone(const std::string path);
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
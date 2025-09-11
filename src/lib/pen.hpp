#ifndef SCRATCHPEN
#define SCRATCHPEN

#endif

namespace Scratch {
    typedef struct {
        int r;
        int b;
        int g;
    } rgb;
    class pen {
        private:
            void* parentSprite; // Switch out for the proper object
            rgb penColor;
            double penSize;
        public:
            pen(void* pSprite);
            // Need to add the stamp method but I have no clue what it does
            void up();
            void down();
            void color(rgb color);
            rgb getcolor();
            double getSize();
            void size(double tsize);
    };
}
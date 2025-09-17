#ifndef SCRATCHTDLIB
#include "scratchtdlib.hpp"
#endif

#ifndef SCRATCHPEN
#define SCRATCHPEN
namespace Scratch {
    class pen {
        private:
            rgb penColor;
            double penSize;
        public:
            // Need to add the stamp method but I have no clue what it does
            void up();
            void down();
            void color(rgb color);
            rgb getcolor();
            double getSize();
            void size(double tsize);
    };
}
#endif
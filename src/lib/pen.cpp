#ifndef SCRATCHPEN
#include "pen.hpp"
#endif

namespace Scratch {
    void pen::up() {
        // Do some renderer things
    }

    void pen::down() {
        // Do some renderer things
    }

    void pen::color(rgb color) {
        penColor.r = color.r;
        penColor.g = color.g;
        penColor.b = color.b;
    }

    rgb pen::getcolor() {
        return penColor;
    }

    void pen::size(double tsize) {
        penSize = tsize;
    }

    double pen::getSize() {
        return penSize;
    }
}
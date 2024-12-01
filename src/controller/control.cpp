#include "control.hpp"

Control::Control() = default;

Control::~Control() = default;

void Control::move(Racket& racket, bool direction) {
    if (direction) { // move right
        float maxRight = WINDOW_WIDTH - (racket.getWidth() / 2); // max pos of the racket on the right
        float newX = racket.getCenter().x_ + racket.getSpeed();
        racket.setCenter(std::min(newX, maxRight));
    } else { // move left
        float maxLeft = racket.getWidth() / 2; // min pos of the racket on the left
        float newX = racket.getCenter().x_ - racket.getSpeed();
        racket.setCenter(std::max(newX, maxLeft));
    }
}

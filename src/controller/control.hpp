#ifndef CONTROL_HPP
#define CONTROL_HPP

#include <vector>
#include <cmath>

#include "entities/ball.hpp"
#include "entities/brick.hpp"
#include "entities/point.hpp"
#include "entities/racket.hpp"
#include "tests/allegro_test.hpp"
#include "global_variables.hpp"

class Control {
    public:
        Control();
        ~Control();
        void move(Racket& racket, bool direction);
        void move(std::vector<Ball>& balls, Racket& racket);
        bool circleRect(float cx, float cy, float radius, float rx, float ry, float rw, float rh);

};

#endif
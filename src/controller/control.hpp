#ifndef CONTROL_HPP
#define CONTROL_HPP

#include <vector>

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
        void move(Racket& racket, bool direction); //returns bool to if out of bounds
};

#endif
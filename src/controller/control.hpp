/**
 * @file control.hpp
 * @author Manuel Rocca
 * @brief Header file for the Control class
 * @date 2024
 *
 */

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
        void checkWallCollision(Ball&);
        void checkRacketCollision(Ball&, Racket&);
        double returnAngle(float, float) const;

};

#endif
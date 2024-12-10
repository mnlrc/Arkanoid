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
        void move(std::vector<Ball>& balls, Racket& racket, std::vector<std::vector<Brick>>& bricks);
        void move(std::vector<Ball>& balls, Racket& racket);
        void checkWallCollision(Ball&);
        void checkRacketCollision(Ball&, Racket&);
        void checkBrickCollision(Ball&, std::vector<std::vector<Brick>>&);
        double returnAngle(double, double) const;

};

#endif
#ifndef ENTITIES_HPP
#define ENTITIES_HPP

#include "ball.hpp"
#include "brick.hpp"
#include "rectangle.hpp"
#include "racket.hpp"
#include "point.hpp"
#include "score.hpp"
#include "vector"


class Entities {
    private:
        Racket racket_;
        std::vector<Ball> balls_;
        std::vector<std::vector<Brick>> bricks_;
        Score score_;

    public:
        Entities();
        ~Entities();

        Racket getRacket() const noexcept;
        std::vector<Ball> getBalls() const noexcept;
        std::vector<std::vector<Brick>> getBricks() const noexcept;
        Score getScore() const noexcept;
};


#endif
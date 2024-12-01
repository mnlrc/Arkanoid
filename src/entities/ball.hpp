#ifndef BALL_HPP
#define BALL_HPP

#include "point.hpp"

#define DEFAULT_BALL_SPEED 20


class Ball{
    private:
        Point center_;
        const float radius_; // is equal to it's height
        unsigned speed_;
        // isMoving when on the racket or no ? 
    public:
        // #### Constructor ####
        Ball(Point c, float w);
        ~Ball();
        float getRadius() const noexcept;
        Point getCenter() const noexcept;
        void setCenter(const Point pt) noexcept;
        void move(float dx, float dy);
};

#endif
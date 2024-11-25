#ifndef BALL_HPP
#define BALL_HPP

#include "point.hpp"


class Ball{
    private:
        Point center_;
        const float radius_; // is equal to it's height
    public:
        // ### BUILDER ###
        Ball(Point c, float w);
        ~Ball();
        float getRadius() const noexcept;
        Point getCenter() const noexcept;
        void setCenter(const Point pt) noexcept;
        void move(float dx, float dy);
};

#endif
#ifndef BALL_HPP
#define BALL_HPP

#include "point.hpp"


class Ball{
    private:
        Point centre;
        const float width; // is equal to it's height
    public:
        // ### BUILDER ###
        Ball(Point c, const float w);
        ~Ball();
        float getWidth() const noexcept;
        void move(float dx, float dy);
};

#endif
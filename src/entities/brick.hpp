#ifndef BRICK_HPP
#define BRICK_HPP

#include "point.hpp"

#define BRICK_WIDTH 35
#define BRICK_HEIGHT 20

class Brick{
    private:
        const float width_;
        const float height_;
        const Point center_;
        bool isBreakable; // for later phases 
    public:
        Brick(float w, float h, Point pt);
        ~Brick();
        float getWidth() const noexcept;
        float getHeight() const noexcept;
        Point getCenter() const noexcept;
};

#endif
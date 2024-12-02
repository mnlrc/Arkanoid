#ifndef BALL_HPP
#define BALL_HPP

#include "point.hpp"

const bool DEFAULT_BALL_STATE = false;
const unsigned DEFAULT_BALL_SPEED = 5;



class Ball{
    private:
        Point center_;
        const float radius_;
        float speedX_;
        float speedY_;
        bool isMoving;
    public:
        // #### Constructor ####
        Ball(Point c, float w, unsigned, unsigned);
        // #### Destructor ####
        ~Ball();
        // #### Getters ####
        float getRadius() const noexcept;
        Point getCenter() const noexcept;
        float getSpeedX() const noexcept;
        float getSpeedY() const noexcept;
        bool getState() const noexcept;

        // #### Setters ####
        void setCenter(const Point pt) noexcept;
        void setSpeedX(const float) noexcept;
        void setSpeedY(const float) noexcept;
        void changeState() noexcept;
};

#endif
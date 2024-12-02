/**
 * @file control.cpp
 * @author Manuel Rocca
 * @brief Source file for the Control class
 * @date 2024
 *
 */

#include "control.hpp"

Control::Control() = default;

Control::~Control() = default;

void Control::move(Racket& racket, bool direction) {
    if (direction) { // move right
        float maxRight = WINDOW_WIDTH - (racket.getWidth() / 2); // max pos of the racket on the right
        float newX = racket.getCenter().x_ + racket.getSpeed();
        racket.setCenter(std::min(newX, maxRight));
    } else { // move left
        float maxLeft = racket.getWidth() / 2; // min pos of the racket on the left
        float newX = racket.getCenter().x_ - racket.getSpeed();
        racket.setCenter(std::max(newX, maxLeft));
    }
}

void Control::move(std::vector<Ball>& balls, Racket& racket) {

    for (auto& ball: balls) {
        checkWallCollision(ball);
        checkRacketCollision(ball, racket);

        ball.setCenter({ball.getCenter().x_ + ball.getSpeedX(), ball.getCenter().y_ + ball.getSpeedY()});
    }
}

void Control::checkWallCollision(Ball& ball) {
    const float TOP = ball.getRadius() + SCORE_HEIGHT;
    const float DOWN = WINDOW_HEIGHT - ball.getRadius();
    const float LEFT = ball.getRadius();
    const float RIGHT = WINDOW_WIDTH - ball.getRadius();

    if (ball.getCenter().x_ >= RIGHT) {
        ball.setSpeedX(ball.getSpeedX() * -1);
        ball.setCenter({RIGHT, ball.getCenter().y_});
    }

    else if (ball.getCenter().x_ <= LEFT) {
        ball.setSpeedX(ball.getSpeedX() * -1);
        ball.setCenter({LEFT, ball.getCenter().y_});
    }

    else if (ball.getCenter().y_ >= DOWN) {
        ball.setSpeedY(ball.getSpeedY() * - 1);
        ball.setCenter({ball.getCenter().x_, DOWN});
    }

    else if (ball.getCenter().y_ <= TOP) {
        ball.setSpeedY(ball.getSpeedY() * - 1);
        ball.setCenter({ball.getCenter().x_, TOP});
    }
}

void Control::checkRacketCollision(Ball& ball, Racket& racket) {
    // ici il n'y a que la collision au sommet de la raquette qui est gérée
    // il y des effets secondaires sur les côtés car si la balle est sous la raquette
    // mais qu'elle percute cette dernière, elle sera "à l'intérieur" et remplira les conditions
    // ce qui la renvoie vers le haut
    // à voir s'il faut gérer plus proprement les collisions latérales
    
    float topRacket = racket.getCenter().y_ - (racket.getHeight() / 2);
    float leftRacket = racket.getCenter().x_ - (racket.getWidth() / 2);
    float rightRacket = racket.getCenter().x_ + (racket.getWidth() / 2);

    if (// Vertical collision
        ball.getCenter().y_ + ball.getRadius() >= topRacket &&
        ball.getCenter().y_ - ball.getRadius() <= topRacket &&
        // Horizontal collision
        ball.getCenter().x_ >= leftRacket &&
        ball.getCenter().x_ <= rightRacket) {

        ball.setCenter({ball.getCenter().x_, topRacket - ball.getRadius()});
        
        float ballShift = ball.getCenter().x_ - leftRacket;
        double angle = returnAngle(ballShift, racket.getWidth());
        float speed = sqrt(ball.getSpeedX() * ball.getSpeedX() + ball.getSpeedY() * ball.getSpeedY());
        float xSpeed = cos(angle); float ySpeed = -sin(angle);
        ball.setSpeedX(xSpeed * speed); ball.setSpeedY(ySpeed * speed);
    }
}

double Control::returnAngle(float x, float L) const {
    return ((30 + 120 * (1 - (x/L))) * (M_PI / 180)); // converting to rads
}
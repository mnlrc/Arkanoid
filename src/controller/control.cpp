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
        const float TOP = ball.getRadius() + SCORE_HEIGHT;
        const float DOWN = WINDOW_HEIGHT - ball.getRadius();
        const float LEFT = ball.getRadius();
        const float RIGHT = WINDOW_WIDTH - ball.getRadius();

        racket.getCenter();
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
        // gestion de la collision avec la raquette
        ball.setCenter({ball.getCenter().x_ + ball.getSpeedX(), ball.getCenter().y_ + ball.getSpeedY()});

        // if (circleRect(cx, cy, r, rx, ry, racket.getWidth(), racket.getHeight())) {
        //     std::cout << "moved ball\n";
        //     ball.setCenter({ball.getCenter().x_ + ball.getSpeed(), ball.getCenter().y_ + ball.getSpeed()});
        // }
    }
}


bool Control::circleRect(float cx, float cy, float radius, float rx, float ry, float rw, float rh) {

  // temporary variables to set edges for testing
  float testX = cx;
  float testY = cy;

  // which edge is closest?
  if (cx < rx) { testX = rx; }    // test left edge
  else if (cx > rx+rw) { testX = rx+rw; }  // right edge
  if (cy < ry) { testY = ry; }      // top edge
  else if (cy > ry+rh){ testY = ry+rh; }   // bottom edge

  // get distance from closest edges
  float distX = cx-testX;
  float distY = cy-testY;
  float distance = sqrt( (distX*distX) + (distY*distY) );

  // if the distance is less than the radius, collision!
  if (distance <= radius) {
    return true;

  }
  return false;
}
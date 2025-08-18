/**
 * @file engine.cpp
 * @author Manuel Rocca
 * @brief Source file for the Engine class
 * @date 2024
 *
 */
//
#include "engine.hpp"

void Engine::move(Racket &racket, Direction direction)
{
    double y = racket.getCenter().y_;
    switch (direction)
    {
    case Direction::RIGHT:
    {
        double maxRight = WINDOW_WIDTH - (racket.getWidth() / 2); // max pos of the racket on the right
        double newX = racket.getCenter().x_ + racket.get_speed();
        racket.set_center(Point{std::min(newX, maxRight), y});
        break;
    }

    case Direction::LEFT:
    {
        double maxLeft = racket.getWidth() / 2; // min pos of the racket on the left
        double newX = racket.getCenter().x_ - racket.get_speed();
        racket.set_center(Point{std::max(newX, maxLeft), y});
        break;
    }
    default:
        Logger::log("[ERROR] Unknown direction");
        break;
    }
}

// void Engine::move(Racket &racket, bool direction)
// {
//     if (direction)
//     {                                                             // move right

//     }
//     else
//     {                                           // move left

//     }
// }

// void Engine::move(std::vector<Ball> &balls, Racket &racket, [[maybe_unused]] std::vector<std::vector<Brick>> &bricks)
// {

//     for (auto &ball : balls)
//     {
//         checkWallCollision(ball);
//         checkRacketCollision(ball, racket);
//         checkBrickCollision(ball, bricks);

//         ball.setCenter({ball.getCenter().x_ + ball.getSpeed().x_, ball.getCenter().y_ + ball.getSpeed().y_});
//     }
// }

// void Engine::move(std::vector<Ball> &balls, Racket &racket)
// {
//     for (auto &ball : balls)
//     {
//         ball.setCenter({racket.getCenter().x_, racket.getCenter().y_ - racket.getHeight() - ball.getRadius()});
//     }
// }

// void Engine::checkWallCollision(Ball &ball)
// {
//     const double TOP = ball.getRadius();
//     const double DOWN = WINDOW_HEIGHT - ball.getRadius();
//     const double LEFT = ball.getRadius();
//     const double RIGHT = WINDOW_WIDTH - ball.getRadius();

//     // Reseting ball position after every bounce to assure it doesn't go out of bounds
//     if (ball.getCenter().x_ >= RIGHT)
//     {
//         ball.setSpeed({ball.getSpeed().x_ * -1, ball.getSpeed().y_});
//         ball.setCenter({RIGHT, ball.getCenter().y_});
//     }

//     else if (ball.getCenter().x_ <= LEFT)
//     {
//         ball.setSpeed({ball.getSpeed().x_ * -1, ball.getSpeed().y_});
//         ball.setCenter({LEFT, ball.getCenter().y_});
//     }

//     else if (ball.getCenter().y_ >= DOWN)
//     {
//         ball.setSpeed({ball.getSpeed().x_, ball.getSpeed().y_ * -1});
//         ball.setCenter({ball.getCenter().x_, DOWN});
//     }

//     else if (ball.getCenter().y_ <= TOP)
//     {
//         ball.setSpeed({ball.getSpeed().x_, ball.getSpeed().y_ * -1});
//         ball.setCenter({ball.getCenter().x_, TOP});
//     }
// }

// void Engine::checkRacketCollision(Ball &ball, Racket &racket)
// {
//     // ici il n'y a que la collision au sommet de la raquette qui est gérée
//     // il y des effets secondaires sur les côtés car si la balle est sous la raquette
//     // mais qu'elle percute cette dernière, elle sera "à l'intérieur" et remplira les conditions
//     // ce qui la renvoie vers le haut
//     // à voir s'il faut gérer plus proprement les collisions latérales

//     double topRacket = racket.getCenter().y_ - (racket.getHeight() / 2);
//     double leftRacket = racket.getCenter().x_ - (racket.getWidth() / 2);
//     double rightRacket = racket.getCenter().x_ + (racket.getWidth() / 2);

//     if ( // Vertical collision
//         ball.getCenter().y_ + ball.getRadius() >= topRacket &&
//         ball.getCenter().y_ - ball.getRadius() <= topRacket &&
//         // Horizontal collision
//         ball.getCenter().x_ >= leftRacket &&
//         ball.getCenter().x_ <= rightRacket)
//     {

//         ball.setCenter({ball.getCenter().x_, topRacket - ball.getRadius()});

//         double ballShift = ball.getCenter().x_ - leftRacket;
//         double angle = returnAngle(ballShift, racket.getWidth());
//         double speed = sqrt(pow(ball.getSpeed().x_, 2) + pow(ball.getSpeed().y_, 2));
//         double xSpeed = cos(angle);
//         double ySpeed = -sin(angle);
//         ball.setSpeed({xSpeed * speed, ySpeed * speed});
//     }
// }

// double Engine::returnAngle(double x, double L) const
// {
//     return ((30 + 120 * (1 - (x / L))) * (M_PI / 180)); // converting to rads
// }

// void Engine::checkBrickCollision(Ball &ball, std::vector<std::vector<Brick>> &bricks)
// {
//     // Don't need to check if the ball is not yet in the delimited brick zone
//     if (ball.getCenter().y_ - ball.getRadius() >= (WINDOW_HEIGHT / 3))
//     {
//         return;
//     }

//     // Defining ball values for clearer code
//     double cX = ball.getCenter().x_;
//     double cY = ball.getCenter().y_;
//     double r = ball.getRadius();

//     // Checking all bricks
//     for (auto &brickRow : bricks)
//     {
//         for (auto &brick : brickRow)
//         {
//             if (brick.isBroken())
//             {
//                 continue;
//             }

//             // Defining brick limits for clearer code
//             double LEFT = brick.getCenter().x_ - (brick.getWidth() / 2);
//             double RIGHT = brick.getCenter().x_ + (brick.getWidth() / 2);
//             double TOP = brick.getCenter().y_ - (brick.getHeight() / 2);
//             double DOWN = brick.getCenter().y_ + (brick.getHeight() / 2);

//             if ((cX + r > LEFT && cX - r < RIGHT) && // Horizontal collision ?
//                 (cY + r > TOP && cY - r < DOWN))
//             { // Vertical collision ?

//                 // Calculating side of collision
//                 double overlapX = std::min(cX + r - LEFT, RIGHT - (cX - r));
//                 double overlapY = std::min(cY + r - TOP, DOWN - (cY - r));

//                 if (overlapX < overlapY)
//                 {
//                     ball.setSpeed({ball.getSpeed().x_ * -1, ball.getSpeed().y_});
//                     if (cX < brick.getCenter().x_)
//                     {
//                         ball.setCenter({LEFT - r, cY});
//                     }
//                     else
//                     {
//                         ball.setCenter({RIGHT + r, cY});
//                     }
//                 }
//                 else
//                 {
//                     ball.setSpeed({ball.getSpeed().x_, ball.getSpeed().y_ * -1});
//                     if (cY < brick.getCenter().y_)
//                     {
//                         ball.setCenter({cX, TOP - r});
//                     }
//                     else
//                     {
//                         ball.setCenter({cX, DOWN + r});
//                     }
//                 }

//                 // Update brick state
//                 if (brick.isBreakable())
//                 {
//                     brick.setBroken();
//                 }
//                 return;
//             }
//         }
//     }
// }

/**
 * @file engine.cpp
 * @author Manuel Rocca
 * @brief Source file for the Engine class
 * @date 2024
 *
 */
//
#include "engine.hpp"

void Engine::move(std::shared_ptr<Racket> racket, Direction direction)
{
    double y = racket->getCenter().y_;
    switch (direction)
    {
    case Direction::RIGHT:
    {
        double maxRight = WINDOW_WIDTH - (racket->getWidth() / 2); // max pos of the racket on the right
        double newX = racket->getCenter().x_ + racket->get_speed();
        racket->set_center(Point{std::min(newX, maxRight), y});
        break;
    }

    case Direction::LEFT:
    {
        double maxLeft = racket->getWidth() / 2; // min pos of the racket on the left
        double newX = racket->getCenter().x_ - racket->get_speed();
        racket->set_center(Point{std::max(newX, maxLeft), y});
        break;
    }
    default:
        Logger::log("[ERROR] Unknown direction");
        break;
    }
}

void Engine::move(std::vector<std::shared_ptr<Ball>> balls,
                  std::vector<std::vector<std::shared_ptr<Brick>>> bricks,
                  std::shared_ptr<Racket> racket)
{
    for (auto &ball : balls)
    {
        check_wall_collision(ball);
        check_racket_collision(ball, racket);
        check_brick_collision(ball, bricks);

        double x_pos = ball->getCenter().x_;
        double y_pos = ball->getCenter().y_;

        double x_speed = ball->getSpeed().x_;
        double y_speed = ball->getSpeed().y_;

        ball->setCenter({x_pos + x_speed, y_pos + y_speed});
    }
}

void Engine::check_wall_collision(std::shared_ptr<Ball> ball)
{
    const double BALL_RADIUS = ball->getRadius();
    const double TOP = BALL_RADIUS;
    const double DOWN = WINDOW_HEIGHT - BALL_RADIUS;
    const double LEFT = BALL_RADIUS;
    const double RIGHT = WINDOW_WIDTH - BALL_RADIUS;

    // Reseting ball position after every bounce to assure it doesn't go out of bounds
    if (ball->getCenter().x_ >= RIGHT)
    {
        ball->setSpeed({ball->getSpeed().x_ * -1, ball->getSpeed().y_});
        ball->setCenter({RIGHT, ball->getCenter().y_});
    }

    else if (ball->getCenter().x_ <= LEFT)
    {
        ball->setSpeed({ball->getSpeed().x_ * -1, ball->getSpeed().y_});
        ball->setCenter({LEFT, ball->getCenter().y_});
    }

    else if (ball->getCenter().y_ >= DOWN)
    {
        ball->setSpeed({ball->getSpeed().x_, ball->getSpeed().y_ * -1});
        ball->setCenter({ball->getCenter().x_, DOWN});
    }

    else if (ball->getCenter().y_ <= TOP)
    {
        ball->setSpeed({ball->getSpeed().x_, ball->getSpeed().y_ * -1});
        ball->setCenter({ball->getCenter().x_, TOP});
    }
}

void Engine::check_racket_collision(std::shared_ptr<Ball> ball, std::shared_ptr<Racket> racket)
{
    // ici il n'y a que la collision au sommet de la raquette qui est gérée
    // il y des effets secondaires sur les côtés car si la balle est sous la raquette
    // mais qu'elle percute cette dernière, elle sera "à l'intérieur" et remplira les conditions
    // ce qui la renvoie vers le haut
    // à voir s'il faut gérer plus proprement les collisions latérales

    const double RACKET_TOP = racket->getCenter().y_ - (racket->getHeight() / 2);
    const double RACKET_LEFT = racket->getCenter().x_ - (racket->getWidth() / 2);
    const double RACKET_RIGHT = racket->getCenter().x_ + (racket->getWidth() / 2);

    if ( // Vertical collision
        ball->getCenter().y_ + ball->getRadius() >= RACKET_TOP &&
        ball->getCenter().y_ - ball->getRadius() <= RACKET_TOP &&
        // Horizontal collision
        ball->getCenter().x_ >= RACKET_LEFT &&
        ball->getCenter().x_ <= RACKET_RIGHT)
    {

        ball->setCenter({ball->getCenter().x_, RACKET_TOP - ball->getRadius()});

        double ballShift = ball->getCenter().x_ - RACKET_LEFT;
        double angle = return_angle(ballShift, racket->getWidth());
        double speed = sqrt(pow(ball->getSpeed().x_, 2) + pow(ball->getSpeed().y_, 2));
        double xSpeed = cos(angle);
        double ySpeed = -sin(angle);
        ball->setSpeed({xSpeed * speed, ySpeed * speed});
    }
}

void Engine::check_brick_collision(std::shared_ptr<Ball> ball,
                                   std::vector<std::vector<std::shared_ptr<Brick>>> bricks)
{
    // Defining ball values for clearer code
    double cX = ball->getCenter().x_;
    double cY = ball->getCenter().y_;
    double r = ball->getRadius();

    // Checking all bricks
    for (auto &brickRow : bricks)
    {
        for (auto &brick : brickRow)
        {
            if (brick->is_broken())
            {
                continue;
            }

            // Defining brick limits for clearer code
            double LEFT = brick->getCenter().x_ - (brick->getWidth() / 2);
            double RIGHT = brick->getCenter().x_ + (brick->getWidth() / 2);
            double TOP = brick->getCenter().y_ - (brick->getHeight() / 2);
            double DOWN = brick->getCenter().y_ + (brick->getHeight() / 2);

            if ((cX + r > LEFT && cX - r < RIGHT) && // Horizontal collision ?
                (cY + r > TOP && cY - r < DOWN))
            { // Vertical collision ?

                // Calculating side of collision
                double overlapX = std::min(cX + r - LEFT, RIGHT - (cX - r));
                double overlapY = std::min(cY + r - TOP, DOWN - (cY - r));

                if (overlapX < overlapY)
                {
                    ball->setSpeed({ball->getSpeed().x_ * -1, ball->getSpeed().y_});
                    if (cX < brick->getCenter().x_)
                    {
                        ball->setCenter({LEFT - r, cY});
                    }
                    else
                    {
                        ball->setCenter({RIGHT + r, cY});
                    }
                }
                else
                {
                    ball->setSpeed({ball->getSpeed().x_, ball->getSpeed().y_ * -1});
                    if (cY < brick->getCenter().y_)
                    {
                        ball->setCenter({cX, TOP - r});
                    }
                    else
                    {
                        ball->setCenter({cX, DOWN + r});
                    }
                }

                // Update brick state
                if (!brick->is_broken())
                {
                    brick->hit();
                }
                // TODO: update score, but should i do it here ?
                return;
            }
        }
    }
}

double Engine::return_angle(double x, double L) const
{
    return ((30 + 120 * (1 - (x / L))) * (M_PI / 180)); // converting to rads
}
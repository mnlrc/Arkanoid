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
    double y = racket->get_center().y_;
    switch (direction)
    {
    case Direction::RIGHT:
    {
        double maxRight = WINDOW_WIDTH - (racket->get_width() / 2); // max pos of the racket on the right
        double newX = racket->get_center().x_ + racket->get_speed();
        racket->set_center(Point{std::min(newX, maxRight), y});
        break;
    }

    case Direction::LEFT:
    {
        double maxLeft = racket->get_width() / 2; // min pos of the racket on the left
        double newX = racket->get_center().x_ - racket->get_speed();
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

        double x_pos = ball->get_center().x_;
        double y_pos = ball->get_center().y_;

        double x_speed = ball->get_speed().x_;
        double y_speed = ball->get_speed().y_;

        ball->set_center({x_pos + x_speed, y_pos + y_speed});
    }
}

void Engine::check_wall_collision(std::shared_ptr<Ball> ball)
{
    const double BALL_RADIUS = ball->get_radius();
    const double TOP = BALL_RADIUS;
    const double DOWN = WINDOW_HEIGHT - BALL_RADIUS;
    const double LEFT = BALL_RADIUS;
    const double RIGHT = WINDOW_WIDTH - BALL_RADIUS;

    // Reseting ball position after every bounce to assure it doesn't go out of bounds
    if (ball->get_center().x_ >= RIGHT)
    {
        ball->set_speed({ball->get_speed().x_ * -1, ball->get_speed().y_});
        ball->set_center({RIGHT, ball->get_center().y_});
    }

    else if (ball->get_center().x_ <= LEFT)
    {
        ball->set_speed({ball->get_speed().x_ * -1, ball->get_speed().y_});
        ball->set_center({LEFT, ball->get_center().y_});
    }

    else if (ball->get_center().y_ >= DOWN)
    {
        ball->set_speed({ball->get_speed().x_, ball->get_speed().y_ * -1});
        ball->set_center({ball->get_center().x_, DOWN});
    }

    else if (ball->get_center().y_ <= TOP)
    {
        ball->set_speed({ball->get_speed().x_, ball->get_speed().y_ * -1});
        ball->set_center({ball->get_center().x_, TOP});
    }
}

void Engine::check_racket_collision(std::shared_ptr<Ball> ball, std::shared_ptr<Racket> racket)
{
    // ici il n'y a que la collision au sommet de la raquette qui est gérée
    // il y des effets secondaires sur les côtés car si la balle est sous la raquette
    // mais qu'elle percute cette dernière, elle sera "à l'intérieur" et remplira les conditions
    // ce qui la renvoie vers le haut
    // à voir s'il faut gérer plus proprement les collisions latérales

    const double RACKET_TOP = racket->get_center().y_ - (racket->get_height() / 2);
    const double RACKET_LEFT = racket->get_center().x_ - (racket->get_width() / 2);
    const double RACKET_RIGHT = racket->get_center().x_ + (racket->get_width() / 2);

    if ( // Vertical collision
        ball->get_center().y_ + ball->get_radius() >= RACKET_TOP &&
        ball->get_center().y_ - ball->get_radius() <= RACKET_TOP &&
        // Horizontal collision
        ball->get_center().x_ >= RACKET_LEFT &&
        ball->get_center().x_ <= RACKET_RIGHT)
    {

        ball->set_center({ball->get_center().x_, RACKET_TOP - ball->get_radius()});

        double ballShift = ball->get_center().x_ - RACKET_LEFT;
        double angle = return_angle(ballShift, racket->get_width());
        double speed = sqrt(pow(ball->get_speed().x_, 2) + pow(ball->get_speed().y_, 2));
        double xSpeed = cos(angle);
        double ySpeed = -sin(angle);
        ball->set_speed({xSpeed * speed, ySpeed * speed});
    }
}

void Engine::check_brick_collision(std::shared_ptr<Ball> ball,
                                   std::vector<std::vector<std::shared_ptr<Brick>>> bricks)
{
    // Defining ball values for clearer code
    double cX = ball->get_center().x_;
    double cY = ball->get_center().y_;
    double r = ball->get_radius();

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
            double LEFT = brick->get_center().x_ - (brick->get_width() / 2);
            double RIGHT = brick->get_center().x_ + (brick->get_width() / 2);
            double TOP = brick->get_center().y_ - (brick->get_height() / 2);
            double DOWN = brick->get_center().y_ + (brick->get_height() / 2);

            if ((cX + r > LEFT && cX - r < RIGHT) && // Horizontal collision ?
                (cY + r > TOP && cY - r < DOWN))
            { // Vertical collision ?

                // Calculating side of collision
                double overlapX = std::min(cX + r - LEFT, RIGHT - (cX - r));
                double overlapY = std::min(cY + r - TOP, DOWN - (cY - r));

                if (overlapX < overlapY)
                {
                    ball->set_speed({ball->get_speed().x_ * -1, ball->get_speed().y_});
                    if (cX < brick->get_center().x_)
                    {
                        ball->set_center({LEFT - r, cY});
                    }
                    else
                    {
                        ball->set_center({RIGHT + r, cY});
                    }
                }
                else
                {
                    ball->set_speed({ball->get_speed().x_, ball->get_speed().y_ * -1});
                    if (cY < brick->get_center().y_)
                    {
                        ball->set_center({cX, TOP - r});
                    }
                    else
                    {
                        ball->set_center({cX, DOWN + r});
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
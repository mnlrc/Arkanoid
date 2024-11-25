#ifndef VIEW_HPP
#define VIEW_HPP


#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include <vector>


#include "entities/ball.hpp"
#include "entities/brick.hpp"
#include "entities/point.hpp"
#include "entities/racket.hpp"
#include "tests/allegro_test.hpp"


#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 600


class View {
    private:
        ALLEGRO_DISPLAY* display;

    public:
        View();
        ~View();
        ALLEGRO_DISPLAY* getDisplay() const noexcept;
        
        // Draw methods
        void draw(Racket racket, std::vector<Ball> balls, std::vector<std::vector<Brick>> bricks);
        void drawRacket(Racket racket);
        void drawBricks(std::vector<std::vector<Brick>> bricks);
        void drawBall(std::vector<Ball> balls);
};


#endif
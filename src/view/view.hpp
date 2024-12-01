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


#include "global_variables.hpp"


class View {
    private:
        ALLEGRO_DISPLAY* display;
        void drawRacket(const Racket& racket);
        void drawBricks(const std::vector<std::vector<Brick>>& bricks);
        void drawBall(const std::vector<Ball>& balls);

    public:
        View();
        ~View();
        ALLEGRO_DISPLAY* getDisplay() const noexcept;
        
        // Draw methods
        void drawAll(const Racket& racket, const std::vector<Ball>& balls, const std::vector<std::vector<Brick>>& bricks);
        void draw(const Racket& racket);
        void draw(const std::vector<Ball>& balls);
        void draw(const std::vector<std::vector<Brick>>& bricks);
};


#endif
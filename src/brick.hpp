#include <allegro5/allegro_color.h>

class Brick{
    private:
        const unsigned width;
        const unsigned height;
        bool isBreakable;
        const ALLEGRO_COLOR color;
    public:
        Brick();
        ~Brick();
};
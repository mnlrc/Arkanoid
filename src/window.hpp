#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <iostream>




class Window {
    
    private:
        const unsigned width;
        const unsigned height;
        ALLEGRO_DISPLAY* display;
    public:
    
        Window();

        ALLEGRO_DISPLAY* getDisplay() const noexcept;
};
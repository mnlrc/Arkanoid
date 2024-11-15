#include "window.hpp"


bool init_test(bool test, const char* description){
    if (!test){
        std::cerr << "Couldn't initialize " << description << std::endl;
        exit (1);
    }
    return;
}

Window::Window(const unsigned w, const unsigned h) : width(w), height(h) {}
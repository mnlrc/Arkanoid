#include "allegro_test.hpp"

void init_test(bool test, const char* description){
    if (!test){
        std::cerr << "Couldn't initialize " << description << std::endl;
        exit (1);
    }
}
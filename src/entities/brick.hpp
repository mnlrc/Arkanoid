#ifndef BRICK_HPP
#define BRICK_HPP

class Brick{
    private:
        const unsigned width_;
        const unsigned height_;
        bool isBreakable; // for later phases 
    public:
        Brick(unsigned w, unsigned h);
        ~Brick();
        unsigned getWidth() const noexcept;
        unsigned getHeight() const noexcept;
};

#endif
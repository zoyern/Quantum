#ifndef BASEOPS_HPP
#define BASEOPS_HPP

#include "def.hpp"

class Baseops {
public:
    Baseops(int width, int height, const std::string& title);
    ~Baseops();
    void run();

private:
    void initSDL();
    void initVulkan();
    void mainLoop();
    void cleanup();

    int width, height;
    std::string title;

    SDL_Window* window;
    VkInstance instance;
};

#endif // $(NAME_UPPER)_HPP

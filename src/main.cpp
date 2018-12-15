#include "gameloop.h"
#include "titlescreen.h"
#include "globals.h"

#include <SDL2pp/SDL2pp.hh>

#include <iostream>

int main(int argc, char **argv)
{
    std::string assetDir = ".";

    if (argc >= 2)
    {
        if (std::string(argv[1]) == "--version")
        {
            std::cout << "Version: 0.1" << std::endl;
            return 0;
        }
        assetDir = argv[1];
    }

    try
    {
        using namespace SDL2pp;

        // Init SDL; will be automatically deinitialized when the object is destroyed
        SDL sdl(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

        // Likewise, init SDL_ttf library
        SDLTTF sdl_ttf;

        // Straightforward wrappers around corresponding SDL2 objects
        // These take full care of proper object destruction and error checking
        Window window("Game Window",
                      SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                      1920, 1080, SDL_WINDOW_RESIZABLE);
        
        auto renderer = std::make_shared<Renderer>(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        renderer->SetLogicalSize(SCREEN_WIDTH, SCREEN_HEIGHT).SetDrawColor(0, 16, 32).Clear();

        auto titleScreen = std::make_shared<TitleScreen>();

        GameLoop loop(renderer, titleScreen);

        loop.setConfigValue("assetDir", assetDir);

        loop.exec();
    }
    catch (SDL2pp::Exception &e)
    {
        // Exception stores SDL_GetError() result and name of function which failed
        std::cerr << "Error in: " << e.GetSDLFunction() << std::endl;
        std::cerr << "  Reason: " << e.GetSDLError() << std::endl;
        return 1;
    }
    catch (std::exception &e)
    {
        // This also works (e.g. "SDL_Init failed: No available video device")
        std::cerr << "Caught exception: \"" << e.what() << "\"" << std::endl;
        return 1;
    }
    catch (...)
    {
        std::cerr << "Unknown exception caught." << std::endl;
        return 1;
    }

    return 0;
}

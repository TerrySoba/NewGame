#include <SDL2pp/SDL2pp.hh>



int main(int argc, char **argv)
{
    std::string assetDir = "";

    if (argc >= 2)
    {
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
        Window window("libSDL2pp demo",
                      SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                      1920, 1080, SDL_WINDOW_RESIZABLE);
        Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        Texture sprite1(renderer, SDL_PIXELFORMAT_ARGB8888,
                        SDL_TEXTUREACCESS_STATIC, 16, 16);
        // Texture sprite2(renderer, "sprite.png"); // SDL_image support

        Font font(assetDir + "/fonts/DejaVuSans.ttf", 40); // SDL_ttf font

        // Initialize audio mixer
        Mixer mixer(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);

        // Chunk sound("effect.ogg"); // OGG sound file

        // Create texture from surface containing text rendered by SDL_ttf
        Texture text(renderer, font.RenderUTF8_Blended(u8"Hello, world!",
                                                     SDL_Color{255, 255, 255, 255}));

        unsigned char pixels[16 * 16 * 4];

        // Note proper constructor for Rect
        sprite1.Update(Rect(0, 0, 16, 16), pixels, 16 * 4);

        // Most setter methods are chainable
        renderer.SetLogicalSize(320, 240).SetDrawColor(0, 16, 32).Clear();

        int pos = 0;

        // Main loop
        while (1)
        {
            // Event processing:
            // - If window is closed, or Q or Escape buttons are pressed,
            //   quit the application
            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    return 0;
                }
                else if (event.type == SDL_KEYDOWN)
                {
                    switch (event.key.keysym.sym)
                    {
                    case SDLK_ESCAPE:
                    case SDLK_q:
                        return 0;
                    }
                }

                

            }

            // Clear screen
            renderer.Clear();

            renderer.Copy(text, NullOpt, Rect(Point(0, pos++ % 240), text.GetSize()));

            renderer.Present();
        }
    }
    catch (SDL2pp::Exception &e)
    {
        // Exception stores SDL_GetError() result and name of function which failed
        std::cerr << "Error in: " << e.GetSDLFunction() << std::endl;
        std::cerr << "  Reason: " << e.GetSDLError() << std::endl;
    }
    catch (std::exception &e)
    {
        // This also works (e.g. "SDL_Init failed: No available video device")
        std::cerr << e.what() << std::endl;
    }
}

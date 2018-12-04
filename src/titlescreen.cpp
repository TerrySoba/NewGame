#include "titlescreen.h"


void TitleScreen::onEnter(GameLoopControl& gameLoopControl, SDL2pp::Renderer& renderer)
{
    SDL2pp::Font font(gameLoopControl.getConfigValue("assetDir") + "/fonts/DejaVuSans.ttf", 12);

    m_text = std::make_shared<SDL2pp::Texture>(renderer, font.RenderUTF8_Blended(u8"This is the title screen",
                                                     SDL_Color{255, 255, 0, 255}));

}

void TitleScreen::onExit(GameLoopControl& gameLoopControl, SDL2pp::Renderer& renderer)
{

}

void TitleScreen::doAction(GameLoopControl& gameLoopControl, GamePad& gamePad, uint64_t timeMs)
{
    if (gamePad.right) x += 1;
    if (gamePad.left) x -= 1;
}

void TitleScreen::draw(SDL2pp::Renderer& renderer, uint64_t timeMs)
{
    renderer.Copy(*m_text, SDL2pp::NullOpt, SDL2pp::Rect(SDL2pp::Point(x, (timeMs / 10) % 240) , m_text->GetSize()));
}

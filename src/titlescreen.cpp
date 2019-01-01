#include "titlescreen.h"

#include "level1.h"

#include <cmath>

void TitleScreen::onEnter(GameLoopControl& gameLoopControl, SDL2pp::Renderer& renderer)
{
    SDL2pp::Font font(gameLoopControl.getConfigValue("assetDir") + "/fonts/DejaVuSans.ttf", 50);

    m_gameTitleText = std::make_shared<SDL2pp::Texture>(renderer, font.RenderUTF8_Blended(u8"New Game",
                                                     SDL_Color{255, 255, 255, 255}));


    SDL2pp::Font font2(gameLoopControl.getConfigValue("assetDir") + "/fonts/DejaVuSans.ttf", 12);


    m_pressStartText = std::make_shared<SDL2pp::Texture>(renderer, font2.RenderUTF8_Blended(u8"Press Action Button to Play",
                                                     SDL_Color{255, 255, 0, 255}));

}

void TitleScreen::onExit(GameLoopControl& gameLoopControl, SDL2pp::Renderer& renderer)
{

}

void TitleScreen::doAction(GameLoopControl& gameLoopControl, const GamePad& gamePad, uint64_t timeMs)
{
    if (gamePad.fire)
    {
        gameLoopControl.switchToLevel(std::make_shared<Level1>());
    }
}

void TitleScreen::draw(SDL2pp::Renderer& renderer, uint64_t timeMs)
{
    renderer.Copy(*m_gameTitleText, SDL2pp::NullOpt, SDL2pp::Rect(SDL2pp::Point(80, 40) , m_gameTitleText->GetSize()));

    float offX = std::sin(timeMs / 321.0) * 10;
    float offY = std::sin(timeMs / 210.0) * 3;
    renderer.Copy(*m_pressStartText, SDL2pp::NullOpt, SDL2pp::Rect(SDL2pp::Point(140 + offX, 200 + offY), m_pressStartText->GetSize()));
}

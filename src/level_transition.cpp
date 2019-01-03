#include "level_transition.h"

#include <cmath>

LevelTransition::LevelTransition(std::shared_ptr<Level> nextLevel) :
    m_nextLevel(nextLevel)
{
}

void LevelTransition::onEnter(GameLoopControl& gameLoopControl, SDL2pp::Renderer& renderer)
{
    SDL2pp::Font font(gameLoopControl.getConfigValue("assetDir") + "/fonts/DejaVuSans.ttf", 50);

    m_gameTitleText = std::make_shared<SDL2pp::Texture>(renderer, font.RenderUTF8_Blended(u8"Get Ready!!",
                                                     SDL_Color{255, 255, 255, 255}));


    SDL2pp::Font font2(gameLoopControl.getConfigValue("assetDir") + "/fonts/DejaVuSans.ttf", 12);


    m_pressStartText = std::make_shared<SDL2pp::Texture>(renderer, font2.RenderUTF8_Blended(u8"Next level will start in 1000ms",
                                                     SDL_Color{255, 255, 0, 255}));

}

void LevelTransition::onExit(GameLoopControl& /*gameLoopControl*/, SDL2pp::Renderer& /*renderer*/)
{

}

void LevelTransition::doAction(GameLoopControl& gameLoopControl, const GamePad& /*gamePad*/, uint64_t timeMs)
{
    if (!m_transitionTime)
    {
        m_transitionTime = timeMs + 1000;
    }

    if (m_transitionTime && timeMs >= *m_transitionTime)
    {
        gameLoopControl.switchToLevel(m_nextLevel);
    }
}

void LevelTransition::draw(SDL2pp::Renderer& renderer, uint64_t timeMs)
{
    renderer.Copy(*m_gameTitleText, SDL2pp::NullOpt, SDL2pp::Rect(SDL2pp::Point(80, 40) , m_gameTitleText->GetSize()));

    float offX = std::sin(timeMs / 321.0) * 10;
    float offY = std::sin(timeMs / 210.0) * 3;
    renderer.Copy(*m_pressStartText, SDL2pp::NullOpt, SDL2pp::Rect(SDL2pp::Point(140 + offX, 200 + offY), m_pressStartText->GetSize()));
}

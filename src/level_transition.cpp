#include "level_transition.h"

#include "globals.h"

#include <cmath>

LevelTransition::LevelTransition(std::shared_ptr<Level> nextLevel, const std::string& text) :
    m_nextLevel(nextLevel),
    m_text(text)
{
}

void LevelTransition::onEnter(GameLoopControl& gameLoopControl, SDL2pp::Renderer& renderer)
{
    SDL2pp::Font font(gameLoopControl.getConfigValue("assetDir") + "/fonts/DejaVuSans.ttf", 50);

    Uint8 color = 255;
    int fontSize = 50;

    for (int i = 0; i < 5; ++i)
    {
        SDL2pp::Font font(gameLoopControl.getConfigValue("assetDir") + "/fonts/DejaVuSans.ttf", fontSize);
        fontSize *= 0.9;

        m_textTextures.push_front(std::make_shared<SDL2pp::Texture>(renderer, font.RenderUTF8_Blended(m_text,
                                                     SDL_Color{color, color, color, color})));
        color *= 0.6;
    }

}

void LevelTransition::onExit(GameLoopControl& /*gameLoopControl*/, SDL2pp::Renderer& /*renderer*/)
{

}

void LevelTransition::doAction(GameLoopControl& gameLoopControl, const GamePad& /*gamePad*/, uint64_t timeMs)
{
    if (!m_transitionTime)
    {
        m_transitionTime = timeMs + 3000;
    }

    if (m_transitionTime && timeMs >= *m_transitionTime)
    {
        gameLoopControl.switchToLevel(m_nextLevel);
    }
}

void LevelTransition::draw(SDL2pp::Renderer& renderer, uint64_t timeMs)
{
    // renderer.Copy(*m_gameTitleText, SDL2pp::NullOpt, SDL2pp::Rect(SDL2pp::Point(80, 40) , m_gameTitleText->GetSize()));

    SDL2pp::Point screenMiddle = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};

    int timeOffset = 0;

    for (auto& texture : m_textTextures)
    {
        SDL2pp::Point textureOff = texture->GetSize() / 2;

        int offX = std::sin((timeMs + timeOffset) / 221.0) * 30;
        int offY = std::sin((timeMs + timeOffset) / 297.0) * 20;

        SDL2pp::Point off = {offX, offY};

        renderer.Copy(*texture, SDL2pp::NullOpt, SDL2pp::Rect(off + screenMiddle - textureOff, texture->GetSize()));

        timeOffset += 40;
    }
}

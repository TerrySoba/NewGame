#include "level1.h"

#include "globals.h"

#include <cmath>

void Level1::onEnter(GameLoopControl& gameLoopControl, SDL2pp::Renderer& renderer)
{
    SDL2pp::Font font(gameLoopControl.getConfigValue("assetDir") + "/fonts/DejaVuSans.ttf", 10);

    m_levelHintText = std::make_shared<SDL2pp::Texture>(renderer, font.RenderUTF8_Blended(u8"Getting Started",
                                                     SDL_Color{255, 255, 0, 255}));



}

void Level1::onExit(GameLoopControl& gameLoopControl, SDL2pp::Renderer& renderer)
{

}

void Level1::doAction(GameLoopControl& gameLoopControl, GamePad& gamePad, uint64_t timeMs)
{
}

void drawCenteredH(SDL2pp::Renderer& renderer, SDL2pp::Texture& texture, int y)
{
    int x = (SCREEN_WIDTH / 2) - (texture.GetWidth() / 2);
    renderer.Copy(texture, SDL2pp::NullOpt, SDL2pp::Rect(SDL2pp::Point(x, y) , texture.GetSize()));
}

void drawActor(SDL2pp::Renderer& renderer, Actor& actor)
{
    renderer.Copy(*actor.texture, SDL2pp::NullOpt, SDL2pp::Rect(actor.pos, actor.texture->GetSize()));
}


void Level1::draw(SDL2pp::Renderer& renderer, uint64_t timeMs)
{
    // renderer.Copy(*m_levelHintText, SDL2pp::NullOpt, SDL2pp::Rect(SDL2pp::Point(100, 0) , m_levelHintText->GetSize()));
    drawCenteredH(renderer, *m_levelHintText, 0);
}

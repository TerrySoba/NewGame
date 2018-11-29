#pragma once

#include "level.h"

#include <SDL2pp/SDL2pp.hh>

class TitleScreen : public Level
{
public:
    virtual void onEnter(GameLoopControl& gameLoopControl, SDL2pp::Renderer& renderer) override;
    virtual void onExit(GameLoopControl& gameLoopControl, SDL2pp::Renderer& renderer) override;
    virtual void doAction(GameLoopControl& gameLoopControl, SDL2pp::Renderer& renderer, GamePad& gamePad, uint64_t timeMs) override;

private:
    std::shared_ptr<SDL2pp::Texture> m_text;
    int x = 0;
    int y = 0;
};

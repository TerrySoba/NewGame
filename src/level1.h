#pragma once

#include "level.h"

#include <SDL2pp/SDL2pp.hh>

#include <list>

struct Actor
{
    std::shared_ptr<SDL2pp::Texture> texture;
    SDL2pp::Point pos;
};

class Level1 : public Level
{
public:
    virtual void onEnter(GameLoopControl& gameLoopControl, SDL2pp::Renderer& renderer) override;
    virtual void onExit(GameLoopControl& gameLoopControl, SDL2pp::Renderer& renderer) override;
    virtual void doAction(GameLoopControl& gameLoopControl, GamePad& gamePad, uint64_t timeMs) override;
    virtual void draw(SDL2pp::Renderer& renderer, uint64_t timeMs) override;

private:
    std::shared_ptr<SDL2pp::Texture> m_levelHintText;

    std::list<Actor> m_idleBullets;
    std::list<Actor> m_activeBullets;

    Actor m_ship;
};

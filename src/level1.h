#pragma once

#include "level.h"
#include "logging.h"
#include "simple_actor.h"

#include <SDL2pp/SDL2pp.hh>

#include <list>

class Level1 : public Level
{
public:
    virtual void onEnter(GameLoopControl& gameLoopControl, SDL2pp::Renderer& renderer) override;
    virtual void onExit(GameLoopControl& gameLoopControl, SDL2pp::Renderer& renderer) override;
    virtual void doAction(GameLoopControl& gameLoopControl, GamePad& gamePad, uint64_t timeMs) override;
    virtual void draw(SDL2pp::Renderer& renderer, uint64_t timeMs) override;

private:
    std::shared_ptr<SDL2pp::Texture> m_levelHintText;

    std::list<ActorPtr> m_idleBullets;
    std::list<ActorPtr> m_activeBullets;

    std::shared_ptr<SimpleActor> m_ship;
};

#pragma once

#include "level.h"
#include "logging.h"
#include "simple_actor.h"
#include "actor_arena.h"
#include "bullet_actor.h"

#include <SDL2pp/SDL2pp.hh>

#include <vector>

class Level1 : public Level
{
public:
    virtual void onEnter(GameLoopControl& gameLoopControl, SDL2pp::Renderer& renderer) override;
    virtual void onExit(GameLoopControl& gameLoopControl, SDL2pp::Renderer& renderer) override;
    virtual void doAction(GameLoopControl& gameLoopControl, const GamePad& gamePad, uint64_t timeMs) override;
    virtual void draw(SDL2pp::Renderer& renderer, uint64_t timeMs) override;

    virtual std::shared_ptr<BulletActor> getInactiveBullet();

private:
    std::shared_ptr<SDL2pp::Texture> m_levelHintText;

    std::vector<std::shared_ptr<BulletActor>> m_bullets;
    uint64_t m_nextBulletTime = 0;

    std::shared_ptr<SimpleActor> m_ship;
    std::shared_ptr<SimpleActor> m_obstacle;

    ActorArena m_arena;
};

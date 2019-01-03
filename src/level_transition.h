#pragma once

#include "level.h"

#include <SDL2pp/SDL2pp.hh>

#include <memory>
#include <optional>

class LevelTransition : public Level
{
public:

    LevelTransition(std::shared_ptr<Level> nextLevel);

    virtual void onEnter(GameLoopControl& gameLoopControl, SDL2pp::Renderer& renderer) override;
    virtual void onExit(GameLoopControl& gameLoopControl, SDL2pp::Renderer& renderer) override;
    virtual void doAction(GameLoopControl& gameLoopControl, const GamePad& gamePad, uint64_t timeMs) override;
    virtual void draw(SDL2pp::Renderer& renderer, uint64_t timeMs) override;

private:
    std::shared_ptr<SDL2pp::Texture> m_gameTitleText;
    std::shared_ptr<SDL2pp::Texture> m_pressStartText;

    std::optional<uint64_t> m_transitionTime;
    std::shared_ptr<Level> m_nextLevel;
};

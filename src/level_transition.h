#pragma once

#include "level.h"

#include <SDL2pp/SDL2pp.hh>

#include <memory>
#include <optional>
#include <list>

class LevelTransition : public Level
{
public:

    LevelTransition(std::shared_ptr<Level> nextLevel, const std::string& text);

    virtual void onEnter(GameLoopControl& gameLoopControl, SDL2pp::Renderer& renderer) override;
    virtual void onExit(GameLoopControl& gameLoopControl, SDL2pp::Renderer& renderer) override;
    virtual void doAction(GameLoopControl& gameLoopControl, const GamePad& gamePad, uint64_t timeMs) override;
    virtual void draw(SDL2pp::Renderer& renderer, uint64_t timeMs) override;

private:
    std::list<std::shared_ptr<SDL2pp::Texture>> m_textTextures;

    std::optional<uint64_t> m_transitionTime;
    std::shared_ptr<Level> m_nextLevel;

    std::string m_text;
};

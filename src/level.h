#pragma once

#include "gamepad.h"
#include "gameloopcontrol.h"

#include <SDL2pp/SDL2pp.hh>

#include <cstdint>

class Level
{
public:
    virtual ~Level() {}

    virtual void onEnter(GameLoopControl& gameLoopControl, SDL2pp::Renderer& renderer) = 0;
    virtual void onExit(GameLoopControl& gameLoopControl, SDL2pp::Renderer& renderer) = 0;

    // called for each frame
    virtual void doAction(GameLoopControl& gameLoopControl, SDL2pp::Renderer& renderer, GamePad& gamePad, uint64_t timeMs) = 0;
};

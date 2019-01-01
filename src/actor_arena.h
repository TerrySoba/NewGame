#pragma once

#include "actor.h"
#include "gameloopcontrol.h"
#include "gamepad.h"

#include <vector>

class ActorArena
{
public:
    ActorArena();

    void addActor(ActorPtr actor);

    // This method must be called 200 times per second.
    void doAction(GameLoopControl& gameLoopControl, const GamePad& gamePad, uint64_t timeMs);

private:
    std::vector<ActorPtr> m_actors;
};

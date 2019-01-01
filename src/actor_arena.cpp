#include "actor_arena.h"


#include <set>

ActorArena::ActorArena()
{

}

void ActorArena::addActor(ActorPtr actor)
{
    m_actors.push_back(actor);
}

void ActorArena::doAction(GameLoopControl& gameLoopControl, const GamePad& gamePad, uint64_t timeMs)
{
    for (auto& actor : m_actors)
    {
        actor->doAction(gamePad, timeMs);
    }

    // now check for collisions
    // todo
}

#pragma once

#include "actor.h"

#include <map>
#include <set>

template <typename ContainerT>
std::map<ActorPtr, std::set<ActorPtr>> actorCollisions(const ContainerT& actors)
{
    std::map<ActorPtr, std::set<ActorPtr>> results;

    for (const ActorPtr& actorA : actors)
    {
        for (const ActorPtr& actorB : actors)
        {
            if (actorA != actorB)
            {
                auto intersects = actorA->getBoundingBox().Intersects(actorB->getBoundingBox());
                if (intersects)
                {
                    results[actorA].insert(actorB);
                }
            }
        }
    }

    return results;
}

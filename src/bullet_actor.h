#pragma once

#include "simple_actor.h"

class BulletActor : public SimpleActor
{
public:
    BulletActor(std::shared_ptr<SDL2pp::Texture> texture, const SDL2pp::Point& pos);

    // This method is called periodically, 200 times per second.
    virtual void doAction(const GamePad& gamePad, uint64_t timeMs) override;

    // This method will be called if the bounding box of this actor collides
    // with the bounding box of another actor.
    virtual void collision(std::set<ActorPtr> otherActors) override;

    virtual bool isActive() const;
    virtual void setActive(bool active);

private:
    bool m_active = false;
};

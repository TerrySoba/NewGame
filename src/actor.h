#pragma once

#include "gamepad.h"

#include <SDL2pp/SDL2pp.hh>

#include <memory>

struct Actor;
typedef std::shared_ptr<Actor> ActorPtr;

struct Actor
{
    virtual SDL2pp::Texture& getTexture() const = 0;
    virtual SDL2pp::Point getPos() const = 0;
    virtual SDL2pp::Rect getBoundingBox() const = 0;

    // This method is called periodically, 200 times per second.
    virtual void doAction(const GamePad& gamePad, uint64_t timeMs) {}

    // This method will be called if the bounding box of this actor collides
    // with the bounding box of another actor.
    virtual void collision(ActorPtr otherActor) {}
};

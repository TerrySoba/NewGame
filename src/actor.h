#pragma once

#include <SDL2pp/SDL2pp.hh>

#include <memory>

struct Actor
{
    virtual SDL2pp::Texture& getTexture() const = 0;
    virtual SDL2pp::Point getPos() const = 0;
    virtual SDL2pp::Rect getBoundingBox() const = 0;
};

typedef std::shared_ptr<Actor> ActorPtr;

#pragma once

#include "actor.h"

#include <memory>

class SimpleActor : public Actor
{
public:
    SimpleActor(std::shared_ptr<SDL2pp::Texture> texture, const SDL2pp::Point& pos);
    virtual SDL2pp::Texture& getTexture() const override;
    virtual SDL2pp::Point getPos() const override;
    virtual SDL2pp::Rect getBoundingBox() const override;

    void setPos(const SDL2pp::Point& p) { m_pos = p; }

private:
    std::shared_ptr<SDL2pp::Texture> m_texture;
    SDL2pp::Point m_pos;
};

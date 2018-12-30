#include "simple_actor.h"

#include "logging.h"

SimpleActor::SimpleActor(std::shared_ptr<SDL2pp::Texture> texture, const SDL2pp::Point& pos) :
    m_texture(texture),
    m_pos(pos)
{
    if (!texture)
    {
        THROW_EXCEPTION("Expected valid texture, but got nullptr.");
    }
}

SDL2pp::Texture& SimpleActor::getTexture() const
{
    return *m_texture;
}

SDL2pp::Point SimpleActor::getPos() const
{
    return m_pos;
}

SDL2pp::Rect SimpleActor::getBoundingBox() const
{
    auto size = m_texture->GetSize();
    return SDL2pp::Rect(m_pos, size);
}

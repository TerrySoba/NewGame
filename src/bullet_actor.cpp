#include "bullet_actor.h"

BulletActor::BulletActor(std::shared_ptr<SDL2pp::Texture> texture, const SDL2pp::Point& pos) :
    SimpleActor(texture, pos)
{

}

void BulletActor::doAction(const GamePad& /*gamePad*/, uint64_t /*timeMs*/)
{
    if (m_active)
    {
        auto pos = getPos();
        pos += SDL2pp::Point{0, -2};
        setPos(pos);

        if (pos.GetY() < -32)
        {
            m_active = false;
        }

    }
}

void BulletActor::collision(std::set<ActorPtr> /*otherActors*/)
{
    this->setActive(false);
    setPos({-100, -100});
}

bool BulletActor::isActive() const
{
    return m_active;
}

void BulletActor::setActive(bool active)
{
    m_active = active;
}

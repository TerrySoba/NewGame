#include "level1.h"
#include "globals.h"
#include "simple_actor.h"

#include <cmath>

void Level1::onEnter(GameLoopControl& gameLoopControl, SDL2pp::Renderer& renderer)
{
    SDL2pp::Font font(gameLoopControl.getConfigValue("assetDir") + "/fonts/DejaVuSans.ttf", 10);

    m_levelHintText = std::make_shared<SDL2pp::Texture>(renderer, font.RenderUTF8_Blended(u8"Getting Started",
                                                     SDL_Color{255, 255, 0, 255}));

    auto shipTexture = std::make_shared<SDL2pp::Texture>(renderer, gameLoopControl.getConfigValue("assetDir") + "/gfx/ship.png");
    m_ship = std::make_shared<SimpleActor>(shipTexture, SDL2pp::Point{100,220});

    m_arena.addActor(m_ship);

    auto bulletTexture = std::make_shared<SDL2pp::Texture>(renderer, gameLoopControl.getConfigValue("assetDir") + "/gfx/bullet.png");

    // add some idle bullets
    for (int i = 0; i < 10; ++i)
    {
        auto bullet = std::make_shared<BulletActor>(bulletTexture, SDL2pp::Point{-100,-100});
        m_arena.addActor(bullet);
        m_bullets.push_back(bullet);
    }
}

void Level1::onExit(GameLoopControl& /*gameLoopControl*/, SDL2pp::Renderer& /*renderer*/)
{
    
}

std::shared_ptr<BulletActor> Level1::getInactiveBullet()
{
    for (auto bullet : m_bullets)
    {
        if (!bullet->isActive())
        {
            return bullet;
        }
    }

    return nullptr;
}

void Level1::doAction(GameLoopControl& gameLoopControl, const GamePad& gamePad, uint64_t timeMs)
{
    auto newShipPos = m_ship->getPos();

    if (gamePad.right)
    {
        newShipPos += {1,0};
    }

    if (gamePad.left)
    {
        newShipPos -= {1,0};
    }

    auto minX = 0;
    auto maxX = SCREEN_WIDTH - m_ship->getBoundingBox().GetW();

    if (newShipPos.GetX() < minX) newShipPos.SetX(minX);
    if (newShipPos.GetX() > maxX) newShipPos.SetX(maxX);

    m_ship->setPos(newShipPos);

    if (gamePad.fire && timeMs >= m_nextBulletTime)
    {
        auto bullet = getInactiveBullet();
        if (bullet)
        {
            bullet->setPos(SDL2pp::Point(newShipPos.GetX(), 200));
            bullet->setActive(true);
            m_nextBulletTime = timeMs + 200;
        }
    }

    m_arena.doAction(gameLoopControl, gamePad, timeMs);
}

void drawCenteredH(SDL2pp::Renderer& renderer, SDL2pp::Texture& texture, int y)
{
    int x = (SCREEN_WIDTH / 2) - (texture.GetWidth() / 2);
    renderer.Copy(texture, SDL2pp::NullOpt, SDL2pp::Rect(SDL2pp::Point(x, y) , texture.GetSize()));
}

void drawActor(SDL2pp::Renderer& renderer, Actor& actor)
{
    SDL2pp::Texture& texture = actor.getTexture();
    renderer.Copy(texture, SDL2pp::NullOpt, SDL2pp::Rect(actor.getPos(), texture.GetSize()));
}


void Level1::draw(SDL2pp::Renderer& renderer, uint64_t /*timeMs*/)
{
    // renderer.Copy(*m_levelHintText, SDL2pp::NullOpt, SDL2pp::Rect(SDL2pp::Point(100, 0) , m_levelHintText->GetSize()));
    drawCenteredH(renderer, *m_levelHintText, 0);

    if (m_ship)
    {
        drawActor(renderer, *m_ship);
    }

    for (auto bullet : m_bullets)
    {
        if (bullet->isActive())
        {
            drawActor(renderer, *bullet);
        }
    }
}

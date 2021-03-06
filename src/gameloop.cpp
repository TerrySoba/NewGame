#include "gameloop.h"

#include <exception>
#include <cassert>

GameLoop::GameLoop(std::shared_ptr<SDL2pp::Renderer> renderer, std::shared_ptr<Level> initialLevel) :
    m_renderer(renderer),
    m_nextLevel(initialLevel)
{
    assert(initialLevel != nullptr);
}

void GameLoop::switchToLevel(std::shared_ptr<Level> level)
{
    m_nextLevel = level;
}

void GameLoop::exec()
{
    bool gameEnd = false;

    GamePad gamePad;

    uint32_t lastTicks = SDL_GetTicks();
    uint32_t currentTicks = lastTicks;

    while (!gameEnd)
    {
        if (m_nextLevel)
        {
            if (m_currentLevel)
                m_currentLevel->onExit(*this, *m_renderer);
            m_currentLevel = m_nextLevel;
            m_nextLevel.reset();
            m_currentLevel->onEnter(*this, *m_renderer);
            lastTicks = SDL_GetTicks();
        }

        currentTicks = SDL_GetTicks();

        while (lastTicks < currentTicks)
        {
            lastTicks += 5; // 5ms corresponds to 200Hz

            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    gameEnd = true;
                }
                else if (event.type == SDL_KEYDOWN)
                {
                    switch (event.key.keysym.sym)
                    {
                    case SDLK_ESCAPE:
                    case SDLK_q:
                        gameEnd = true;
                        break;
                    case SDLK_LEFT:
                        gamePad.left = true;
                        break;
                    case SDLK_RIGHT:
                        gamePad.right = true;
                        break;
                    case SDLK_LCTRL:
                        gamePad.fire = true;
                        break;
                    }
                }
                else if (event.type == SDL_KEYUP)
                {
                    switch (event.key.keysym.sym)
                    {
                    case SDLK_LEFT:
                        gamePad.left = false;
                        break;
                    case SDLK_RIGHT:
                        gamePad.right = false;
                        break;
                    case SDLK_LCTRL:
                        gamePad.fire = false;
                        break;
                    }
                }
            }

            m_currentLevel->doAction(*this, gamePad, lastTicks);
        }

        m_renderer->Clear();
        m_currentLevel->draw(*m_renderer, SDL_GetTicks());
        m_renderer->Present();
    }
}

void GameLoop::setConfigValue(const std::string& key, const std::string& value)
{
    m_config.insert({key, value});
}

std::string GameLoop::getConfigValue(const std::string& key)
{
    auto it = m_config.find(key);
    if (it != m_config.end()) {
        return it->second;
    } else {
        return "";
    } 
}

#pragma once

#include "level.h"
#include "gameloopcontrol.h"

#include <SDL2pp/SDL2pp.hh>

#include <memory>
#include <map>
#include <string>

class GameLoop : public GameLoopControl
{
public:
    GameLoop(std::shared_ptr<SDL2pp::Renderer> renderer, std::shared_ptr<Level> initialLevel);
    void exec();

    // GameLoopControl interface
    virtual void switchToLevel(std::shared_ptr<Level> level) override;
    virtual void setConfigValue(const std::string& key, const std::string& value) override;
    virtual std::string getConfigValue(const std::string& key) override;

private:
    std::shared_ptr<SDL2pp::Renderer> m_renderer;
    std::shared_ptr<Level> m_currentLevel;
    std::shared_ptr<Level> m_nextLevel;

    std::map<std::string, std::string> m_config;

};

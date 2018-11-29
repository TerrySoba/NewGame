#pragma once

#include <memory>
#include <string>

// forward declaration
class Level;

class GameLoopControl
{
public:
    virtual ~GameLoopControl() {}
    virtual void switchToLevel(std::shared_ptr<Level> level) = 0;
    virtual void setConfigValue(const std::string& key, const std::string& value) = 0;
    virtual std::string getConfigValue(const std::string& key) = 0;
};

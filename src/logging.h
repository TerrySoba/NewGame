#pragma once

#include <sstream>
#include <exception>
#include <iostream>

class NewGameException : public std::runtime_error
{
public:
    NewGameException(const std::string& message) :
        std::runtime_error(message) {}
};

#define SOURCE_LOCATION __FILE__ << ":" << __LINE__

#define LOG_ERROR(message) \
    { \
        std::stringstream location; \
        location << __FILE__ << ":" << __LINE__; \
        std::cerr << location.str() << " " << message << std::endl; \
    }

#define THROW_EXCEPTION(message) \
    { \
        LOG_ERROR("Exception thrown: \"" << message << "\""); \
        std::stringstream ss; \
        ss << message; \
        throw NewGameException(ss.str()); \
    }

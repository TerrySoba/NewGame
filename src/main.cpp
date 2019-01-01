#include "new_game.h"

#include <string>
#include <iostream>

int main(int argc, char **argv)
{
    std::string assetDir = ".";

    if (argc >= 2)
    {
        if (std::string(argv[1]) == "--version")
        {
            std::cout << "Version: 0.1" << std::endl;
            return 0;
        }
        assetDir = argv[1];
    }

    return runNewGame(assetDir);
}

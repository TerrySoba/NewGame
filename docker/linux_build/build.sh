#!/bin/bash

docker build . -t yoshi252/newgamebuilder
docker run -v "$(pwd)"/../../:/repo -v "$(pwd)"/../../build:/build -t yoshi252/newgamebuilder sh -c "cd /build && cmake -GNinja /repo && ninja"


REM docker build -t yoshi252/mingw64 .
docker run -v %~dp0../../../:C:/repo -v %~dp0build:C:/build -t yoshi252/mingw64 cmd /c ^
    "cd build && cmake -DCMAKE_LIBRARY_ARCHITECTURE=x64 -DCMAKE_PREFIX_PATH=C:/SDL2/SDL2-2.0.9/x86_64-w64-mingw32;C:/SDL2/SDL2_image-2.0.4/x86_64-w64-mingw32;C:/SDL2/SDL2_mixer-2.0.4/x86_64-w64-mingw32;C:/SDL2/SDL2_ttf-2.0.14/x86_64-w64-mingw32 -GNinja -DCMAKE_BUILD_TYPE=Release C:/repo && ninja && ninja install"
rem echo %~dp0
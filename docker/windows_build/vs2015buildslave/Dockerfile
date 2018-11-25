FROM yoshi252/vs2015

WORKDIR C:\\cmake
RUN powershell -Command Invoke-WebRequest -Uri https://github.com/Kitware/CMake/releases/download/v3.13.0/cmake-3.13.0-win64-x64.msi -OutFile cmake-3.13.0-win64-x64.msi
RUN msiexec.exe /i cmake-3.13.0-win64-x64.msi /quiet /qn /norestart /log install.log
RUN setx path "C:\\Program Files\\CMake\\bin;%PATH%"

WORKDIR C:\\java
RUN powershell -Command Invoke-WebRequest -Uri https://download.java.net/java/GA/jdk10/10.0.2/19aef61b38124481863b1413dce1855f/13/openjdk-10.0.2_windows-x64_bin.tar.gz -OutFile jdk10.tar.gz
RUN cmake -E tar xzf jdk10.tar.gz
RUN setx path "C:\\java\\jdk-10.0.2\\bin;%PATH%"

WORKDIR C:\\SDL2
RUN powershell -Command Invoke-WebRequest -Uri https://www.libsdl.org/release/SDL2-devel-2.0.9-VC.zip -OutFile SDL2-devel-2.0.9-VC.zip
RUN cmake -E tar xzf SDL2-devel-2.0.9-VC.zip

RUN powershell -Command Invoke-WebRequest -Uri https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-devel-2.0.14-VC.zip -OutFile SDL2_ttf-devel-2.0.14-VC.zip
RUN cmake -E tar xzf SDL2_ttf-devel-2.0.14-VC.zip

RUN powershell -Command Invoke-WebRequest -Uri https://www.libsdl.org/projects/SDL_mixer/release/SDL2_mixer-devel-2.0.4-VC.zip -OutFile SDL2_mixer-devel-2.0.4-VC.zip
RUN cmake -E tar xzf SDL2_mixer-devel-2.0.4-VC.zip

RUN powershell -Command Invoke-WebRequest -Uri https://www.libsdl.org/projects/SDL_image/release/SDL2_image-devel-2.0.4-VC.zip -OutFile SDL2_image-devel-2.0.4-VC.zip
RUN cmake -E tar xzf SDL2_image-devel-2.0.4-VC.zip


WORKDIR C:\\ninja
RUN powershell -Command Invoke-WebRequest -Uri https://github.com/ninja-build/ninja/releases/download/v1.8.2/ninja-win.zip -OutFile ninja-win.zip
RUN cmake -E tar xzf ninja-win.zip
RUN setx path "C:\\ninja;%PATH%"

WORKDIR C:\\git
RUN powershell -Command Invoke-WebRequest -Uri https://github.com/git-for-windows/git/releases/download/v2.19.2.windows.1/MinGit-2.19.2-64-bit.zip -OutFile MinGit-2.19.2-64-bit.zip
RUN cmake -E tar xzf MinGit-2.19.2-64-bit.zip
RUN setx path "C:\\git\\cmd;%PATH%"

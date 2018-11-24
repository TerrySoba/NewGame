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

WORKDIR C:\\ninja
RUN powershell -Command Invoke-WebRequest -Uri https://github.com/ninja-build/ninja/releases/download/v1.8.2/ninja-win.zip -OutFile ninja-win.zip
RUN cmake -E tar xzf ninja-win.zip
RUN setx path "C:\\ninja;%PATH%"


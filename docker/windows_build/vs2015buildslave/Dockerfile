FROM yoshi252/vs2015

WORKDIR C:\\wget
ADD https://eternallybored.org/misc/wget/1.19.4/64/wget.exe .
RUN setx path "C:\\wget;%PATH%"

RUN mkdir C:\\7zip && \
    cd C:\\7zip && \
    wget --no-check-certificate https://www.7-zip.org/a/7z1805-x64.msi && \
    msiexec.exe /i 7z1805-x64.msi /quiet /qn /norestart /log install.log && \
    setx path "C:\\Program Files\\7-Zip;%PATH%"

RUN mkdir C:\\cmake && \
    cd C:\\cmake && \
    wget --no-check-certificate https://github.com/Kitware/CMake/releases/download/v3.13.1/cmake-3.13.1-win64-x64.zip && \
    7z.exe x cmake-3.13.1-win64-x64.zip && \
    setx path "C:\\cmake\\cmake-3.13.1-win64-x64\\bin;%PATH%"

RUN mkdir C:\\java && \
    cd C:\\java && \
	wget --no-check-certificate https://download.java.net/java/GA/jdk10/10.0.2/19aef61b38124481863b1413dce1855f/13/openjdk-10.0.2_windows-x64_bin.tar.gz && \
    cmake -E tar xzf openjdk-10.0.2_windows-x64_bin.tar.gz && \
    setx path "C:\\java\\jdk-10.0.2\\bin;%PATH%"

RUN mkdir C:\\SDL2 && \
	cd C:\\SDL2 && \
	wget --no-check-certificate https://www.libsdl.org/release/SDL2-devel-2.0.9-VC.zip && \
	cmake -E tar xzf SDL2-devel-2.0.9-VC.zip && \
	wget --no-check-certificate https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-devel-2.0.14-VC.zip && \
	cmake -E tar xzf SDL2_ttf-devel-2.0.14-VC.zip && \
	wget --no-check-certificate https://www.libsdl.org/projects/SDL_mixer/release/SDL2_mixer-devel-2.0.4-VC.zip && \
	cmake -E tar xzf SDL2_mixer-devel-2.0.4-VC.zip && \
	wget --no-check-certificate https://www.libsdl.org/projects/SDL_image/release/SDL2_image-devel-2.0.4-VC.zip && \
	cmake -E tar xzf SDL2_image-devel-2.0.4-VC.zip

RUN mkdir C:\\ninja && \
    cd C:\\ninja && \
    wget --no-check-certificate https://github.com/ninja-build/ninja/releases/download/v1.8.2/ninja-win.zip && \
    cmake -E tar xzf ninja-win.zip && \
	setx path "C:\\ninja;%PATH%"

RUN mkdir C:\\git && \
    cd C:\\git && \
	wget --no-check-certificate https://github.com/git-for-windows/git/releases/download/v2.19.2.windows.1/MinGit-2.19.2-64-bit.zip && \
	cmake -E tar xzf MinGit-2.19.2-64-bit.zip && \
	setx path "C:\\git\\cmd;%PATH%"

# FROM mcr.microsoft.com/windows/nanoserver:1809
FROM mcr.microsoft.com/windows/servercore:ltsc2019 as builder

WORKDIR C:\\wget
ADD https://eternallybored.org/misc/wget/1.19.4/64/wget.exe .
RUN setx /M  PATH "C:\\wget;%PATH%"

WORKDIR C:\\7zip
ADD https://www.7-zip.org/a/7z1805-x64.msi .
RUN msiexec.exe /i 7z1805-x64.msi /quiet /qn /norestart /log install.log && \
    setx /M  path "C:\\Program Files\\7-Zip;%PATH%"

RUN mkdir C:\\cmake && \
    cd C:\\cmake && \
    wget --no-check-certificate https://github.com/Kitware/CMake/releases/download/v3.13.1/cmake-3.13.1-win64-x64.zip && \
    7z.exe x cmake-3.13.1-win64-x64.zip && \
    setx /M  path "C:\\cmake\\cmake-3.13.1-win64-x64\\bin;%PATH%"

RUN mkdir C:\\java && \
    cd C:\\java && \
	wget --no-check-certificate https://download.java.net/java/GA/jdk10/10.0.2/19aef61b38124481863b1413dce1855f/13/openjdk-10.0.2_windows-x64_bin.tar.gz && \
    cmake -E tar xzf openjdk-10.0.2_windows-x64_bin.tar.gz && \
    setx /M  path "C:\\java\\jdk-10.0.2\\bin;%PATH%"

RUN mkdir C:\\ninja && \
    cd C:\\ninja && \
    wget --no-check-certificate https://github.com/ninja-build/ninja/releases/download/v1.8.2/ninja-win.zip && \
    cmake -E tar xzf ninja-win.zip && \
	setx /M  path "C:\\ninja;%PATH%"

RUN mkdir C:\\git && \
    cd C:\\git && \
	wget --no-check-certificate https://github.com/git-for-windows/git/releases/download/v2.19.2.windows.1/MinGit-2.19.2-64-bit.zip && \
	cmake -E tar xzf MinGit-2.19.2-64-bit.zip && \
	setx /M  path "C:\\git\\cmd;%PATH%"

RUN mkdir C:\\SDL2 && \
	cd C:\\SDL2 && \
	wget --no-check-certificate https://www.libsdl.org/release/SDL2-devel-2.0.9-mingw.tar.gz && \
	cmake -E tar xzf SDL2-devel-2.0.9-mingw.tar.gz && \
	wget --no-check-certificate https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-devel-2.0.14-mingw.tar.gz && \
	cmake -E tar xzf SDL2_ttf-devel-2.0.14-mingw.tar.gz && \
	wget --no-check-certificate https://www.libsdl.org/projects/SDL_mixer/release/SDL2_mixer-devel-2.0.4-mingw.tar.gz && \
	cmake -E tar xzf SDL2_mixer-devel-2.0.4-mingw.tar.gz && \
	wget --no-check-certificate https://www.libsdl.org/projects/SDL_image/release/SDL2_image-devel-2.0.4-mingw.tar.gz && \
	cmake -E tar xzf SDL2_image-devel-2.0.4-mingw.tar.gz
	
RUN cd C:\\ && \
	wget --no-check-certificate https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/8.1.0/threads-win32/seh/x86_64-8.1.0-release-win32-seh-rt_v6-rev0.7z
	
RUN cd C:\\ && \
    7z.exe x x86_64-8.1.0-release-win32-seh-rt_v6-rev0.7z && \
	dir
	
#RUN cd C:\\ && \
#    wget --no-check-certificate http://repo.msys2.org/distrib/x86_64/msys2-base-x86_64-20181211.tar.xz


#RUN cd C:\\ && \
#    7z.exe x msys2-base-x86_64-20181211.tar.xz && \
#	7z.exe x msys2-base-x86_64-20181211.tar && \
#    dir && \
#	C:\\msys64\\msys2_shell.cmd
	

	
FROM mcr.microsoft.com/windows/nanoserver:1809
USER Administrator
COPY --from=builder C:\\git C:\\git
RUN setx /M  path "C:\\git\\cmd;%PATH%"

COPY --from=builder C:\\cmake C:\\cmake
RUN setx /M  path "C:\\cmake\\cmake-3.13.1-win64-x64\\bin;%PATH%"

COPY --from=builder C:\\java C:\\java
RUN setx /M  path "C:\\java\\jdk-10.0.2\\bin;%PATH%"

COPY --from=builder C:\\ninja C:\\ninja
RUN setx /M  path "C:\\ninja;%PATH%"

COPY --from=builder C:\\SDL2 C:\\SDL2

COPY --from=builder C:\\mingw64 C:\\mingw64
RUN setx /M  path "C:\\mingw64\bin;%PATH%"

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
if (WIN32)

    set(MINGW_DLL_DIR C:/mingw64/bin)

    install(
        FILES 
            ${MINGW_DLL_DIR}/libgcc_s_seh-1.dll
            ${MINGW_DLL_DIR}/libstdc++-6.dll
        DESTINATION bin)

    install(
        FILES 
            C:/SDL2/SDL2-2.0.9/x86_64-w64-mingw32/bin/SDL2.dll
        DESTINATION bin
    )

    set(SDL2_MIXER_DLL_DIR C:/SDL2/SDL2_mixer-2.0.4/x86_64-w64-mingw32/bin)

    install(
        FILES
            ${SDL2_MIXER_DLL_DIR}/libFLAC-8.dll
            ${SDL2_MIXER_DLL_DIR}/libmodplug-1.dll
            ${SDL2_MIXER_DLL_DIR}/libmpg123-0.dll
            ${SDL2_MIXER_DLL_DIR}/libogg-0.dll
            ${SDL2_MIXER_DLL_DIR}/libopus-0.dll
            ${SDL2_MIXER_DLL_DIR}/libopusfile-0.dll
            ${SDL2_MIXER_DLL_DIR}/libvorbis-0.dll
            ${SDL2_MIXER_DLL_DIR}/libvorbisfile-3.dll
            ${SDL2_MIXER_DLL_DIR}/SDL2_mixer.dll
        DESTINATION bin 
    )

    set(SDL2_TTF_DLL_DIR C:/SDL2/SDL2_ttf-2.0.14/x86_64-w64-mingw32/bin)
    install(
        FILES
            ${SDL2_TTF_DLL_DIR}/libfreetype-6.dll
            ${SDL2_TTF_DLL_DIR}/SDL2_ttf.dll
            ${SDL2_TTF_DLL_DIR}/zlib1.dll
        DESTINATION bin 
    ) 

    set(SDL2_IMAGE_DLL_DIR C:/SDL2/SDL2_image-2.0.4/x86_64-w64-mingw32/bin)
    install(
        FILES
            ${SDL2_IMAGE_DLL_DIR}/libjpeg-9.dll
            ${SDL2_IMAGE_DLL_DIR}/libpng16-16.dll
            ${SDL2_IMAGE_DLL_DIR}/libtiff-5.dll
            ${SDL2_IMAGE_DLL_DIR}/libwebp-7.dll
            ${SDL2_IMAGE_DLL_DIR}/SDL2_image.dll
            ${SDL2_IMAGE_DLL_DIR}/zlib1.dll
        DESTINATION bin
    )

endif (WIN32)
endif ()

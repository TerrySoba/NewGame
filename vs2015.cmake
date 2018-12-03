if (MSVC_VERSION)

    set(VC_DLL_DIR C:/BuildTools/VC/Tools/MSVC/14.16.27023/bin/Hostx86/x86)

    install(
        FILES 
            ${VC_DLL_DIR}/msvcp140.dll
            ${VC_DLL_DIR}/vcruntime140.dll
        DESTINATION bin)

    install(
        FILES 
            C:/SDL2/SDL2-2.0.9/lib/x86/SDL2.dll
        DESTINATION bin 
    )

    set(SDL2_MIXER_DLL_DIR C:/SDL2/SDL2_mixer-2.0.4/lib/x86)

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

    set(SDL2_TTF_DLL_DIR C:/SDL2/SDL2_ttf-2.0.14/lib/x86)
    install(
        FILES
            ${SDL2_TTF_DLL_DIR}/libfreetype-6.dll
            ${SDL2_TTF_DLL_DIR}/SDL2_ttf.dll
            ${SDL2_TTF_DLL_DIR}/zlib1.dll
        DESTINATION bin 
    ) 

    set(SDL2_IMAGE_DLL_DIR C:/SDL2/SDL2_image-2.0.4/lib/x86)
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

endif (MSVC_VERSION)
pipeline {
    agent none

    options {
        skipDefaultCheckout()
    }

    stages {
        stage('Build') {
            agent {
                label 'vs2015buildslave'
            }

            steps {
                checkout scm
                echo 'Building..'
                bat 'C:\\BuildTools\\VC\\Auxiliary\\Build\\vcvarsall.bat x86 -vcvars_ver=14.0 && cmake -DCMAKE_LIBRARY_ARCHITECTURE=x86 -DCMAKE_PREFIX_PATH=C:/SDL2/SDL2-2.0.9;C:/SDL2/SDL2_image-2.0.4;C:/SDL2/SDL2_mixer-2.0.4;C:/SDL2/SDL2_ttf-2.0.14 -GNinja -DCMAKE_BUILD_TYPE=Release . && ninja && ninja install'
                archiveArtifacts artifacts: 'install', fingerprint: true
            }
        }

    }
}

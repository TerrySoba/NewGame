pipeline {
    agent none

    /* options {
        skipDefaultCheckout()
    } */

    stages {
	
        stage('Build Windows') {
            agent {
                // label 'vs2015buildslave'
                // dockerfile {
                docker {
                    image 'vs2015buildslave'
                    // filename 'Dockerfile'
                    // dir 'docker/windows_build/vs2015buildslave'
                }
            }

            steps {
                checkout scm
                echo 'Building..'
                bat '''C:\\BuildTools\\VC\\Auxiliary\\Build\\vcvarsall.bat x86 -vcvars_ver=14.0 && \
                    cmake -DCMAKE_LIBRARY_ARCHITECTURE=x86 \
                        -DCMAKE_PREFIX_PATH=C:/SDL2/SDL2-2.0.9;C:/SDL2/SDL2_image-2.0.4;C:/SDL2/SDL2_mixer-2.0.4;C:/SDL2/SDL2_ttf-2.0.14 \
                        -GNinja -DCMAKE_BUILD_TYPE=Release . && \
                    ninja && \
                    ninja install
                    '''
                archiveArtifacts artifacts: 'install/**/*', fingerprint: true
                stash includes: 'install/**', name: 'installed_app'
            }
        }

        stage('Smoke Test') {
            agent {
                label 'windows'
            }

            steps {
                echo 'Running Smoke Test'
                unstash 'installed_app'
                bat 'install\\NewGame\\bin\\NewGame.exe --version'
            }

            post {
                always {
                    echo 'Clean up workspace'
                    deleteDir() /* clean up our workspace */
                }
            }

        }

    }
}

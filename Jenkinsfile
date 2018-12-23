pipeline {
    agent none

    options {
        skipDefaultCheckout()
    }

    stages {
	
        stage('Build Windows') {
            agent {
                label 'mingw64'
            }

            steps {
                checkout scm
                echo 'Building..'
                bat '''cmake -DCMAKE_LIBRARY_ARCHITECTURE=x64 \
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

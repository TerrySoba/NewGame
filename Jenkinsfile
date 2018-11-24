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
                bat 'cmake -GNinja -DCMAKE_BUILD_TYPE=Release . && ninja && ninja install'
            }
        }

    }
}

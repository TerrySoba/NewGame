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
                bat 'C:\BuildTools\VC\Auxiliary\Build\vcvarsall.bat x86 -vcvars_ver=14.0 && cmake -GNinja -DCMAKE_BUILD_TYPE=Release . && ninja'
            }
        }

    }
}

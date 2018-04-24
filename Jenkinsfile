/* Jenkinsfile
* Test EPITECH plateforme collaborative étudiant
* florent.poinsard@epitech.eu
*/

pipeline {
	agent any

	stages {
		stage('Build') {
			steps {
				echo 'Building the project'
				sh 'make fclean && make > make_log.txt'
			}
		}
		stage('Coding_Style') {
			steps {
				echo 'Check the coding style'
				sh 'coding_style > coding_style_log.txt'
			}
		}
		stage('Test') {
			steps {
				sh 'make tests_auto'
			}
		}
		stage('Report') {
			steps {
				echo 'Sending report to student'
			}
		}
	}
	post {
		always {
			archiveArtifacts artifacts: '*_log.txt', fingerprint: true
		}
		failure {
			emailext attachLog: true, attachmentsPattern: '*_log.txt', body: 'Check out the given files.', subject: 'PSU_42sh_2017 [FAILURE]', to: 'florent.poinsard@epitech.eu, florian.davasse@epitech.eu'
		}
		success {
			emailext attachLog: true, attachmentsPattern: '*_log.txt', body: 'Check out the given files.', subject: 'PSU_42sh_2017 [SUCCESS]', to: 'florent.poinsard@epitech.eu, florian.davasse@epitech.eu'
		}
	}
}

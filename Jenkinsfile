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
		stage('Unit_Test') {
			steps {
				/* Compiling unit tests. Makefile rule : tests_compile */
				echo 'Running Unit Test'
				sh 'make fclean && make tests_compile > make_test_log.txt'
				/* Execute unit tests binary. Binary name : 42sh_test */
				timeout(time: 1.5, unit: 'MINUTES') {
					sh './42sh_test || true'
				}
				/* Coverage */
				sh 'gcovr -r . > coverage_test_log.txt'
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
	}
}

#!/bin/bash

RESULTS="test_report_log.txt"
BINARY="42sh"
BUFFER_TCSH="buffer_tcsh.txt"
BUFFER_42SH="buffer_42sh.txt"
BUFFER2_TCSH="buffer2_tcsh.txt"
BUFFER2_42SH="buffer2_42sh.txt"
RESULT_BUFFER=0

init_repo() {
	if [ -f $RESULTS ]; then
		rm $RESULTS
	fi
	if [ -f $BINARY ]; then
		clear
		echo "The test will begin soon ..."
	else
		make re
		if [[ $? -ne 0 ]]; then
			clear
			echo "Got an error when compiling. Try again."
			echo "Got an error when compiling. Try again." >> $RESULTS
			exit 1
		fi
		clear
		echo "The test will begin soon ..."
	fi
}

clean_up_repo() {
	rm $BUFFER_42SH $BUFFER_TCSH $BUFFER2_42SH $BUFFER2_TCSH
	if [[ $? -ne 0 ]]; then
		echo "Got an error when cleaning the repo."
		echo "Got an error when cleaning the repo." >> $RESULTS
		exit 1
	fi
}

display_result() {
	clear
	cat $RESULTS
}

check_return() {
	if [[ $1 -ne $2 ]]; then
		RESULT_BUFFER=1
	elif [[ $1 -eq $2 ]]; then
		RESULT_BUFFER=0
	fi
}

# cd_builtin
cd_builtin_easy() {
	echo -ne "cd ..\nenv" | ./$BINARY > $BUFFER_42SH
	check_return "$?" "0"
	if [[ $RESULT_BUFFER -eq 1 ]]; then
		echo -e "[ FAILURE ] -> cd_builtin_easy wrong exit status got different than 0. Got = $?" >> $RESULTS
	else
		echo -ne "cd ..\nenv" | tcsh > $BUFFER_TCSH
		cat $BUFFER_42SH | grep -w "PWD" > $BUFFER2_42SH
		cat $BUFFER_TCSH | grep -w "PWD" > $BUFFER2_TCSH
		diff $BUFFER2_42SH $BUFFER2_TCSH
		if [[ $? -eq 1 ]]; then
			echo -e "[ FAILURE ] -> cd_builtin_easy wrong pwd." >> $RESULTS
		else
			echo -e "[ SUCCESS ] -> cd_builtin_easy." >> $RESULTS
		fi
	fi
}

cd_builtin_home() {
	echo -ne "cd\nenv" | ./$BINARY > $BUFFER_42SH
	check_return "$?" "0"
	if [[ $RESULT_BUFFER -eq 1 ]]; then
		echo -e "[ FAILURE ] -> cd_builtin_home wrong exit status got different than 0. Got = $?" >> $RESULTS
	else
		echo -ne "cd\nenv" | tcsh > $BUFFER_TCSH
		cat $BUFFER_42SH | grep -w "PWD" > $BUFFER2_42SH
		cat $BUFFER_TCSH | grep -w "PWD" > $BUFFER2_TCSH
		diff $BUFFER2_42SH $BUFFER2_TCSH
		if [[ $? -eq 1 ]]; then
			echo -e "[ FAILURE ] -> cd_builtin_home wrong pwd." >> $RESULTS
		else
			echo -e "[ SUCCESS ] -> cd_builtin_home." >> $RESULTS
		fi
	fi
}

cd_builtin_error() {
	echo -ne "cd toto" | ./$BINARY > $BUFFER_42SH
	check_return "$?" "1"
	if [[ $RESULT_BUFFER -eq 1 ]]; then
		echo -e "[ FAILURE ] -> cd_builtin_error wrong exit status got different than 1. Got = $?" >> $RESULTS
	else
		grep "toto: No such file or directory." $BUFFER_42SH
		if [[ $? -eq 1 ]]; then
			echo -e "[ FAILURE ] -> cd_builtin_error wrong error message." >> $RESULTS
		else
			echo -e "[ SUCCESS ] -> cd_builtin_error." >> $RESULTS
		fi
	fi
}

# exec_binary
non_existing_binary() {
	echo -ne "./toto" | ./$BINARY > $BUFFER_42SH
	check_return "$?" "1"
	if [[ $RESULT_BUFFER -eq 1 ]]; then
		echo -e "[ FAILURE ] -> non_existing_binary wrong exit status got different than 1. Got = $?" >> $RESULTS
	else
		grep "./toto: Command not found." $BUFFER_42SH
		if [[ $? -eq 1 ]]; then
			echo -e "[ FAILURE ] -> non_existing_binary wrong error message." >> $RESULTS
		else
			echo -e "[ SUCCESS ] -> non_existing_binary." >> $RESULTS
		fi
	fi
}

non_existing_binary_2() {
	echo -ne "./../../Delivery/toto" | ./$BINARY > $BUFFER_42SH
	check_return "$?" "1"
	if [[ $RESULT_BUFFER -eq 1 ]]; then
		echo -e "[ FAILURE ] -> non_existing_binary_2 wrong exit status got different than 1. Got = $?" >> $RESULTS
	else
		grep "./../../Delivery/toto: Command not found." $BUFFER_42SH
		if [[ $? -eq 1 ]]; then
			echo -e "[ FAILURE ] -> non_existing_binary_2 wrong error message." >> $RESULTS
		else
			echo -e "[ SUCCESS ] -> non_existing_binary_2." >> $RESULTS
		fi
	fi
}

ls_command() {
	echo -ne "ls" | ./$BINARY > $BUFFER_42SH
	check_return "$?" "0"
	if [[ $RESULT_BUFFER -eq 1 ]]; then
		echo -e "[ FAILURE ] -> ls_command wrong exit status got different than 0. Got = $?" >> $RESULTS
	else
		grep "Makefile" $BUFFER_42SH
		if [[ $? -eq 1 ]]; then
			echo -e "[ FAILURE ] -> ls_command wrong output." >> $RESULTS
		else
			echo -e "[ SUCCESS ] -> ls_command." >> $RESULTS
		fi
	fi
}

cat_command() {
	echo -ne "cat 42sh_tester" | ./$BINARY > $BUFFER_42SH
	check_return "$?" "0"
	if [[ $RESULT_BUFFER -eq 1 ]]; then
		echo -e "[ FAILURE ] -> cat_command wrong exit status got different than 0. Got = $?" >> $RESULTS
	else
		grep "#!/bin/sh" $BUFFER_42SH
		if [[ $? -eq 1 ]]; then
			echo -e "[ FAILURE ] -> cat_command wrong output." >> $RESULTS
		else
			echo -e "[ SUCCESS ] -> cat_command." >> $RESULTS
		fi
	fi
}

# parsing
easy_parsing() {
	echo -ne "cd         \t   ..\nenv" | ./$BINARY > $BUFFER_42SH
	check_return "$?" "0"
	if [[ $RESULT_BUFFER -eq 1 ]]; then
		echo -e "[ FAILURE ] -> easy_parsing wrong exit status got different than 0. Got = $?" >> $RESULTS
	else
		echo -ne "cd ..\nenv" | tcsh > $BUFFER_TCSH
		cat $BUFFER_42SH | grep -w "PWD" > $BUFFER2_42SH
		cat $BUFFER_TCSH | grep -w "PWD" > $BUFFER2_TCSH
		diff $BUFFER2_42SH $BUFFER2_TCSH
		if [[ $? -eq 1 ]]; then
			echo -e "[ FAILURE ] -> easy_parsing wrong pwd." >> $RESULTS
		else
			echo -e "[ SUCCESS ] -> easy_parsing." >> $RESULTS
		fi
	fi
}

easy_parsing_2() {
	echo -ne "  cd    \t   \t         \t   ..   \t \n      env " | ./$BINARY > $BUFFER_42SH
	check_return "$?" "0"
	if [[ $RESULT_BUFFER -eq 1 ]]; then
		echo -e "[ FAILURE ] -> easy_parsing_2 wrong exit status got different than 0. Got = $?" >> $RESULTS
	else
		echo -ne "cd ..\nenv" | tcsh > $BUFFER_TCSH
		cat $BUFFER_42SH | grep -w "PWD" > $BUFFER2_42SH
		cat $BUFFER_TCSH | grep -w "PWD" > $BUFFER2_TCSH
		diff $BUFFER2_42SH $BUFFER2_TCSH
		if [[ $? -eq 1 ]]; then
			echo -e "[ FAILURE ] -> easy_parsing_2 wrong pwd." >> $RESULTS
		else
			echo -e "[ SUCCESS ] -> easy_parsing_2." >> $RESULTS
		fi
	fi
}

easy_parsing_3() {
	echo -ne "  cd\t    \t   \t         \t   \t..\t   \t \n      env " | ./$BINARY > $BUFFER_42SH
	check_return "$?" "0"
	if [[ $RESULT_BUFFER -eq 1 ]]; then
		echo -e "[ FAILURE ] -> easy_parsing_3 wrong exit status got different than 0. Got = $?" >> $RESULTS
	else
		echo -ne "cd ..\nenv" | tcsh > $BUFFER_TCSH
		cat $BUFFER_42SH | grep -w "PWD" > $BUFFER2_42SH
		cat $BUFFER_TCSH | grep -w "PWD" > $BUFFER2_TCSH
		diff $BUFFER2_42SH $BUFFER2_TCSH
		if [[ $? -eq 1 ]]; then
			echo -e "[ FAILURE ] -> easy_parsing_3 wrong pwd." >> $RESULTS
		else
			echo -e "[ SUCCESS ] -> easy_parsing_3." >> $RESULTS
		fi
	fi
}

cd_builtin() {
	echo "------ CD BUILTIN ------" >> $RESULTS
	cd_builtin_easy
	cd_builtin_home
	cd_builtin_error
}

exec_binary() {
	echo "------ EXEC BINARY ------" >> $RESULTS
	non_existing_binary
	non_existing_binary_2
	ls_command
	cat_command
}

parsing() {
	echo "------ PARSING ------" >> $RESULTS
	easy_parsing
	easy_parsing_2
	easy_parsing_3
}

basic_test() {
	echo "--> BASIC TEST" >> $RESULTS
	cd_builtin
	exec_binary
	parsing
}

if [[ $# -eq 0 ]]; then
	init_repo
	basic_test
	clean_up_repo
	display_result
else
	echo "Please do not enter any argument to the program."
	exit 1
fi

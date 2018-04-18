#!/bin/sh

##
## AUTOMATED TEST : MINISHELL2 / EPITECH 2018 PROJECT
##
## florent.poinsard@epitech.eu
##

BUFFER="__buffer__"
BUFFER2="__buffer2__"
BUFFER3="__buffer3__"
RESULT_FILE="__result_file__.txt"

prepare_repo() {
  clear
  make re
  rm $RESULT_FILE
  make
  mkdir __exec_file__
  clear
}

write_test_result() {
  if [ $1 -eq $2 ]
  then
    printf "[  SUCCESS  ] -> Test %s\n" $3 >> $RESULT_FILE
  else
    printf "[  FAILURE  ] -> Test %s\n" $3 >> $RESULT_FILE
  fi
}

## invalid command
{
  test_invalid_command_1() {
    echo -ne "exitt" | ./mysh > ./__exec_file__/file_ref_1_log.txt
    grep "exitt: Command not found." ./__exec_file__/file_ref_1_log.txt > /dev/null
    write_test_result "$?" "0" "basic_invalid_1"
  }

  test_invalid_command_2() {
    echo -ne "/usr/pwd" | ./mysh > ./__exec_file__/file_ref_2_log.txt
    grep "/usr/pwd: Command not found." ./__exec_file__/file_ref_2_log.txt > /dev/null
    write_test_result "$?" "0" "basic_invalid_2"
  }

  test_invalid_command_3() {
    echo -ne "e cd" | ./mysh > ./__exec_file__/file_ref_3_log.txt
    grep "e: Command not found." ./__exec_file__/file_ref_3_log.txt > /dev/null
    write_test_result "$?" "0" "basic_invalid_3"
  }
}

## simple exec
{
  test_simple_exec_1() {
    echo -ne "/usr/bin/ls mysh" | ./mysh > ./__exec_file__/simple_exec_1.txt
    grep "mysh" ./__exec_file__/simple_exec_1.txt > /dev/null
    write_test_result "$?" "0" "simple_exec_1"
  }

  test_simple_exec_2() {
    echo -ne "hey guys how are you ?\n" > $BUFFER
    echo "/usr/bin/cat __buffer__" | ./mysh > ./__exec_file__/simple_exec_2.txt
    grep "hey guys how are you ?" ./__exec_file__/simple_exec_2.txt > /dev/null
    write_test_result "$?" "0" "simple_exec_2"
    rm $BUFFER
  }
}

## cd builtins
{
  test_cd_builtins_1() {
    echo -ne "cd ..\nunsetenv OLDPWD\nenv\n" | tcsh -f > $BUFFER
    grep "PWD=" $BUFFER > $BUFFER2
    echo -ne "cd ..\nunsetenv OLDPWD\nenv\n" | ./mysh > $BUFFER
    grep "PWD=" $BUFFER > $BUFFER3
    diff $BUFFER3 $BUFFER2 > ./__exec_file__/cd_builtins_1.txt
    write_test_result "$?" "0" "cd_builtins_1"
    rm $BUFFER
    rm $BUFFER2
    rm $BUFFER3
  }

  test_cd_builtins_2() {
    echo -ne "cd\nunsetenv OLDPWD\nenv\n" | tcsh -f > $BUFFER
    grep "PWD=" $BUFFER > $BUFFER2
    echo -ne "cd\nunsetenv OLDPWD\nenv\n" | ./mysh > $BUFFER
    grep "PWD=" $BUFFER > $BUFFER3
    diff $BUFFER3 $BUFFER2 > ./__exec_file__/cd_builtins_2.txt
    write_test_result "$?" "0" "cd_builtins_2"
    rm $BUFFER
    rm $BUFFER2
    rm $BUFFER3
  }

  test_cd_builtins_3() {
    echo -ne "cd ../../\nunsetenv OLDPWD\nenv\n" | tcsh -f > $BUFFER
    grep "PWD=" $BUFFER > $BUFFER2
    echo -ne "cd ../../\nunsetenv OLDPWD\nenv\n" | env -i ./mysh > $BUFFER
    grep "PWD=" $BUFFER > $BUFFER3
    diff $BUFFER3 $BUFFER2 > ./__exec_file__/cd_builtins_3.txt
    write_test_result "$?" "0" "cd_builtins_3"
    rm $BUFFER
    rm $BUFFER2
    rm $BUFFER3
  }

  test_cd_builtins_4() {
    echo -ne "cd /\nunsetenv OLDPWD\nenv\n" | env -i tcsh -f > $BUFFER
    grep "PWD=" $BUFFER > $BUFFER2
    echo -ne "cd /\nunsetenv OLDPWD\nenv\n" | env -i ./mysh > $BUFFER
    grep "PWD=" $BUFFER > $BUFFER3
    diff $BUFFER3 $BUFFER2 > ./__exec_file__/cd_builtins_4.txt
    write_test_result "$?" "0" "cd_builtins_4"
    rm $BUFFER
    rm $BUFFER2
    rm $BUFFER3
  }
}

## setenv builtins
{
  test_setenv_builtins_1() {
    echo -ne "setenv TITI 123\nenv\n" | ./mysh > ./__exec_file__/setenv_builtins_1.txt
    grep "TITI=" __exec_file__/setenv_builtins_1.txt > /dev/null
    write_test_result "$?" "0" "setenv_builtins_1"
  }

  test_setenv_builtins_2() {
    echo -ne "setenv TITI 123\nsetenv TOTO 789AZE\nenv\n" | ./mysh > ./__exec_file__/setenv_builtins_2.txt
    grep "TITI=123" __exec_file__/setenv_builtins_2.txt > /dev/null
    write_test_result "$?" "0" "setenv_builtins_2"
  }

  test_setenv_builtins_3() {
    echo -ne "setenv TITI 123=123=123=123=ABCDEF\nenv\n" | env -i ./mysh > ./__exec_file__/setenv_builtins_3.txt
    grep "TITI=123=123=123=123=ABCDEF" __exec_file__/setenv_builtins_3.txt > /dev/null
    write_test_result "$?" "0" "setenv_builtins_3"
  }
}

## unsetenv builtins
{
  test_unsetenv_builtins_1() {
    echo -ne "setenv TITI 123\nunsetenv TITI\nenv\n" | ./mysh > ./__exec_file__/unsetenv_builtins_1.txt
    grep "TITI=" __exec_file__/unsetenv_builtins_1.txt > /dev/null
    write_test_result "$?" "1" "unsetenv_builtins_1"
  }

  test_unsetenv_builtins_2() {
    echo -ne "setenv TITI 123\nsetenv TOTO 789AZE\nunsetenv TITI\nenv\n" | ./mysh > ./__exec_file__/unsetenv_builtins_2.txt
    grep "TITI=123" __exec_file__/unsetenv_builtins_2.txt > /dev/null
    write_test_result "$?" "1" "unsetenv_builtins_2"
  }

  test_unsetenv_builtins_3() {
    echo -ne "setenv TITI 123=123=123=123=ABCDEF\nunsetenv TITI\nenv\n" | env -i ./mysh > ./__exec_file__/unsetenv_builtins_3.txt
    grep "TITI=123=123=123=123=ABCDEF" __exec_file__/unsetenv_builtins_3.txt > /dev/null
    write_test_result "$?" "1" "unsetenv_builtins_3"
  }
}

# main
prepare_repo
printf "Tests will begin soon...\n"
echo -ne "----- SIMPLE INVALID COMMAND -----\n" > $RESULT_FILE
test_invalid_command_1
test_invalid_command_2
test_invalid_command_3
echo -ne "\n----- SIMPLE EXEC -----\n" >> $RESULT_FILE
test_simple_exec_1
test_simple_exec_2
echo -ne "\n----- CD BUILTINS -----\n" >> $RESULT_FILE
test_cd_builtins_1
test_cd_builtins_2
test_cd_builtins_3
test_cd_builtins_4
echo -ne "\n----- SETENV BUILTINS -----\n" >> $RESULT_FILE
test_setenv_builtins_1
test_setenv_builtins_2
test_setenv_builtins_3
echo -ne "\n----- UNSETENV BUILTINS -----\n" >> $RESULT_FILE
test_unsetenv_builtins_1
test_unsetenv_builtins_2
test_unsetenv_builtins_3

cat $RESULT_FILE

#!/bin/sh

##
## AUTOMATED TEST : 42sh / EPITECH 2018 PROJECT
##
## florent.poinsard@epitech.eu; benjamin.feller@epitech.eu
## Can be used for 42sh and minishells, feel free to use it
## and push it in you ./bonus/ to test you binary
##

BIN="./42sh"
TESTSPATH="dirname $0"
if [ $# -gt 0 ]; then BIN=$1; fi

BUFFER="__buffer__"
BUFFER2="__buffer2__"
BUFFER3="__buffer3__"
RESULT_FILE="__result_file__.txt"
RM_AFTR=1

TEXT="\e[96m"
PASS="\e[32m"
FAIL="\e[91m\e[5m"
END="\e[0m"

prepare_repo() {
  #make re > /dev/null
  rm -f $RESULT_FILE
  rm -rf __exec_file__
  rm -f $TESTSPATH/$BIN
  cp $BIN $TESTSPATH/ &> /dev/null
  #make > /dev/null
  mkdir __exec_file__
}

write_test_result() {
  if [ $1 -eq $2 ]
  then printf "$PASS[ OK ]$END $TEXT$> %s %s %s\n$END" $4 $5 $6 >> $RESULT_FILE
  else printf "$FAIL[ KO ]$END $TEXT$> %s %s %s\n$END" $4 $5 $6 >> $RESULT_FILE
  fi
}

## Invalid command
{
  test_invalid_command_1() {
    cmd="exitt"
    echo -ne $cmd | $BIN &> ./__exec_file__/file_ref_1_log.txt
    grep "$cmd: Command not found." ./__exec_file__/file_ref_1_log.txt > /dev/null
    write_test_result "$?" "0" "basic_invalid_1" $cmd
  }

  test_invalid_command_2() {
    cmd="/usr/pwd"
    echo -ne $cmd | $BIN &> ./__exec_file__/file_ref_2_log.txt
    grep "$cmd: Command not found." ./__exec_file__/file_ref_2_log.txt > /dev/null
    write_test_result "$?" "0" "basic_invalid_2" $cmd
  }

  test_invalid_command_3() {
    cmd="e cd"
    echo -ne $cmd | $BIN &> ./__exec_file__/file_ref_3_log.txt
    grep "e: Command not found." ./__exec_file__/file_ref_3_log.txt > /dev/null
    write_test_result "$?" "0" "basic_invalid_3" $cmd
  }
}

## Simple exec
{
  test_simple_exec_1() {
    cmd="/usr/bin/ls 42sh"
    echo -ne $cmd | $BIN > ./__exec_file__/simple_exec_1.txt
    grep "42sh" ./__exec_file__/simple_exec_1.txt > /dev/null
    write_test_result "$?" "0" "simple_exec_1" $cmd
  }

  test_simple_exec_2() {
    cmd="/usr/bin/cat __buffer__"
    echo -ne "hey guys how are you ?\n" > $BUFFER
    echo $cmd | $BIN > ./__exec_file__/simple_exec_2.txt
    grep "hey guys how are you ?" ./__exec_file__/simple_exec_2.txt > /dev/null
    write_test_result "$?" "0" "simple_exec_2" $cmd
    rm $BUFFER
  }
  test_simple_exec_3() {
    cmd="/usr/bin/cat __buffer__"
    echo -ne "hey guys how are you ?\n" > $BUFFER
    echo $cmd | $BIN > ./__exec_file__/simple_exec_3.txt
    grep "hey guys how are you ?" ./__exec_file__/simple_exec_3.txt > /dev/null
    write_test_result "$?" "0" "simple_exec_2" $cmd
    rm $BUFFER
  }
}

## Built-in cd
{
  test_cd_builtins_1() {
    cmd="cd ..\nunsetenv OLDPWD\nenv\n"
    echo -ne $cmd | tcsh -f > $BUFFER
    grep "PWD=" $BUFFER > $BUFFER2
    echo -ne $cmd | $BIN > $BUFFER
    grep "PWD=" $BUFFER > $BUFFER3
    diff $BUFFER3 $BUFFER2 > ./__exec_file__/cd_builtins_1.txt
    write_test_result "$?" "0" "cd_builtins_1" $cmd
    rm $BUFFER
    rm $BUFFER2
    rm $BUFFER3
  }

  test_cd_builtins_2() {
    cmd="cd ..\nunsetenv OLDPWD PWD\nenv\ncd -\npwd\n"
    echo -ne $cmd | tcsh -f > $BUFFER
    grep $PWD $BUFFER > $BUFFER2
    echo -ne $cmd | $BIN > $BUFFER
    grep $PWD $BUFFER > $BUFFER3
    diff $BUFFER3 $BUFFER2 > ./__exec_file__/cd_builtins_2.txt
    write_test_result "$?" "0" "cd_builtins_2" $cmd
    rm $BUFFER
    rm $BUFFER2
    rm $BUFFER3
  }

  test_cd_builtins_3() {
    cmd="cd ../../\nunsetenv OLDPWD PWD\nenv\ncd -\npwd"
    echo -ne $cmd | env -i tcsh -f > $BUFFER
    grep $PWD $BUFFER > $BUFFER2
    echo -ne $cmd | env -i $BIN > $BUFFER
    grep $PWD $BUFFER > $BUFFER3
    diff $BUFFER3 $BUFFER2 > ./__exec_file__/cd_builtins_3.txt
    write_test_result "$?" "0" "cd_builtins_3" $cmd
    rm $BUFFER
    rm $BUFFER2
    rm $BUFFER3
  }

  test_cd_builtins_4() {
    cmd="cd /\nunsetenv OLDPWD\nenv\n"
    echo -ne $cmd | env -i tcsh -f > $BUFFER
    grep "PWD=" $BUFFER > $BUFFER2
    echo -ne $cmd | env -i $BIN > $BUFFER
    grep "PWD=" $BUFFER > $BUFFER3
    diff $BUFFER3 $BUFFER2 > ./__exec_file__/cd_builtins_4.txt
    write_test_result "$?" "0" "cd_builtins_4" $cmd
    rm $BUFFER
    rm $BUFFER2
    rm $BUFFER3
  }

  test_cd_builtins_no_home() {
    cmd="cd ~\npwd\n"
    echo -ne $cmd | env -i $BIN &> ./__exec_file__/cd_builtins_4.txt
    grep 'No $home variable set.' ./__exec_file__/cd_builtins_4.txt >> ./__exec_file__/cd_builtins_no_home.txt
    write_test_result "$?" "0" "useless param" $cmd
  }
}

## Built-in setenv
{
  test_setenv_builtins_1() {
    cmd="setenv TITI 123\nenv\n"
    echo -ne $cmd | $BIN > ./__exec_file__/setenv_builtins_1.txt
    grep "TITI=" __exec_file__/setenv_builtins_1.txt > /dev/null
    write_test_result "$?" "0" "setenv_builtins_1" $cmd
  }

  test_setenv_builtins_2() {
    cmd="setenv TITI 123\nsetenv TOTO 789AZE\nenv\n"
    echo -ne $cmd | $BIN > ./__exec_file__/setenv_builtins_2.txt
    grep "TITI=123" __exec_file__/setenv_builtins_2.txt > /dev/null
    write_test_result "$?" "0" "setenv_builtins_2" $cmd
  }

  test_setenv_builtins_3() {
    cmd="setenv TITI 123=123=123=123=ABCDEF\nenv\n"
    echo -ne $cmd | env -i $BIN > ./__exec_file__/setenv_builtins_3.txt
    grep "TITI=123=123=123=123=ABCDEF" __exec_file__/setenv_builtins_3.txt > /dev/null
    write_test_result "$?" "0" "setenv_builtins_3" $cmd
  }
}

## Built-in unsetenv
{
  test_unsetenv_builtins_1() {
    cmd="setenv TITI 123\nunsetenv TITI\nenv\n"
    echo -ne $cmd | $BIN > ./__exec_file__/unsetenv_builtins_1.txt
    grep "TITI=" __exec_file__/unsetenv_builtins_1.txt > /dev/null
    write_test_result "$?" "1" "unsetenv_builtins_1" $cmd
  }

  test_unsetenv_builtins_2() {
    cmd="setenv TITI 123\nsetenv TOTO 789AZE\nunsetenv TITI\nenv\n"
    echo -ne $cmd | $BIN > ./__exec_file__/unsetenv_builtins_2.txt
    grep "TITI=123" __exec_file__/unsetenv_builtins_2.txt > /dev/null
    write_test_result "$?" "1" "unsetenv_builtins_2" $cmd
  }

  test_unsetenv_builtins_3() {
    cmd="setenv TITI 123=123=123=123=ABCDEF\nunsetenv TITI\nenv\n"
    echo -ne $cmd | env -i $BIN > ./__exec_file__/unsetenv_builtins_3.txt
    grep "TITI=123=123=123=123=ABCDEF" __exec_file__/unsetenv_builtins_3.txt > /dev/null
    write_test_result "$?" "1" "unsetenv_builtins_3" $cmd
  }
}

## 42sh only tests
{
  subject_ok_42sh() {
    cmd="cd ; </etc/hosts od -c | grep xx | wc >> /tmp/z -l ; cd - && echo \“OK\”"
    echo -ne $cmd | env -i tcsh &> ./__exec_file__/subject_ok_tcsh.txt
    echo -ne $cmd | env -i $BIN &> ./__exec_file__/subject_ok_42sh.txt
    diff ./__exec_file__/subject_ok_tcsh.txt ./__exec_file__/subject_ok_42sh.txt > /dev/null
    write_test_result "$?" "0" "unsetenv_builtins_3" "Goto 42sh subject"
  }
}

## Main
main() {
  prepare_repo
  echo "Tests will begin soon..."
  ## Mandatories for shells
  echo -ne "$TEXT\n--- SIMPLE INVALID COMMAND ---\n$END" > $RESULT_FILE
  test_invalid_command_1
  test_invalid_command_2
  test_invalid_command_3
  echo -ne "$TEXT\n--- SIMPLE EXEC ---\n$END" >> $RESULT_FILE
  test_simple_exec_1
  test_simple_exec_2
  echo -ne "$TEXT\n--- CD BUILTINS ---\n$END" >> $RESULT_FILE
  test_cd_builtins_1
  test_cd_builtins_2
  test_cd_builtins_3
  test_cd_builtins_4
  test_cd_builtins_no_home
  echo -ne "$TEXT\n--- SETENV BUILTINS ---\n$END" >> $RESULT_FILE
  test_setenv_builtins_1
  test_setenv_builtins_2
  test_setenv_builtins_3
  echo -ne "$TEXT\n--- UNSETENV BUILTINS ---\n$END" >> $RESULT_FILE
  test_unsetenv_builtins_1
  test_unsetenv_builtins_2
  test_unsetenv_builtins_3
  echo -e "$TEXT\n--- 42SH COMPLETED ---$END" >> $RESULT_FILE
  subject_ok_42sh

  cat $RESULT_FILE

  if [ $RM_AFTR -eq 1 ]; then
    rm -f $RESULT_FILE
    rm -rf __exec_file__
    rm -f ./bonus/gitlab/$BIN
  fi
}

main

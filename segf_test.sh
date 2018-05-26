#!/bin/sh

i=0

while [[ i -ne 1000 ]]
do
	echo simulation $i
	echo -ne "echo $bite\nset toto\necho $toto\n" | ./42sh
	if [[ $? -ne 0 ]]; then
		exit 84
	fi
	i=$i+1
done

echo ALL DONE

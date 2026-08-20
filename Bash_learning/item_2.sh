#! /bin/bash


echo "enter the name of the file : $1"


if [ $# -ne 0 ]
then
    if [ -f "$1" ]
    then
        cp "$1" "$1_backup_$(date +%Y%m%d)" 
        echo "copie success"
    else 
        echo "file name $1 not exit"
        exit 1
    fi
else
    echo"Please enter file"
    exit 1
fi

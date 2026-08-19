#!/bin/bash - 



echo "What is your favourite linux?"


echo "1-Arch"
echo "2-CwntOS"
echo "3-Debian"
echo "4-Mint"
echo "5-Ubuntu"
echo "6-Somthing else..."


read distro;

case $distro in
    1) echo "Arch is a rolling release";;
    2) echo "CentOs is popular on servers";;
    3) echo "Mint is popular on Desktops and labtops";;
    4) echo "Ubuntu is popular on both servers and computers.";;
    5) echo "Debian" ;;
    6) echo "to many distro";;
    *) echo "invalid argument";;
esac

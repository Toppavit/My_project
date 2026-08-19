#!/bin/bash 

release_file=/etc/os-release
log_file=/var/log/updater.log
error_log=/var/log/updater_errors.log

# Check for Arch Linux
if grep -q "Arch" "$release_file"; then
    # Pacman update (--noconfirm auto-approves prompts)
    sudo pacman -Syu --noconfirm 1>>"$log_file" 2>>"$error_log"
    if [ $? -ne 0 ]; then
        echo "An error occurred, please check the $error_log file."
    fi
fi

# Check for Debian / Ubuntu / Kali
if grep -q -i -E "debian|ubuntu|kali" "$release_file"; then
    # APT Update
    sudo apt update -y 1>>"$log_file" 2>>"$error_log"
    if [ $? -ne 0 ]; then
        echo "An error occurred during apt update, please check $error_log file."
    fi

    # APT Upgrade
    sudo apt dist-upgrade -y 1>>"$log_file" 2>>"$error_log"
    if [ $? -ne 0 ]; then
        echo "An error occurred during dist-upgrade, please check $error_log file."
    fi
fi

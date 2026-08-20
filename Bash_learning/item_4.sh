#!/bin/bash

for i in {1..5}; do
    ip="127.0.0.$i"

    if ping -c 1 -W 1 "$ip" > /dev/null 2>&1; then
        echo "[ONLINE]  : $ip"
    else
        echo "[OFFLINE] : $ip"
    fi
done




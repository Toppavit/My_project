#1 /bin/bsah

Hostname=/etc/hostname

echo "$(whoami)"
echo "$(cat $Hostname)"
echo "$(date)"
echo "$(df)"

#!/bin/bash
dir=$HOME/keeplog


mkdir -p "$dir"
cd "$dir" || exit 1


for num in {1..9}; do 
    touch "number_$num.log"
    echo "iteration $num"
done
    

echo "finish add file to $dir"

for file in *.log ; do
     if [ -f $file ]
     then 
         new_name="old_$file"
         mv "$file" "$new_name"
         echo "Rename : $file -> $new_name"
     fi
done

#!/bin/bash
read -p "Enter the number of terms: " n

a=0
b=1

echo "Fibonacci Series up to $n terms:"

for (( i=0; i<n; i++ ))
do
    echo "$a "
    sum=$((a + b))
    a=$b
    b=$sum
done

echo  # to print a newline at the end

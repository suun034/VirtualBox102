# doing the fibonacci work

read -p "Enter how many numbers to be printed from the fibonacci series = " num

a=0
b=1


for (( i=0; i<num; i++ )); do
    echo "$a"
    sum=$((a+b))
    a=$b
    b=$sum
done

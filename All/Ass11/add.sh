# read a
# read b

# sum=$(expr $a + $b)
# echo $sum

# read a
# read b

# sum=$((a+b))
# echo $sum

add_numbers(){
    sum=$(($1 + $2))
    return $sum
}

read num1
read num2

add_numbers $num1 $num2
received_value=$?

echo $received_value

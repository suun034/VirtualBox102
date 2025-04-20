#checking armstrong number

read -p "Enter a number to be checked = " num

checkdi=0
num1=$num

while (( num > 0 )); do
    num1=$((num1 / 10))
    checkdi=$((num1 + 1))
done

echo $checkdi
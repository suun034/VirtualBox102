#checking armstrong number

read -p "Enter a number to be checked = " num

original=$num
num1=$num
checkdi=0

# Count the number of digits
while (( num1 > 0 )); do
    num1=$((num1 / 10))
    checkdi=$((checkdi + 1))
done

echo "Number of digits = $checkdi"

# Check for Armstrong number
sum=0
temp=$num

while (( temp > 0 )); do
    digit=$(( temp % 10 ))
    power=$(( digit ** checkdi ))
    sum=$(( sum + power ))
    temp=$(( temp / 10 ))
done

if (( sum == original )); then
    echo "$original is an Armstrong number."
else
    echo "$original is not an Armstrong number."
fi

read -p "Enter a number to check = " num

if (( num % 2 == 0 )); then
    echo "$num is Even"
else
    echo "$num is Odd"
fi
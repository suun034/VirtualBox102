read -p "Enter the multiplicand = " num

for (( i=1; i<=10; i++ )); do
    echo "$num * $i = $((num * i))"
done

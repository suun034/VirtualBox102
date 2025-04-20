read -p "Enter a number = " num

if (( num < 2 )); then
    echo "$num is not a Prime Number"
fi

for (( i=2; i<num/2; i++ )); do
    if (( num % i == 0 )); then
        echo "$num is Prime Number"
        exit 1
    fi
done

echo "$num is not a Prime Number"

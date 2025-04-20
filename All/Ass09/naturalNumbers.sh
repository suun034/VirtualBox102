echo "Natural Numbers start from 1"
read -p "Enter the number of natural numbers to print = " num

for (( i=1 ; i <= num ; i++ )); do
    echo $i
done
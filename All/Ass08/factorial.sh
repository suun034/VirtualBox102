//factorial of a number

read -p "Enter the number to be factored = " num
fact=1

for (( i=1; i<=num; i++ )); do
  fact=$(( $fact * $i ))
done

echo "Factorial of $num = $fact"

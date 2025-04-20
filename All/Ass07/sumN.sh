read -p "Enter the number of natural numbers to add = " n

sum=0
for (( i=1; i<=n; i++ )); do
    sum=$((sum + i))
done

echo "Sum of $n natural numbers = $sum"
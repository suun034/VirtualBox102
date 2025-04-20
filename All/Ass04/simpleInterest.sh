read -p "Enter the principal amount = " p
read -p "Enter the rate percentage = " r
read -p "Enter the time in years = " t

# Step-by-step calculation
product=$(echo "$p * $r * $t" | bc)
si=$(echo "scale=2; $product / 100" | bc)


echo "Simple Interest = $si"

read -p "Enter a number = " num

nodig=0

while [ $num -gt 0 ];do
    num=$(expr $num / 10)
    nodig=$(expr $nodig + 1)
done

echo $nodig

# OR


#!/bin/bash

#!/bin/bash

read -p "Enter a number = " num1

nodig=0

while (( num1 > 0 )); do
    num1=$((num1 / 10))   # Reduce number by removing last digit
    nodig=$((nodig + 1))  # Increment digit count
done

echo "Number of digits = $nodig"


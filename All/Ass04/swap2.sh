read -p "Enter the first number = " a
read -p "Enter the second number = " b

echo "a = $a"
echo "b = $b"


# c=$(expr $a + $b )
# d=$(expr $a - $b )
# e=$(expr $a \* $b )

# echo $c
# echo $d
# echo $e

a=$(expr $a + $b)
b=$(expr $a - $b)
a=$(expr $a - $b)

echo "a = $a"
echo "b = $b"
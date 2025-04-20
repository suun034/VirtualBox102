#!/bin/bash

while true; do
    read -p "Enter the first number = " a
    read -p "Enter the second number = " b
    read -p "Enter the sign (+, -, *, /, %) = " s

    case $s in
        +) echo "Result = $((a + b))" ;;
        -) echo "Result = $((a - b))" ;;
        \*) echo "Result = $((a * b))" ;;   # Escaped * to prevent globbing
        /)echo "Result = $((a / b))" ;;
        %) echo "Result = $((a % b))" ;;
        *) echo "Invalid operator!" ;;
    esac

    read -p "Do you want to continue (yes/no)? " choice
    if [ "$choice" == "no" ]; then
        exit 0
    fi
done





















#!/bin/bash

# while ((1)); do
#     echo "Enter first number:"
#     read a
#     echo "Enter second number:"
#     read b
#     echo "Enter operator (+ - * / %):"
#     read op

#     case "$op" in
#         +) result=$((a + b)) ;;
#         -) result=$((a - b)) ;;
#         \*) result=$((a * b)) ;;
#         /) 
#             if (( b == 0 )); then
#                 echo "Division by zero not allowed."
#                 continue
#             fi
#             result=$((a / b))
#             ;;
#         %) 
#             if (( b == 0 )); then
#                 echo "Modulo by zero not allowed."
#                 continue
#             fi
#             result=$((a % b))
#             ;;
#         *) echo "Invalid operator"; continue ;;
#     esac

#     echo "Result = $result"
#     echo "Do you want to continue? (y/n)"
#     read ans
#     if [[ "$ans" != "y" ]]; then
#         break
#     fi
# done


# #!/bin/bash

# while [ 1 ]; do
#     echo "Enter first number:"
#     read a
#     echo "Enter second number:"
#     read b
#     echo "Enter operator (+ - * / %):"
#     read op

#     case "$op" in
#         +) result=$(expr $a + $b) ;;
#         -) result=$(expr $a - $b) ;;
#         \*) result=$(expr $a \* $b) ;;  # escape * to avoid globbing
#         /) 
#             if [ "$b" -eq 0 ]; then
#                 echo "Division by zero not allowed."
#                 continue
#             fi
#             result=$(expr $a / $b)
#             ;;
#         %) 
#             if [ "$b" -eq 0 ]; then
#                 echo "Modulo by zero not allowed."
#                 continue
#             fi
#             result=$(expr $a % $b)
#             ;;
#         *) echo "Invalid operator"; continue ;;
#     esac

#     echo "Result = $result"
#     echo "Do you want to continue? (y/n)"
#     read ans
#     [ "$ans" != "y" ] && break
# done


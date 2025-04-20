#!/bin/bash

while ((1)); do
    echo "Enter first number:"
    read a
    echo "Enter second number:"
    read b
    echo "Enter operator (+ - * / %):"
    read op

    case "$op" in
        +) result=$((a + b)) ;;
        -) result=$((a - b)) ;;
        \*) result=$((a * b)) ;;
        /) 
            if (( b == 0 )); then
                echo "Division by zero not allowed."
                continue
            fi
            result=$((a / b))
            ;;
        %) 
            if (( b == 0 )); then
                echo "Modulo by zero not allowed."
                continue
            fi
            result=$((a % b))
            ;;
        *) echo "Invalid operator"; continue ;;
    esac

    echo "Result = $result"
    echo "Do you want to continue? (y/n)"
    read ans
    if [[ "$ans" != "y" ]]; then
        break
    fi
done

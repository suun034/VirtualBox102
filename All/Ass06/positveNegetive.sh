# read -p "Enter a number = " num

# if [ $num -eq 0 ]; then
#     echo "$num is Zero"
# elif [ $num -gt 0 ]; then
#     echo "$num is Positive"
# else
#     echo "$num is Negetive"
# fi


# checking positive or negetive

read -p "Enter a number = " num

if [ $num -eq 0 ];then
    echo "$num is zero."
elif [ $num -gt 0 ];then 
    echo "$num is positive"
elif [ $num -lt 0 ];then 
    echo "$num is negetive"
else   
    echo "Invalid Input"
fi
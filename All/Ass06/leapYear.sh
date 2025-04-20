# read -p "Enter a year = " year


#     if (( ($year % 400 == 0) || ($year % 4 == 0 && $year % 100 != 0) )); then
#         echo "$year is a Leap Year"
#     else
#         echo "$year is not a Leap Year"
#     fi


read -p "Enter a year = " year

#checking if leap year
if (( ($year % 400 == 0) | ($year % 4 ==0 && $year % 100 != 0) )); then
    echo "$year is a Leap Year"
fi
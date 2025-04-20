# add_numbers(){
#     sum=$(($1+$2))
#     echo "Sum of $1 and $2 = $sum"
# }

# read -p "Enter the first number = " a
# read -p "Enter the second number = " b

# add_numbers $a $b

#!/bin/bash

# Get the day of the week using date command
day_of_week=$(date +%A)
echo "Today is: $day_of_week"

#!/bin/bash

# Read month and year from user
read -p "Enter year (e.g., 2025): " year
read -p "Enter month (1-12): " month

# Use date to find the number of days in the month
#days_in_month=$(date -d "$year-$month-01 + 1 month - 1 day" +%d)
#echo "Number of days in $month/$year: $days_in_month"


#!/bin/bash

# Read month and year from user
#read -p "Enter year (e.g., 2025): " year
#read -p "Enter month (1-12): " month

# Check if the month is valid
if [ "$month" -lt 1 ] || [ "$month" -gt 12 ]; then
  echo "Invalid month!"
  exit 1
fi

# Using cal command to find the number of days in the month
days_in_month=$(cal $month $year | awk 'NF {DAYS = $NF} END {print DAYS}')
echo "Number of days in $month/$year: $days_in_month"

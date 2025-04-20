# compareGrade(){
#     if (( $1 > 90 )); then
#         return 34
#     fi
# }

# compareGrade $a
# value=$?

# echo $value

read -p "Enter the marks for first subject = " a
read -p "Enter the marks for second subject = " b
read -p "Enter the marks for third subject = " c

compareGrade(){
    m=$1
    if (( m > 90 )); then
        echo "Grade A"
    elif (( m > 80 && m < 90)); then
        echo "Grade B"
    elif (( m > 70 && m < 80)); then
        echo "Grade C"
    elif (( m > 60 && m < 70)); then
        echo "Grade D"
    elif (( m > 40 && m < 60)); then
        echo "Grade E"
    else
        echo "Invalid"
    fi
}

compareGrade $a
compareGrade $b
compareGrade $c
read year
read month

if [[ $month -lt 1 || $month -gt 12 ]]; then
    echo "Invalid Month"
    exit 1
fi

days=$(cal $month $year | awk 'NF{d=$NF}; END{print d}')
echo $days

# Find leap years

read -p "Enter a year: " year

if [ $((year%4)) -eq 0 ]
then
    echo "Year $year is a leap year"
else
    echo "$year is not a leap year"
fi
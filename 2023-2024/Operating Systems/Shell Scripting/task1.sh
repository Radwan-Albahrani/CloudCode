# Program to do subtraction multiplication and division

read -p "Enter two numbers: " a b

# if i dont enter a second number, assign it to 0

if [ -z $b ]
then
    b=0
fi


echo "Subtraction: $((a-b))"
echo "Multiplication: $((a*b))"
if [ $b == 0 ]
then
    echo "Division: Not possible"
else
    echo "Division: $((a/b))"
fi
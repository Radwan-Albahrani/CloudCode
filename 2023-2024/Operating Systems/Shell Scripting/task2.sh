# Converting time

echo "Choose the conversion: "
echo "1. Hours to Minutes"
echo "2. Hours to Seconds"
echo "3. Seconds to Hours"
echo "4. Minutes to Seconds"
echo "5. Seconds to Minutes"

read -p "Enter your choice: " choice

case $choice in
    1) read -p "Enter the number of hours: " hours
       echo "$hours hours = $((hours*60)) minutes"
       ;;
    2) read -p "Enter the number of hours: " hours
       echo "$hours hours = $((hours*3600)) seconds"
       ;;
    3) read -p "Enter the number of seconds: " seconds
       echo "$seconds seconds = $((seconds/3600)) hours"
       ;;
    4) read -p "Enter the number of minutes: " minutes
       echo "$minutes minutes = $((minutes*60)) seconds"
       ;;
    5) read -p "Enter the number of seconds: " seconds
       echo "$seconds seconds = $((seconds/60)) minutes"
       ;;
    *) echo "Invalid choice"
       ;;
esac
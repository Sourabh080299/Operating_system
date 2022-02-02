echo "..........................................................."
echo "[1] Find the number of users logged into the system"
echo "[2] Print the calendar for cuurent year"
echo "[3] Print the date"
read -p "Enter choice: " choice
case "$choice" in
1)
who --count ;;
2)
cal -y ;;
3)
date ;;
*)
echo "none" ;;
esac

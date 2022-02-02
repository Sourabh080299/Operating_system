if [[ $# == 3 ]]
then 
case "$2" in
"+")
echo "$1 + $3" | bc ;;
"-")
echo "$1 - $3" | bc ;;
"X")
echo "$1 * $3" | bc ;;
"/")
echo "$1 / $3" | bc ;;
"%")
echo "$1 % $3" | bc ;;
*)
echo "Incorrect input" ;;

esac
else
echo "Enter 3 arguments only"
fi

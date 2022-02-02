if [[ $# == 2 ]]
then
echo "$1 + $2 " | bc
else
echo "Enter 2 arguments only"
fi

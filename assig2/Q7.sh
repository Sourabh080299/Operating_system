if [[ $# == 3 ]]
then 
if [[ $1 -ge $2 && $1 -ge $3 ]]
then 
echo "$1 is the greatesst value"
elif [[ $2 -ge $1 && $2 -ge $3 ]]
then
echo "$2 is the greatest value"
else
echo "$3 is greatest value"
fi
else
echo "Enter 3 arguments only"
fi

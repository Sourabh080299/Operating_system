if [ $# == 1 ]
then
if [ -e $1 ]
then
if [ -f $1 ]
then
echo "Regular file"
elif [ -d $1 ]
then
echo "Directory"
elif [ -b $1 ]
then
echo "Block special file"
elif [ -c $1 ]
then
echo "Character special"
elif [ -S $1 ]
then
echo "Socket"
elif [ -p $1 ]
then
echo "Named pipe"
elif [ -h $1 ]
then
echo "Symbolic link"
fi
else
echo "'$1' doesn't exist"
fi
else
echo "Incorrect no of arguments"
fi
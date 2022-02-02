read -p "Enter directory name: " dir
if [ -d "$dir" ]
then 
echo "Is a directory"
else
echo "Is not a directory"
fi

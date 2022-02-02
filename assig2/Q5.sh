read -p "Enter sourace file to copy: " file1
read -p "Enter  destination  file: " file2
if [[ -f "$file1" && -f  "$file2"  ]]
then
cp $file1 $file2
echo "Copay Successful"
else
if [[ ! -f "$file1" ]]
then
echo "Source file doesn't exist"
else 
echo "Destintion file doesn't exist"
fi
fi


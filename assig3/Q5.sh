read -p "Enter the file name: " file 
if [ -e $file ] 
then 
 echo -n "Total num of blank lines in file: " 
 grep -cvP '\S' $file 
else 
 echo "File does not exist" 
fi 


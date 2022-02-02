read -p "Enter the directory name: " dir 
if [[ -e $dir ]] 
then 
 echo "Files greater than 1000 bytes:" 
 find $dir -type f -size +1k -exec du -h {} \; | sort -rh 
 echo -n "No of files: " 
 find $dir -type f -size +1k -ls | wc -l 
else echo "Directory does not exist" 
fi

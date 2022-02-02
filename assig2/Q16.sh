read -p "Enter a file name: " file 
if [ -f $file ] 
then 
lines=`wc -l $file` 
word=`wc -w $file` 
char=`wc -m $file` 
echo -e "Charecters = $char \nWords = $word \nLines = $lines" 
else 
echo -E "File doesn't exist!" 
fi
if [ $# -lt 2 ] 
then 
 echo "Enter 2 arguments!" 
else 
 for ((i=0;i<$1;i++)) 
 do 
 echo "$2" 
 done 
fi 


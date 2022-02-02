time=$(date "+%H") 
if [[ $time -lt 12 ]] 
then 
 echo "Good morning" 
elif [[ $time -lt 17 ]] 
then 
 echo "Good Afternoon" 
else 
 echo "Good Evening" 
fi

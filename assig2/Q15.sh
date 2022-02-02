read -p "Enter lower limit: " start 
read -p "Enter upper limit: " end 
if [ $start -lt $end ] 
then 
while [ $start -lt $end ] 
do 
if [ $((start % 2)) == 0 ] 
then 
echo $start 
fi 
start=$((start + 1)) 
done 
else 
echo "Incorrent range" 
fi
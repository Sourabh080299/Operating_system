read -p "Enter number: " num 
temp=0 
while [ $num -gt 0 ] 
do 
temp=$((temp * 10 + num % 10)) 
num=$((num / 10)) 
done 
echo "Reverse = $temp"

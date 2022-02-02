read -p "Enter number: " num 
ans=1 
while [ $num -gt 0 ] 
do 
ans=$((ans * num)) 
num=$((num - 1)) 
done 
echo "Factorial = $ans"
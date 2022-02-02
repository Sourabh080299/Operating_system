read -p "Enter the number of element in Fibonacci series: " num 
echo "Fibonacci series: " 
num1=1 
num2=1 
temp=0 
count=0 
while [ $count -lt $num ] 
do 
count=$((count + 1)) 
echo "$num1" 
temp=$((num1 + num2)) 
num1=$num2 
num2=$temp 
done

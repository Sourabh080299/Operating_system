read -p "Enter a positive num: " n 
echo "Its divisors:" 
for (( i=1;i<=$n;i++ )) 
do 
 if [ $((n % i)) == 0 ] 
 then 
 echo -n "$i " 
 fi 
done 
echo

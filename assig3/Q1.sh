read -p "Enter a num: " n 
flag=0 
while [ `expr $n % 2` == 0 ] 
do 
 flag=1 
 n=$((n / 2)) 
done 
if [ $flag == 1 ] 
then 
 echo -n "2 " 
fi 
i=3 
while [ `expr $i \* $i ` -le $n ] 
do 
 while [ `expr $n % $i` == 0 ] 
 do 
 n=$((n / i)) 
 flag=1 
 done 
 echo -n "$i " 
 i=$((i + 2)) 
done 
if [ $n -gt 2 ] 
then 
 echo -n "$n" 
fi
echo


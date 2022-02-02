read -p "Enter number 1: " num1 
read -p "Enter number 2: " num2 
read -p "Enter operator: " op 
case "$op" in 
"+") 
echo "$num1 + $num2 = `expr $num1 + $num2`" 
;; 
"-") 
echo "$num1 - $num2 = `expr $num1 - $num2`" 
;; 
"*") 
echo "$num1 * $num2 = `expr $num1 \* $num2`" 
;; 
"/") 
echo "$num1 / $num2 = `expr $num1 / $num2`" 
;; 
"%") 
echo "$num1 % $num2 = `expr $num1 % $num2`" 
;; 
*) 
echo "Incorrect input" 
;; 
esac
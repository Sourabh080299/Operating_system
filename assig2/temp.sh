#! /bin/bash

read -p "Enter a character: " CHAR 
case "$CHAR" in 
[aeiouAEIOU]) 
echo "Vowel" ;; 
[A-Z]) 
echo "Upper Case" ;; 
[a-z]) 
echo "Lower Case" ;; 
[0-9]) 
echo "Digit" ;; 
['!@#\$%^\&*()_+']) 
echo "Special Character" ;; 
*) 
echo "None" ;; 
esac
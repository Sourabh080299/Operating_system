direc="."
echo -e "Enter sub-dir name: \c" 
read direc
find $direc -mindepth 2 -executable -type f
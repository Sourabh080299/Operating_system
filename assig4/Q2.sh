for direc in $@
do
if [ -d $direc ]
then
find $direc -type d |
while read -r dir
do printf "%10s:\t" "$dir"; find "$dir" -maxdepth 1 -type f | wc -l;
done
echo " "
else
echo "./Q2.sh [dirname]"
fi
done
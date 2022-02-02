for direc in $@
do
if [ -d $direc ]
then
echo -e "Blocks by $direc: \c"
ls -s $direc | sed 's/^ *//' | grep total
else
echo "$direc not found"
fi
done

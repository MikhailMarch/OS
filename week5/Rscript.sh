if test ! -f Numbers
then
    echo 0 > Numbers
fi

for i in 'seq 1 100':
do
  n=$(tail -n  1 < Numbers)
  expr $n + 1 >> Numbers
done

# this script could couse a race condition when two scrips access the same file Numbers

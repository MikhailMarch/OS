if test ! -f NumbersNR
then
    echo 0 > NumbersNR
fi

if ln NumbersNR numbers.lock
  then
  for i in 'seq 1 100':
  do
    n=$(tail -n  1 < Numbers)
    expr $n + 1 >> Numbers
  done    
  rm numbers.lock
fi

# this script will not couse a race condition

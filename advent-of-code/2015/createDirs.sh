for i in `seq 1 24` 
do 
    if [ $i -lt 10 ]; then
        i="0$i"
    fi
        mkdir $i
    
done

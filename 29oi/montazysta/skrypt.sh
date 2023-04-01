#!/bin/bash

for i in {0..4999}
do
    #: '
    #if [ $i -lt 10 ]
#    then
 #       a="00${i}"
  #  else
#        if [ $i -lt 100 ]
 #       then
  #          a="0${i}"
   #     else
    #        a="${i}"
#        fi
 #   fi
 #   '


    ./mon < ./in/mon$i.in > ./mon.out

    ./spr ./in/mon$i.in ./mon.out ./out/mon$i.out; 
    if [ $? -ne 0 ]
    then break;
    fi

    
done

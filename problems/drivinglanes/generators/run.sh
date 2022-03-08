#!/bin/bash

for FILE in *.in ; do
  OUT=`echo $FILE | sed -e 's/.in/.ans/'`
  ../submissions/accepted/DL < $FILE > $OUT
done

#!/bin/bash
echo 'testing sorts:'
for i in {1000..10000..1000}
do
	fname='k.txt'
	echo "Testing $i$fname"
	#./bubblesort < "$i$fname" >> 'results_bubble.txt'
	#./selsort < "$i$fname" >>'results_sel.txt'
	./mergesort < "$i$fname" >>'results_merge.txt'
done

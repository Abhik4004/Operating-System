#!/bin/bash

echo "Enter no: "
read no

for i in $(seq 1 "$no"); do 
	mul=$(echo "$i*$i*$i" | bc)
	echo "Cube of $i is $mul"
done



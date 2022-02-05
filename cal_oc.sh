# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    cal_oc.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 01:40:54 by hyeonsok          #+#    #+#              #
#    Updated: 2022/02/04 05:31:18 by hyeonsok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

read -p "look from x,y,z: " -a lookfrom
read -p "look at x,y,z: " -a lookat

## [[ string =~ regex ]]
# The re-match operator performs regular expression matching of the string on 
# its left to the right. If the left side matches the right side, the operator
# returns a 0 and a 1 otherwise.

## Check the length of the array
if [[ $((${#lookfrom[@]})) -ne 3 || $((${#lookat[@]})) -ne 3 ]]; then
	printf "Error\n"; exit 1
fi

## Check the format of a floating-point number
for i in "${lookfrom[@]}"
do
	if [[ $i =~ [:digit:]|([:digit:]\.[:digit:]) ]]; then
		printf "Error\n"; exit 1
	fi
done

for i in "${lookat[@]}"
do
	if [[ $i =~ [:digit:]|([:digit:]\.[:digit:]) ]]; then
		printf "Error\n"; exit 1
	fi
done

## Find relative postion
x=$(echo "${lookat[0]} - ${lookfrom[0]}" | bc -l)
y=$(echo "${lookat[1]} - ${lookfrom[1]}" | bc -l)
z=$(echo "${lookat[2]} - ${lookfrom[2]}" | bc -l)

## Square calculation
xx=$(echo $x \* $x | bc -l)
yy=$(echo $y \* $y | bc -l)
zz=$(echo $z \* $z | bc -l)

distance=$(echo "sqrt($xx + $yy + $zz)" | bc -l)

## Vector normalization
vec_i=$(echo "$x / $distance" | bc -l)
vec_j=$(echo "$y / $distance" | bc -l)
vec_k=$(echo "$z / $distance" | bc -l)

printf "%.5f,%.5f,%.5f\n" $vec_i $vec_j $vec_k

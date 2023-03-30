#!/usr/bin/gnuplot
set termoption enhanced
set terminal png size 1920,1080 font "Arial, 20"
set output "graph.png"
set border lw 2
set grid
set key top left
set xlabel "Количество элементов в массиве"
set ylabel "Время выполнения, с" rotate by 90
set xtics 100000
set mxtics
set title "Зависимость времени выполнения сортировок от количества элементов в массиве"
set format x "%6.0f"
set format y "%.2f"
set xrange [50000:1000000]
plot "sort.txt" using 1:4 title "Heap Sort" with lines lt rgb "blue" lw 4, \
"sort.txt" using 1:3 title "Radix Sort" with lines lt rgb "red" lw 4, \
"sort.txt" using 1:2 title "Odd Even Sort" with lines lt rgb "green" lw 4
 
unset label
clear
set terminal pdf
set output "Grafica.pdf"
set title "Ploteo de datos"
set xlabel "Tiempo (s)"
set ylabel "Velocidad (m/s)"
set grid
set style data points
plot "Datos" using 1:2, "MC" using 1:2 with lines

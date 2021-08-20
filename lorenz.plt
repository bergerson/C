set terminal tikz size 8.1cm, 5.2cm fontscale 0.8 fulldoc header "\\usepackage{amsmath}"
set output "lorenz_t_27.tex"

#set format x  "%$10^{%T}$"
#set format x  "%h$"
set xlabel offset 0.2, 0.4 "$t$"
set ylabel offset 1, 0 "$X$"

#set decimalsign ","

set xtics  offset 0.0, 0.0  10.0 nomirror
set ytics  offset  1.0, 0.5 10.0 nomirror
set xrange  [0:30]
set yrange  [-20:20]

#set key Right top Right reverse samplen 2.0 sample 0.6 spacing 1.3 height 0.3 width 4.0 box

set title "Time history of X - Lorenz equation (Parameter 27)"

set style line 1 dt 1 lc rgb "#0000ff" lw 2.5
set style line 2 dt 2 lc rgb "#000000" lw 2.5
set style line 3 dt 3 lc rgb "#000000" lw 1.5

plot 	 "lorenz.dat" u ($1):($2) w l ls 1 t" "
		
	  
		
		

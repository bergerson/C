	make lorenz-c
	time ./lorenz
	gnuplot *.plt
	pdflatex *.tex
	rm -f *.log *.aux *.tex

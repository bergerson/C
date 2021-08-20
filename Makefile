CC = gcc
TARGETS = lorenz

#CFLAGS = -Wall
CFLAGS = -O2 -Wall

LIBS = -lm -lgsl -lgslcblas

#all: $(TARGETS)

lorenz: lorenz.c
	$(CC) $(CFLAGS) lorenz.c $(LIBS) -o lorenz
	

	

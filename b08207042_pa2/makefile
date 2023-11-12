# CC and CFLAGS are varilables
CC = g++
CFLAGS = -c
AR = ar
ARFLAGS = rcv
# -O2 option is for optimized version
OPTFLAGS = -O2

all	: bin/mps

# formal version
bin/mps	: maxPlanarSubset.o main.o
			$(CC) maxPlanarSubset.o main.o -o bin/mps
main.o 	   	: src/main.cpp
			$(CC) $(CFLAGS) $< -o $@
maxPlanarSubset.o	: src/maxPlanarSubset.cpp src/maxPlanarSubset.h
			$(CC) $(CFLAGS) $(CFLAGS) $< -o $@

# clean all the .o and executable files
clean:
	rm -rf *.o bin/*
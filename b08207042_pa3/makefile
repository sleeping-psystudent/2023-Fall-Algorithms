# CC and CFLAGS are varilables
CC = g++
CFLAGS = -c
AR = ar
ARFLAGS = rcv
# -O2 option is for optimized version
OPTFLAGS = -O2

all	: bin/cb

# formal version
bin/cb	: functions.o main.o
			$(CC) functions.o main.o -o bin/cb
main.o 	   	: src/main.cpp
			$(CC) $(CFLAGS) $< -o $@
functions.o	: src/functions.cpp src/functions.h
			$(CC) $(CFLAGS) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o bin/*
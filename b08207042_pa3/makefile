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



# time testing version
#bin/cb	: functions.o main.o
			$(CC) functions.o main.o -ltm_usage -Llib -o bin/cb
#main.o 	   	: src/main.cpp lib/tm_usage.h
			$(CC) $(CFLAGS) $< -o $@
#functions.o	: src/functions.cpp src/functions.h
			$(CC) $(CFLAGS) $(CFLAGS) $< -o $@

#lib: lib/libtm_usage.a

#lib/libtm_usage.a: tm_usage.o
	$(AR) $(ARFLAGS) $@ $<
#tm_usage.o: lib/tm_usage.cpp lib/tm_usage.h
	$(CC) $(CFLAGS) $<

# clean all the .o and executable files
clean:
	rm -rf *.o bin/*
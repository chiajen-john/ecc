CC = g++
CFLAGS = -Wall -g -Werror

ecc: ecc.o main.o
	$(CC) $(CCFLAGS) -o ecc ecc.o main.o -std=gnu++0x

main.o: main.cpp ecc.cpp ecc.h
	$(CC) $(CCFLAGS) -c main.cpp -std=gnu++0x

ecc.o: ecc.cpp ecc.h
	$(CC) $(CCFLAGS) -c ecc.cpp -std=gnu++0x

check:
	./ecc

clean:
	rm -f *.o
	rm ecc
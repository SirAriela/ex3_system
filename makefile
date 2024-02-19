CC=gcc
OBJECTS_MAIN=main.o 
FLAGS= -Wall -g

all: StrList

StrList: $(OBJECTS_MAIN) StrList.o
	$(CC) $(FLAGS) -o StrList $(OBJECTS_MAIN) StrList.o

StrList.o: StrList.c
	$(CC) $(FLAGS) -fPIC -c StrList.c

main.o: main.c
	$(CC) $(FLAGS) -c main.c
	
clean:
	rm -f *.o StrList

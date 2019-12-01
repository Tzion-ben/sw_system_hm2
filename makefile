CC=gcc
OBJECTS_MAIN=main.o
OBJECTS_LIB=myBank.o 
FLAGS= -Wall -g

all: myBankL main	

main:  $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o main $(OBJECTS_MAIN) ./libmyBank.so

myBankL: libmyBank.so

libmyBank.so: $(OBJECTS_LIB)
	$(CC) -shared -o libmyBank.so $(OBJECTS_LIB)	

myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -fPIC -c myBank.c
main.o: main.c myBank.h  
	$(CC) $(FLAGS) -c main.c 

.PHONY: clean all

clean:
	rm -f *.o *.a *.so main
